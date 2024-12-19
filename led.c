#include "led.h"




void setup_rg_led()
{
    gpio_init(R_PIN);
    gpio_init(G_PIN);
    gpio_set_dir(G_PIN, GPIO_OUT);
    gpio_set_dir(R_PIN, GPIO_OUT);
}


void set_rg_led(uint8_t r, uint8_t g)
{

    gpio_put(R_PIN, r);
    gpio_put(G_PIN, g);
    printf("R: %d\n",gpio_get(R_PIN));
    printf("G: %d\n",gpio_get(G_PIN));

}