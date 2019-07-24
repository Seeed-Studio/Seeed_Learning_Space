// constants won't change. They're used here to set pin numbers:
const int vibrationPin = 2;     // the number of the vibration pin
const int buzzer =  3;      // the number of the buzzer pin

// variables will change:
int state = 0;         // variable for reading the viabration sensor status

void setup() {
  // initialize the buzzer  as an output:
  pinMode(buzzer, OUTPUT);
  // initialize the viabraiton as an input:
  pinMode(vibrationPin, INPUT);
}

void loop() {
  // read the state of the viabration value:
  state = digitalRead(vibrationPin);

  if (state == HIGH) {
    // turn Buzzer off:
    digitalWrite(buzzer, LOW);
  } else {
    // turn Buzzer on:
    digitalWrite(buzzer, HIGH);
  }
}
