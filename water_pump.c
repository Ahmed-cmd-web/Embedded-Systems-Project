#include "water_pump.h"

void setup_water_pump()
{
    gpio_init(PUMP_PIN);
    gpio_init(PUMP_PIN2);
    gpio_set_dir(PUMP_PIN, GPIO_OUT);
    gpio_set_dir(PUMP_PIN2, GPIO_OUT);
    gpio_set_function(PUMP_PWM, GPIO_FUNC_PWM);

    uint slice_num = pwm_gpio_to_slice_num(PUMP_PWM);


    pwm_set_wrap(slice_num, 255);
    pwm_set_clkdiv(slice_num, 1);


    pwm_set_enabled(slice_num, true);
}



void run_pump(bool isRunning)
{
    printf("Pump is running: %d\n", isRunning);
    gpio_put(PUMP_PIN, isRunning);
    gpio_put(PUMP_PIN2, false);


    pwm_set_gpio_level(PUMP_PWM, 255);
    printf("Pump is running: %d\n", gpio_get(PUMP_PIN));
    printf("Pump is running2: %d\n", gpio_get(PUMP_PIN2));
}