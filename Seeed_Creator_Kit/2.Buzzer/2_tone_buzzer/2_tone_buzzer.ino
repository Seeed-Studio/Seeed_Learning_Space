//assign buzzer as pin 6 
#define buzzer 6                

void setup()
{
  /* tone(pin, frequency, duration) */
  //set buzzer pin to play 264Hz for 300ms
  tone(buzzer, 262, 300);
  //wait 1s
  delay(1000);

  //set buzzer pin to play 297Hz for 300ms
  tone(buzzer, 294, 300);
  //wait 1s
  delay(1000);

  //set buzzer pin to play 330Hz for 300ms
  tone(buzzer, 330, 300);
  //wait 1s
  delay(1000);
}

void loop()
{
  // no need to repeat the tone.
}
