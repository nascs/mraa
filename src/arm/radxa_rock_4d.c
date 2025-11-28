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
 #include "arm/radxa_rock_4d.h"
 #include "common.h"
 
 const char* radxa_rock_4d_serialdev[MRAA_RADXA_ROCK_4D_UART_COUNT] = { "/dev/ttyS0", "/dev/ttyS2", "/dev/ttyS3", "/dev/ttyS4", "/dev/ttyS7", "/dev/ttyS10" };
 
 void
 mraa_radxa_rock_4d_pininfo(mraa_board_t* board, int index, int gpio_chip, int gpio_line, mraa_pincapabilities_t pincapabilities_t, char* pin_name)
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
mraa_radxa_rock_4d()
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

    if (mraa_file_contains("/proc/device-tree/model", PLATFORM_NAME_RADXA_ROCK_4D)) {
        b->platform_name = PLATFORM_NAME_RADXA_ROCK_4D;
    } else if (mraa_file_contains("/proc/device-tree/model", PLATFORM_NAME_RADXA_ROCK_4D_SPI)) {
        b->platform_name = PLATFORM_NAME_RADXA_ROCK_4D_SPI;
    } else {
        syslog(LOG_ERR, "An unknown product detected. Fail early...");
        free(b);
        return NULL;
    }

    // pin mux for buses are setup by default by kernel so tell mraa to ignore them
    b->no_bus_mux = 1;
    b->phy_pin_count = MRAA_RADXA_ROCK_4D_PIN_COUNT + 1;

    b->platform_name = PLATFORM_NAME_RADXA_ROCK_4D;
    b->chardev_capable = 1;

    // UART
    b->uart_dev_count = MRAA_RADXA_ROCK_4D_UART_COUNT;
    b->def_uart_dev = 0;
    b->uart_dev[0].index = 0;
    b->uart_dev[1].index = 2;
    b->uart_dev[2].index = 3;
    b->uart_dev[3].index = 4;
    b->uart_dev[4].index = 7;
    b->uart_dev[5].index = 10;
    b->uart_dev[0].device_path = (char*) radxa_rock_4d_serialdev[0];
    b->uart_dev[1].device_path = (char*) radxa_rock_4d_serialdev[1];
    b->uart_dev[2].device_path = (char*) radxa_rock_4d_serialdev[2];
    b->uart_dev[3].device_path = (char*) radxa_rock_4d_serialdev[3];
    b->uart_dev[4].device_path = (char*) radxa_rock_4d_serialdev[4];
    b->uart_dev[5].device_path = (char*) radxa_rock_4d_serialdev[5];

    // I2C
    b->i2c_bus_count = MRAA_RADXA_ROCK_4D_I2C_COUNT;
    b->def_i2c_bus = 0;
    b->i2c_bus[0].bus_id = 5;
    b->i2c_bus[1].bus_id = 6;
    b->i2c_bus[2].bus_id = 8;
    b->i2c_bus[3].bus_id = 9;

    // SPI
    b->spi_bus_count = MRAA_RADXA_ROCK_4D_SPI_COUNT;
    b->def_spi_bus = 0;
    b->spi_bus[0].bus_id = 1;
    b->spi_bus[1].bus_id = 2;

    // PWM
    b->pwm_dev_count = MRAA_RADXA_ROCK_4D_PWM_COUNT;
    b->pwm_default_period = 500;
    b->pwm_max_period = 2147483;
    b->pwm_min_period = 1;

    b->pins = (mraa_pininfo_t*) malloc(sizeof(mraa_pininfo_t) * b->phy_pin_count);
    if (b->pins == NULL) {
        free(b->adv_func);
        free(b);
        return NULL;
    }

    b->pins[13].pwm.parent_id = 1; // PWM1_CH0_M2
    b->pins[13].pwm.mux_total = 0;
    b->pins[13].pwm.pinmap = 0;
    b->pins[19].pwm.parent_id = 1;  // PWM1_CH1_M1
    b->pins[19].pwm.mux_total = 0;
    b->pins[19].pwm.pinmap = 0;
    b->pins[22].pwm.parent_id = 2; // PWM2_CH7_M2
    b->pins[22].pwm.mux_total = 0;
    b->pins[22].pwm.pinmap = 0;
    b->pins[23].pwm.parent_id = 1; // PWM1_CH0_M1
    b->pins[23].pwm.mux_total = 0;
    b->pins[23].pwm.pinmap = 0;
    b->pins[26].pwm.parent_id = 0; // PWM0_CH0_M1
    b->pins[26].pwm.mux_total = 0;
    b->pins[26].pwm.pinmap = 0;
    b->pins[27].pwm.parent_id = 2; // PWM2_CH3_M1
    b->pins[27].pwm.mux_total = 0;
    b->pins[27].pwm.pinmap = 0;
    b->pins[28].pwm.parent_id = 2;  // PWM2_CH2_M1
    b->pins[28].pwm.mux_total = 0;
    b->pins[28].pwm.pinmap = 0;
    b->pins[33].pwm.parent_id = 1; // PWM1_CH2_M1
    b->pins[33].pwm.mux_total = 0;
    b->pins[33].pwm.pinmap = 0;
    b->pins[35].pwm.parent_id = 1; // PWM1_CH3_M1
    b->pins[35].pwm.mux_total = 0;
    b->pins[35].pwm.pinmap = 0;
    b->pins[38].pwm.parent_id = 1; // PWM1_CH4_M1
    b->pins[38].pwm.mux_total = 0;
    b->pins[38].pwm.pinmap = 0;

    // hardware V1.11
    mraa_radxa_rock_4d_pininfo(b, 0, -1, -1, (mraa_pincapabilities_t){0,0,0,0,0,0,0,0}, "INVALID");
    mraa_radxa_rock_4d_pininfo(b, 1, -1, -1, (mraa_pincapabilities_t){1,0,0,0,0,0,0,0}, "3V3");
    mraa_radxa_rock_4d_pininfo(b, 2, -1, -1, (mraa_pincapabilities_t){1,0,0,0,0,0,0,0}, "5V");
    mraa_radxa_rock_4d_pininfo(b, 3, 1, 23, (mraa_pincapabilities_t){1,1,0,0,0,1,0,1}, "GPIO1_C7");
    mraa_radxa_rock_4d_pininfo(b, 4, -1, -1, (mraa_pincapabilities_t){1,0,0,0,0,0,0,0}, "5V");
    mraa_radxa_rock_4d_pininfo(b, 5, 1, 22, (mraa_pincapabilities_t){1,1,0,0,0,1,0,1}, "GPIO1_C6");
    mraa_radxa_rock_4d_pininfo(b, 6, -1, -1, (mraa_pincapabilities_t){1,0,0,0,0,0,0,0}, "GND");
    mraa_radxa_rock_4d_pininfo(b, 7, 1, 19, (mraa_pincapabilities_t){1,1,0,0,1,1,0,1}, "GPIO1_C3");
    mraa_radxa_rock_4d_pininfo(b, 8, 0, 28, (mraa_pincapabilities_t){1,1,0,0,0,0,0,1}, "GPIO0_D4");
    mraa_radxa_rock_4d_pininfo(b, 9, -1, -1, (mraa_pincapabilities_t){1,0,0,0,0,0,0,0}, "GND");
    mraa_radxa_rock_4d_pininfo(b, 10, 0, 29, (mraa_pincapabilities_t){1,1,0,0,0,0,0,1}, "GPIO0_D5");
    mraa_radxa_rock_4d_pininfo(b, 11, 1, 20, (mraa_pincapabilities_t){1,1,0,0,1,0,0,1}, "GPIO1_C4");
    mraa_radxa_rock_4d_pininfo(b, 12, 1, 25, (mraa_pincapabilities_t){1,1,0,0,0,0,0,1}, "GPIO1_D1");
    mraa_radxa_rock_4d_pininfo(b, 13, 2, 16, (mraa_pincapabilities_t){1,1,1,0,0,0,0,0}, "GPIO2_C0");
    mraa_radxa_rock_4d_pininfo(b, 14, -1, -1, (mraa_pincapabilities_t){1,0,0,0,0,0,0,0}, "GND");
    mraa_radxa_rock_4d_pininfo(b, 15, 1, 21, (mraa_pincapabilities_t){1,1,0,0,1,0,0,1}, "GPIO1_C5");
    mraa_radxa_rock_4d_pininfo(b, 16, 2, 14, (mraa_pincapabilities_t){1,1,0,0,0,1,0,1}, "GPIO2_B6");
    mraa_radxa_rock_4d_pininfo(b, 17, -1, -1, (mraa_pincapabilities_t){1,0,0,0,0,0,0,0}, "3V3");
    mraa_radxa_rock_4d_pininfo(b, 18, 2, 15, (mraa_pincapabilities_t){1,1,0,0,0,1,0,1}, "GPIO2_B7");
    mraa_radxa_rock_4d_pininfo(b, 19, 1, 13, (mraa_pincapabilities_t){1,1,1,0,1,1,0,1}, "GPIO1_B5");
    mraa_radxa_rock_4d_pininfo(b, 20, -1, -1, (mraa_pincapabilities_t){1,0,0,0,0,0,0,0}, "GND");
    mraa_radxa_rock_4d_pininfo(b, 21, 1, 14, (mraa_pincapabilities_t){1,1,0,0,1,0,0,1}, "GPIO1_B6");
    mraa_radxa_rock_4d_pininfo(b, 22, 2, 31, (mraa_pincapabilities_t){1,1,1,0,0,0,0,0}, "GPIO2_D7");
    mraa_radxa_rock_4d_pininfo(b, 23, 1, 12, (mraa_pincapabilities_t){1,1,1,0,1,1,0,0}, "GPIO1_B4");
    mraa_radxa_rock_4d_pininfo(b, 24, 1, 15, (mraa_pincapabilities_t){1,1,0,0,1,0,0,1}, "GPIO1_B7");
    mraa_radxa_rock_4d_pininfo(b, 25, -1, -1, (mraa_pincapabilities_t){1,0,0,0,0,0,0,0}, "GND");
    mraa_radxa_rock_4d_pininfo(b, 26, 1, 16, (mraa_pincapabilities_t){1,1,1,0,1,0,0,1}, "GPIO1_C0");
    mraa_radxa_rock_4d_pininfo(b, 27, 4, 23, (mraa_pincapabilities_t){1,1,1,0,0,1,0,0}, "GPIO4_C7");
    mraa_radxa_rock_4d_pininfo(b, 28, 4, 22, (mraa_pincapabilities_t){1,1,1,0,0,1,0,0}, "GPIO4_C6");
    mraa_radxa_rock_4d_pininfo(b, 29, 3, 2, (mraa_pincapabilities_t){1,1,0,0,0,0,0,0}, "GPIO3_A2");
    mraa_radxa_rock_4d_pininfo(b, 30, -1, -1, (mraa_pincapabilities_t){1,1,0,0,0,0,0,0}, "GND");
    mraa_radxa_rock_4d_pininfo(b, 31, 1, 17, (mraa_pincapabilities_t){1,1,0,0,0,0,0,1}, "GPIO1_C1");
    mraa_radxa_rock_4d_pininfo(b, 32, 1, 29, (mraa_pincapabilities_t){1,1,0,0,1,1,0,1}, "GPIO1_D5");
    mraa_radxa_rock_4d_pininfo(b, 33, 1, 18, (mraa_pincapabilities_t){1,1,1,0,1,1,0,1}, "GPIO1_C2");
    mraa_radxa_rock_4d_pininfo(b, 34, -1, -1, (mraa_pincapabilities_t){1,1,0,0,0,0,0,0}, "GND");
    mraa_radxa_rock_4d_pininfo(b, 35, 1, 26, (mraa_pincapabilities_t){1,1,1,0,0,0,0,0}, "GPIO1_D2");
    mraa_radxa_rock_4d_pininfo(b, 36, 1, 28, (mraa_pincapabilities_t){1,1,0,0,0,1,0,1}, "GPIO1_D4");
    mraa_radxa_rock_4d_pininfo(b, 37, 3, 3, (mraa_pincapabilities_t){1,1,0,0,0,0,0,0}, "GPIO3_A3");
    mraa_radxa_rock_4d_pininfo(b, 38, 1, 27, (mraa_pincapabilities_t){1,1,1,0,0,0,0,0}, "GPIO1_D3");
    mraa_radxa_rock_4d_pininfo(b, 39, -1, -1, (mraa_pincapabilities_t){1,1,0,0,0,0,0,0}, "GND");
    mraa_radxa_rock_4d_pininfo(b, 40, 1, 24, (mraa_pincapabilities_t){1,1,0,0,0,0,0,1}, "GPIO1_D0");

    return b;
}
