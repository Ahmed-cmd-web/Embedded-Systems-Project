#include "temp_sensor.h"

void setup_temp_sensor()
{
    
    adc_gpio_init(SENSOR_PIN);
    adc_select_input(SENSOR_ANALOG_PIN);
}



// 280 highest dryness
// 0 highest wetness
float read_temp_sensor()
{
    uint16_t result = adc_read();
    float voltage = (result * 3.3) / 4095;
    float temp = (voltage - 0.5) * 100;
    return temp;
}