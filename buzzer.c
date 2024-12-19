#include "buzzer.h"




void setup_buzzer()
{
    gpio_init(BUZZER_PIN);
    gpio_set_dir(BUZZER_PIN, GPIO_OUT);
}


void buzz()
{
    gpio_put(BUZZER_PIN, 1);
    sleep_ms(2000);
    gpio_put(BUZZER_PIN, 0);

}