#include "pico/stdlib.h"
#include "hardware/i2c.h"

#define I2C_PORT I2C0_BASE
#define SDA_PIN 12
#define SCL_PIN 13
#define LSM6DSOX_ADDR 0x28

void setup_i2c();
void write_register(uint8_t reg, uint8_t value);
uint8_t read_register(uint8_t reg);
void configure_accelerometer();
void read_accelerometer(int16_t *x, int16_t *y, int16_t *z);