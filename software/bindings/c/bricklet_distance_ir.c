/*************************************************************
 * This file was automatically generated on 2011-08-23.      *
 *                                                           *
 * If you have a bugfix for this file and want to commit it, *
 * please fix the bug in the generator. You can find a link  *
 * to the generator git on tinkerforge.com                   *
 *************************************************************/

#include "bricklet_distance_ir.h"

#include <string.h>

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

typedef void (*distance_func_t)(uint16_t);
typedef void (*analog_value_func_t)(uint16_t);
typedef void (*distance_reached_func_t)(uint16_t);
typedef void (*analog_value_reached_func_t)(uint16_t);

#ifdef _MSC_VER
	#pragma pack(push)
	#pragma pack(1)

	#define PACKED
#else
	#define PACKED __attribute__((packed))
#endif

typedef struct {
	uint8_t stack_id;
	uint8_t type;
	uint16_t length;
} PACKED GetDistance;

typedef struct {
	uint8_t stack_id;
	uint8_t type;
	uint16_t length;
	uint16_t distance;
} PACKED GetDistanceReturn;

typedef struct {
	uint8_t stack_id;
	uint8_t type;
	uint16_t length;
} PACKED GetAnalogValue;

typedef struct {
	uint8_t stack_id;
	uint8_t type;
	uint16_t length;
	uint16_t value;
} PACKED GetAnalogValueReturn;

typedef struct {
	uint8_t stack_id;
	uint8_t type;
	uint16_t length;
	uint8_t position;
	uint16_t distance;
} PACKED SetSamplingPoint;

typedef struct {
	uint8_t stack_id;
	uint8_t type;
	uint16_t length;
	uint8_t position;
} PACKED GetSamplingPoint;

typedef struct {
	uint8_t stack_id;
	uint8_t type;
	uint16_t length;
	uint16_t distance;
} PACKED GetSamplingPointReturn;

typedef struct {
	uint8_t stack_id;
	uint8_t type;
	uint16_t length;
	uint32_t period;
} PACKED SetDistanceCallbackPeriod;

typedef struct {
	uint8_t stack_id;
	uint8_t type;
	uint16_t length;
} PACKED GetDistanceCallbackPeriod;

typedef struct {
	uint8_t stack_id;
	uint8_t type;
	uint16_t length;
	uint32_t period;
} PACKED GetDistanceCallbackPeriodReturn;

typedef struct {
	uint8_t stack_id;
	uint8_t type;
	uint16_t length;
	uint32_t period;
} PACKED SetAnalogValueCallbackPeriod;

typedef struct {
	uint8_t stack_id;
	uint8_t type;
	uint16_t length;
} PACKED GetAnalogValueCallbackPeriod;

typedef struct {
	uint8_t stack_id;
	uint8_t type;
	uint16_t length;
	uint32_t period;
} PACKED GetAnalogValueCallbackPeriodReturn;

typedef struct {
	uint8_t stack_id;
	uint8_t type;
	uint16_t length;
	char option;
	int16_t min;
	int16_t max;
} PACKED SetDistanceCallbackThreshold;

typedef struct {
	uint8_t stack_id;
	uint8_t type;
	uint16_t length;
} PACKED GetDistanceCallbackThreshold;

typedef struct {
	uint8_t stack_id;
	uint8_t type;
	uint16_t length;
	char option;
	int16_t min;
	int16_t max;
} PACKED GetDistanceCallbackThresholdReturn;

typedef struct {
	uint8_t stack_id;
	uint8_t type;
	uint16_t length;
	char option;
	uint16_t min;
	uint16_t max;
} PACKED SetAnalogValueCallbackThreshold;

typedef struct {
	uint8_t stack_id;
	uint8_t type;
	uint16_t length;
} PACKED GetAnalogValueCallbackThreshold;

typedef struct {
	uint8_t stack_id;
	uint8_t type;
	uint16_t length;
	char option;
	uint16_t min;
	uint16_t max;
} PACKED GetAnalogValueCallbackThresholdReturn;

