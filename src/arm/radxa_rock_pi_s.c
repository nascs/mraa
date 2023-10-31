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
#include "arm/radxa_rock_pi_s.h"
#include "common.h"

const char* radxa_rock_pi_s_serialdev[MRAA_RADXA_ROCK_PI_S_UART_COUNT] = { "/dev/ttyS0", "/dev/ttyS1", "/dev/ttyS2", "/dev/ttyS3" };

void
mraa_radxa_rock_pi_s_pininfo(mraa_board_t* board, int index, int gpio_chip, int gpio_line, mraa_pincapabilities_t pincapabilities_t, char* pin_name)
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
mraa_radxa_rock_pi_s()
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
    b->phy_pin_count = MRAA_RADXA_ROCK_PI_S_PIN_COUNT + 1;

    b->platform_name = PLATFORM_NAME_RADXA_ROCK_PI_S;
    b->chardev_capable = 1;

    // UART
    b->uart_dev_count = MRAA_RADXA_ROCK_PI_S_UART_COUNT;
    b->def_uart_dev = 0;
    b->uart_dev[0].index = 0;
    b->uart_dev[1].index = 2;
    b->uart_dev[2].index = 3;
    b->uart_dev[3].index = 5;
    b->uart_dev[4].index = 7;
    b->uart_dev[5].index = 9;
    b->uart_dev[0].device_path = (char*) radxa_rock_pi_s_serialdev[0];
    b->uart_dev[1].device_path = (char*) radxa_rock_pi_s_serialdev[1];
    b->uart_dev[2].device_path = (char*) radxa_rock_pi_s_serialdev[2];
    b->uart_dev[3].device_path = (char*) radxa_rock_pi_s_serialdev[3];
    b->uart_dev[4].device_path = (char*) radxa_rock_pi_s_serialdev[4];
    b->uart_dev[5].device_path = (char*) radxa_rock_pi_s_serialdev[5];

    // I2C
    b->i2c_bus_count = MRAA_RADXA_ROCK_PI_S_I2C_COUNT;
    b->def_i2c_bus = 0;
    b->i2c_bus[0].bus_id = 0;
    b->i2c_bus[1].bus_id = 1;
    b->i2c_bus[2].bus_id = 3;

    // SPI
    b->spi_bus_count = MRAA_RADXA_ROCK_PI_S_SPI_COUNT;
    b->def_spi_bus = 0;
    b->spi_bus[0].bus_id = 1;
    b->spi_bus[1].bus_id = 2;

    // PWM
    b->pwm_dev_count = MRAA_RADXA_ROCK_PI_S_PWM_COUNT;
    b->pwm_default_period = 500;
    b->pwm_max_period = 2147483;
    b->pwm_min_period = 1;

    b->pins = (mraa_pininfo_t*) malloc(sizeof(mraa_pininfo_t) * b->phy_pin_count);
    if (b->pins == NULL) {
        free(b->adv_func);
        free(b);
        return NULL;
    }

    b->pins[11].pwm.parent_id = 2;  // pwm2
    b->pins[11].pwm.mux_total = 0;
    b->pins[13].pwm.parent_id = 3;  // pwm3
    b->pins[13].pwm.mux_total = 0;

    mraa_radxa_rock_pi_s_pininfo(b, 0, -1, -1, (mraa_pincapabilities_t){0,0,0,0,0,0,0,0}, "INVALID");
    mraa_radxa_rock_pi_s_pininfo(b, 1, -1, -1, (mraa_pincapabilities_t){1,0,0,0,0,0,0,0}, "3V3");
    mraa_radxa_rock_pi_s_pininfo(b, 2, -1, -1, (mraa_pincapabilities_t){1,0,0,0,0,0,0,0}, "5V");
    mraa_radxa_rock_pi_s_pininfo(b, 3, 0, 11, (mraa_pincapabilities_t){1,1,0,0,0,1,0,0}, "GPIO0_B3");
    mraa_radxa_rock_pi_s_pininfo(b, 4, -1, -1, (mraa_pincapabilities_t){1,0,0,0,0,0,0,0}, "5V");
    mraa_radxa_rock_pi_s_pininfo(b, 5, 0, 12, (mraa_pincapabilities_t){1,1,0,0,0,1,0,0}, "GPIO0_B4");
    mraa_radxa_rock_pi_s_pininfo(b, 6, -1, -1, (mraa_pincapabilities_t){1,0,0,0,0,0,0,0}, "GND");
    mraa_radxa_rock_pi_s_pininfo(b, 7, 2, 4, (mraa_pincapabilities_t){1,1,0,0,0,0,0,0}, "GPIO2_A4");
    mraa_radxa_rock_pi_s_pininfo(b, 8, 2, 1, (mraa_pincapabilities_t){1,1,0,0,1,0,0,1}, "GPIO2_A1");
    mraa_radxa_rock_pi_s_pininfo(b, 9, -1, -1, (mraa_pincapabilities_t){1,0,0,0,0,0,0,0}, "GND");
    mraa_radxa_rock_pi_s_pininfo(b, 10, 2, 0, (mraa_pincapabilities_t){1,1,0,0,1,0,0,1}, "GPIO2_A0");
    mraa_radxa_rock_pi_s_pininfo(b, 11, 0, 15, (mraa_pincapabilities_t){1,1,1,0,0,1,0,0}, "GPIO0_B7");
    mraa_radxa_rock_pi_s_pininfo(b, 12, 2, 5, (mraa_pincapabilities_t){1,1,0,0,0,0,0,0}, "GPIO2_A5");
    mraa_radxa_rock_pi_s_pininfo(b, 13, 0, 16, (mraa_pincapabilities_t){1,1,1,0,0,1,0,0}, "GPIO0_C0");
    mraa_radxa_rock_pi_s_pininfo(b, 14, -1, -1, (mraa_pincapabilities_t){1,0,0,0,0,0,0,0}, "GND");
    mraa_radxa_rock_pi_s_pininfo(b, 15, 0, 17, (mraa_pincapabilities_t){1,1,0,0,0,0,0,0}, "GPIO0_C1");
    mraa_radxa_rock_pi_s_pininfo(b, 16, 2, 10, (mraa_pincapabilities_t){1,1,0,0,0,0,0,0}, "GPIO2_B2");
    mraa_radxa_rock_pi_s_pininfo(b, 17, -1, -1, (mraa_pincapabilities_t){1,0,0,0,0,0,0,0}, "3V3");
    mraa_radxa_rock_pi_s_pininfo(b, 18, 2, 9, (mraa_pincapabilities_t){1,1,0,0,0,0,0,0}, "GPIO2_B1");
    mraa_radxa_rock_pi_s_pininfo(b, 19, 1, 23, (mraa_pincapabilities_t){1,1,0,0,1,0,0,1}, "GPIO1_C7");
    mraa_radxa_rock_pi_s_pininfo(b, 20, -1, -1, (mraa_pincapabilities_t){1,0,0,0,0,0,0,0}, "GND");
    mraa_radxa_rock_pi_s_pininfo(b, 21, 1, 22, (mraa_pincapabilities_t){1,1,0,0,1,0,0,1}, "GPIO1_C6");
    mraa_radxa_rock_pi_s_pininfo(b, 22, 2, 7, (mraa_pincapabilities_t){1,0,0,0,0,0,0,0}, "GPIO2_A7");
    mraa_radxa_rock_pi_s_pininfo(b, 23, 1, 24, (mraa_pincapabilities_t){1,0,0,0,1,1,0,1}, "GPIO1_D0");
    mraa_radxa_rock_pi_s_pininfo(b, 24, 1, 25, (mraa_pincapabilities_t){1,0,0,0,0,0,0,0}, "GPIO1_D1");
    mraa_radxa_rock_pi_s_pininfo(b, 25, -1, -1, (mraa_pincapabilities_t){1,0,0,0,0,0,0,0}, "GND");
    mraa_radxa_rock_pi_s_pininfo(b, 26, -1, -1, (mraa_pincapabilities_t){1,0,0,0,0,0,1,0}, "ADC_IN0");
    mraa_radxa_rock_pi_s_pininfo(b, 27, -1, -1, (mraa_pincapabilities_t){1,0,0,0,0,0,0,0}, "GND");
    mraa_radxa_rock_pi_s_pininfo(b, 28, 2, 13, (mraa_pincapabilities_t){1,1,0,0,0,0,0,0}, "GPIO2_B5");
    mraa_radxa_rock_pi_s_pininfo(b, 29, -1, -1, (mraa_pincapabilities_t){1,0,0,0,0,0,1,0}, "ADC_KEY_IN1");
    mraa_radxa_rock_pi_s_pininfo(b, 30, 2, 14, (mraa_pincapabilities_t){1,1,0,0,0,0,0,0}, "GPIO2_B6");
    mraa_radxa_rock_pi_s_pininfo(b, 31, -1, -1, (mraa_pincapabilities_t){1,0,0,0,0,0,0,0}, "MICBIAS2");
    mraa_radxa_rock_pi_s_pininfo(b, 32, 2, 15, (mraa_pincapabilities_t){1,1,0,0,0,0,0,0}, "GPIO2_B7");
    mraa_radxa_rock_pi_s_pininfo(b, 33, -1, -1, (mraa_pincapabilities_t){1,0,0,0,0,0,0,0}, "MICBIAS1");
    mraa_radxa_rock_pi_s_pininfo(b, 34, 2, 16, (mraa_pincapabilities_t){1,1,0,0,0,0,0,0}, "GPIO2_C0");
    mraa_radxa_rock_pi_s_pininfo(b, 35, -1, -1, (mraa_pincapabilities_t){1,0,0,0,0,0,0,0}, "MICN8");
    mraa_radxa_rock_pi_s_pininfo(b, 36, -1, -1, (mraa_pincapabilities_t){1,0,0,0,0,0,0,0}, "MCIP8");
    mraa_radxa_rock_pi_s_pininfo(b, 37, -1, -1, (mraa_pincapabilities_t){1,0,0,0,0,0,0,0}, "MICN7");
    mraa_radxa_rock_pi_s_pininfo(b, 38, -1, -1, (mraa_pincapabilities_t){1,0,0,0,0,0,0,0}, "MCIP7");
    mraa_radxa_rock_pi_s_pininfo(b, 39, 3, 13, (mraa_pincapabilities_t){1,1,0,0,1,1,0,1}, "GPOI3_B5");
    mraa_radxa_rock_pi_s_pininfo(b, 40, 3, 12, (mraa_pincapabilities_t){1,1,0,0,1,1,0,1}, "GPOI3_B4");
    mraa_radxa_rock_pi_s_pininfo(b, 41, 3, 11, (mraa_pincapabilities_t){1,1,0,0,1,0,0,0}, "GPOI3_B3");
    mraa_radxa_rock_pi_s_pininfo(b, 42, 3, 10, (mraa_pincapabilities_t){1,1,0,0,1,0,0,0}, "GPOI3_B2");
    mraa_radxa_rock_pi_s_pininfo(b, 43, 2, 12, (mraa_pincapabilities_t){1,1,0,0,0,0,0,0}, "GPIO2_B4");
    mraa_radxa_rock_pi_s_pininfo(b, 44, 2, 11, (mraa_pincapabilities_t){1,1,0,0,0,0,0,0}, "GPIO2_B3");
    mraa_radxa_rock_pi_s_pininfo(b, 45, 2, 8, (mraa_pincapabilities_t){1,1,0,0,0,0,0,0}, "GPIO2_B0");
    mraa_radxa_rock_pi_s_pininfo(b, 46, 2, 6, (mraa_pincapabilities_t){1,1,0,0,0,0,0,0}, "GPIO2_A6");
    mraa_radxa_rock_pi_s_pininfo(b, 47, -1, -1, (mraa_pincapabilities_t){1,0,0,0,0,0,0,0}, "MICN2");
    mraa_radxa_rock_pi_s_pininfo(b, 48, -1, -1, (mraa_pincapabilities_t){1,0,0,0,0,0,0,0}, "MCIP2");
    mraa_radxa_rock_pi_s_pininfo(b, 49, -1, -1, (mraa_pincapabilities_t){1,0,0,0,0,0,0,0}, "MICN1");
    mraa_radxa_rock_pi_s_pininfo(b, 50, -1, -1, (mraa_pincapabilities_t){1,0,0,0,0,0,0,0}, "MCIP1");
    mraa_radxa_rock_pi_s_pininfo(b, 51, -1, -1, (mraa_pincapabilities_t){1,0,0,0,0,0,0,0}, "LINEOUT_R");
    mraa_radxa_rock_pi_s_pininfo(b, 52, -1, -1, (mraa_pincapabilities_t){1,0,0,0,0,0,0,0}, "LINEOUT_L");

    return b;
}
