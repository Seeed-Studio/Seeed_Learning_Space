//1: toggle mode, 2: follow mode
#define LED_MODE   1

const int ledPin = 3;      // the number of the LED pin, D3
const int buttonPin = 4;    // the number of the pushbutton pin, D4

void setup() {
  pinMode(buttonPin, INPUT);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  int reading = digitalRead(buttonPin);
  if (reading != true){
    digitalWrite(ledPin, HIGH); 
  }
  else
  {
    digitalWrite(ledPin, LOW); 
  }
}
