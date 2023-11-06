Radxa S0 {#_Radxa}
========

Radxa S0 is a Rockchip RK3566 based SBC(Single Board Computer) by Radxa. It can run Linux.

Interface notes
---------------

- UART2 is enabled as the default console.
- All UART ports support baud up to 1500000.
- Pin 3 & 5 are connected to the 3.3V supply through a 2.2K pull-up resistor to support I2C function. As such they cannot be used as GPIO.

Pin Mapping
-----------

Radxa S0 has a 40-pin expansion header. Each pin is distinguished by the color.

|    Function3|  Function3|    Function2| Function1|  PIN  |  PIN  | Function1|    Function2| Function3|   Function4|   Function4|
|-------------|-----------|-------------|----------|:------|------:|----------|-------------|----------|------------|------------|
|             |           |             |       3V3|   1   |   2   |     +5.0V|             |          |            |            |
|             |I2C3_SDA_M0|  UART3_RX_M0|  GPIO0_D1|   3   |   4   |     +5.0V|             |          |            |            |
|             |I2C3_SCL_M0|  UART3_TX_M0|  GPIO1_A1|   5   |   6   |       GND|             |          |            |            |
|             |           |     PWM14_M0|  GPIO3_C4|   7   |   8   |  GPIO2_A1|    SPI0_MOSI|  UART0_TX|            |            |
|             |           |             |       GND|   9   |   10  |  GPIO2_A0|    SPI0_MISO|  UART0_RX| I2C3_SDA_M2|            |
|             |           |             |  GPIO3_A1|   11  |   12  |  GPIO2_B1| SPI1_CSN0_M1|          |            |            |
|             |           |             |  GPIO3_A2|   13  |   14  |       GND|             |          |            |            |
|             |           |             |  GPIO3_B0|   15  |   16  |  GPIO0_A1|             |          |            |        PWM4|
|             |           |             |     +3.3V|   17  |   18  |  GPIO2_B7|             |          |            |            |
|             |PWM15_IR_M1| SPI3_MOSI_M1|  GPIO4_C3|   19  |   20  |       GND|             |          |            |            |
|  UART9_TX_M1|   PWM12_M1| SPI3_MISO_M1|  GPIO4_C5|   21  |   22  |  GPIO2_B3|             |          |            |        PWM9|
|             |           |  SPI3_CLK_M1|  GPIO4_C2|   23  |   24  |  GPIO1_D1|    SPI2_CSN0|  UART1_TX|    I2C0_SCL|            |
|             |           |             |       GND|   25  |   26  |  GPIO2_B0|             |          |            |        PWM7|
|             |           |  I2C4_SDA_M0|  GPIO4_B2|   27  |   28  |  GPIO0_C0|             |          | I2C3_SCL_M0|        PWM3|
|             |           |             |  GPIO3_B3|   29  |   30  |       GND|             |          |            |            |
|             |           |             |  GPIO3_B4|   31  |   32  |  GPIO2_B4|             |          |            |       PWM10|
|             |           |  UART5_RX_M1|  GPIO3_C3|   33  |   34  |       GND|             |          |            |            |
|             |           |             |  GPIO3_A4|   35  |   36  |  GPIO2_A6|             |          |            |            |
|             |           |             |  GPIO1_A4|   37  |   38  |  GPIO2_A5| SPI1_MOSI_M1|          |            |            |
|             |           |             |       GND|   39  |   40  |  GPIO2_A5|  SPI1_CLK_M1|          |            |            |

Supports
--------

You can find additional product support in the following channels:

- [Product Info](https://docs.radxa.com/en/rocks)
- [Forums](https://forum.radxa.com/c/rockpiS)
- [Github](https://github.com/radxa)
