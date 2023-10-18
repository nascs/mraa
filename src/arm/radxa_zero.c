/*
 * Author: Nascs <nascs@radxa.com>
 * Copyright (c) Radxa Limited.
 *
 * SPDX-License-Identifier: MIT
 */

#include <mraa/common.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include "arm/radxa_zero.h"
#include "common.h"

#define DT_BASE "/proc/device-tree"

#define PLATFORM_NAME_RADXA_ZERO "Radxa Zero"

#define MAX_SIZE 64

const char* radxa_zero_serialdev[MRAA_RADXA_ZERO_UART_COUNT] = { "/dev/ttyAML0", "/dev/ttyAML1", "/dev/ttyAML4" };

void
mraa_radxa_zero_pininfo(mraa_board_t* board, int index, int gpio_chip, int gpio_line, mraa_pincapabilities_t pincapabilities_t, char* pin_name)
{

    if (index > board->phy_pin_count)
        return;

    mraa_pininfo_t* pininfo = &board->pins[index];
    strncpy(pininfo->name, pin_name, MRAA_PIN_NAME_SIZE);

    if(pincapabilities_t.gpio == 1) {
        pininfo->gpio.gpio_chip = gpio_chip;
        pininfo->gpio.gpio_line = gpio_line;
    }

    pininfo->capabilities = pincapabilities_t;

    pininfo->gpio.mux_total = 0;
}

