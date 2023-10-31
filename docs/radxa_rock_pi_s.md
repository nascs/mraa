Radxa ROCK PI S {#_Radxa}
===============

Radxa ROCK PI S is a Rockchip RK3308 based SBC(Single Board Computer) by Radxa. It can run Linux. Radxa ROCK PI S features a four core ARM processor. It equips a 64bits quad core processor, USB, ethernet, wireless connectivity and voice detection engine at the size of 1.7 inch, make it perfect for IoT and voice applications. ROCK Pi S comes in two ram sizes 256MB or 512MB DDR3, and uses uSD card for OS and storage. Optionally, ROCK Pi S can provide on board storage version with 1Gb/2Gb/4Gb/8Gb NAND flash.

Interface notes
---------------

- UART0 is enabled as the default console.
- All UART ports support baud up to 1500000.

Pin Mapping
-----------

Radxa ROCK PI S has a 40-pin expansion header. Each pin is distinguished by the color.

|    Function3|   Function3|       Function2|    Function1|  PIN  |  PIN  |  Fun-ction1|        Function2|    Function3|    Function4|
|-------------|------------|----------------|-------------|:------|------:|------------|-----------------|-------------|-------------|
|             |            |                | +3.3V       |   1   |   2   |      +5.0V |                 |             |             |
|             |            | I2C1_SDA       | GPIO0_B3    |   3   |   4   |      +5.0V |                 |             |             |
|             |            | I2C1_SCL       | GPIO0_B4    |   5   |   6   |        GND |                 |             |             |
|             |            |                | GPIO2_A4    |   7   |   8   |   GPIO2_A1 |        UART0_TX |   SPI0_MOSI |             |
|             |            |                | GND         |   9   |   10  |   GPIO2_A0 |        UART0_RX |   SPI0_MISO |             |
|             | I2C3_SDA_M0| PWM2           | GPIO0_B7    |   11  |   12  |   GPIO2_A5 |                 |             |             |
|             | I2C3_SCL_M0| PWM3           | GPIO0_C0    |   13  |   14  |        GND |                 |             |             |
|             |            |                | GPIO0_C1    |   15  |   16  |   GPIO2_B2 |                 |             |             |
|             |            |                | +3.3V       |   17  |   18  |   GPIO2_B1 |                 |             |             |
| SPI2_MOSI   | UART2_TX_M0| UART1_RTSN     | GPIO1_C7    |   19  |   20  |        GND |                 |             |             |
| SPI2_MISO   | UART2_RX_M0| UART1_CTSN     | GPIO1_C6    |   21  |   22  |   GPIO2_A7 |                 |             |             |
| SPI2_CLK    | I2C0_SDA   | UART1_RX       | GPIO1_D0    |   23  |   24  |   GPIO1_D1 |        UART1_TX |    I2C0_SCL |   SPI2_CSN0 |
|             |            |                | GND         |   25  |   26  |    ADC_IN0 |                 |             |             |
|             |            |                | GND         |   27  |   28  |   GPIO2_B5 |                 |             |             |
|             |            |                | ADC_KEY_IN1 |   29  |   30  |   GPIO2_B6 |                 |             |             |
|             |            |                | MICBIAS2    |   31  |   32  |   GPIO2_B7 |                 |             |             |
|             |            |                | MICBIAS1    |   33  |   34  |   GPIO2_C0 |                 |             |             |
|             |            |                | MICN8       |   35  |   36  |      MCIP8 |                 |             |             |
|             |            |                | MICN7       |   37  |   38  |      MCIP7 |                 |             |             |
| UART3_TX    | I2C3_SCL_M1| SPI1_CSN0      | GPOI3_B5    |   39  |   40  |   GPOI3_B4 |       SPI1_MOSI | I2C3_SDA_M1 |    UART3_RX |
|             |            | SPI1_CLK       | GPOI3_B3    |   41  |   42  |   GPOI3_B2 |       SPI1_MISO |             |             |
|             |            |                | GPIO2_B4    |   43  |   44  |   GPIO2_B3 |                 |             |             |
|             |            |                | GPIO2_B0    |   45  |   46  |   GPIO2_A6 |                 |             |             |
|             |            |                | MICN2       |   47  |   48  |     MCIP2  |                 |             |             |
|             |            |                | MICN1       |   49  |   50  |     MCIP1  |                 |             |             |
|             |            |                | LINEOUT_R   |   51  |   52  |  LINEOUT_L |                 |             |             |

Supports
--------

You can find additional product support in the following channels:

- [Product Info](https://docs.radxa.com/en/rockpis)
- [Forums](https://forum.radxa.com/c/rockpiS)
- [Github](https://github.com/radxa)
