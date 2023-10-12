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

#include "arm/radxa_cm5_rpi_cm4_io.h"
#include "common.h"

#define DT_BASE "/proc/device-tree"

const char* radxa_cm5_rpi_cm4_io_serialdev[MRAA_RADXA_CM5_RPI_CM4_IO_UART_COUNT] = { "/dev/ttyS2", "/dev/ttyS4", "/dev/ttyS7"};

void
mraa_radxa_cm5_rpi_cm4_io_pininfo(mraa_board_t* board, int index, int gpio_chip, int gpio_line, mraa_pincapabilities_t pincapabilities_t, char* pin_name)
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
mraa_radxa_cm5_rpi_cm4_io()
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
    b->phy_pin_count = MRAA_RADXA_CM5_RPI_CM4_IO_PIN_COUNT + 1;

    // UART
    b->uart_dev_count = MRAA_RADXA_CM5_RPI_CM4_IO_UART_COUNT;
    b->platform_name = PLATFORM_NAME_RADXA_CM5_RPI_CM4_IO;
    b->def_uart_dev = 0;
    b->uart_dev[0].index = 2;
    b->uart_dev[1].index = 4;
    b->uart_dev[2].index = 7;
    b->uart_dev[0].device_path = (char*) radxa_cm5_rpi_cm4_io_serialdev[0];
    b->uart_dev[1].device_path = (char*) radxa_cm5_rpi_cm4_io_serialdev[1];
    b->uart_dev[1].device_path = (char*) radxa_cm5_rpi_cm4_io_serialdev[2];

    // I2C
    b->i2c_bus_count = MRAA_RADXA_CM5_RPI_CM4_IO_I2C_COUNT;
    b->def_i2c_bus = 0;
    b->i2c_bus[0].bus_id = 1;
    b->i2c_bus[1].bus_id = 4;
    b->i2c_bus[2].bus_id = 6;

    // SPI
    b->spi_bus_count = MRAA_RADXA_CM5_RPI_CM4_IO_SPI_COUNT;
    b->def_spi_bus = 0;
    b->spi_bus[0].bus_id = 0;

    // PWM
    b->pwm_dev_count = MRAA_RADXA_CM5_RPI_CM4_IO_PWM_COUNT;
    b->pwm_default_period = 500;
    b->pwm_max_period = 2147483;
    b->pwm_min_period = 1;

    b->pins = (mraa_pininfo_t*) malloc(sizeof(mraa_pininfo_t) * b->phy_pin_count);
    if (b->pins == NULL) {
        free(b->adv_func);
        free(b);
        return NULL;
    }

    b->pins[40].pwm.parent_id = 0;    // PWM0_M2
    b->pins[40].pwm.mux_total = 0;
    b->pins[40].pwm.pinmap = 0;
    b->pins[11].pwm.parent_id = 6;    // PWM3_IR_M2
    b->pins[11].pwm.mux_total = 0;
    b->pins[11].pwm.pinmap = 0;
    b->pins[16].pwm.parent_id = 7;   // PWM3_IR_M3
    b->pins[16].pwm.mux_total = 0;
    b->pins[16].pwm.pinmap = 0;
    b->pins[5].pwm.parent_id = 11;   // PWM6_M0
    b->pins[5].pwm.mux_total = 0;
    b->pins[5].pwm.pinmap = 0;
    b->pins[3].pwm.parent_id = 13;  // PWM7_IR_M0
    b->pins[3].pwm.mux_total = 0;
    b->pins[3].pwm.pinmap = 0;
    b->pins[32].pwm.parent_id = 11;   // PWM14_M1
    b->pins[32].pwm.mux_total = 0;
    b->pins[32].pwm.pinmap = 0;
    b->pins[29].pwm.parent_id = 15;   // PWM15_IR_M3
    b->pins[29].pwm.mux_total = 0;
    b->pins[29].pwm.pinmap = 0;

    // Hardware X2.0
    mraa_radxa_cm5_rpi_cm4_io_pininfo(b, 0, -1, -1, (mraa_pincapabilities_t){0,0,0,0,0,0,0,0}, "INVALID");
    mraa_radxa_cm5_rpi_cm4_io_pininfo(b, 1, -1, -1, (mraa_pincapabilities_t){1,0,0,0,0,0,0,0}, "3V3");
    mraa_radxa_cm5_rpi_cm4_io_pininfo(b, 2, -1, -1, (mraa_pincapabilities_t){1,0,0,0,0,0,0,0}, "5V");
    mraa_radxa_cm5_rpi_cm4_io_pininfo(b, 3,  0, 24, (mraa_pincapabilities_t){1,1,1,0,0,1,0,0}, "GPIO0_D0");
    mraa_radxa_cm5_rpi_cm4_io_pininfo(b, 4, -1, -1, (mraa_pincapabilities_t){1,0,0,0,0,0,0,0}, "5V");
    mraa_radxa_cm5_rpi_cm4_io_pininfo(b, 5,  0, 23, (mraa_pincapabilities_t){1,1,1,0,0,1,0,0}, "GPIO0_C7");
    mraa_radxa_cm5_rpi_cm4_io_pininfo(b, 6, -1, -1, (mraa_pincapabilities_t){1,0,0,0,0,0,0,0}, "GND");
    mraa_radxa_cm5_rpi_cm4_io_pininfo(b, 7,  1, 28, (mraa_pincapabilities_t){1,1,0,0,0,0,0,0}, "GPIO1_D4");
    mraa_radxa_cm5_rpi_cm4_io_pininfo(b, 8,  1, 13, (mraa_pincapabilities_t){1,0,0,0,0,1,0,1}, "GPIO0_B5");  // IO resources is occupied by uart, function GPIO can't be used.
    mraa_radxa_cm5_rpi_cm4_io_pininfo(b, 9, -1, -1, (mraa_pincapabilities_t){1,0,0,0,0,0,0,0}, "GND");
    mraa_radxa_cm5_rpi_cm4_io_pininfo(b, 10, 1, 14, (mraa_pincapabilities_t){1,0,0,0,0,1,0,1}, "GPIO0_B6");  // IO resources is occupied by uart, function GPIO can't be used.
    mraa_radxa_cm5_rpi_cm4_io_pininfo(b, 11, 1, 18, (mraa_pincapabilities_t){1,1,1,0,0,0,0,0}, "GPIO1_C2");
    mraa_radxa_cm5_rpi_cm4_io_pininfo(b, 12, 1, 3, (mraa_pincapabilities_t){1,1,0,0,0,1,0,0}, "GPIO1_A3");
    mraa_radxa_cm5_rpi_cm4_io_pininfo(b, 13, 1, 21, (mraa_pincapabilities_t){1,1,0,0,0,0,0,0}, "GPIO1_C5");
    mraa_radxa_cm5_rpi_cm4_io_pininfo(b, 14, -1, -1, (mraa_pincapabilities_t){1,0,0,0,0,0,0,0}, "GND");
    mraa_radxa_cm5_rpi_cm4_io_pininfo(b, 15, 1, 19, (mraa_pincapabilities_t){1,1,0,0,0,0,0,0}, "GPIO1_C3");
    mraa_radxa_cm5_rpi_cm4_io_pininfo(b, 16, 1, 7, (mraa_pincapabilities_t){1,1,1,0,0,0,0,0}, "GPIO1_A7");
    mraa_radxa_cm5_rpi_cm4_io_pininfo(b, 17, -1, -1, (mraa_pincapabilities_t){1,0,0,0,0,0,0,0}, "3V3");
    mraa_radxa_cm5_rpi_cm4_io_pininfo(b, 18, 1, 6, (mraa_pincapabilities_t){1,1,0,0,0,0,0,0}, "GPIO1_A6");
    mraa_radxa_cm5_rpi_cm4_io_pininfo(b, 19, 1, 10, (mraa_pincapabilities_t){1,1,0,0,1,0,0,1}, "GPIO1_B2");
    mraa_radxa_cm5_rpi_cm4_io_pininfo(b, 20, -1, -1, (mraa_pincapabilities_t){1,0,0,0,0,0,0,0}, "GND");
    mraa_radxa_cm5_rpi_cm4_io_pininfo(b, 21, 1, 9, (mraa_pincapabilities_t){1,1,0,0,1,0,0,0}, "GPIO1_B1");
    mraa_radxa_cm5_rpi_cm4_io_pininfo(b, 22, 1, 8, (mraa_pincapabilities_t){1,1,0,0,0,0,0,0}, "GPIO1_B0");
    mraa_radxa_cm5_rpi_cm4_io_pininfo(b, 23, 1, 11, (mraa_pincapabilities_t){1,1,0,0,1,0,0,1}, "GPIO1_B3");
    mraa_radxa_cm5_rpi_cm4_io_pininfo(b, 24, 1, 12, (mraa_pincapabilities_t){1,1,0,0,1,0,0,1}, "GPIO1_B4");
    mraa_radxa_cm5_rpi_cm4_io_pininfo(b, 25, -1, -1, (mraa_pincapabilities_t){1,0,0,0,0,0,0,0}, "GND");
    mraa_radxa_cm5_rpi_cm4_io_pininfo(b, 26, 1, 13, (mraa_pincapabilities_t){1,1,0,0,1,0,0,1}, "GPIO1_B5");
    mraa_radxa_cm5_rpi_cm4_io_pininfo(b, 27, -1, -1, (mraa_pincapabilities_t){1,0,0,0,0,0,0,0}, "3V3");
    mraa_radxa_cm5_rpi_cm4_io_pininfo(b, 28, -1, -1, (mraa_pincapabilities_t){1,0,0,0,0,0,0,0}, "3V3");
    mraa_radxa_cm5_rpi_cm4_io_pininfo(b, 29, 1, 31, (mraa_pincapabilities_t){1,1,1,0,0,0,0,0}, "GPIO1_D7");
    mraa_radxa_cm5_rpi_cm4_io_pininfo(b, 30, -1, -1, (mraa_pincapabilities_t){1,0,0,0,0,0,0,0}, "GND");
    mraa_radxa_cm5_rpi_cm4_io_pininfo(b, 31, 1, 23, (mraa_pincapabilities_t){1,1,0,0,0,0,0,0}, "GPIO1_C7");
    mraa_radxa_cm5_rpi_cm4_io_pininfo(b, 32, 4, 10, (mraa_pincapabilities_t){1,1,1,0,0,0,0,0}, "GPIO4_B2");
    mraa_radxa_cm5_rpi_cm4_io_pininfo(b, 33, 4, 2, (mraa_pincapabilities_t){1,1,0,0,0,0,0,0}, "GPIO4_A2");
    mraa_radxa_cm5_rpi_cm4_io_pininfo(b, 34, -1, -1, (mraa_pincapabilities_t){1,0,0,0,0,0,0,0}, "GND");
    mraa_radxa_cm5_rpi_cm4_io_pininfo(b, 35, 4, 1, (mraa_pincapabilities_t){1,1,0,0,0,0,0,0}, "GPIO4_A1");
    mraa_radxa_cm5_rpi_cm4_io_pininfo(b, 36, 1, 4, (mraa_pincapabilities_t){1,1,0,0,0,0,0,0}, "GPIO1_A4");
    mraa_radxa_cm5_rpi_cm4_io_pininfo(b, 37, 3, 24, (mraa_pincapabilities_t){1,1,1,0,0,0,0,0}, "GPIO3_D0");
    mraa_radxa_cm5_rpi_cm4_io_pininfo(b, 38, 1, 1, (mraa_pincapabilities_t){1,1,0,0,0,0,0,0}, "GPIO1_A1");
    mraa_radxa_cm5_rpi_cm4_io_pininfo(b, 39, -1, -1, (mraa_pincapabilities_t){1,0,0,0,0,0,0,0}, "GND");
    mraa_radxa_cm5_rpi_cm4_io_pininfo(b, 40, 1, 2, (mraa_pincapabilities_t){1,1,1,0,0,1,0,0}, "GPIO1_A2");

    return b;
}
