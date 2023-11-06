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

#define MRAA_RADXA_S0_GPIO_COUNT 28
#define MRAA_RADXA_S0_I2C_COUNT  4
#define MRAA_RADXA_S0_SPI_COUNT  3
#define MRAA_RADXA_S0_UART_COUNT 4
#define MRAA_RADXA_S0_PWM_COUNT  10
#define MRAA_RADXA_S0_AIO_COUNT  0
#define MRAA_RADXA_S0_PIN_COUNT  40
#define PLATFORM_NAME_RADXA_S0   "Radxa S0"

mraa_board_t *
        mraa_radxa_s0();

#ifdef __cplusplus
}
#endif
