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

#define MRAA_RADXA_ZERO3_GPIO_COUNT 27
#define MRAA_RADXA_ZERO3_I2C_COUNT  2
#define MRAA_RADXA_ZERO3_SPI_COUNT  1
#define MRAA_RADXA_ZERO3_UART_COUNT 5
#define MRAA_RADXA_ZERO3_PWM_COUNT  7
#define MRAA_RADXA_ZERO3_AIO_COUNT  0
#define MRAA_RADXA_ZERO3_PIN_COUNT  40
#define PLATFORM_NAME_RADXA_ZERO3   "Radxa ZERO 3"

mraa_board_t *
        mraa_radxa_zero3();

#ifdef __cplusplus
}
#endif
