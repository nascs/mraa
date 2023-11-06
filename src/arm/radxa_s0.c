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
#include "arm/radxa_s0.h"
#include "common.h"

const char* radxa_s0_serialdev[MRAA_RADXA_S0_UART_COUNT] = { "/dev/ttyS0", "/dev/ttyS1", "/dev/ttyS2", "/dev/ttyS3" };

void
mraa_radxa_s0_pininfo(mraa_board_t* board, int index, int gpio_chip, int gpio_line, mraa_pincapabilities_t pincapabilities_t, char* pin_name)
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
mraa_radxa_s0()
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
    b->phy_pin_count = MRAA_RADXA_S0_PIN_COUNT + 1;

    b->platform_name = PLATFORM_NAME_RADXA_S0;
    b->chardev_capable = 1;

    // UART
    b->uart_dev_count = MRAA_RADXA_S0_UART_COUNT;
    b->def_uart_dev = 0;
    b->uart_dev[0].index = 0;
    b->uart_dev[1].index = 1;
    b->uart_dev[2].index = 2;
    b->uart_dev[3].index = 3;
    b->uart_dev[0].device_path = (char*) radxa_s0_serialdev[0];
    b->uart_dev[1].device_path = (char*) radxa_s0_serialdev[1];
    b->uart_dev[2].device_path = (char*) radxa_s0_serialdev[2];
    b->uart_dev[3].device_path = (char*) radxa_s0_serialdev[3];

    // I2C
    b->i2c_bus_count = MRAA_RADXA_S0_I2C_COUNT;
    b->def_i2c_bus = 0;
    b->i2c_bus[0].bus_id = 0;
    b->i2c_bus[1].bus_id = 1;
    b->i2c_bus[2].bus_id = 2;
    b->i2c_bus[3].bus_id = 3;

    // SPI
    b->spi_bus_count = MRAA_RADXA_S0_SPI_COUNT;
    b->def_spi_bus = 0;
    b->spi_bus[0].bus_id = 0;
    b->spi_bus[1].bus_id = 1;
    b->spi_bus[2].bus_id = 2;

    // PWM
    b->pwm_dev_count = MRAA_RADXA_S0_PWM_COUNT;
    b->pwm_default_period = 500;
    b->pwm_max_period = 2147483;
    b->pwm_min_period = 1;

    b->pins = (mraa_pininfo_t*) malloc(sizeof(mraa_pininfo_t) * b->phy_pin_count);
    if (b->pins == NULL) {
        free(b->adv_func);
        free(b);
        return NULL;
    }

    b->pins[15].pwm.parent_id = 5;  // pwm5
    b->pins[15].pwm.mux_total = 0;
    b->pins[27].pwm.parent_id = 2;  // pwm2
    b->pins[27].pwm.mux_total = 0;
    b->pins[29].pwm.parent_id = 11;  // pwm11
    b->pins[29].pwm.mux_total = 0;
    b->pins[31].pwm.parent_id = 8;  // pwm8
    b->pins[31].pwm.mux_total = 0;
    b->pins[33].pwm.parent_id = 6;  // pwm6
    b->pins[33].pwm.mux_total = 0;
    b->pins[16].pwm.parent_id = 4;  // pwm4
    b->pins[16].pwm.mux_total = 0;
    b->pins[22].pwm.parent_id = 9;  // pwm9
    b->pins[22].pwm.mux_total = 0;
    b->pins[26].pwm.parent_id = 7;  // pwm7
    b->pins[26].pwm.mux_total = 0;
    b->pins[28].pwm.parent_id = 3;  // pwm3
    b->pins[28].pwm.mux_total = 0;
    b->pins[32].pwm.parent_id = 2;  // pwm10
    b->pins[32].pwm.mux_total = 0;

    mraa_radxa_s0_pininfo(b, 0, -1, -1, (mraa_pincapabilities_t){0,0,0,0,0,0,0,0}, "INVALID");
    mraa_radxa_s0_pininfo(b, 1, -1, -1, (mraa_pincapabilities_t){1,0,0,0,0,0,0,0}, "3V3");
    mraa_radxa_s0_pininfo(b, 2, -1, -1, (mraa_pincapabilities_t){1,0,0,0,0,0,0,0}, "5V");
    mraa_radxa_s0_pininfo(b, 3, 0, 11, (mraa_pincapabilities_t){1,1,0,0,0,1,0,0}, "GPIO0_B3");
    mraa_radxa_s0_pininfo(b, 4, -1, -1, (mraa_pincapabilities_t){1,0,0,0,0,0,0,0}, "5V");
    mraa_radxa_s0_pininfo(b, 5, 0, 12, (mraa_pincapabilities_t){1,1,0,0,0,1,0,0}, "GPIO0_B4");
    mraa_radxa_s0_pininfo(b, 6, -1, -1, (mraa_pincapabilities_t){1,0,0,0,0,0,0,0}, "GND");
    mraa_radxa_s0_pininfo(b, 7, 0, 13, (mraa_pincapabilities_t){1,1,0,0,0,0,0,0}, "GPIO2_B5");
    mraa_radxa_s0_pininfo(b, 8, 2, 1, (mraa_pincapabilities_t){1,1,0,0,1,0,0,1}, "GPIO2_A1"); // Used by fiq_debugger
    mraa_radxa_s0_pininfo(b, 9, -1, -1, (mraa_pincapabilities_t){1,0,0,0,0,0,0,0}, "GND");
    mraa_radxa_s0_pininfo(b, 10, 2, 0, (mraa_pincapabilities_t){1,0,0,0,1,1,0,1}, "GPIO2_A0"); // Used by fiq_debugger
    mraa_radxa_s0_pininfo(b, 11, 2, 14, (mraa_pincapabilities_t){1,0,0,0,0,0,0,0}, "GPIO2_B6");
    mraa_radxa_s0_pininfo(b, 12, 2, 9, (mraa_pincapabilities_t){1,0,0,0,0,0,0,0}, "GPIO2_B1");
    mraa_radxa_s0_pininfo(b, 13, 2, 3, (mraa_pincapabilities_t){1,1,0,0,1,1,0,1}, "GPIO2_A3");
    mraa_radxa_s0_pininfo(b, 14, -1, -1, (mraa_pincapabilities_t){1,0,0,0,0,0,0,0}, "GND");
    mraa_radxa_s0_pininfo(b, 15, 0, 17, (mraa_pincapabilities_t){1,0,0,0,0,0,0,0}, "GPIO0_C1");
    mraa_radxa_s0_pininfo(b, 16, 0, 1, (mraa_pincapabilities_t){1,1,1,0,0,0,0,0}, "GPIO0_A1");
    mraa_radxa_s0_pininfo(b, 17, -1, -1, (mraa_pincapabilities_t){1,0,0,0,0,0,0,0}, "3V3");
    mraa_radxa_s0_pininfo(b, 18, 2, 15, (mraa_pincapabilities_t){1,1,0,0,0,0,0,0}, "GPIO2_B7");
    mraa_radxa_s0_pininfo(b, 19, 1, 23, (mraa_pincapabilities_t){1,1,0,0,1,0,0,1}, "GPIO1_C7");
    mraa_radxa_s0_pininfo(b, 20, -1, -1, (mraa_pincapabilities_t){1,0,0,0,0,0,0,0}, "GND");
    mraa_radxa_s0_pininfo(b, 21, 1, 22, (mraa_pincapabilities_t){1,1,0,0,1,0,0,1}, "GPIO1_C6");
    mraa_radxa_s0_pininfo(b, 22, 2, 11, (mraa_pincapabilities_t){1,1,1,0,0,0,0,0}, "GPIO2_B3");
    mraa_radxa_s0_pininfo(b, 23, 1, 24, (mraa_pincapabilities_t){1,1,0,0,1,1,0,1}, "GPIO1_D0");
    mraa_radxa_s0_pininfo(b, 24, 1, 25, (mraa_pincapabilities_t){1,1,0,0,1,1,0,1}, "GPIO1_D1");
    mraa_radxa_s0_pininfo(b, 25, -1, -1, (mraa_pincapabilities_t){1,0,0,0,0,0,0,0}, "GND");
    mraa_radxa_s0_pininfo(b, 26, 2, 8, (mraa_pincapabilities_t){1,1,1,0,0,0,0,0}, "GPIO2_B0");
    mraa_radxa_s0_pininfo(b, 27, 0, 15, (mraa_pincapabilities_t){1,1,1,0,0,1,0,0}, "GPIO0_B7");
    mraa_radxa_s0_pininfo(b, 28, 0, 16, (mraa_pincapabilities_t){1,1,1,0,0,1,0,0}, "GPIO0_C0");
    mraa_radxa_s0_pininfo(b, 29, 2, 16, (mraa_pincapabilities_t){1,1,1,0,0,0,0,0}, "GPIO2_C0");
    mraa_radxa_s0_pininfo(b, 30, -1, -1, (mraa_pincapabilities_t){1,0,0,0,0,0,0,0}, "GND");
    mraa_radxa_s0_pininfo(b, 31, 2, 10, (mraa_pincapabilities_t){1,1,1,0,0,0,0,0}, "GPIO2_B2");
    mraa_radxa_s0_pininfo(b, 32, 2, 12, (mraa_pincapabilities_t){1,1,1,0,0,0,0,0}, "GPIO2_B4");
    mraa_radxa_s0_pininfo(b, 33, 0, 18, (mraa_pincapabilities_t){1,1,1,0,0,0,0,1}, "GPIO0_C2");
    mraa_radxa_s0_pininfo(b, 34, -1, -1, (mraa_pincapabilities_t){1,0,0,0,0,0,0,0}, "GND");
    mraa_radxa_s0_pininfo(b, 35, 2, 4, (mraa_pincapabilities_t){1,1,0,0,1,0,0,0}, "GPIO2_A4");
    mraa_radxa_s0_pininfo(b, 36, 2, 6, (mraa_pincapabilities_t){1,1,0,0,0,0,0,0}, "GPIO2_A6");
    mraa_radxa_s0_pininfo(b, 37, 2, 2, (mraa_pincapabilities_t){1,1,0,0,1,1,0,0}, "GPIO2_A2");
    mraa_radxa_s0_pininfo(b, 38, 2, 5, (mraa_pincapabilities_t){1,1,0,0,1,0,0,0}, "GPIO2_A5");
    mraa_radxa_s0_pininfo(b, 39, -1, -1, (mraa_pincapabilities_t){1,0,0,0,0,0,0,0}, "GND");
    mraa_radxa_s0_pininfo(b, 40, 2, 7, (mraa_pincapabilities_t){1,0,0,0,0,0,0,0}, "GPIO2_A7");

    return b;
}
