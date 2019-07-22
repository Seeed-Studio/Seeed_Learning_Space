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
//initialise hue as float point with value of 0.0
float hue = 0.0;
//initialise up as boolean with value of true
boolean up = true;

void loop()
{
  /*for loop is used for loop through
    each LED connected to the chain
    in this case there is only one LED
  */
  for (byte i = 0; i < NUM_LEDS; i++) {

    /*setColorHSB(byte led, float hue, float saturation, float brightness);
       in this case set the first and only chainableLED 0 with changing hue
       and full saturation and half brightness
    */
    leds.setColorHSB(i, hue, 1, 0.5);
    //    delay for 50ms for each color
    delay(50);

    /*if up is true increase
      hue at 0.025 interval
      otherwise decrease hue
      at 0.025 interval
    */
    if (up) {
      hue += 0.025;
    }
    else
    {
      hue -= 0.025;
    }
    /*
      if hue is greater than 1.0
       and up is true set up to false,
       otherwise if hue is less or
       equal to 0.0 and up is not
       ture(! means is not) set up
       to true
    */
    if (hue >= 1.0 && up)
    {
      up = false;
    }
    else if (hue <= 0.0 && !up)
    {
      up = true;
    }
  }
}
