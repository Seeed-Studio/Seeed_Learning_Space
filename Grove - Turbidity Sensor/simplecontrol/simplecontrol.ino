int ledPin = 13;                // Connect LED on pin 13, or use the onboard one
int sensor_in = 2;                 // Turbidity sensor on Digital Pin 2

void setup(){
  pinMode(ledPin, OUTPUT);      // Set ledPin as output mode
  pinMode(sensor_in, INPUT);       //Set Turbidity sensor pin to input mode
}

void loop(){
   if(digitalRead(sensor_in)==LOW){       //Read Touch sensor signal 
        digitalWrite(ledPin, HIGH);   // if Touch sensor is LOW, then turn on
     }else{
        digitalWrite(ledPin, LOW);    // if Touch sensor is HIGH, then turn off the led
     }
}