typedef struct {
	uint8_t stack_id;
	uint8_t type;
	uint16_t length;
	uint32_t debounce;
} PACKED SetDebouncePeriod;

typedef struct {
	uint8_t stack_id;
	uint8_t type;
	uint16_t length;
} PACKED GetDebouncePeriod;

typedef struct {
	uint8_t stack_id;
	uint8_t type;
	uint16_t length;
	uint32_t debounce;
} PACKED GetDebouncePeriodReturn;

typedef struct {
	uint8_t stack_id;
	uint8_t type;
	uint16_t length;
	uint16_t distance;
} PACKED DistanceCallback;

typedef struct {
	uint8_t stack_id;
	uint8_t type;
	uint16_t length;
	uint16_t value;
} PACKED AnalogValueCallback;

typedef struct {
	uint8_t stack_id;
	uint8_t type;
	uint16_t length;
	uint16_t distance;
} PACKED DistanceReachedCallback;

typedef struct {
	uint8_t stack_id;
	uint8_t type;
	uint16_t length;
	uint16_t value;
} PACKED AnalogValueReachedCallback;

#ifdef _MSC_VER
	#pragma pack(pop)
#endif

int distance_ir_get_distance(DistanceIR *distance_ir, uint16_t *ret_distance) {
	if(distance_ir->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(distance_ir);

	distance_ir->answer.type = TYPE_GET_DISTANCE;
	distance_ir->answer.length = sizeof(GetDistanceReturn);
	GetDistance gd;
	gd.stack_id = distance_ir->stack_id;
	gd.type = TYPE_GET_DISTANCE;
	gd.length = sizeof(GetDistance);

	ipcon_device_write(distance_ir, (char *)&gd, sizeof(GetDistance));

	if(ipcon_answer_sem_wait_timeout(distance_ir) != 0) {
		ipcon_sem_post_write(distance_ir);
		return E_TIMEOUT;
	}

	GetDistanceReturn *gdr = (GetDistanceReturn *)distance_ir->answer.buffer;
	*ret_distance = gdr->distance;

	ipcon_sem_post_write(distance_ir);

	return E_OK;
}

int distance_ir_get_analog_value(DistanceIR *distance_ir, uint16_t *ret_value) {
	if(distance_ir->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(distance_ir);

	distance_ir->answer.type = TYPE_GET_ANALOG_VALUE;
	distance_ir->answer.length = sizeof(GetAnalogValueReturn);
	GetAnalogValue gav;
	gav.stack_id = distance_ir->stack_id;
	gav.type = TYPE_GET_ANALOG_VALUE;
	gav.length = sizeof(GetAnalogValue);

	ipcon_device_write(distance_ir, (char *)&gav, sizeof(GetAnalogValue));

	if(ipcon_answer_sem_wait_timeout(distance_ir) != 0) {
		ipcon_sem_post_write(distance_ir);
		return E_TIMEOUT;
	}

	GetAnalogValueReturn *gavr = (GetAnalogValueReturn *)distance_ir->answer.buffer;
	*ret_value = gavr->value;

	ipcon_sem_post_write(distance_ir);

	return E_OK;
}

int distance_ir_set_sampling_point(DistanceIR *distance_ir, uint8_t position, uint16_t distance) {
	if(distance_ir->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(distance_ir);

	SetSamplingPoint ssp;
	ssp.stack_id = distance_ir->stack_id;
	ssp.type = TYPE_SET_SAMPLING_POINT;
	ssp.length = sizeof(SetSamplingPoint);
	ssp.position = position;
	ssp.distance = distance;

	ipcon_device_write(distance_ir, (char *)&ssp, sizeof(SetSamplingPoint));

	ipcon_sem_post_write(distance_ir);

	return E_OK;
}

int distance_ir_get_sampling_point(DistanceIR *distance_ir, uint8_t position, uint16_t *ret_distance) {
	if(distance_ir->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(distance_ir);

	distance_ir->answer.type = TYPE_GET_SAMPLING_POINT;
	distance_ir->answer.length = sizeof(GetSamplingPointReturn);
	GetSamplingPoint gsp;
	gsp.stack_id = distance_ir->stack_id;
	gsp.type = TYPE_GET_SAMPLING_POINT;
	gsp.length = sizeof(GetSamplingPoint);
	gsp.position = position;

	ipcon_device_write(distance_ir, (char *)&gsp, sizeof(GetSamplingPoint));

	if(ipcon_answer_sem_wait_timeout(distance_ir) != 0) {
		ipcon_sem_post_write(distance_ir);
		return E_TIMEOUT;
	}

	GetSamplingPointReturn *gspr = (GetSamplingPointReturn *)distance_ir->answer.buffer;
	*ret_distance = gspr->distance;

	ipcon_sem_post_write(distance_ir);

	return E_OK;
}

int distance_ir_set_distance_callback_period(DistanceIR *distance_ir, uint32_t period) {
	if(distance_ir->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(distance_ir);

	SetDistanceCallbackPeriod sdcp;
	sdcp.stack_id = distance_ir->stack_id;
	sdcp.type = TYPE_SET_DISTANCE_CALLBACK_PERIOD;
	sdcp.length = sizeof(SetDistanceCallbackPeriod);
	sdcp.period = period;

	ipcon_device_write(distance_ir, (char *)&sdcp, sizeof(SetDistanceCallbackPeriod));

	ipcon_sem_post_write(distance_ir);

	return E_OK;
}

int distance_ir_get_distance_callback_period(DistanceIR *distance_ir, uint32_t *ret_period) {
	if(distance_ir->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(distance_ir);

	distance_ir->answer.type = TYPE_GET_DISTANCE_CALLBACK_PERIOD;
	distance_ir->answer.length = sizeof(GetDistanceCallbackPeriodReturn);
	GetDistanceCallbackPeriod gdcp;
	gdcp.stack_id = distance_ir->stack_id;
	gdcp.type = TYPE_GET_DISTANCE_CALLBACK_PERIOD;
	gdcp.length = sizeof(GetDistanceCallbackPeriod);

	ipcon_device_write(distance_ir, (char *)&gdcp, sizeof(GetDistanceCallbackPeriod));

	if(ipcon_answer_sem_wait_timeout(distance_ir) != 0) {
		ipcon_sem_post_write(distance_ir);
		return E_TIMEOUT;
	}

	GetDistanceCallbackPeriodReturn *gdcpr = (GetDistanceCallbackPeriodReturn *)distance_ir->answer.buffer;
	*ret_period = gdcpr->period;

	ipcon_sem_post_write(distance_ir);

	return E_OK;
}

int distance_ir_set_analog_value_callback_period(DistanceIR *distance_ir, uint32_t period) {
	if(distance_ir->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(distance_ir);

	SetAnalogValueCallbackPeriod savcp;
	savcp.stack_id = distance_ir->stack_id;
	savcp.type = TYPE_SET_ANALOG_VALUE_CALLBACK_PERIOD;
	savcp.length = sizeof(SetAnalogValueCallbackPeriod);
	savcp.period = period;

	ipcon_device_write(distance_ir, (char *)&savcp, sizeof(SetAnalogValueCallbackPeriod));

	ipcon_sem_post_write(distance_ir);

	return E_OK;
}

int distance_ir_get_analog_value_callback_period(DistanceIR *distance_ir, uint32_t *ret_period) {
	if(distance_ir->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(distance_ir);

	distance_ir->answer.type = TYPE_GET_ANALOG_VALUE_CALLBACK_PERIOD;
	distance_ir->answer.length = sizeof(GetAnalogValueCallbackPeriodReturn);
	GetAnalogValueCallbackPeriod gavcp;
	gavcp.stack_id = distance_ir->stack_id;
	gavcp.type = TYPE_GET_ANALOG_VALUE_CALLBACK_PERIOD;
	gavcp.length = sizeof(GetAnalogValueCallbackPeriod);

	ipcon_device_write(distance_ir, (char *)&gavcp, sizeof(GetAnalogValueCallbackPeriod));

	if(ipcon_answer_sem_wait_timeout(distance_ir) != 0) {
		ipcon_sem_post_write(distance_ir);
		return E_TIMEOUT;
	}

	GetAnalogValueCallbackPeriodReturn *gavcpr = (GetAnalogValueCallbackPeriodReturn *)distance_ir->answer.buffer;
	*ret_period = gavcpr->period;

	ipcon_sem_post_write(distance_ir);

	return E_OK;
}

int distance_ir_set_distance_callback_threshold(DistanceIR *distance_ir, char option, int16_t min, int16_t max) {
	if(distance_ir->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(distance_ir);

	SetDistanceCallbackThreshold sdct;
	sdct.stack_id = distance_ir->stack_id;
	sdct.type = TYPE_SET_DISTANCE_CALLBACK_THRESHOLD;
	sdct.length = sizeof(SetDistanceCallbackThreshold);
	sdct.option = option;
	sdct.min = min;
	sdct.max = max;

	ipcon_device_write(distance_ir, (char *)&sdct, sizeof(SetDistanceCallbackThreshold));

	ipcon_sem_post_write(distance_ir);

	return E_OK;
}

int distance_ir_get_distance_callback_threshold(DistanceIR *distance_ir, char *ret_option, int16_t *ret_min, int16_t *ret_max) {
	if(distance_ir->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(distance_ir);

	distance_ir->answer.type = TYPE_GET_DISTANCE_CALLBACK_THRESHOLD;
	distance_ir->answer.length = sizeof(GetDistanceCallbackThresholdReturn);
	GetDistanceCallbackThreshold gdct;
	gdct.stack_id = distance_ir->stack_id;
	gdct.type = TYPE_GET_DISTANCE_CALLBACK_THRESHOLD;
	gdct.length = sizeof(GetDistanceCallbackThreshold);

	ipcon_device_write(distance_ir, (char *)&gdct, sizeof(GetDistanceCallbackThreshold));

	if(ipcon_answer_sem_wait_timeout(distance_ir) != 0) {
		ipcon_sem_post_write(distance_ir);
		return E_TIMEOUT;
	}

	GetDistanceCallbackThresholdReturn *gdctr = (GetDistanceCallbackThresholdReturn *)distance_ir->answer.buffer;
	*ret_option = gdctr->option;
	*ret_min = gdctr->min;
	*ret_max = gdctr->max;

	ipcon_sem_post_write(distance_ir);

	return E_OK;
}

int distance_ir_set_analog_value_callback_threshold(DistanceIR *distance_ir, char option, uint16_t min, uint16_t max) {
	if(distance_ir->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(distance_ir);

	SetAnalogValueCallbackThreshold savct;
	savct.stack_id = distance_ir->stack_id;
	savct.type = TYPE_SET_ANALOG_VALUE_CALLBACK_THRESHOLD;
	savct.length = sizeof(SetAnalogValueCallbackThreshold);
	savct.option = option;
	savct.min = min;
	savct.max = max;

	ipcon_device_write(distance_ir, (char *)&savct, sizeof(SetAnalogValueCallbackThreshold));

	ipcon_sem_post_write(distance_ir);

	return E_OK;
}

int distance_ir_get_analog_value_callback_threshold(DistanceIR *distance_ir, char *ret_option, uint16_t *ret_min, uint16_t *ret_max) {
	if(distance_ir->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(distance_ir);

	distance_ir->answer.type = TYPE_GET_ANALOG_VALUE_CALLBACK_THRESHOLD;
	distance_ir->answer.length = sizeof(GetAnalogValueCallbackThresholdReturn);
	GetAnalogValueCallbackThreshold gavct;
	gavct.stack_id = distance_ir->stack_id;
	gavct.type = TYPE_GET_ANALOG_VALUE_CALLBACK_THRESHOLD;
	gavct.length = sizeof(GetAnalogValueCallbackThreshold);

	ipcon_device_write(distance_ir, (char *)&gavct, sizeof(GetAnalogValueCallbackThreshold));

	if(ipcon_answer_sem_wait_timeout(distance_ir) != 0) {
		ipcon_sem_post_write(distance_ir);
		return E_TIMEOUT;
	}

	GetAnalogValueCallbackThresholdReturn *gavctr = (GetAnalogValueCallbackThresholdReturn *)distance_ir->answer.buffer;
	*ret_option = gavctr->option;
	*ret_min = gavctr->min;
	*ret_max = gavctr->max;

	ipcon_sem_post_write(distance_ir);

	return E_OK;
}

int distance_ir_set_debounce_period(DistanceIR *distance_ir, uint32_t debounce) {
	if(distance_ir->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(distance_ir);

	SetDebouncePeriod sdp;
	sdp.stack_id = distance_ir->stack_id;
	sdp.type = TYPE_SET_DEBOUNCE_PERIOD;
	sdp.length = sizeof(SetDebouncePeriod);
	sdp.debounce = debounce;

	ipcon_device_write(distance_ir, (char *)&sdp, sizeof(SetDebouncePeriod));

	ipcon_sem_post_write(distance_ir);

	return E_OK;
}

int distance_ir_get_debounce_period(DistanceIR *distance_ir, uint32_t *ret_debounce) {
	if(distance_ir->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(distance_ir);

	distance_ir->answer.type = TYPE_GET_DEBOUNCE_PERIOD;
	distance_ir->answer.length = sizeof(GetDebouncePeriodReturn);
	GetDebouncePeriod gdp;
	gdp.stack_id = distance_ir->stack_id;
	gdp.type = TYPE_GET_DEBOUNCE_PERIOD;
	gdp.length = sizeof(GetDebouncePeriod);

	ipcon_device_write(distance_ir, (char *)&gdp, sizeof(GetDebouncePeriod));

	if(ipcon_answer_sem_wait_timeout(distance_ir) != 0) {
		ipcon_sem_post_write(distance_ir);
		return E_TIMEOUT;
	}

	GetDebouncePeriodReturn *gdpr = (GetDebouncePeriodReturn *)distance_ir->answer.buffer;
	*ret_debounce = gdpr->debounce;

	ipcon_sem_post_write(distance_ir);

	return E_OK;
}

int distance_ir_callback_distance(DistanceIR *distance_ir, const unsigned char *buffer) {
	DistanceCallback *dc = (DistanceCallback *)buffer;
	((distance_func_t)distance_ir->callbacks[dc->type])(dc->distance);
	return sizeof(DistanceCallback);
}

int distance_ir_callback_analog_value(DistanceIR *distance_ir, const unsigned char *buffer) {
	AnalogValueCallback *avc = (AnalogValueCallback *)buffer;
	((analog_value_func_t)distance_ir->callbacks[avc->type])(avc->value);
	return sizeof(AnalogValueCallback);
}

int distance_ir_callback_distance_reached(DistanceIR *distance_ir, const unsigned char *buffer) {
	DistanceReachedCallback *drc = (DistanceReachedCallback *)buffer;
	((distance_reached_func_t)distance_ir->callbacks[drc->type])(drc->distance);
	return sizeof(DistanceReachedCallback);
}

int distance_ir_callback_analog_value_reached(DistanceIR *distance_ir, const unsigned char *buffer) {
	AnalogValueReachedCallback *avrc = (AnalogValueReachedCallback *)buffer;
	((analog_value_reached_func_t)distance_ir->callbacks[avrc->type])(avrc->value);
	return sizeof(AnalogValueReachedCallback);
}

void distance_ir_register_callback(DistanceIR *distance_ir, uint8_t cb, void *func) {
    distance_ir->callbacks[cb] = func;
}

void distance_ir_create(DistanceIR *distance_ir, const char *uid) {
	ipcon_device_create(distance_ir, uid);

	distance_ir->device_callbacks[TYPE_DISTANCE] = distance_ir_callback_distance;
	distance_ir->device_callbacks[TYPE_ANALOG_VALUE] = distance_ir_callback_analog_value;
	distance_ir->device_callbacks[TYPE_DISTANCE_REACHED] = distance_ir_callback_distance_reached;
	distance_ir->device_callbacks[TYPE_ANALOG_VALUE_REACHED] = distance_ir_callback_analog_value_reached;
}
