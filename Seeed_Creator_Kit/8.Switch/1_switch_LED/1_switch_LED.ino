const int switchPin = 2;     // the number of the pushbutton pin
const int ledPin =  6;      // the number of the LED pin

int switchState = 0;         // variable for reading the pushbutton status

void setup() {
    // initialize the LED pin as an output:
    pinMode(ledPin, OUTPUT);
    // initialize the switch pin as an input:
    pinMode(switchPin, INPUT);
    Serial.begin(9600);
}

void loop(){
    // read the state of the switch value:
    switchState = digitalRead(switchPin);

    if (switchState == HIGH) {
        //turn LED on:
        digitalWrite(ledPin, HIGH);
        Serial.println("switch high!");
    }
    else {
        //turn LED off:
        digitalWrite(ledPin, LOW);
        Serial.println("switch low");
    }
}
