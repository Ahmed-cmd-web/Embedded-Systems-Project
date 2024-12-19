#include <stdio.h>
#include <pico/stdlib.h>
#include "hardware/adc.h"

#define SENSOR_PIN 26   // A0,D14
#define SENSOR_ANALOG_PIN 0
#define temp_threshold 15

void setup_temp_sensor();


float read_temp_sensor();
