/* distance-ir-bricklet
 * Copyright (C) 2012 Olaf Lüke <olaf@tinkerforge.com>
 *
 * distance-ir.c: Implementation of Distance IR Bricklet messages
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the
 * Free Software Foundation, Inc., 59 Temple Place - Suite 330,
 * Boston, MA 02111-1307, USA.
 */

#include "distance-ir.h"

#include "brickletlib/bricklet_entry.h"
#include "bricklib/bricklet/bricklet_communication.h"
#include "bricklib/drivers/adc/adc.h"
#include "bricklib/utility/util_definitions.h"
#include "bricklib/bricklet/bricklet_config.h"
#include "bricklib/com/i2c/i2c_eeprom/i2c_eeprom_common.h"
#include "config.h"

#define MAX_ADC_VALUE ((1  << 12) - 1)
#define MAX_DISTANCE 128

#define DISTANCE_DIVIDER 32

#define EEPROM_POSITION (I2C_EEPROM_INTERNAL_ADDRESS_PLUGIN + \
                         BRICKLET_PLUGIN_MAX_SIZE)

#define SIMPLE_UNIT_DISTANCE 0
#define SIMPLE_UNIT_ANALOG_VALUE 1

#define LOOKUP_SIZE 128

const SimpleMessageProperty smp[] = {
	{SIMPLE_UNIT_DISTANCE, SIMPLE_TRANSFER_VALUE, SIMPLE_DIRECTION_GET}, // FID_GET_DISTANCE
	{SIMPLE_UNIT_ANALOG_VALUE, SIMPLE_TRANSFER_VALUE, SIMPLE_DIRECTION_GET}, // FID_GET_ANALOG_VALUE
	{0, 0, 0}, // FID_SET_SAMPLING_POINT
	{0, 0, 0}, // FID_GET_SAMPLING_POINT
	{SIMPLE_UNIT_DISTANCE, SIMPLE_TRANSFER_PERIOD, SIMPLE_DIRECTION_SET}, // FID_SET_DISTANCE_CALLBACK_PERIOD
	{SIMPLE_UNIT_DISTANCE, SIMPLE_TRANSFER_PERIOD, SIMPLE_DIRECTION_GET}, // FID_GET_DISTANCE_CALLBACK_PERIOD
	{SIMPLE_UNIT_ANALOG_VALUE, SIMPLE_TRANSFER_PERIOD, SIMPLE_DIRECTION_SET}, // FID_SET_ANALOG_VALUE_CALLBACK_PERIOD
	{SIMPLE_UNIT_ANALOG_VALUE, SIMPLE_TRANSFER_PERIOD, SIMPLE_DIRECTION_GET}, // FID_GET_ANALOG_VALUE_CALLBACK_PERIOD
	{SIMPLE_UNIT_DISTANCE, SIMPLE_TRANSFER_THRESHOLD, SIMPLE_DIRECTION_SET}, // FID_SET_DISTANCE_CALLBACK_THRESHOLD
	{SIMPLE_UNIT_DISTANCE, SIMPLE_TRANSFER_THRESHOLD, SIMPLE_DIRECTION_GET}, // FID_GET_DISTANCE_CALLBACK_THRESHOLD
	{SIMPLE_UNIT_ANALOG_VALUE, SIMPLE_TRANSFER_THRESHOLD, SIMPLE_DIRECTION_SET}, // FID_SET_ANALOG_VALUE_CALLBACK_THRESHOLD
	{SIMPLE_UNIT_ANALOG_VALUE, SIMPLE_TRANSFER_THRESHOLD, SIMPLE_DIRECTION_GET}, // FID_GET_ANALOG_VALUE_CALLBACK_THRESHOLD
	{0, SIMPLE_TRANSFER_DEBOUNCE, SIMPLE_DIRECTION_SET}, // FID_SET_DEBOUNCE_PERIOD
	{0, SIMPLE_TRANSFER_DEBOUNCE, SIMPLE_DIRECTION_GET}, // FID_GET_DEBOUNCE_PERIOD
};

const SimpleUnitProperty sup[] = {
	{distance_from_analog_value, SIMPLE_SIGNEDNESS_UINT, FID_DISTANCE, FID_DISTANCE_REACHED, SIMPLE_UNIT_ANALOG_VALUE}, // distance
	{analog_value_from_mc, SIMPLE_SIGNEDNESS_UINT, FID_ANALOG_VALUE, FID_ANALOG_VALUE_REACHED, SIMPLE_UNIT_ANALOG_VALUE}, // analog value
};

const uint8_t smp_length = sizeof(smp);

