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

//naming pin3 as lineFinder
#define lineFinder 3

void setup() {
  // initialize the digital pin as an input:
  pinMode(lineFinder, INPUT);
  //initialise ChainableLED leds
  leds.init();
}

void loop() {
  /*read the line detector input
   * if detected black(HIGH) turn on LED
  */
  if (HIGH == digitalRead(lineFinder))
  {
    //turn off LED
    leds.setColorRGB(0, 10, 10, 10);
  }
  
  /*read the line detector input
   * if reading Logic low turn off LED
  */
  if (LOW == digitalRead(lineFinder))
  {
    //turn off LED
    leds.setColorRGB(0, 0, 0, 0);
  }
}
