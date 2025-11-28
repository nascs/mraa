Radxa ROCK 4 Model D {#_Radxa}
====================

Radxa ROCK 4 Model D is a Rockchip RK3576 based SBC(Single Board Computer) by Radxa. It can run Android or Linux. Radxa ROCK 4 Model D features a four core ARM processor, 64bit dual channel 2736MHz LPDDR5, HDMI up to 4K60p, MIPI DSI, MIPI CSI, 3.5mm combo audio jack, Wi-Fi 6, Bluetooth 5.0, USB, GbE LAN, and 40-pin color expansion header. Radxa ROCK 4 Model D is powered by the USB Type-C port, and supports 5V input only. The recommended power adapter is 5V/3A without SSD, or 5V/5A with SSD.

Interface notes
---------------

- UART2 is enabled as the default console.
- All UART ports support baud up to 1500000.

Pin Mapping
-----------

Radxa ROCK 4 Model D has a 40-pin expansion header. Each pin is distinguished by the color.

|   Function6   |  Function5  |  Function4   |  Function3  |   Function2   | Function1  |  PIN  |  PIN  | Function1  |     Function2     |   Function3    |  Function4   |  Function5  |   Function6   |
| :-----------: | :---------: | :----------: | :---------: | :-----------: | :--------: |:------|------:| :--------: | :---------------: | :------------: | :----------: | :---------: | :-----------: |
|               |             |              |             |               |    3V3     |   1   |   2   |     5V     |                   |                |              |             |               |
|               |             |              | I2C8_SDA_M1 |  UART2_RX_M0  | GPIO1_C7_d |   3   |   4   |     5V     |                   |                |              |             |               |
|               |             |              | I2C8_SCL_M1 |  UART2_TX_M0  | GPIO1_C6_d |   5   |   6   |    GND     |                   |                |              |             |               |
|               |             | SPI2_CSN0_M1 | I2C6_SDA_M1 | UART4_CTSN_M1 | GPIO1_C3_u |   7   |   8   | GPIO0_D4_u | UART0_TX_M0_DEBUG |                |              |             |               |
|               |             |              |             |               |    GND     |   9   |   10  | GPIO0_D5_u | UART0_RX_M0_DEBUG |                |              |             |               |
| UART2_RTSN_M0 |             | SPI2_MOSI_M1 |             |  UART4_TX_M1  | GPIO1_C4_d |   11  |   12  | GPIO1_D1_d |   UART10_RX_M1    | I3C0_SDA_PU_M1 |              |             |               |
|               | PWM1_CH0_M2 |              |             |               | GPIO2_C0_d |   13  |   14  |    GND     |                   |                |              |             |               |
| UART2_CTSN_M0 |             | SPI2_MISO_M1 |             |  UART4_RX_M1  | GPIO1_C5_d |   15  |   16  | GPIO2_B6_d |    UART7_TX_M0    |  I2C8_SCL_M2   |              |             |               |
|               |             |              |             |               |    3V3     |   17  |   18  | GPIO2_B7_d |    UART7_RX_M0    |  I2C8_SDA_M2   |              |             |               |
|               | PWM1_CH1_M1 | SPI1_MOSI_M0 | I2C9_SCL_M1 |               | GPIO1_B5_d |   19  |   20  |    GND     |                   |                |              |             |               |
|               |             | SPI1_MISO_M0 |             | UART3_CTSN_M2 | GPIO1_B6_d |   21  |   22  | GPIO2_D7_d |                   |                |              | PWM2_CH7_M2 |               |
|               | PWM1_CH0_M1 | SPI1_CLK_M0  | I2C9_SDA_M1 |               | GPIO1_B4_d |   23  |   24  | GPIO1_B7_d |                   |                | SPI1_CSN0_M0 |             | UART3_RTSN_M2 |
|               |             |              |             |               |    GND     |   25  |   26  | GPIO1_C0_d |    UART3_TX_M2    |                | SPI1_CSN1_M0 | PWM0_CH0_M1 |               |
|               | PWM2_CH3_M1 |              | I2C6_SDA_M3 |               | GPIO4_C7_d |   27  |   28  | GPIO4_C6_d |                   |  I2C6_SCL_M3   |              | PWM2_CH2_M1 |  CAN1_TX_M1   |
|               |             |              |             |               | GPIO3_A2_d |   29  |   30  |    GND     |                   |                |              |             |               |
|               |             |              |             |  UART3_RX_M2  | GPIO1_C1_d |   31  |   32  | GPIO1_D5_d |  UART10_CTSN_M1   |  I2C5_SDA_M1   | SPI2_CLK_M1  |             |               |
|               | PWM1_CH2_M1 | SPI2_CSN1_M1 | I2C6_SCL_M1 | UART4_RTSN_M1 | GPIO1_C2_u |   33  |   34  |    GND     |                   |                |              |             |               |
|               | PWM1_CH3_M1 |              | I3C0_SCL_M1 |               | GPIO1_D2_d |   35  |   36  | GPIO1_D4_d |  UART10_RTSN_M1   |  I2C5_SCL_M1   |              |             | PDM0_SDI3_M2  |
|               |             |              |             |               | GPIO3_A3_d |   37  |   38  | GPIO1_D3_d |                   |  I3C0_SDA_M1   |              | PWM1_CH4_M1 |               |
|               |             |              |             |               |    GND     |   39  |   40  | GPIO1_D0_d |   UART10_TX_M1    |                |              |             |               |

Supports
--------

You can find additional product support in the following channels:

- [Product Info](https://docs.radxa.com/en/rock4/rock4d)
- [Forums](https://forum.radxa.com/c/rock4)
- [Github](https://github.com/radxa)
