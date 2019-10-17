

# Grove - OLED Display 0.96''(SSD1315)V1.0

This example applies to the following products, All examples depend  on [U8g2](https://github.com/olikraus/U8g2_Arduino). Please import this libraries.

## Import 

Choose any of the following

-  Directly search the U8g2 installation in the library management of Arduino IDE.
- Making download on [Here](https://github.com/olikraus/U8g2_Arduino) , then unzip into Arduino libraries folder.

## Notic

**If you are working on a project in Arduino UNO (Ateml 328p), you can only use the software I2C port.**

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

more settings and description:

| Controller "ssd1306", Display "128x64_noname"                | Descirption                         |
| ------------------------------------------------------------ | ----------------------------------- |
| U8G2_SSD1306_128X64_NONAME_1_SW_I2C(rotation, clock, data [, reset]) | page buffer, size = 128 bytes       |
| U8G2_SSD1306_128X64_NONAME_2_SW_I2C(rotation, clock, data [, reset]) | page buffer, size = 256 bytes       |
| U8G2_SSD1306_128X64_NONAME_F_SW_I2C(rotation, clock, data [, reset]) | full framebuffer, size = 1024 bytes |
| U8G2_SSD1306_128X64_NONAME_1_HW_I2C(rotation, [reset [, clock, data]]) | page buffer, size = 128 bytes       |
| U8G2_SSD1306_128X64_NONAME_2_HW_I2C(rotation, [reset [, clock, data]]) | page buffer, size = 256 bytes       |
| U8G2_SSD1306_128X64_NONAME_F_HW_I2C(rotation, [reset [, clock, data]]) | full framebuffer, size = 1024 bytes |
| U8G2_SSD1306_128X64_NONAME_1_2ND_HW_I2C(rotation, [reset])   | page buffer, size = 128 bytes       |
| U8G2_SSD1306_128X64_NONAME_2_2ND_HW_I2C(rotation, [reset])   | page buffer, size = 256 bytes       |
| U8G2_SSD1306_128X64_NONAME_F_2ND_HW_I2C(rotation, [reset])   | full framebuffer, size = 1024 bytes |

##### Page buffer usage

```C
  u8g2.firstPage();
  do {
     //draw some you want; such as 
    u8g2.setFont(u8g2_font_ncenB10_tr);
    u8g2.drawStr(0,24,"Hello World!");
  } while ( u8g2.nextPage() );
```



##### Frame buffer usage

```C
  u8g2.clearBuffer();          // clear the internal memory

  //draw some you want; such as 
  u8g2.setFont(u8g2_font_ncenB10_tr);

  u8g2.drawStr(0,10,"Hello World!");  // write something to the internal memory

  u8g2.sendBuffer(); 
```

## More

- [U8g2 WiKi](https://github.com/olikraus/u8g2/wiki)
- [U8g2 Reference Manual](https://github.com/olikraus/u8g2/wiki/u8g2reference)

