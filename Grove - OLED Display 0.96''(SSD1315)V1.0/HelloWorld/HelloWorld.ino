#include <Arduino.h>
#include <U8g2lib.h>

#ifdef U8X8_HAVE_HW_SPI
#include <SPI.h>
#endif
#ifdef U8X8_HAVE_HW_I2C
#include <Wire.h>
#endif


/*
  U8g2lib Example Overview:
    Frame Buffer Examples: clearBuffer/sendBuffer. Fast, but may not work with all Arduino boards because of RAM consumption
    Page Buffer Examples: firstPage/nextPage. Less RAM usage, should work with all Arduino boards.
    U8x8 Text Only Example: No RAM usage, direct communication with display controller. No graphics, 8x8 Text only.
    
  This is a frame buffer example.    
*/


//U8G2_SSD1306_128X64_NONAME_1_HW_I2C u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE); // if you use Hardware I2C port, page buffer, size = 128Bytes
//U8G2_SSD1306_128X64_NONAME_2_HW_I2C u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE); // if you use Hardware I2C port, page buffer, size = 256Bytes
U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE); // if you use Hardware I2C port, full framebuffer, size = 1024 bytes

//U8G2_SSD1306_128X64_NONAME_1_SW_I2C u8g2(U8G2_R0, /* SCL= */ 2, /* SDA= */3, /* reset=*/ U8X8_PIN_NONE); // if you use software I2C port，page buffer, size = 128Bytes
//U8G2_SSD1306_128X64_NONAME_2_SW_I2C u8g2(U8G2_R0, /* SCL= */ 2, /* SDA= */3, /* reset=*/ U8X8_PIN_NONE); // if you use software I2C port, page buffer, size = 256Bytes
//U8G2_SSD1306_128X64_NONAME_F_SW_I2C u8g2(U8G2_R0, /* SCL= */ 2, /* SDA= */3, /* reset=*/ U8X8_PIN_NONE); // if you use software I2C port, full framebuffer, size = 1024 bytes​

void setup(void) {
  u8g2.begin();
}
void loop(void) {
  u8g2.clearBuffer();          // clear the internal memory
  u8g2.setFont(u8g2_font_ncenB08_tr); // choose a suitable font
  u8g2.drawStr(0,10,"Hello World!");  // write something to the internal memory
  u8g2.setFont(u8g2_font_ncenB18_tr); // choose a suitable font
  u8g2.drawStr(0,40,"Hello World!");  // write something to the internal memory
  u8g2.setFont(u8g2_font_pieceofcake_mel_tr); // choose a suitable font
  u8g2.drawStr(0,60,"Hello World!");  // write something to the internal memory
  u8g2.setCursor(40, 80);
  u8g2.setFont(u8g2_font_ncenB08_tr); // choose a suitable font
  u8g2.print("Hello World!");
  u8g2.setFont(u8g2_font_unifont_t_symbols);
  u8g2.drawGlyph(40, 100, 0x2603);
  u8g2.sendBuffer();          // transfer internal memory to the display
  delay(1000);  
}