const uint16_t lookup[LOOKUP_SIZE] = {8000, 8000, 8000, 8000, 8000, 8000, 8000, 8000, 8000, 8000, 8000, 8000, 8000, 8406, 6897, 6471, 5679, 5516, 5216, 4846, 4600, 4184, 3934, 3765, 3563, 3395, 3265, 3147, 3017, 2866, 2720, 2600, 2505, 2429, 2363, 2301, 2237, 2169, 2095, 2024, 1962, 1916, 1891, 1874, 1830, 1731, 1654, 1625, 1590, 1524, 1467, 1435, 1417, 1402, 1381, 1354, 1324, 1296, 1272, 1251, 1232, 1215, 1197, 1179, 1160, 1139, 1118, 1097, 1074, 1051, 1028, 1005, 982, 961, 941, 923, 910, 901, 896, 895, 894, 890, 880, 861, 830, 783, 700, 700, 700, 700, 700, 700, 700, 700, 700, 700, 700, 700, 700, 700, 700, 700, 700, 700, 700, 700, 700, 700, 700, 700, 700, 700, 700, 700, 700, 700, 700, 700, 700, 700, 700, 700, 700, 700, 700, 700, 700};

void invocation(const ComType com, const uint8_t *data) {
	switch(((SimpleStandardMessage*)data)->header.fid) {
		case FID_GET_SAMPLING_POINT: {
			get_sampling_point(com, (GetSamplingPoint*)data);
			return;
		}

		case FID_SET_SAMPLING_POINT: {
			set_sampling_point(com, (SetSamplingPoint*)data);
			return;
		}

		default: {
			simple_invocation(com, data);
			break;
		}
	}

	if(((SimpleStandardMessage*)data)->header.fid > FID_LAST) {
		BA->com_return_error(data, sizeof(MessageHeader), MESSAGE_ERROR_CODE_NOT_SUPPORTED, com);
	}

}

void constructor(void) {
	_Static_assert(sizeof(BrickContext) <= BRICKLET_CONTEXT_MAX_SIZE, "BrickContext too big");

	for(uint8_t i = 0; i < NUM_MOVING_AVERAGE; i++) {
		BC->moving_average[i] = 0;
	}
	BC->moving_average_tick = 0;
	BC->moving_average_sum = 0;

	adc_channel_enable(BS->adc_channel);
	simple_constructor();
}

void destructor(void) {
	simple_destructor();
	adc_channel_disable(BS->adc_channel);
}

void get_sampling_point(const ComType com, const GetSamplingPoint *data) {
	GetSamplingPointReturn gspr;

	if(data->position >= LOOKUP_SIZE) {
		BA->com_return_error(data, sizeof(GetSamplingPointReturn), MESSAGE_ERROR_CODE_INVALID_PARAMETER, com);
		return;
	}

	gspr.header        = data->header;
	gspr.header.length = sizeof(GetSamplingPointReturn);
	gspr.distance      = lookup[data->position];

	BA->send_blocking_with_timeout(&gspr,
	                               sizeof(GetSamplingPointReturn),
	                               com);
}

void set_sampling_point(const ComType com, const SetSamplingPoint *data) {
	if(data->position >= LOOKUP_SIZE) {
		BA->com_return_error(data, sizeof(MessageHeader), MESSAGE_ERROR_CODE_INVALID_PARAMETER, com);
		return;
	}

	// Calculate position of lookup table in eeprom
	uint16_t lookup_start_position = I2C_EEPROM_INTERNAL_ADDRESS_PLUGIN +
	                                 (uint32_t)lookup - BS->baddr->plugin;

    BA->bricklet_select(BS->port - 'a');
    BA->i2c_eeprom_master_write(BA->twid->pTwi,
                                lookup_start_position + data->position*2,
                                (char *)&data->distance,
                                2);
    BA->bricklet_deselect(BS->port - 'a');

    BA->com_return_setter(com, data);
}

int32_t analog_value_from_mc(const int32_t value) {
	uint16_t analog_data = BA->adc_channel_get_data(BS->adc_channel);
	BC->moving_average_sum = BC->moving_average_sum -
	                         BC->moving_average[BC->moving_average_tick] +
	                         analog_data;

	BC->moving_average[BC->moving_average_tick] = analog_data;
	BC->moving_average_tick = (BC->moving_average_tick + 1) % NUM_MOVING_AVERAGE;

	return (BC->moving_average_sum + NUM_MOVING_AVERAGE/2)/NUM_MOVING_AVERAGE;
}

int32_t distance_from_analog_value(const int32_t value) {
	uint16_t div_value = value/DISTANCE_DIVIDER;
	uint8_t mod = div_value % DISTANCE_DIVIDER;

	uint16_t distance = ((DISTANCE_DIVIDER - mod)*lookup[div_value] +
						mod*lookup[div_value+1])/DISTANCE_DIVIDER;

	// Make mm
	return (distance + 5) / 10;
}

void tick(uint8_t tick_type) {
	simple_tick(tick_type);
}
