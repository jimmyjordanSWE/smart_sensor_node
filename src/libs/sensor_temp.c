#include "sensor_temp.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <uuid/uuid.h>

#define BUFFER_SIZE (1024 * 10)

typedef struct temperature_sensor {
    uuid_t id;
    size_t cadence_ms;
    float history[BUFFER_SIZE];
    size_t history_length;
    float max_c;
    float min_c;
    temperature_sensor_alarm_fn alarm;
} temperature_sensor;

int sensor_temp_init(temperature_sensor** sensor, size_t cadence_ms, float max_c, float min_c) {
    if (sensor == NULL || max_c <= min_c) return -1;

    *sensor = (temperature_sensor*)malloc(sizeof(**sensor));
    if (*sensor == NULL) return -2;

    (*sensor)->cadence_ms = cadence_ms;
    (*sensor)->max_c = max_c;
    (*sensor)->min_c = min_c;
    (*sensor)->history_length = 0;
    (*sensor)->alarm = NULL;

    return 0;
}

void sensor_temp_destroy(temperature_sensor** sensor) {
    if (sensor == NULL || *sensor == NULL) return;
    free(*sensor);
    *sensor = NULL;
}

void sensor_temp_set_alarm(temperature_sensor* sensor, temperature_sensor_alarm_fn validator) {
    if (sensor == NULL) return;
    sensor->alarm = validator;
}

int sensor_temp_check_alarm(temperature_sensor* sensor) {
    // TODO better error handling here, we cant let user check alarm without having first set an alarm
    // should set errors on struct not just return an int. Or atleast an enum.
    if (sensor == NULL) return -2;
    if (sensor->alarm == NULL) return -3;

    return sensor->alarm(sensor->history[sensor->history_length - 1], sensor->min_c, sensor->max_c);
}

int sensor_temp_save_to_disk(temperature_sensor* sensor, FILE* stream) {
    if (sensor && stream) {
    }
    return 0;
}