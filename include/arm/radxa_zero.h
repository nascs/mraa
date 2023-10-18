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

#define MRAA_RADXA_ZERO_GPIO_COUNT 23
#define MRAA_RADXA_ZERO_I2C_COUNT  3
#define MRAA_RADXA_ZERO_SPI_COUNT  2
#define MRAA_RADXA_ZERO_UART_COUNT 3
#define MRAA_RADXA_ZERO_PWM_COUNT  4
#define MRAA_RADXA_ZERO_PIN_COUNT  40
#define PLATFORM_NAME_RADXA_ZERO   "Radxa Zero"

mraa_board_t *
        mraa_radxa_zero();

#ifdef __cplusplus
}
#endif
