#include "pico/stdlib.h"
#include "hardware/adc.h"



#define TRIGGER_PIN 28
#define ECHO_PIN 29
#define ultraSonic_threshold 10



void setup_ultraSonic_sensor();

float read_ultraSonic_sensor_cm();