// Relay Control

void setup()
{
  pinMode(2, INPUT);
  pinMode(3, INPUT);
  pinMode(4, OUTPUT);
}

void loop()
{
  if (digitalRead(2)==HIGH)
  {
    digitalWrite(4, HIGH);
    delay(100);
  }
  if (digitalRead(3)==HIGH)
  {
    digitalWrite(4, LOW);
  }
}
