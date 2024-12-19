#include <stdio.h>
#include <pico/stdlib.h>
#include "hardware/adc.h"


#define GAS_SENSOR_PIN 27
#define GAS_SENSOR_ANALOG_PIN 1
#define SENSOR_DIGITAL_PIN 1
#define gas_threshold 1000


void setup_gas_sensor();

float read_gas_sensor();