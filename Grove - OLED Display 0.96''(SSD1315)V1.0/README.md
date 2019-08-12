

# Grove - OLED Display 0.96''(SSD1315)V1.0

This example applies to the following products, All examples depend  on [U8g2](https://github.com/olikraus/U8g2_Arduino). Please import this libraries.

## Import 

Choose any of the following

-  Directly search the U8g2 installation in the library management of Arduino IDE.
- Making download on [Here](https://github.com/olikraus/U8g2_Arduino) , then unzip into Arduino libraries folder.

## Usage

You can use all the examples provided by U8g2. Here's how to construct an instance then make Grove - OLED Display 0.96''(SSD1315)V1.0 work.

- Use hardware I2C port

```c
U8G2_SSD1306_128X64_NONAME_1_HW_I2C u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE);
```

- Use software I2C port

```C
U8G2_SSD1306_128X64_NONAME_1_SW_I2C u8g2(U8G2_R0, /* SCL= */ 2, /* SDA= */3, /* reset=*/ U8X8_PIN_NONE);
```

## More

- [U8g2 WiKi](https://github.com/olikraus/u8g2/wiki)
- [U8g2 Reference Manual](https://github.com/olikraus/u8g2/wiki/u8g2reference)

