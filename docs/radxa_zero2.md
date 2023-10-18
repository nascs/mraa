Radxa Zero2 {#_Radxa}
===========

Radxa Zero2 is a Amlogic A311D based SBC(Single Board Computer) by Radxa. It can run Android or Linux. 

Interface notes
---------------

- UART2 is enabled as the default console.
- All UART ports support baud up to 115200.

Pin Mapping
-----------

Radxa Zero2 has a 40-pin expansion header. Each pin is distinguished by the color.

|    Function4|    Function3|  Function3|    Function2| Function1|  PIN  |  PIN  | Function1|    Function2| Function3|   Function4|   Function5|
|-------------|-------------|-----------|-------------|----------|:------|------:|----------|-------------|----------|------------|------------|
|             |             |           |             |       3V3|   1   |   2   |     +5.0V|             |          |            |            |
|             |             |           |I2C_EE_M3_SDA|  GPIOA_14|   3   |   4   |     +5.0V|             |          |            |            |
|             |             |           |I2C_EE_M3_SCL|  GPIOA_15|   5   |   6   |       GND|             |          |            |            |
|             |             |PWM_D      |             |   GPIOZ_2|   7   |   8   |  GPIOAO_0|             |          |UART_AO_A_TX|            |
|             |             |           |             |       GND|   9   |   10  |  GPIOAO_1|             |          |UART_AO_A_RX|            |
|             |             |           |             |   GPIOZ_3|   11  |   12  |   GPIOA_1|             |          |            |            |
|             |             |           |             |   GPIOZ_4|   13  |   14  |       GND|             |          |            |            |
|             |             |           |             |   GPIOZ_5|   15  |   16  |   GPIOZ_8|             |          |            |            |
|             |             |           |             |     +3.3V|   17  |   18  |   GPIOZ_6|             |          |            |            |
|             |SPI_B_MOSI   |           |             |   GPIOH_4|   19  |   20  |       GND|             |          |            |            |
|             |SPI_B_MISO   |           |             |   GPIOH_5|   21  |   22  |   GPIOZ_9|             |          |            |            |
|UART_EE_C_TX |             |           |             |   GPIOH_7|   23  |   24  |   GPIOH_6|I2C_EE_M1_SDA|          |UART_EE_C_RX|   SPI_B_SS0|
|             |             |           |             |       GND|   25  |   26  |SARADC_CH2|             |          |            |            |
|             |             |PWM_B      |I2C_EE_M0_SDA|   GPIOZ_0|   27  |   28  |   GPIOZ_1|I2C_EE_M0_SCL|     PWM_C|            |            |
|             |             |           |             |  GPIOAO_7|   29  |   30  |       GND|             |          |            |            |
|             |             |PWM_D      |             |   GPIOA_4|   31  |   32  |   GPIOA_0|             |          |            |            |
|UART_AO_B_TX |             |           |             |  GPIOAO_8|   33  |   34  |       GND|             |          |            |            |
|             |             |           |             |   GPIOA_2|   35  |   36  |   GPIOA_3|             |          |            |            |
|UART_AO_B_RX |             |           |             |  GPIOAO_9|   37  |   38  |   GPIOA_5|             |          |            |            |
|             |             |           |             |       GND|   39  |   40  |   GPIOZ_7|I2C_EE_M0_SDA|          |            |            |

Supports
--------

You can find additional product support in the following channels:

- [Product Info](https://docs.radxa.com/zero/zero2pro)
- [Forums](https://forum.radxa.com/c/zero)
- [Github](https://github.com/radxa)
