
/*
   Example of using the ChainableRGB library for controlling a Grove RGB.
   This code fades in an out colors in a strip of leds.
*/

//add ChainableLED library to this project
#include <ChainableLED.h>

//set the number of leds linked to the chain
#define NUM_LEDS  1

/*assign leds as the name of
  the ChainableLED set the
  pin of the ChainableLED to
  pin7(clock pin) and pin8(data pin)
  and number of the leds*/
ChainableLED leds(7, 8, NUM_LEDS);

void setup()
{
  //initialise ChainableLED leds
  leds.init();
}
//initialise power as byte with value of 0
byte power = 0;

void loop()
{
  /*for loop is used for loop through
    each LED connected to the chain
    in this case there is only one LED
  */
  for (byte i = 0; i < NUM_LEDS; i++)
  {
    /*
      % means modulo operation to find remainder
      eg 0 % 2 = 0, 1 % 2 = 1,  2 % 2 = 0...
      setColorRGB(byte led, byte red, byte green, byte blue);
      so in this case the even number of the LED chain
      will fading green color, odd number of the LED
      chain will fading red color, since we count the
      first LED as 0.
    */
    if (i % 2 == 0)
      //brighter red color from 0 to full power
      leds.setColorRGB(i, power, 0, 0);
    else
      //dimmer green color from full power to 0
      leds.setColorRGB(i, 0, 255 - power, 0);
  }
  //set power increment as 10
  power += 10;
  //light 0.5s for each brightness
  delay(500);
}
