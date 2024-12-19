#include <stdio.h>
#include <pico/stdlib.h>
#include "hardware/pwm.h"

#define PUMP_PIN 19
#define PUMP_PIN2 18
#define PUMP_PWM 17


void setup_water_pump();


void run_pump(bool isRunning);
