
int MoPin = 2;    // vibrator Grove connected to digital pin 2

void setup()  {
    pinMode( MoPin, OUTPUT );
}

void loop()  {

    digitalWrite(MoPin, HIGH); //Turn on the vibration motor 
    delay(1000); //Delay for 1 second

    digitalWrite(MoPin, LOW); //Turn off the vibration motor 
    delay(1000); //Delay for 1 second
}
