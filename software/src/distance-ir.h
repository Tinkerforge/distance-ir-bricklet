/* distance-ir-bricklet
 * Copyright (C) 2012 Olaf Lüke <olaf@tinkerforge.com>
 *
 * distance-ir.h: Implementation of Distance IR Bricklet messages
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

#ifndef DISTANCE_IR_H
#define DISTANCE_IR_H

#include <stdint.h>

#include "bricklib/com/com_common.h"

#define FID_GET_DISTANCE 1
#define FID_GET_ANALOG_VALUE 2
#define FID_SET_SAMPLING_POINT 3
#define FID_GET_SAMPLING_POINT 4
#define FID_SET_DISTANCE_CALLBACK_PERIOD 5
#define FID_GET_DISTANCE_CALLBACK_PERIOD 6
#define FID_SET_ANALOG_VALUE_CALLBACK_PERIOD 7
#define FID_GET_ANALOG_VALUE_CALLBACK_PERIOD 8
#define FID_SET_DISTANCE_CALLBACK_THRESHOLD 9
#define FID_GET_DISTANCE_CALLBACK_THRESHOLD 10
#define FID_SET_ANALOG_VALUE_CALLBACK_THRESHOLD 11
#define FID_GET_ANALOG_VALUE_CALLBACK_THRESHOLD 12
#define FID_SET_DEBOUNCE_PERIOD 13
#define FID_GET_DEBOUNCE_PERIOD 14
#define FID_DISTANCE 15
#define FID_ANALOG_VALUE 16
#define FID_DISTANCE_REACHED 17
#define FID_ANALOG_VALUE_REACHED 18

#define FID_LAST 18

typedef struct {
	MessageHeader header;
	uint8_t position;
} __attribute__((__packed__)) GetSamplingPoint;

typedef struct {
	MessageHeader header;
	uint16_t distance;
} __attribute__((__packed__)) GetSamplingPointReturn;

typedef struct {
	MessageHeader header;
	uint8_t position;
	uint16_t distance;
} __attribute__((__packed__)) SetSamplingPoint;

void get_sampling_point(const ComType com, const GetSamplingPoint *sm);
void set_sampling_point(const ComType com, const SetSamplingPoint *sm);
int32_t analog_value_from_mc(const int32_t value);
int32_t distance_from_analog_value(const int32_t value);

void invocation(const ComType com, const uint8_t *data);
void constructor(void);
void destructor(void);
void tick(const uint8_t tick_type);

#endif