mraa_board_t*
mraa_radxa_zero()
{
    mraa_board_t* b = (mraa_board_t*) calloc(1, sizeof(mraa_board_t));
    if (b == NULL) {
        return NULL;
    }

    b->adv_func = (mraa_adv_func_t*) calloc(1, sizeof(mraa_adv_func_t));
    if (b->adv_func == NULL) {
        free(b);
        return NULL;
    }

    // pin mux for buses are setup by default by kernel so tell mraa to ignore them
    b->no_bus_mux = 1;
    b->phy_pin_count = MRAA_RADXA_ZERO_PIN_COUNT + 1;

    b->platform_name = PLATFORM_NAME_RADXA_ZERO;
    b->chardev_capable = 1;

    // UART
    b->uart_dev_count = MRAA_RADXA_ZERO_UART_COUNT;
    b->def_uart_dev = 0;
    b->uart_dev[0].index = 0;
    b->uart_dev[1].index = 1;
    b->uart_dev[2].index = 2;
    b->uart_dev[0].device_path = (char*) radxa_zero_serialdev[0];
    b->uart_dev[1].device_path = (char*) radxa_zero_serialdev[1];
    b->uart_dev[2].device_path = (char*) radxa_zero_serialdev[2];

    // I2C
    b->i2c_bus_count = MRAA_RADXA_ZERO_I2C_COUNT;
    b->def_i2c_bus = 0;
    b->i2c_bus[0].bus_id = 1;
    b->i2c_bus[1].bus_id = 3;
    b->i2c_bus[2].bus_id = 4;

    // SPI
    b->spi_bus_count = MRAA_RADXA_ZERO_SPI_COUNT;
    b->def_spi_bus = 0;
    b->spi_bus[0].bus_id = 0;
    b->spi_bus[1].bus_id = 1;

    // PWM
    b->pwm_dev_count = MRAA_RADXA_ZERO_PWM_COUNT;
    b->pwm_default_period = 500;
    b->pwm_max_period = 2147483;
    b->pwm_min_period = 1;

    b->pins = (mraa_pininfo_t*) malloc(sizeof(mraa_pininfo_t) * b->phy_pin_count);
    if (b->pins == NULL) {
        free(b->adv_func);
        free(b);
        return NULL;
    }

    b->pins[18].pwm.parent_id = 4;
    b->pins[18].pwm.mux_total = 0;
    b->pins[18].pwm.pinmap = 0;
    b->pins[21].pwm.parent_id = 2;
    b->pins[21].pwm.mux_total = 0;
    b->pins[21].pwm.pinmap = 0;
    b->pins[32].pwm.parent_id = 0;
    b->pins[32].pwm.mux_total = 0;
    b->pins[32].pwm.pinmap = 0;
    b->pins[40].pwm.parent_id = 2;
    b->pins[40].pwm.mux_total = 0;
    b->pins[40].pwm.pinmap = 0;

    mraa_radxa_zero_pininfo(b, 0, -1, -1, (mraa_pincapabilities_t){0,0,0,0,0,0,0,0}, "INVALID");
    mraa_radxa_zero_pininfo(b, 1, -1, -1, (mraa_pincapabilities_t){1,0,0,0,0,0,0,0}, "3V3");
    mraa_radxa_zero_pininfo(b, 2, -1, -1, (mraa_pincapabilities_t){1,0,0,0,0,0,0,0}, "5V");
    mraa_radxa_zero_pininfo(b, 3, 0, 63, (mraa_pincapabilities_t){1,1,0,0,0,1,0,0}, "GPIOA_14");
    mraa_radxa_zero_pininfo(b, 4, -1, -1, (mraa_pincapabilities_t){1,0,0,0,0,0,0,0}, "5V");
    mraa_radxa_zero_pininfo(b, 5, 0, 64, (mraa_pincapabilities_t){1,1,0,0,0,1,0,0}, "GPIOA_15");
    mraa_radxa_zero_pininfo(b, 6, -1, -1, (mraa_pincapabilities_t){1,0,0,0,0,0,0,0}, "GND");
    mraa_radxa_zero_pininfo(b, 7, 1, 3, (mraa_pincapabilities_t){1,1,0,0,0,1,0,1}, "GPIOAO_3");
    mraa_radxa_zero_pininfo(b, 8, 1, 0, (mraa_pincapabilities_t){1,1,0,0,0,0,0,1}, "GPIOAO_0");
    mraa_radxa_zero_pininfo(b, 9, -1, -1, (mraa_pincapabilities_t){1,0,0,0,0,0,0,0}, "GND");
    mraa_radxa_zero_pininfo(b, 10, 1, 1, (mraa_pincapabilities_t){1,1,0,0,0,0,0,1}, "GPIOAO_1");
    mraa_radxa_zero_pininfo(b, 11, 1, 2, (mraa_pincapabilities_t){1,1,0,0,0,1,0,1}, "GPIOAO_2");
    mraa_radxa_zero_pininfo(b, 12, 0, 74, (mraa_pincapabilities_t){1,1,0,0,1,0,0,0}, "GPIOX_9");
    mraa_radxa_zero_pininfo(b, 13, 0, 76, (mraa_pincapabilities_t){1,1,0,0,1,1,0,0}, "GPIOX_11");
    mraa_radxa_zero_pininfo(b, 14, -1, -1, (mraa_pincapabilities_t){1,0,0,0,0,0,0,0}, "GND");
    mraa_radxa_zero_pininfo(b, 15, -1, -1, (mraa_pincapabilities_t){1,0,0,0,0,0,0,0}, "SARADC_CH1");
    mraa_radxa_zero_pininfo(b, 16, 0, 75, (mraa_pincapabilities_t){1,1,0,0,1,1,0,0}, "GPIOX_10");
    mraa_radxa_zero_pininfo(b, 17, -1, -1, (mraa_pincapabilities_t){1,0,0,0,0,0,0,0}, "3V3");
    mraa_radxa_zero_pininfo(b, 18, 0, 73, (mraa_pincapabilities_t){1,1,1,0,1,0,0,0}, "GPIOX_8");
    mraa_radxa_zero_pininfo(b, 19, 0, 20, (mraa_pincapabilities_t){1,1,0,0,1,0,0,1}, "GPIOH_4");
    mraa_radxa_zero_pininfo(b, 20, -1, -1, (mraa_pincapabilities_t){1,0,0,0,0,0,0,0}, "GND");
    mraa_radxa_zero_pininfo(b, 21, 0, 21, (mraa_pincapabilities_t){1,1,1,0,1,0,0,1}, "GPIOH_5");
    mraa_radxa_zero_pininfo(b, 22, 0, 48, (mraa_pincapabilities_t){1,0,0,0,0,0,0,0}, "GPIOC_7"); // OD3.3V
    mraa_radxa_zero_pininfo(b, 23, 0, 23, (mraa_pincapabilities_t){1,1,0,0,1,1,0,1}, "GPIOH_7");
    mraa_radxa_zero_pininfo(b, 24, 0, 22, (mraa_pincapabilities_t){1,1,0,0,1,1,0,1}, "GPIOH_6");
    mraa_radxa_zero_pininfo(b, 25, -1, -1, (mraa_pincapabilities_t){1,0,0,0,0,0,0,0}, "GND");
    mraa_radxa_zero_pininfo(b, 26, -1, -1, (mraa_pincapabilities_t){1,0,0,0,0,0,1,0}, "SARADC_CH2");
    mraa_radxa_zero_pininfo(b, 27, 1, 3, (mraa_pincapabilities_t){1,1,0,0,1,1,0,1}, "GPIOAO_3");
    mraa_radxa_zero_pininfo(b, 28, 1, 2, (mraa_pincapabilities_t){1,1,0,0,0,1,0,0}, "GPIOAO_2");
    mraa_radxa_zero_pininfo(b, 29, -1, -1, (mraa_pincapabilities_t){1,0,0,0,0,0,0,0}, "NC");
    mraa_radxa_zero_pininfo(b, 30, -1, -1, (mraa_pincapabilities_t){1,0,0,0,0,0,0,0}, "GND");
    mraa_radxa_zero_pininfo(b, 31, -1, -1, (mraa_pincapabilities_t){1,0,0,0,0,0,0,0}, "NC");
    mraa_radxa_zero_pininfo(b, 32, 1, 4, (mraa_pincapabilities_t){1,1,1,0,0,0,0,0}, "GPIOAO_4");
    mraa_radxa_zero_pininfo(b, 33, -1, -1, (mraa_pincapabilities_t){1,0,0,0,0,0,0,0}, "NC");
    mraa_radxa_zero_pininfo(b, 34, -1, -1, (mraa_pincapabilities_t){1,0,0,0,0,0,0,0}, "GND");
    mraa_radxa_zero_pininfo(b, 35, 1, 8, (mraa_pincapabilities_t){1,1,0,0,0,0,0,1}, "GPIOAO_8");  // available in v1.51 and later
    mraa_radxa_zero_pininfo(b, 36, 0, 24, (mraa_pincapabilities_t){1,1,0,0,0,0,0,0}, "GPIOH_8");  // available in v1.51 and later
    mraa_radxa_zero_pininfo(b, 37, 1, 9, (mraa_pincapabilities_t){1,1,0,0,0,0,0,1}, "GPIOAO_9");
    mraa_radxa_zero_pininfo(b, 38, 1, 10, (mraa_pincapabilities_t){1,1,1,0,0,0,0,0}, "GPIOAO_10");  // available in v1.51 and later
    mraa_radxa_zero_pininfo(b, 39, -1, -1, (mraa_pincapabilities_t){1,0,0,0,0,0,0,0}, "GND");
    mraa_radxa_zero_pininfo(b, 40, 1, 11, (mraa_pincapabilities_t){1,1,1,0,0,0,0,0}, "GPIOAO_11");

    return b;
}
