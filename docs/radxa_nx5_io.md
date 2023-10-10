Radxa NX5 IO {#_Radxa}
============

Radxa NX5 IO is a Rockchip RK3588s based SBC(Single Board Computer) by Radxa. It can run android or some Linux distributions. Radxa NX5 IO features a eight core ARM processor, 64bit dual channel 3200Mb/s LPDDR4, up to 8Kp60 HDMI, MIPI DSI, MIPI CSI, 3.5mm jack with mic, 802.11 ac WIFI, Bluetooth 5.0, USB Port, GbE LAN, 40-pin color expansion header, RTC. Also, Radxa NX5 IO supports USB PD and QC powering.

Interface notes
---------------

- UART2 is enabled as the default console.
- All UART ports support baud up to 1500000.
- Pin 7's IO is occupied by pwm-fan, function GPIO/PWM can't be used.
- Pin 13's IO is occupied by hym8563 rtc, function GPIO/UART can't be used.

Pin Mapping
-----------

Radxa NX5 IO has a 40-pin expansion header. Each pin is distinguished by color.

|Function5   |Function4   |Function3   |Function2   |Function1|       |  PIN  |  PIN    |   Function1|  Function2|   Function3|   Function4|
|------------|------------|------------|------------|---------|:------|------:|---------|------------|-----------|------------|------------|
|            |            |            |            |+3.3V    |   1   |   2   |    +5.0V|            |           |            |            |
|            |SPI3_CS0_M2 |PWM3_IR_M0  |I2C1_SCL_M2 |GPIO0_D4 |   3   |   4   |    +5.0V|            |           |            |            |
|            |            |SPI3_CS1_M2 |I2C1_SDA_M2 |GPIO0_D5 |   5   |   6   |      GND|            |           |            |            |
|            |UART9_RX_M1 |SPI3_MISO_M1|PWM12_M1    |GPIO4_B5 |   7   |   8   | GPIO0_B5| UART2_TX_M0|I2C1_SCL_M0|            |            |
|            |            |            |            |GND      |   9   |   10  | GPIO0_B6| UART2_RX_M0|I2C1_SDA_M0|            |            |
|            |            |SPI0_MOSI_M3|I2C7_SCL_M2 |GPIO3_D2 |   11  |   12  | GPIO1_C3| I2C6_SCL_M1| PWM7_IR_M2| SPI4_CS0_M0|            |
|UART4_TX_M0 |SPI1_CLK_M2 |PWM0_M1     |I2C1_SCL_M4 |GPIO1_D2 |   13  |   14  |      GND|            |           |            |            |
|            |UART0_RX_M1 |SPI2_CS1_M2 |I2C1_SCL_M1 |GPIO0_B0 |   15  |   16  | GPIO1_D5| SPI1_CS1_M2|           |            |            |
|            |            |            |            |+3.3     |   17  |   18  | GPIO1_D3| I2C1_SDA_M4|    PWM1_M1| SPI1_CS0_M2| UART4_RX_M0|
|            |            |UART4_RX_M2 |SPI0_MOSI_M2|GPIO1_B2 |   19  |   20  |      GND|            |           |            |            |
|            |            |            |SPI0_MISO_M2|GPIO1_B1 |   21  |   22  | GPIO1_D0| I2C7_SCL_M0|UART6_TX_M2|SPI1_MISO_M2|            |
|            |            |UART4_TX_M2 |SPI0_CLK_M2 |GPIO1_B3 |   23  |   24  | GPIO1_B4| SPI0_CS0_M2|UART7_RX_M2|            |            |
|            |            |            |            |     GND |   25  |   26  | GPIO1_B5| SPI0_CS1_M2|UART7_TX_M2|            |            |
|            |UART1_RX_M2 |SPI3_MOSI_M2|I2C0_SDA_M2 |GPIO0_D2 |   27  |   28  | GPIO0_D1| I2C0_SCL_M2|SPI0_CS0_M0| UART1_TX_M2|            |
|            |SPI3_MOSI_M1|PWM13_M1    |I2C5_SCL_M1 |GPIO4_B6 |   29  |   30  |      GND|            |           |            |            |
|            |            |            |            |GPIO0_A0 |   31  |   32  | GPIO4_B3| I2C7_SDA_M3|PWM15_IR_M1|            |            |
|            |UART6_TX_M1 |SPI4_MOSI_M2|I2C2_SCL_M4 |GPIO1_A1 |   33  |   34  |      GND|            |           |            |            |
|            |            |            |I2C2_SCL_M3 |GPIO1_C5 |   35  |   36  | GPIO3_D3| I2C7_SDA_M2|   PWM10_M2| SPI0_CLK_M3|            |
|            |UART6_RX_M2 |SPI1_MOSI_M2|I2C7_SDA_M0 |GPIO1_D1 |   37  |   38  | GPIO1_D4|            |           |            |            |
|            |            |            |            |GND      |   39  |   40  | GPIO1_C7| I2C4_SCL_M4|           |            |            |

Resources
---------

You can find additional product support in the following channels:

- [Product Info](https://docs.radxa.com/en/rock5/nx5-io)
- [Forums](https://forum.radxa.com/c/rock5)
- [Github](https://github.com/radxa)
