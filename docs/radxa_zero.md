Radxa ZERO {#_Radxa}
====================

Radxa ZERO is a Amlogic S905Y2 based SBC(Single Board Computer) by Radxa. It can run Linux. Radxa ZERO features a four core ARM processor,

Interface notes
---------------

- UART2 is enabled as the default console.
- All UART ports support baud up to 1500000.

Pin Mapping
-----------

Radxa ZERO has a 40-pin expansion header. Each pin is distinguished by the color.

|Function6     |Function5    |Function4    |Function3     |Function2     |Function1 |  PIN  |  PIN  | Function1|    Function2|    Function3|    Function4|    Function5|    Function6|
|------------- |-------------|-------------|--------------|--------------|----------|:------|------:|----------|-------------|-------------|-------------|-------------|-------------|
|              |             |             |              |              |+3.3V     |   1   |   2   |     +5.0V|             |             |             |             |             |
|              |             |             |              |I2C_EE_M3_SDA |GPIOA_14  |   3   |   4   |     +5.0V|             |             |             |             |             |
|              |             |             |              |I2C_EE_M3_SCL |GPIOA_15  |   5   |   6   |       GND|             |             |             |             |             |
|              |             |UART_AO_B_RX |I2C_AO_S0_SDA |I2C_AO_M0_SDA |GPIOAO_3  |   7   |   8   |  GPIOAO_0|             |             |UART_AO_A_TXD|             |             |
|              |             |             |              |              |GND       |   9   |   10  |  GPIOAO_1|             |             |UART_AO_A_RXD|   SPI_A_MISO|             |
|              |             |UART_AO_B_TX |I2C_AO_S0_SCL |I2C_AO_M0_SCL |GPIOAO_2  |   11  |   12  |   GPIOX_9|             |             |             |             |             |
|              |SPI_A_SCLK   |             |              |I2C_EE_M1_SCL |GPIOX_11  |   13  |   14  |       GND|             |             |             |             |             |
|              |             |             |              |              |SARADC_CH1|   15  |   16  |  GPIOX_10|I2C_EE_M1_SDA|             |             |    SPI_A_SS0|             |
|              |             |             |              |              |+3.3V     |   17  |   18  |   GPIOX_8|             |             |             |   SPI_A_MOSI|        PWM_C|
|              |SPI_B_MOSI   |             |              |              |GPIOH_4   |   19  |   20  |       GND|             |             |             |             |             |
|PWM_F         |SPI_B_MISO   |             |              |              |GPIOH_5   |   21  |   22  |   GPIOC_7|             |             |             |             |             |
|              |SPI_B_SCLK   |UART_EE_C_TX |              |I2C_EE_M1_SCL |GPIOH_7   |   23  |   24  |   GPIOH_6|I2C_EE_M1_SDA|             | UART_EE_C_RX|    SPI_B_SS0|             |
|              |             |             |              |              |GND       |   25  |   26  |SARADC_CH2|             |             |             |             |             |
|              |             |UART_AO_B_RX |I2C_AO_S0_SDA |I2C_AO_M0_SDA |GPIOAO_3  |   27  |   28  |  GPIOAO_2|I2C_AO_M0_SCL|I2C_AO_S0_SCL| UART_AO_B_TX|             |             |
|              |             |             |              |              |NC        |   29  |   30  |       GND|             |             |             |             |             |
|              |             |             |              |              |NC        |   31  |   32  |  GPIOAO_4|             |             |             |             |      PWMAO_C|
|              |             |             |              |              |NC        |   33  |   34  |       GND|             |             |             |             |             |
|              |             |UART_AO_B_TX |              |              |GPIOAO_8  |   35  |   36  |   GPIOH_8|             |             |             |             |             |
|              |             |UART_AO_B_RX |              |              |GPIOAO_9  |   37  |   38  | GPIOAO_10|             |             |             |             |      PWMAO_D|
|              |             |             |              |              |GND       |   39  |   40  | GPIOAO_11|             |             |             |             |      PWMAO_A|

Supports
--------

You can find additional product support in the following channels:

- [Product Info](https://docs.radxa.com/en/zero/zero)
- [Forums](https://forum.radxa.com/c/zero)
- [Github](https://github.com/radxa)
