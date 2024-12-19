#include "accelerometer.h"

void setup_i2c()
{
    i2c_init(I2C_PORT, 115200);
    gpio_set_function(SDA_PIN, GPIO_FUNC_I2C);
    gpio_set_function(SCL_PIN, GPIO_FUNC_I2C);
    gpio_pull_up(SDA_PIN);
    gpio_pull_up(SCL_PIN);
}

void write_register(uint8_t reg, uint8_t value)
{
    uint8_t data[2] = {reg, value};
    i2c_write_blocking(I2C_PORT, LSM6DSOX_ADDR, data, 2, false);
}

uint8_t read_register(uint8_t reg)
{
    uint8_t value;
    i2c_write_blocking(I2C_PORT, LSM6DSOX_ADDR, &reg, 1, true);
    i2c_read_blocking(I2C_PORT, LSM6DSOX_ADDR, &value, 1, false);
    return value;
}

void configure_accelerometer()
{
    write_register(0x10, 4); // CTRL1_XL: Set ODR=104Hz, FS=±2g
}

void read_accelerometer(int16_t *x, int16_t *y, int16_t *z)
{
    uint8_t buffer[6];
    uint8_t reg = 0x28 | 0x80;
    i2c_write_blocking(I2C_PORT, LSM6DSOX_ADDR, &reg, 1, true);
    i2c_read_blocking(I2C_PORT, LSM6DSOX_ADDR, buffer, 6, false);

    *x = (int16_t)(buffer[1] << 8 | buffer[0]);
    *y = (int16_t)(buffer[3] << 8 | buffer[2]);
    *z = (int16_t)(buffer[5] << 8 | buffer[4]);
}