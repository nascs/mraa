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

#define MRAA_RADXA_ROCK2_GPIO_COUNT 28
#define MRAA_RADXA_ROCK2_I2C_COUNT  2
#define MRAA_RADXA_ROCK2_SPI_COUNT  1
#define MRAA_RADXA_ROCK2_UART_COUNT 3
#define MRAA_RADXA_ROCK2_PWM_COUNT  5
#define MRAA_RADXA_ROCK2_AIO_COUNT  1
#define MRAA_RADXA_ROCK2_PIN_COUNT  40
#define PLATFORM_NAME_RADXA_ROCK_2A   "Radxa ROCK 2A"
#define PLATFORM_NAME_RADXA_ROCK_2F   "Radxa ROCK 2F"

mraa_board_t *
    mraa_radxa_rock2();

#ifdef __cplusplus
}
#endif
