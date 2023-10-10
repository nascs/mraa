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

#include "arm/radxa_nx5_io.h"
#include "common.h"

#define DT_BASE "/proc/device-tree"

const char* radxa_nx5_io_serialdev[MRAA_RADXA_NX5_IO_UART_COUNT] = { "/dev/ttyS1", "/dev/ttyS2", "/dev/ttyS4", "/dev/ttyS6", "/dev/ttyS7"};

void
mraa_radxa_nx5_io_pininfo(mraa_board_t* board, int index, int gpio_chip, int gpio_line, mraa_pincapabilities_t pincapabilities_t, char* pin_name)
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
mraa_radxa_nx5_io()
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
    b->phy_pin_count = MRAA_RADXA_NX5_IO_PIN_COUNT + 1;

    // UART
    b->uart_dev_count = MRAA_RADXA_NX5_IO_UART_COUNT;
    b->platform_name = PLATFORM_NAME_RADXA_NX5_IO;
    b->def_uart_dev = 0;
    b->uart_dev[0].index = 1;
    b->uart_dev[1].index = 2;
    b->uart_dev[2].index = 4;
    b->uart_dev[3].index = 6;
    b->uart_dev[4].index = 7;
    b->uart_dev[0].device_path = (char*) radxa_nx5_io_serialdev[0];
    b->uart_dev[1].device_path = (char*) radxa_nx5_io_serialdev[1];
    b->uart_dev[2].device_path = (char*) radxa_nx5_io_serialdev[2];
    b->uart_dev[3].device_path = (char*) radxa_nx5_io_serialdev[3];
    b->uart_dev[4].device_path = (char*) radxa_nx5_io_serialdev[4];

    // I2C
    b->i2c_bus_count = MRAA_RADXA_NX5_IO_I2C_COUNT;
    b->def_i2c_bus = 0;
    b->i2c_bus[0].bus_id = 0;
    b->i2c_bus[1].bus_id = 1;
    b->i2c_bus[2].bus_id = 7;

    // SPI
    b->spi_bus_count = MRAA_RADXA_NX5_IO_SPI_COUNT;
    b->def_spi_bus = 0;
    b->spi_bus[0].bus_id = 0;
    b->spi_bus[1].bus_id = 1;

    // PWM
    b->pwm_dev_count = MRAA_RADXA_NX5_IO_PWM_COUNT;
    b->pwm_default_period = 500;
    b->pwm_max_period = 2147483;
    b->pwm_min_period = 1;

    b->pins = (mraa_pininfo_t*) malloc(sizeof(mraa_pininfo_t) * b->phy_pin_count);
    if (b->pins == NULL) {
        free(b->adv_func);
        free(b);
        return NULL;
    }

    b->pins[13].pwm.parent_id = 0;    // PWM0-M1
    b->pins[13].pwm.mux_total = 0;
    b->pins[13].pwm.pinmap = 0;
    b->pins[18].pwm.parent_id = 1;    // PWM1-M1
    b->pins[18].pwm.mux_total = 0;
    b->pins[18].pwm.pinmap = 0;
    b->pins[3].pwm.parent_id = 3;   // PWM3-M0
    b->pins[3].pwm.mux_total = 0;
    b->pins[3].pwm.pinmap = 0;
    b->pins[12].pwm.parent_id = 7;   // PWM7-M2
    b->pins[12].pwm.mux_total = 0;
    b->pins[12].pwm.pinmap = 0;
    b->pins[36].pwm.parent_id = 10;  // PWM10-M2 
    b->pins[36].pwm.mux_total = 0;
    b->pins[36].pwm.pinmap = 0;
    b->pins[29].pwm.parent_id = 13;   // PWM13-M1
    b->pins[29].pwm.mux_total = 0;
    b->pins[29].pwm.pinmap = 0;
    b->pins[32].pwm.parent_id = 15;   // PWM15-M1
    b->pins[32].pwm.mux_total = 0;
    b->pins[32].pwm.pinmap = 0;

    // Hardware X1.2
    mraa_radxa_nx5_io_pininfo(b, 0, -1, -1, (mraa_pincapabilities_t){0,0,0,0,0,0,0,0}, "INVALID");
    mraa_radxa_nx5_io_pininfo(b, 1, -1, -1, (mraa_pincapabilities_t){1,0,0,0,0,0,0,0}, "3V3");
    mraa_radxa_nx5_io_pininfo(b, 2, -1, -1, (mraa_pincapabilities_t){1,0,0,0,0,0,0,0}, "5V");
    mraa_radxa_nx5_io_pininfo(b, 3, 0, 28, (mraa_pincapabilities_t){1,1,1,0,1,1,0,0}, "GPIO0_D4");
    mraa_radxa_nx5_io_pininfo(b, 4, -1, -1, (mraa_pincapabilities_t){1,0,0,0,0,0,0,0}, "5V");
    mraa_radxa_nx5_io_pininfo(b, 5, 0, 29, (mraa_pincapabilities_t){1,1,0,0,1,1,0,0}, "GPIO0_D5");
    mraa_radxa_nx5_io_pininfo(b, 6, -1, -1, (mraa_pincapabilities_t){1,0,0,0,0,0,0,0}, "GND");
    mraa_radxa_nx5_io_pininfo(b, 7, 4, 13, (mraa_pincapabilities_t){1,0,0,0,0,0,0,0}, "GPIO4_B5");  // IO resources is occupied by pwm-fan, function GPIO/PWM can't be used.
    mraa_radxa_nx5_io_pininfo(b, 8, 0, 13, (mraa_pincapabilities_t){1,0,0,0,0,1,0,1}, "GPIO0_B5");  // Used by fiq_debugger
    mraa_radxa_nx5_io_pininfo(b, 9, -1, -1, (mraa_pincapabilities_t){1,0,0,0,0,0,0,0}, "GND");
    mraa_radxa_nx5_io_pininfo(b, 10, 0, 14, (mraa_pincapabilities_t){1,0,0,0,0,1,0,1}, "GPIO0_B6");  // Used by fiq_debugger
    mraa_radxa_nx5_io_pininfo(b, 11, 3, 26, (mraa_pincapabilities_t){1,1,0,0,1,1,0,1}, "GPIO3_D2");
    mraa_radxa_nx5_io_pininfo(b, 12, 1, 19, (mraa_pincapabilities_t){1,1,1,0,1,1,0,1}, "GPIO1_C3");
    mraa_radxa_nx5_io_pininfo(b, 13, 1, 26, (mraa_pincapabilities_t){1,0,1,0,1,0,0,0}, "GPIO3_D2");  // IO resource is occupied by hym8563 rtc, function GPIO/UART can't be used.
    mraa_radxa_nx5_io_pininfo(b, 14, -1, -1, (mraa_pincapabilities_t){1,0,0,0,0,0,0,0}, "GND");
    mraa_radxa_nx5_io_pininfo(b, 15, 1, 26, (mraa_pincapabilities_t){1,1,1,0,1,1,0,1}, "GPIO1_D2");
    mraa_radxa_nx5_io_pininfo(b, 16, 1, 29, (mraa_pincapabilities_t){1,1,0,0,1,0,0,0}, "GPIO1_D5");
    mraa_radxa_nx5_io_pininfo(b, 17, -1, -1, (mraa_pincapabilities_t){1,0,0,0, 0,0,0,0}, "3V3");
    mraa_radxa_nx5_io_pininfo(b, 18, 1, 27, (mraa_pincapabilities_t){1,1,1,0,1,1,0,0}, "GPIO1_D3");
    mraa_radxa_nx5_io_pininfo(b, 19, 1, 10, (mraa_pincapabilities_t){1,1,0,0,1,0,0,1}, "GPIO1_B2");
    mraa_radxa_nx5_io_pininfo(b, 20, -1, -1, (mraa_pincapabilities_t){1,0,0,0, 0,0,0,0}, "GND");
    mraa_radxa_nx5_io_pininfo(b, 21, 1, 9, (mraa_pincapabilities_t){1,1,0,0,1,0,0,1}, "GPIO1_B1");
    mraa_radxa_nx5_io_pininfo(b, 22, 1, 24, (mraa_pincapabilities_t){1,1,0,0,1,1,0,1}, "GPIO1_D0");
    mraa_radxa_nx5_io_pininfo(b, 23, 1, 11, (mraa_pincapabilities_t){1,1,0,0,1,0,0,1}, "GPIO1_B3");
    mraa_radxa_nx5_io_pininfo(b, 24, 1, 12, (mraa_pincapabilities_t){1,1,0,0,1,0,0,1}, "GPIO1_B4");
    mraa_radxa_nx5_io_pininfo(b, 25, -1, -1, (mraa_pincapabilities_t){1,0,0,0, 0,0,0,0}, "GND");
    mraa_radxa_nx5_io_pininfo(b, 26, 1, 13, (mraa_pincapabilities_t){1,1,0,0,1,0,0,1}, "GPIO1_B5");
    mraa_radxa_nx5_io_pininfo(b, 27, 0, 26, (mraa_pincapabilities_t){1,0,0,0,1,1,0,1}, "GPIO0_D2"); //  Hardware pull-up on this pin, Function GPIO can't be uesed
    mraa_radxa_nx5_io_pininfo(b, 28, 0, 25, (mraa_pincapabilities_t){1,0,0,0,1,1,0,1}, "GPIO0_D1"); //  Hardware pull-up on this pin, Function GPIO can't be uesed
    mraa_radxa_nx5_io_pininfo(b, 29, 4, 14, (mraa_pincapabilities_t){1,1,1,0, 1,1,0,0}, "GPIO4_B6");
    mraa_radxa_nx5_io_pininfo(b, 30, -1, -1, (mraa_pincapabilities_t){1,0,0,0, 0,0,0,0}, "GND");
    mraa_radxa_nx5_io_pininfo(b, 31, 0, 0, (mraa_pincapabilities_t){1,1,0,0, 0,0,0,0}, "GPIO0_A0");
    mraa_radxa_nx5_io_pininfo(b, 32, 4, 11, (mraa_pincapabilities_t){1,1,1,0, 0,1,0,0}, "GPIO4_B3");
    mraa_radxa_nx5_io_pininfo(b, 33, 1, 1, (mraa_pincapabilities_t){1,1,0,0,1,1,0,1}, "GPIO1_A1");
    mraa_radxa_nx5_io_pininfo(b, 34, -1, -1, (mraa_pincapabilities_t){1,0,0,0,0,0,0,0}, "GND");
    mraa_radxa_nx5_io_pininfo(b, 35, 1, 21, (mraa_pincapabilities_t){1,1,0,0, 0,1,0,1}, "GPIO1_C5");
    mraa_radxa_nx5_io_pininfo(b, 36, 3, 27, (mraa_pincapabilities_t){1,1,1,0, 1,1,0,0}, "GPIO3_D3");
    mraa_radxa_nx5_io_pininfo(b, 37, 1, 25, (mraa_pincapabilities_t){1,1,0,0,1,1,0,1}, "GPIO1_D1");
    mraa_radxa_nx5_io_pininfo(b, 38, 1, 28, (mraa_pincapabilities_t){1,1,0,0,0,0,0,0}, "GPIO1_D4");
    mraa_radxa_nx5_io_pininfo(b, 39, -1, -1, (mraa_pincapabilities_t){1,0,0,0,0,0,0,0}, "GND");
    mraa_radxa_nx5_io_pininfo(b, 40, 1, 23, (mraa_pincapabilities_t){1,1,0,0, 0,1,0,0}, "GPIO1_C7");

    return b;
}
