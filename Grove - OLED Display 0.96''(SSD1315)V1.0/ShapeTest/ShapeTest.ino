#include <Arduino.h>
#include <U8g2lib.h>

//U8G2_SSD1306_128X64_NONAME_1_HW_I2C u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE); // if you use Hardware I2C port, page buffer, size = 128Bytes
//U8G2_SSD1306_128X64_NONAME_2_HW_I2C u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE); // if you use Hardware I2C port, page buffer, size = 256Bytes
U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE); // if you use Hardware I2C port, full framebuffer, size = 1024 bytes

//U8G2_SSD1306_128X64_NONAME_1_SW_I2C u8g2(U8G2_R0, /* SCL= */ 2, /* SDA= */3, /* reset=*/ U8X8_PIN_NONE); // if you use software I2C port，page buffer, size = 128Bytes
//U8G2_SSD1306_128X64_NONAME_2_SW_I2C u8g2(U8G2_R0, /* SCL= */ 2, /* SDA= */3, /* reset=*/ U8X8_PIN_NONE); // if you use software I2C port, page buffer, size = 256Bytes
//U8G2_SSD1306_128X64_NONAME_F_SW_I2C u8g2(U8G2_R0, /* SCL= */ 2, /* SDA= */3, /* reset=*/ U8X8_PIN_NONE); // if you use software I2C port, full framebuffer, size = 1024 bytes​

void setup(void) {
  u8g2.begin();  // start a display.
}

void drawPixels()
{
  u8g2.clearBuffer();          // clear the internal memory
  for(int i = 0; i < 100; i++){
    // generate 100 points randomly
    u8g2.drawPixel(random(128), random(128)); 
    u8g2.sendBuffer();    
    delay(5); 
  }
}

void drawLines()
{
  u8g2.clearBuffer();          // clear the internal memory
  u8g2.drawLine(0,0, u8g2.getDisplayWidth(), u8g2.getDisplayHeight());
  u8g2.sendBuffer();    
  delay(1000);
  u8g2.drawLine(u8g2.getDisplayWidth(),0, 0, u8g2.getDisplayHeight());
  u8g2.sendBuffer();    
  delay(1000);
  u8g2.drawLine(0, u8g2.getDisplayHeight()/2, u8g2.getDisplayWidth(), u8g2.getDisplayHeight()/2);
  u8g2.sendBuffer();   
  delay(1000);
  u8g2.drawLine(u8g2.getDisplayWidth()/2,0, u8g2.getDisplayWidth()/2, u8g2.getDisplayHeight());
  u8g2.sendBuffer();   
}

void drawBoxes()
{
  u8g2.clearBuffer();          // clear the internal memory
  u8g2.drawBox(0, 0, u8g2.getDisplayWidth()/2-5,u8g2.getDisplayHeight()/2-5);
  u8g2.sendBuffer();    
  delay(1000);
  u8g2.drawBox(0, u8g2.getDisplayHeight()/2+5, u8g2.getDisplayWidth()/2-5,u8g2.getDisplayHeight());
  u8g2.sendBuffer();    
  delay(1000);
  u8g2.drawBox(u8g2.getDisplayWidth()/2+5, u8g2.getDisplayHeight()/2+5, u8g2.getDisplayWidth(),u8g2.getDisplayHeight());
  u8g2.sendBuffer();    
  delay(1000);
  u8g2.drawBox(u8g2.getDisplayWidth()/2+5, 0, u8g2.getDisplayWidth(),u8g2.getDisplayHeight()/2-5);
  u8g2.sendBuffer();    
}

void drawFrames()
{
  u8g2.clearBuffer();          // clear the internal memory
  u8g2.drawFrame(u8g2.getDisplayWidth()/2-5, u8g2.getDisplayHeight()/2-5, 10, 10);
  u8g2.sendBuffer();    
  delay(1000);
  u8g2.drawFrame(u8g2.getDisplayWidth()/2-10, u8g2.getDisplayHeight()/2-10, 20, 20);
  u8g2.sendBuffer();    
  delay(1000);
  u8g2.drawFrame(u8g2.getDisplayWidth()/2-15, u8g2.getDisplayHeight()/2-15, 30, 30);
  u8g2.sendBuffer();    
  delay(1000);
  u8g2.drawFrame(u8g2.getDisplayWidth()/2-20, u8g2.getDisplayHeight()/2-20, 40, 40);
  u8g2.sendBuffer();    
  delay(1000);
  u8g2.drawFrame(u8g2.getDisplayWidth()/2-25, u8g2.getDisplayHeight()/2-25, 50, 50);
  u8g2.sendBuffer();   
}

void drawCircles()
{
   u8g2.clearBuffer();          // clear the internal memory
   u8g2.drawCircle(u8g2.getDisplayWidth()/2, u8g2.getDisplayHeight()/2, 20, U8G2_DRAW_UPPER_RIGHT);
   u8g2.sendBuffer();    
   delay(1000);
   u8g2.drawCircle(u8g2.getDisplayWidth()/2, u8g2.getDisplayHeight()/2, 20, U8G2_DRAW_UPPER_LEFT);
   u8g2.sendBuffer();    
   delay(1000);
   u8g2.drawCircle(u8g2.getDisplayWidth()/2, u8g2.getDisplayHeight()/2, 20, U8G2_DRAW_LOWER_LEFT);
   u8g2.sendBuffer();    
   delay(1000);
   u8g2.drawCircle(u8g2.getDisplayWidth()/2, u8g2.getDisplayHeight()/2, 20, U8G2_DRAW_LOWER_RIGHT);
   u8g2.sendBuffer();    
   delay(1000);
   u8g2.drawCircle(u8g2.getDisplayWidth()/2, u8g2.getDisplayHeight()/2, 30, U8G2_DRAW_ALL);
   u8g2.sendBuffer();
}

void loop(void) {
  drawPixels();
  delay(2000);
  drawLines();
  delay(2000);
  drawFrames();
  delay(2000);
  drawCircles();
  delay(2000);
  drawBoxes();
  delay(2000);
}
