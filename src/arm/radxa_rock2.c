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
#include "arm/radxa_rock2.h"
#include "common.h"

const char* radxa_rock2_serialdev[MRAA_RADXA_ROCK2_UART_COUNT] = { "/dev/ttyS0", "/dev/ttyS2", "/dev/ttyS3" };

void
mraa_radxa_rock2_pininfo(mraa_board_t* board, int index, int gpio_chip, int gpio_line, mraa_pincapabilities_t pincapabilities_t, char* pin_name)
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
mraa_radxa_rock2()
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

    if (mraa_file_contains("/proc/device-tree/model", PLATFORM_NAME_RADXA_ROCK_2A)) {
        b->platform_name = PLATFORM_NAME_RADXA_ROCK_2A;
    } else if (mraa_file_contains("/proc/device-tree/model", PLATFORM_NAME_RADXA_ROCK_2F)) {
        b->platform_name = PLATFORM_NAME_RADXA_ROCK_2F;
    } else {
        syslog(LOG_ERR, "An unknown product detected. Fail early...");
        free(b);
        return NULL;
    }

    // pin mux for buses are setup by default by kernel so tell mraa to ignore them
    b->no_bus_mux = 1;
    b->phy_pin_count = MRAA_RADXA_ROCK2_PIN_COUNT + 1;

    b->chardev_capable = 1;

    // UART
    b->uart_dev_count = MRAA_RADXA_ROCK2_UART_COUNT;
    b->def_uart_dev = 0;
    b->uart_dev[0].index = 0;
    b->uart_dev[1].index = 2;
    b->uart_dev[2].index = 3;
    b->uart_dev[0].device_path = (char*) radxa_rock2_serialdev[0];
    b->uart_dev[1].device_path = (char*) radxa_rock2_serialdev[1];
    b->uart_dev[2].device_path = (char*) radxa_rock2_serialdev[2];

    // I2C
    b->i2c_bus_count = MRAA_RADXA_ROCK2_I2C_COUNT;
    b->def_i2c_bus = 0;
    b->i2c_bus[0].bus_id = 0;
    b->i2c_bus[1].bus_id = 1;

    // SPI
    b->spi_bus_count = MRAA_RADXA_ROCK2_SPI_COUNT;
    b->def_spi_bus = 0;
    b->spi_bus[0].bus_id = 0;

    // PWM
    b->pwm_dev_count = MRAA_RADXA_ROCK2_PWM_COUNT;
    b->pwm_default_period = 500;
    b->pwm_max_period = 2147483;
    b->pwm_min_period = 1;

    b->pins = (mraa_pininfo_t*) malloc(sizeof(mraa_pininfo_t) * b->phy_pin_count);
    if (b->pins == NULL) {
        free(b->adv_func);
        free(b);
        return NULL;
    }

    b->pins[11].pwm.parent_id = 4; // PWM4_M0
    b->pins[11].pwm.mux_total = 0;
    b->pins[11].pwm.pinmap = 0;
    b->pins[13].pwm.parent_id = 5; // PWM5_M0
    b->pins[13].pwm.mux_total = 0;
    b->pins[13].pwm.pinmap = 0;
    b->pins[15].pwm.parent_id = 3; // PWM3_M0
    b->pins[15].pwm.mux_total = 0;
    b->pins[15].pwm.pinmap = 0;
    b->pins[26].pwm.parent_id = 6; // PWM6_M0
    b->pins[26].pwm.mux_total = 0;
    b->pins[26].pwm.pinmap = 0;
    b->pins[32].pwm.parent_id = 0; // PWM0_M0
    b->pins[32].pwm.mux_total = 0;
    b->pins[32].pwm.pinmap = 0;

    mraa_radxa_rock2_pininfo(b, 0, -1, -1, (mraa_pincapabilities_t){0,0,0,0,0,0,0,0}, "INVALID");
    mraa_radxa_rock2_pininfo(b, 1, -1, -1, (mraa_pincapabilities_t){1,0,0,0,0,0,0,0}, "3V3");
    mraa_radxa_rock2_pininfo(b, 2, -1, -1, (mraa_pincapabilities_t){1,0,0,0,0,0,0,0}, "5V");
    mraa_radxa_rock2_pininfo(b, 3, 4, 0, (mraa_pincapabilities_t){1,1,0,0,0,1,0,0}, "GPIO4_A0");
    mraa_radxa_rock2_pininfo(b, 4, -1, -1, (mraa_pincapabilities_t){1,0,0,0,0,0,0,0}, "5V");
    mraa_radxa_rock2_pininfo(b, 5, 4, 1, (mraa_pincapabilities_t){1,1,0,0,0,1,0,0}, "GPIO4_A1");
    mraa_radxa_rock2_pininfo(b, 6, -1, -1, (mraa_pincapabilities_t){1,0,0,0,0,0,0,0}, "GND");
    mraa_radxa_rock2_pininfo(b, 7, 4, 6, (mraa_pincapabilities_t){1,1,0,0,0,0,0,1}, "GPIO4_A6");
    mraa_radxa_rock2_pininfo(b, 8, 4, 24, (mraa_pincapabilities_t){1,1,0,0,0,0,0,1}, "GPIO4_D0");
    mraa_radxa_rock2_pininfo(b, 9, -1, -1, (mraa_pincapabilities_t){1,0,0,0,0,0,0,0}, "GND");
    mraa_radxa_rock2_pininfo(b, 10, 4, 23, (mraa_pincapabilities_t){1,1,0,0,0,0,0,1}, "GPIO4_C7");
    mraa_radxa_rock2_pininfo(b, 11, 4, 15, (mraa_pincapabilities_t){1,1,1,0,0,0,0,1}, "GPIO4_B7");
    mraa_radxa_rock2_pininfo(b, 12, 1, 13, (mraa_pincapabilities_t){1,1,0,0,0,0,0,0}, "GPIO1_B5");
    mraa_radxa_rock2_pininfo(b, 13, 4, 16, (mraa_pincapabilities_t){1,1,1,0,0,0,0,1}, "GPIO4_C0");
    mraa_radxa_rock2_pininfo(b, 14, -1, -1, (mraa_pincapabilities_t){1,0,0,0,0,0,0,0}, "GND");
    mraa_radxa_rock2_pininfo(b, 15, 4, 22, (mraa_pincapabilities_t){1,1,1,0,0,1,0,1}, "GPIO4_C6");
    mraa_radxa_rock2_pininfo(b, 16, 4, 8, (mraa_pincapabilities_t){1,1,0,0,0,0,0,1}, "GPIO4_B0");
    mraa_radxa_rock2_pininfo(b, 17, -1, -1, (mraa_pincapabilities_t){1,0,0,0,0,0,0,0}, "3V3");
    mraa_radxa_rock2_pininfo(b, 18, 4, 9, (mraa_pincapabilities_t){1,1,0,0,0,0,0,1}, "GPIO4_B1");
    mraa_radxa_rock2_pininfo(b, 19, 4, 10, (mraa_pincapabilities_t){1,1,0,0,1,0,0,0}, "GPIO4_B2");
    mraa_radxa_rock2_pininfo(b, 20, -1, -1, (mraa_pincapabilities_t){1,0,0,0,0,0,0,0}, "GND");
    mraa_radxa_rock2_pininfo(b, 21, 4, 11, (mraa_pincapabilities_t){1,1,0,0,1,0,0,0}, "GPIO4_B3");
    mraa_radxa_rock2_pininfo(b, 22, 1, 10, (mraa_pincapabilities_t){1,1,0,0,0,1,0,1}, "GPIO1_B2");
    mraa_radxa_rock2_pininfo(b, 23, 4, 12, (mraa_pincapabilities_t){1,1,0,0,1,0,0,0}, "GPIO4_B4");
    mraa_radxa_rock2_pininfo(b, 24, 4, 14, (mraa_pincapabilities_t){1,1,0,0,1,0,0,0}, "GPIO4_B6");
    mraa_radxa_rock2_pininfo(b, 25, -1, -1, (mraa_pincapabilities_t){1,0,0,0,0,0,0,0}, "GND");
    mraa_radxa_rock2_pininfo(b, 26, 4, 17, (mraa_pincapabilities_t){1,1,1,0,1,0,0,0}, "GPIO4_C1");
    mraa_radxa_rock2_pininfo(b, 27, 4, 2, (mraa_pincapabilities_t){1,1,0,0,0,1,0,1}, "GPIO4_A2");
    mraa_radxa_rock2_pininfo(b, 28, 4, 3, (mraa_pincapabilities_t){1,1,0,0,0,1,0,1}, "GPIO4_A3");
    mraa_radxa_rock2_pininfo(b, 29, 4, 13, (mraa_pincapabilities_t){1,1,0,0,0,0,0,0}, "GPIO4_B5");
    mraa_radxa_rock2_pininfo(b, 30, -1, -1, (mraa_pincapabilities_t){1,0,0,0,0,0,0,0}, "GND");
    mraa_radxa_rock2_pininfo(b, 31, 1, 8, (mraa_pincapabilities_t){1,1,0,0,0,0,0,1}, "GPIO1_B0");
    mraa_radxa_rock2_pininfo(b, 32, 4, 19, (mraa_pincapabilities_t){1,1,1,0,0,1,0,0}, "GPIO4_C3");
    mraa_radxa_rock2_pininfo(b, 33, 1, 9, (mraa_pincapabilities_t){1,1,0,0,0,0,0,1}, "GPIO1_B1");
    mraa_radxa_rock2_pininfo(b, 34,-1, -1, (mraa_pincapabilities_t){1,0,0,0,0,0,0,0}, "GND");
    mraa_radxa_rock2_pininfo(b, 35, 1, 14, (mraa_pincapabilities_t){1,1,0,0,1,0,0,0}, "GPIO1_B6");
    mraa_radxa_rock2_pininfo(b, 36, 1, 12, (mraa_pincapabilities_t){1,1,0,0,0,0,0,0}, "GPIO1_B4");
    mraa_radxa_rock2_pininfo(b, 37, -1, -1, (mraa_pincapabilities_t){1,0,0,0,0,0,1,0}, "SARADC_IN3");
    mraa_radxa_rock2_pininfo(b, 38, 1, 15, (mraa_pincapabilities_t){1,1,0,0,1,0,0,0}, "GPIO1_B7");
    mraa_radxa_rock2_pininfo(b, 39, -1, -1, (mraa_pincapabilities_t){1,0,0,0,0,0,0,0}, "GND");
    mraa_radxa_rock2_pininfo(b, 40, 1, 16, (mraa_pincapabilities_t){1,1,0,0,1,0,0,0}, "GPIO1_C0");

    return b;
}
