#ifndef CONFIG_H
#define CONFIG_H

#include <stdint.h>
#include <stdbool.h>

#include "bricklib/drivers/board/sam3s/SAM3S.h"
#include "distance-ir.h"

#define BRICKLET_HARDWARE_NAME "Distance IR Bricklet 1.0"
#define BRICKLET_FIRMWARE_VERSION_MAJOR 1
#define BRICKLET_FIRMWARE_VERSION_MINOR 1
#define BRICKLET_FIRMWARE_VERSION_REVISION 1

#define LOGGING_LEVEL LOGGING_DEBUG
#define DEBUG_BRICKLET 0

#define BRICKLET_HAS_SIMPLE_SENSOR
#define BRICKLET_NO_OFFSET
#define INVOCATION_IN_BRICKLET_CODE
#define NUM_SIMPLE_VALUES 2
#define NUM_MOVING_AVERAGE 50

typedef struct {
	int32_t value[NUM_SIMPLE_VALUES];
	int32_t last_value[NUM_SIMPLE_VALUES];

	uint32_t signal_period[NUM_SIMPLE_VALUES];
	uint32_t signal_period_counter[NUM_SIMPLE_VALUES];

	uint32_t threshold_debounce;
	uint32_t threshold_period_current[NUM_SIMPLE_VALUES];
	int32_t  threshold_min[NUM_SIMPLE_VALUES];
	int32_t  threshold_max[NUM_SIMPLE_VALUES];
	char     threshold_option[NUM_SIMPLE_VALUES];

	int32_t  threshold_min_save[NUM_SIMPLE_VALUES];
	int32_t  threshold_max_save[NUM_SIMPLE_VALUES];
	char     threshold_option_save[NUM_SIMPLE_VALUES];

	uint32_t tick;

	uint16_t moving_average[NUM_MOVING_AVERAGE];
	uint32_t moving_average_sum;
	uint8_t moving_average_tick;
} BrickContext;

#endif
