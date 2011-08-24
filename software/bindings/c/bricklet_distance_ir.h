/*************************************************************
 * This file was automatically generated on 23.08.2011.      *
 *                                                           *
 * If you have a bugfix for this file and want to commit it, *
 * please fix the bug in the generator. You can find a link  *
 * to the generator git on tinkerforge.com                   *
 *************************************************************/

#ifndef BRICKLET_DISTANCE_IR_H
#define BRICKLET_DISTANCE_IR_H

#include "ip_connection.h"

typedef Device DistanceIR;

#define DISTANCE_IR_CALLBACK_DISTANCE 15
#define DISTANCE_IR_CALLBACK_ANALOG_VALUE 16
#define DISTANCE_IR_CALLBACK_DISTANCE_REACHED 17
#define DISTANCE_IR_CALLBACK_ANALOG_VALUE_REACHED 18

void distance_ir_create(DistanceIR *distance_ir, const char *uid);

int distance_ir_get_distance(DistanceIR *distance_ir, uint16_t *ret_distance);
int distance_ir_get_analog_value(DistanceIR *distance_ir, uint16_t *ret_value);
int distance_ir_set_sampling_point(DistanceIR *distance_ir, uint8_t position, uint16_t distance);
int distance_ir_get_sampling_point(DistanceIR *distance_ir, uint8_t position, uint16_t *ret_distance);
int distance_ir_set_distance_callback_period(DistanceIR *distance_ir, uint32_t period);
int distance_ir_get_distance_callback_period(DistanceIR *distance_ir, uint32_t *ret_period);
int distance_ir_set_analog_value_callback_period(DistanceIR *distance_ir, uint32_t period);
int distance_ir_get_analog_value_callback_period(DistanceIR *distance_ir, uint32_t *ret_period);
int distance_ir_set_distance_callback_threshold(DistanceIR *distance_ir, char option, int16_t min, int16_t max);
int distance_ir_get_distance_callback_threshold(DistanceIR *distance_ir, char *ret_option, int16_t *ret_min, int16_t *ret_max);
int distance_ir_set_analog_value_callback_threshold(DistanceIR *distance_ir, char option, uint16_t min, uint16_t max);
int distance_ir_get_analog_value_callback_threshold(DistanceIR *distance_ir, char *ret_option, uint16_t *ret_min, uint16_t *ret_max);
int distance_ir_set_debounce_period(DistanceIR *distance_ir, uint32_t debounce);
int distance_ir_get_debounce_period(DistanceIR *distance_ir, uint32_t *ret_debounce);
int distance_ir_distance(DistanceIR *distance_ir, uint16_t *ret_distance);
int distance_ir_analog_value(DistanceIR *distance_ir, uint16_t *ret_value);
int distance_ir_distance_reached(DistanceIR *distance_ir, uint16_t *ret_distance);
int distance_ir_analog_value_reached(DistanceIR *distance_ir, uint16_t *ret_value);

void distance_ir_register_callback(DistanceIR *distance_ir, uint8_t cb, void *func);

#endif