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

#define MRAA_RADXA_ROCK_PI_S_GPIO_COUNT 28
#define MRAA_RADXA_ROCK_PI_S_I2C_COUNT  3
#define MRAA_RADXA_ROCK_PI_S_SPI_COUNT  2
#define MRAA_RADXA_ROCK_PI_S_UART_COUNT 4
#define MRAA_RADXA_ROCK_PI_S_PWM_COUNT  2
#define MRAA_RADXA_ROCK_PI_S_AIO_COUNT  2
#define MRAA_RADXA_ROCK_PI_S_PIN_COUNT  52
#define PLATFORM_NAME_RADXA_ROCK_PI_S   "Radxa ROCK Pi S"

mraa_board_t *
        mraa_radxa_rock_pi_s();

#ifdef __cplusplus
}
#endif
