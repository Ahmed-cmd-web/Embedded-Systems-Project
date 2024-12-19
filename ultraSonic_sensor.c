#include "ultraSonic_sensor.h"

void setup_ultraSonic_sensor()
{

    gpio_init(TRIGGER_PIN);
    gpio_init(ECHO_PIN);
    gpio_set_dir(TRIGGER_PIN, GPIO_OUT);
    gpio_set_dir(ECHO_PIN, GPIO_IN);
}


float read_ultraSonic_sensor_cm()
{
    // Send 10us pulse to trigger
    gpio_put(TRIGGER_PIN, 1);
    sleep_us(10);
    gpio_put(TRIGGER_PIN, 0);

    // Wait for echo to start
    while (gpio_get(ECHO_PIN) == 0)
        ;
    uint32_t start = time_us_32();

    // Wait for echo to end
    while (gpio_get(ECHO_PIN) == 1)
        ;
    uint32_t end = time_us_32();

    // Calculate distance
    uint32_t duration = end - start;
    float distance = (duration * 0.0343) / 2;
    return distance;
}