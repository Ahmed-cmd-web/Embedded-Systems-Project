#include <stdio.h>
#include "pico/stdlib.h"
#include "temp_sensor.h"
#include "water_pump.h"
#include "led.h"
#include "ultraSonic_sensor.h"
#include "gas_sensor.h"
#include "buzzer.h"
#include "hardware/adc.h"






int main()
{

    stdio_init_all();
    adc_init();
    setup_temp_sensor();
    setup_water_pump();
    setup_gas_sensor();
    setup_rg_led();
    setup_buzzer();
    setup_ultraSonic_sensor();

    while (true)
    {

        float temp = read_temp_sensor();
        float gas = read_gas_sensor();
        float distance = read_ultraSonic_sensor_cm();



        printf("Distance: %f cm\n", distance);
        printf("Temp: %f\n",temp);
        printf("%d\n", temp > temp_threshold);
        printf("Gas: %f\n",gas);

        if (gas > gas_threshold || distance < ultraSonic_threshold)
        {
            set_rg_led(1, 0);
            buzz();
            run_pump(0);
        }
        if (temp> temp_threshold){
            set_rg_led(1, 0);
            run_pump(1);
        }
        if (!(gas > gas_threshold || distance < ultraSonic_threshold || temp> temp_threshold))

        {
            set_rg_led(0,1);
            run_pump(0);
        }
        // run_pump(1);

        sleep_ms(1000);
    }
}
