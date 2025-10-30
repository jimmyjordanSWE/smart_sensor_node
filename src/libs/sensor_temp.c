#include "sensor_temp.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <uuid/uuid.h> // sudo apt-get install uuid-dev

#define BUFFER_SIZE (1024 * 10)

typedef struct temperature_sensor {
    uuid_t id; // TODO currently not set
    size_t cadence_ms;
    float history[BUFFER_SIZE];
    size_t history_length;
    float max_c;
    float min_c;
} temperature_sensor;

int sensor_temp_init(temperature_sensor** self, size_t cadence_ms, float max_c, float min_c) {
    if (self == NULL || max_c <= min_c) return -1;

    // get size by dereferensing is safer, dont have to change two things incase of typechange.
    *self = (temperature_sensor*)malloc(sizeof(**self));
    if (*self == NULL) return -2;

    (*self)->cadence_ms = cadence_ms;
    (*self)->max_c = max_c;
    (*self)->min_c = min_c;
    (*self)->history_length = 0;

    return 0;
}

void sensor_temp_destroy(temperature_sensor* self) {
    if (self == NULL) return;

    free(self);
}

int sensor_temp_save_to_disk(temperature_sensor* self, FILE* stream) {
    if (self && stream) {
    }
    /*
    TODO
    - save to disk
    - validate disk data
    - clear history
    */
    return 0;
}