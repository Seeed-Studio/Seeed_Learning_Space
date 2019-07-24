/****************************************************************************/	
//	Function: When a magnet whose south pole is facing up is approaching to 
//			  the onboard sensor, the LED will be turned on.Otherwise, the 
//			  LED will be turned off.
//	Hardware: Grove - Hall Sensor, Grove - LED
//	Arduino IDE: Arduino-1.0
//	Author:	 FrankieChu		
//	Date: 	 Jan 20,2013
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
/*macro definitions of magnetic pin and LED pin*/
#define HALL_SENSOR 2
#define LED	4//the Grove - LED is connected to D4 of Arduino

void setup()
{
 	pinsInit();
}
 
void loop() 
{
	if(isNearMagnet())//if the hall sensor is near the magnet?
	{
		turnOnLED();
	}
	else
	{
		turnOffLED();
	}
}
void pinsInit()
{
	pinMode(HALL_SENSOR, INPUT);
	pinMode(LED,OUTPUT);
}

/*If the hall sensor is near the magnet whose south pole is facing up, */
/*it will return ture, otherwise it will return false.				*/
boolean isNearMagnet()
{
	int sensorValue = digitalRead(HALL_SENSOR);
	if(sensorValue == LOW)//if the sensor value is LOW?
	{
		return true;//yes,return ture
	}
	else
	{
		return false;//no,return false
	}
}
void turnOnLED()
{
	digitalWrite(LED,HIGH);
}
void turnOffLED()
{
	digitalWrite(LED,LOW);
}

