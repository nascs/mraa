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

#define MRAA_RADXA_NX5_IO_GPIO_COUNT 26
#define MRAA_RADXA_NX5_IO_I2C_COUNT  3
#define MRAA_RADXA_NX5_IO_SPI_COUNT  2
#define MRAA_RADXA_NX5_IO_UART_COUNT 5
#define MRAA_RADXA_NX5_IO_PWM_COUNT  7
#define MRAA_RADXA_NX5_IO_AIO_COUNT  0
#define MRAA_RADXA_NX5_IO_PIN_COUNT  40
#define PLATFORM_NAME_RADXA_NX5_IO   "Radxa NX5 IO"

mraa_board_t *
    mraa_radxa_nx5_io();

#ifdef __cplusplus
}
#endif
