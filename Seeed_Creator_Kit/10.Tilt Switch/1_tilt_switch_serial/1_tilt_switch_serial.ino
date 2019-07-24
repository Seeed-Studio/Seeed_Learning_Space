//assign name tiltswitchPin to pin 5
#define tiltswitchPin 5
//creates a integer variable called 'val' to store read value
int val;

void setup()
{
  //set pinMode of tiltswitchPin to input
  pinMode(tiltswitchPin, INPUT);
  // opens serial port, sets data rate to 9600 bps
  Serial.begin(9600);
}

void loop()
{ //read the tilt switch input
  val = digitalRead(tiltswitchPin);
  //display the tilt switch status, 1 is on, 0 is off.
  Serial.println(val);
}
