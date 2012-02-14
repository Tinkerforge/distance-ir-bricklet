#ifndef DISTANCE_IR_H
#define DISTANCE_IR_H

#include <stdint.h>

#define TYPE_GET_DISTANCE 1
#define TYPE_GET_ANALOG_VALUE 2
#define TYPE_SET_SAMPLING_POINT 3
#define TYPE_GET_SAMPLING_POINT 4
#define TYPE_SET_DISTANCE_CALLBACK_PERIOD 5
#define TYPE_GET_DISTANCE_CALLBACK_PERIOD 6
#define TYPE_SET_ANALOG_VALUE_CALLBACK_PERIOD 7
#define TYPE_GET_ANALOG_VALUE_CALLBACK_PERIOD 8
#define TYPE_SET_DISTANCE_CALLBACK_THRESHOLD 9
#define TYPE_GET_DISTANCE_CALLBACK_THRESHOLD 10
#define TYPE_SET_ANALOG_VALUE_CALLBACK_THRESHOLD 11
#define TYPE_GET_ANALOG_VALUE_CALLBACK_THRESHOLD 12
#define TYPE_SET_DEBOUNCE_PERIOD 13
#define TYPE_GET_DEBOUNCE_PERIOD 14
#define TYPE_DISTANCE 15
#define TYPE_ANALOG_VALUE 16
#define TYPE_DISTANCE_REACHED 17
#define TYPE_ANALOG_VALUE_REACHED 18

typedef struct {
	uint8_t stack_id;
	uint8_t type;
	uint16_t length;
	uint8_t position;
} __attribute__((__packed__)) GetSamplingPoint;

typedef struct {
	uint8_t stack_id;
	uint8_t type;
	uint16_t length;
	uint16_t distance;
} __attribute__((__packed__)) GetSamplingPointReturn;

typedef struct {
	uint8_t stack_id;
	uint8_t type;
	uint16_t length;
	uint8_t position;
	uint16_t distance;
} __attribute__((__packed__)) SetSamplingPoint;

void get_sampling_point(uint8_t com, GetSamplingPoint *sm);
void set_sampling_point(uint8_t com, SetSamplingPoint *sm);
int32_t analog_value_from_mc(int32_t value);
int32_t distance_from_analog_value(int32_t value);

void invocation(uint8_t com, uint8_t *data);
void constructor(void);
void destructor(void);
void tick(uint8_t tick_type);

#endif
