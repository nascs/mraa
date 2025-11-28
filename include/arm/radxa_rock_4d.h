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

#define MRAA_RADXA_ROCK_4D_GPIO_COUNT 28
#define MRAA_RADXA_ROCK_4D_I2C_COUNT  4
#define MRAA_RADXA_ROCK_4D_SPI_COUNT  2
#define MRAA_RADXA_ROCK_4D_UART_COUNT 6
#define MRAA_RADXA_ROCK_4D_PWM_COUNT  3
#define MRAA_RADXA_ROCK_4D_AIO_COUNT  0
#define MRAA_RADXA_ROCK_4D_PIN_COUNT  40
#define PLATFORM_NAME_RADXA_ROCK_4D   "Radxa ROCK 4D"
#define PLATFORM_NAME_RADXA_ROCK_4D_SPI   "Radxa ROCK 4D SPI"

mraa_board_t *
    mraa_radxa_rock_4d();

#ifdef __cplusplus
}
#endif
