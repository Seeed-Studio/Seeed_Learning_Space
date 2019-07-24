/****************************************************************************/	
//	Function: Measure the revolutions per minute(RPM) of a rotating disc and 
//			  there is a magnet whose south pole is facing up a at the edge of
//			  the disc.The serial monitor will print the value of the revolutions
//			  and its unit is RPM.
//	Hardware: Grove - Hall Sensor, a rotating disc with a magnet
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
/****************************************************************************/

volatile uint8_t rpmcount;//(rpmcount - 1) is the number of revolutions
 
uint16_t rpm;//revolutions per minute
 
uint32_t timeold;
uint32_t rotating_time;

void setup()
{
	Serial.begin(9600);
	attachInterrupt(0, rpm_fun, RISING); // Interrupt triggers on rising edge; 
										//when the sensor turns off(the magnet leaves).
}
 
void loop()
{
	if (rpmcount == 1) 
		timeold=millis();
	else if (rpmcount > 20) 
	{ 
		rotating_time = millis() - timeold;
		//Update RPM every 20 counts, increase this for better RPM resolution,
		//decrease for faster update
		rpm = 60000/rotating_time*(rpmcount-1);//1 min = 60000ms
		rpmcount = 0;
		Serial.println(rpm, DEC);
	}
}
 
void rpm_fun()
{
	rpmcount++;
}
