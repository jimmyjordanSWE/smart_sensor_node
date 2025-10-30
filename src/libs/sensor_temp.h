/*
    Temperature sensor
*/
#ifndef SENSOR_TEMP_H
#define SENSOR_TEMP_H

#include <stddef.h>
#include <stdio.h>

typedef struct temperature_sensor temperature_sensor;

int sensor_temp_init(temperature_sensor** self, size_t cadence_ms, float max_c, float min_c);
void sensor_temp_destroy(temperature_sensor* self);
int sensor_temp_save_to_disk(temperature_sensor* self, FILE* stream);

// TODO make getters and setters
// int sensor_temp_get_temp ...

#endif // SENSOR_TEMP_H