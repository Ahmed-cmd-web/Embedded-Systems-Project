#include "gas_sensor.h"

void setup_gas_sensor()
{
    adc_gpio_init(GAS_SENSOR_PIN);
    adc_select_input(GAS_SENSOR_ANALOG_PIN);
}


float read_gas_sensor()
{
    uint16_t result = adc_read();
    float voltage = (result * 3.3) / 4095;
    float gas = (voltage - 0.5) * 100;
    return adc_read();
}