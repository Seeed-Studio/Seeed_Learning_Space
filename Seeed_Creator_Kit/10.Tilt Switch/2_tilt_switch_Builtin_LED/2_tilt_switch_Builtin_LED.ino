//set title of pin 5 as tiltSwitch
#define tiltSwitch 5

void setup()
{
  pinMode(tiltSwitch, INPUT);               //set pin 5(tilt switch) as input pin
  pinMode(LED_BUILTIN, OUTPUT);             //set pin 13(Builtin LED) as output pin
}

void loop()
{
  if (HIGH == digitalRead(tiltSwitch)) {   //read the status of tilt switch
    digitalWrite(LED_BUILTIN, HIGH);       //if the logic level of tilt switch is high turn on the builtin LED
  } else
  {
    digitalWrite(LED_BUILTIN, LOW);        //otherwise turn off the builtin LED
  }
}
