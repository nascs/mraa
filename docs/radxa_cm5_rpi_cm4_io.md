Radxa CM5 RPI CM4 IO {#_Radxa}
============

Radxa CM5 RPI CM4 IO is a Rockchip RK3588s based SBC(Single Board Computer) by Radxa. It can run android or some Linux distributions. Radxa CM5 RPI CM4 IO features a eight core ARM processor, 64bit dual channel 3200Mb/s LPDDR4, up to 8Kp60 HDMI, MIPI DSI, MIPI CSI, 3.5mm jack with mic, 802.11 ac WIFI, Bluetooth 5.0, USB Port, GbE LAN, 40-pin color expansion header, RTC. Also, Radxa CM5 RPI CM4 IO supports USB PD and QC powering.

Interface notes
---------------

- UART2 is enabled as the default console.
- All UART ports support baud up to 1500000.
- 

Pin Mapping
-----------

Radxa CM5 RPI CM4 IO has a 40-pin expansion header. Each pin is distinguished by color.

|Function4    |Function4   |Function3   |Function2   |Function1  |       |  PIN  |  PIN    |   Function1|  Function2|   Function3|   Function4|
|-------------|------------|------------|------------|-----------|:------|------:|---------|------------|-----------|------------|------------|
|             |            |            |            |+3.3V      |   1   |   2   |    +5.0V|            |           |            |            |
|             |            |I2C6_SCL_M0 |PWM7_IR_M0  |GPIO0_D0   |   3   |   4   |    +5.0V|            |           |            |            |
|             |            |I2C6_SDA_M0 |PWM6_M0     |GPIO0_C7   |   5   |   6   |      GND|            |           |            |            |
|             |            |            |            |GPIO1_D4   |   7   |   8   | GPIO0_B5| UART2_TX_M0|I2C1_SCL_M0|            |            |
|             |            |            |            |GND        |   9   |  10   | GPIO0_B6| UART2_RX_M0|I2C1_SDA_M0|            |            |
|             |            |            |PWM3_IR_M2  |GPIO1_C2   |  11   |  12   | GPIO1_A3|            |I2C4_SCL_M3|            |            |
|             |            |            |            |GPIO1_C5   |  13   |  14   |      GND|            |           |            |            |
|             |            |            |            |GPIO1_C3   |  15   |  16   | GPIO1_A7|            |           |            |  PWM3_IR_M3|
|             |            |            |            |+3.3V      |  17   |  18   | GPIO1_A6|            |           |            |            |
|UART4_RX_M2  |SPI0_MOSI_M2|            |            |GPIO1_B2   |  19   |  20   |      GND|            |           |            |            |
|             |SPI0_MISO_M2|            |            |GPIO1_B1   |  21   |  22   | GPIO1_B0|            |           |            |            |
|UART4_TX_M2  |SPI0_CLK_M2 |            |            |GPIO1_B3   |  23   |  24   | GPIO1_B4| UART7_RX_M2|           | SPI0_CS0_M2|            |
|             |            |            |            |GND        |  25   |  26   | GPIO1_B5| UART7_TX_M2|           | SPI0_CS1_M2|            |
|             |            |            |            |+3.3V      |  27   |  28   |    +3.3V|            |           |            |            |
|             |            |            |PWM15_IR_M3 |GPIO1_D7   |  29   |  30   |      GND|            |           |            |            |
|             |            |            |            |GPIO1_C7   |  31   |  32   | GPIO4_B2|            |           |            |    PWM14_M1|
|             |            |            |            |GPIO4_A2   |  33   |  34   |      GND|            |           |            |            |
|             |            |            |            |GPIO4_A1   |  35   |  36   | GPIO1_A4|            |           |            |            |
|             |            |            |PWM8_M2     |GPIO3_D0   |  37   |  38   | GPIO1_A1|            |           |            |            |
|             |            |            |            |GND        |  39   |  40   | GPIO1_A2|            |I2C4_SDA_M3|            |     PWM0_M2|

Resources
---------

You can find additional product support in the following channels:

- [Product Info](https://docs.radxa.com/en/rock5/cm5-io)
- [Forums](https://forum.radxa.com/c/rock5)
- [Github](https://github.com/radxa)
