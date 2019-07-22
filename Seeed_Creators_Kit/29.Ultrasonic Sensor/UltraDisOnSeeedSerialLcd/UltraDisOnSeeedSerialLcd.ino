/*
 * UltraDisOnSeeedSerialLcd.ino
 * Example sketch for ultrasonic ranger
 *
 * Copyright (c) 2012 seeed technology inc.
 * Website    : www.seeed.cc
 * Author     : LG, FrankieChu
 * Create Time: Jan 17,2013
 * Change Log :
 *
 * The MIT License (MIT)
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */


/***************************************************************************/
//  Function: Measure the distance to obstacles in front and display the
//			  result on seeedstudio serialLcd. Make sure you installed the
//			  serialLCD, SofewareSerial and Ultrasonic library.
//	Hardware: Grove - Ultrasonic Ranger, Grove - Serial LCD
//	Arduino IDE: Arduino-1.0
/*****************************************************************************/

//Include Ultrasonic Range Library
#include <SoftwareSerial.h>
#include <SerialLCD.h>
#include "Ultrasonic.h"

SerialLCD slcd(4,5);
Ultrasonic ultrasonic(7);
void setup()
{
   slcd.begin();
}
void loop()
{
	long RangeInCentimeters;
	RangeInCentimeters = ultrasonic.MeasureInCentimeters();
	delay(150);
	slcd.clear();
	slcd.setCursor(0,0);
	slcd.print("The distance:");
	slcd.setCursor(0,1) ;
	slcd.print(RangeInCentimeters,DEC);
	slcd.setCursor(5,1) ;
	slcd.print("cm");
}
