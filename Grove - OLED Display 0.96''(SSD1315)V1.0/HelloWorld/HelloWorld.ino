/*

  HelloWorld.ino

  Universal 8bit Graphics Library (https://github.com/olikraus/u8g2/)

  Copyright (c) 2016, olikraus@gmail.com
  All rights reserved.

  Redistribution and use in source and binary forms, with or without modification, 
  are permitted provided that the following conditions are met:

  * Redistributions of source code must retain the above copyright notice, this list 
    of conditions and the following disclaimer.
    
  * Redistributions in binary form must reproduce the above copyright notice, this 
    list of conditions and the following disclaimer in the documentation and/or other 
    materials provided with the distribution.

  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND 
  CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, 
  INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF 
  MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE 
  DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR 
  CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, 
  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT 
  NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; 
  LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER 
  CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, 
  STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) 
  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF 
  ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  
  
  27 Oct 2018:
  
  U8G2_SSD1306_128X64_NONAME_1_4W_HW_SPI u8g2
  make -f Makefile.184.uno
  
   text     
   8732               default, all active
   8500     -232      -2.65%    no U8G2_WITH_CLIP_WINDOW_SUPPORT
   8316     -416      -4.76%    no U8G2_WITH_FONT_ROTATION
   8606     -126      -1.44%    no U8G2_WITH_UNICODE
   8692     -40     -0.45%    no U8G2_WITH_INTERSECTION
   8328     -404      -4.62%      no U8G2_WITH_INTERSECTION  no U8G2_WITH_CLIP_WINDOW_SUPPORT
   8718     -14     -4.86%    no U8G2_WITH_HVLINE_SPEED_OPTIMIZATION
   8026     -706      -8.08%    no U8G2_WITH_FONT_ROTATION   no U8G2_WITH_INTERSECTION  no U8G2_WITH_CLIP_WINDOW_SUPPORT
   
   Some flags depend on each other: `U8G2_WITH_INTERSECTION` is required for `U8G2_WITH_CLIP_WINDOW_SUPPORT`, so `U8G2_WITH_INTERSECTION` is partly active as long
   as `U8G2_WITH_CLIP_WINDOW_SUPPORT` is requested.
   
*/

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
    
  This is a page buffer example.    
*/


U8G2_SSD1306_128X64_NONAME_1_HW_I2C u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE); // if you use Hardware I2C port

//U8G2_SSD1306_128X64_NONAME_1_SW_I2C u8g2(U8G2_R0, /* SCL= */ 2, /* SDA= */3, /* reset=*/ U8X8_PIN_NONE); // if you use software I2C port


void setup(void) {

  u8g2.begin();  
}

void loop(void) {
  u8g2.firstPage();
  do {
    u8g2.setFont(u8g2_font_ncenB10_tr);
    u8g2.drawStr(0,24,"Hello World!");
  } while ( u8g2.nextPage() );
}
