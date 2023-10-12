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

#define MRAA_RADXA_CM5_RPI_CM4_IO_GPIO_COUNT 25
#define MRAA_RADXA_CM5_RPI_CM4_IO_I2C_COUNT  3
#define MRAA_RADXA_CM5_RPI_CM4_IO_SPI_COUNT  1
#define MRAA_RADXA_CM5_RPI_CM4_IO_UART_COUNT 3
#define MRAA_RADXA_CM5_RPI_CM4_IO_PWM_COUNT  7
#define MRAA_RADXA_CM5_RPI_CM4_IO_AIO_COUNT  0
#define MRAA_RADXA_CM5_RPI_CM4_IO_PIN_COUNT  40
#define PLATFORM_NAME_RADXA_CM5_RPI_CM4_IO   "Radxa CM5 RPI CM4 IO"

mraa_board_t *
        mraa_radxa_cm5_rpi_cm4_io();

#ifdef __cplusplus
}
#endif
