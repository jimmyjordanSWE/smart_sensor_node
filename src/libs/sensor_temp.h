/*
    Temperature sensor
*/
#ifndef SENSOR_TEMP_H
#define SENSOR_TEMP_H

#include <stddef.h>
#include <stdio.h>

typedef struct temperature_sensor temperature_sensor;

// used for custom validation functions. Not yet tested.
typedef int (*temperature_sensor_alarm_fn)(float temperature, float min, float max);

int sensor_temp_init(temperature_sensor** sensor, size_t cadence_ms, float max_c, float min_c);
void sensor_temp_destroy(temperature_sensor** sensor);
int sensor_temp_save_to_disk(temperature_sensor* sensor, FILE* stream);

void sensor_temp_set_alarm(temperature_sensor* sensor, temperature_sensor_alarm_fn validator);

int sensor_temp_check_alarm(temperature_sensor* sensor);

#endif // SENSOR_TEMP_H