/****************************************************************************/	
//	Function: When the sensor detects the flame, the the LED will be turned on.
//	Hardware: Grove - Flame Sensor, Grove - LED
//	Arduino IDE: Arduino-1.0
//	Author:	 Frankie.Chu		
//	Date: 	 Feb 18,2013
//	Version: v1.0
//	by www.seeedstudio.com
//
//  This library is free software; you can redistribute it and/or
//  modify it under the terms of the GNU Lesser General Public
//  License as published by the Free Software Foundation; either
//  version 2.1 of the License, or (at your option) any later version.
//
//  This library is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
//  Lesser General Public License for more details.
//
//  You should have received a copy of the GNU Lesser General Public
//  License along with this library; if not, write to the Free Software
//  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA
//
/******************************************************************************/

#define FLAME_SENSOR 3 //connect FLAME_SENSOR to digital pin3
#define LED 2//connect Grove - LED to pin2

void setup() 
{                
	pinsInit();
}
void loop() 
{
  if(isFlameDetected())
  	turnOnLED();
  else turnOffLED();
}
/********************************/
void pinsInit()
{
	pinMode(FLAME_SENSOR, INPUT);
	pinMode(LED,OUTPUT);
	digitalWrite(LED,LOW);
}
void turnOnLED()
{
	digitalWrite(LED,HIGH);
}
void turnOffLED()
{
	digitalWrite(LED,LOW);
}
boolean isFlameDetected()
{
	if(digitalRead(FLAME_SENSOR))
		return false;
	else return true;
}
