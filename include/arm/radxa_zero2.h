/*
 * Author: Nascs <nascs@radxa.com>
 * Copyright (c) Radxa Limited.
 *
 * SPDX-License-Identifier: MIT
 */

#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include "mraa_internal.h"

#define MRAA_RADXA_ZERO2_GPIO_COUNT 27
#define MRAA_RADXA_ZERO2_I2C_COUNT  3
#define MRAA_RADXA_ZERO2_SPI_COUNT  1
#define MRAA_RADXA_ZERO2_UART_COUNT 3
#define MRAA_RADXA_ZERO2_PWM_COUNT  4
#define MRAA_RADXA_ZERO2_AIO_COUNT  1
#define MRAA_RADXA_ZERO2_PIN_COUNT  40
#define PLATFORM_NAME_RADXA_ZERO2   "Radxa Zero2"


mraa_board_t *
        mraa_radxa_zero2();

#ifdef __cplusplus
}
#endif


typedef struct {
    /*@{*/
    mraa_boolean_t valid:1;     /**< Is the pin valid at all */
    mraa_boolean_t gpio:1;      /**< Is the pin gpio capable */
    mraa_boolean_t pwm:1;       /**< Is the pin pwm capable */
    mraa_boolean_t fast_gpio:1; /**< Is the pin fast gpio capable */

    mraa_boolean_t spi:1;       /**< Is the pin spi capable */
    mraa_boolean_t i2c:1;       /**< Is the pin i2c capable */
    mraa_boolean_t aio:1;       /**< Is the pin analog input capable */
    mraa_boolean_t uart:1;       /**< Is the pin uart capable */
    /*@}*/
} mraa_pincapabilities_t;
