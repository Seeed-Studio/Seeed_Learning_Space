/*macro definitions modules*/

#define ROTARY_ANGLE_SENSOR A0
#define buzzer 2
#define button 3
#define LED 4

//Note frequenicies used in melodies.
#define NOTE_CS3 139
#define NOTE_D3  147
#define NOTE_A2  110
#define NOTE_C3  131
#define NOTE_F3  175
#define NOTE_C2  65
#define NOTE_AS3 233
#define NOTE_B3  247
#define NOTE_A3  220
#define NOTE_E3  165
#define NOTE_G3  196
#define NOTE_A4  440
#define NOTE_AS4 466
#define NOTE_C4  262
#define NOTE_D4  294
#define NOTE_DS4 311
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_FS4 370
#define NOTE_G4  392
#define NOTE_C5  523
#define NOTE_E5  659
#define NOTE_G5  784
#define NOTE_D5  587
#define NOTE_F5  698

#define ADC_REF 5 //reference voltage of ADC is 5v.If the Vcc switch on the seeeduino
//board switches to 3V3, the ADC_REF should be 3.3
#define GROVE_VCC 5 //VCC of the grove interface is normally 5v
#define FULL_ANGLE 300 //full value of the rotary angle is 300 degrees

int melody1[] = {
  NOTE_C4, NOTE_C4, NOTE_D4, NOTE_C4, NOTE_F4, NOTE_E4,
  NOTE_C4, NOTE_C4, NOTE_D4, NOTE_C4, NOTE_G4, NOTE_F4,
  NOTE_C4, NOTE_C4, NOTE_C5, NOTE_A4, NOTE_F4, NOTE_E4, NOTE_D4,
  NOTE_AS4, NOTE_AS4, NOTE_A4, NOTE_F4, NOTE_G4, NOTE_F4
};
int melody2[] = {
  NOTE_D4, NOTE_G4, NOTE_FS4, NOTE_A4,
  NOTE_G4, NOTE_C5, NOTE_AS4, NOTE_A4,
  NOTE_FS4, NOTE_G4, NOTE_A4, NOTE_FS4, NOTE_DS4, NOTE_D4,
  NOTE_C4, NOTE_D4, 0
};
int melody3[] = {
  NOTE_E4, NOTE_E4, 0, NOTE_E4,
  0, NOTE_C4, NOTE_E4, 0,
  NOTE_G4, 0, 0, NOTE_G3, 0,

  NOTE_C4, 0, 0, NOTE_G3,
  0, NOTE_E3, 0,
  0, NOTE_A3, 0, NOTE_B3,
  0, NOTE_AS3, NOTE_A3, 0,

  NOTE_G3, NOTE_E4, NOTE_G4,
  NOTE_A4, 0, NOTE_F4, NOTE_G4,
  0, NOTE_E4, 0, NOTE_C4,
  NOTE_D4, NOTE_B3, 0
};
int melody4[] = {
  NOTE_E5, NOTE_E5, NOTE_E5,
  NOTE_E5, NOTE_E5, NOTE_E5,
  NOTE_E5, NOTE_G5, NOTE_C5, NOTE_D5,
  NOTE_E5,
  NOTE_F5, NOTE_F5, NOTE_F5, NOTE_F5,
  NOTE_F5, NOTE_E5, NOTE_E5, NOTE_E5, NOTE_E5,
  NOTE_E5, NOTE_D5, NOTE_D5, NOTE_E5,
  NOTE_D5, NOTE_G5
};
int melody5[] = {
  NOTE_C2, NOTE_F3, NOTE_C3, NOTE_A2,
  NOTE_C3, NOTE_F3, NOTE_C3,
  NOTE_C3, NOTE_F3, NOTE_C3, NOTE_F3,
  NOTE_AS3, NOTE_G3, NOTE_F3, NOTE_E3, NOTE_D3, NOTE_CS3,
  NOTE_C3, NOTE_F3, NOTE_C3, NOTE_A2, // the same again
  NOTE_C3, NOTE_F3, NOTE_C3,
  NOTE_AS3, 0, NOTE_G3, NOTE_F3,
  NOTE_E3, NOTE_D3, NOTE_CS3, NOTE_C3
};

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations1[] = {
  8, 8, 4, 4, 4, 2,
  8, 8, 4, 4, 4, 2,
  8, 8, 4, 4, 4, 4, 4,
  8, 8, 4, 4, 4, 2,
};
int noteDurations2[] = {       //duration of the notes
  8, 4, 8, 4,
  4, 4, 4, 12,
  4, 4, 4, 4, 4, 4,
  4, 16, 4,
};
int noteDurations3[] = {
  4, 4, 4, 4,
  4, 4, 4, 4,
  4, 2, 4, 2, 2,

  4, 4, 4, 4,
  2, 4, 4,
  4, 4, 4, 4,
  4, 4, 4, 4,

  4, 2, 4,
  4, 4, 4, 4,
  4, 4, 4, 4,
  4, 4, 2
};
int noteDurations4[] = {
  8, 8, 4,
  8, 8, 4,
  8, 8, 8, 8,
  2,
  8, 8, 8, 8,
  8, 8, 8, 16, 16,
  8, 8, 8, 8,
  4, 4
};
int noteDurations5[] = {
  4, 4, 4, 4,
  4, 4, 2,
  4, 4, 4, 4,
  3, 8, 8, 8, 8, 8,
  4, 4, 4, 4, // the same again
  4, 4, 2,
  4, 8, 8, 4, 4,
  4, 4, 4, 4,
  0
};

int state = 0; //state of button

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); //Initilises serial monitor
  pinMode(ROTARY_ANGLE_SENSOR, INPUT); //defining inputs and outputs
  pinMode(button, INPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(LED, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  float voltage;
  int sensor_value = analogRead(ROTARY_ANGLE_SENSOR); // value from 0-1023
  voltage = (float)sensor_value * ADC_REF / 1023; 
  float degrees = (voltage * FULL_ANGLE) / GROVE_VCC; //covert back to degrees
  //Serial.println("The angle between the mark and the starting position:");
  //Serial.println(degrees); //degrees of the rotatry sensor

  state = digitalRead(button); //read button state
  //Serial.println(state);

  int sensorValue1 = analogRead(A2); //Assign pins for x axis of joystick
  int sensorValue2 = analogRead(A3); //Assign pins for y axis of joystick

  //X and Y axis of Joystick
  //Serial.print("The X and Y coordinate is:");
  //Serial.print(sensorValue1, DEC);
  //Serial.print(",");
  //Serial.println(sensorValue2, DEC);
  //Serial.println(" ");

  if (sensorValue1 == 1023) { // if joysstick is pressed
    for (int thisNote = 0 ; thisNote < 25; thisNote++) { //plays pre-defined melody 1
      digitalWrite(LED, HIGH);
      delay(20);
      digitalWrite(LED, LOW);
      // to calculate the note duration, take one second divided by the note type.
      //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
      int noteDuration1 = 1000 / noteDurations1[thisNote];
      tone(buzzer, melody1[thisNote], noteDuration1); //tone(INPUT Pin,Frequency, delay time)

      // to distinguish the notes, set a minimum time between them.
      int pauseBetweenNotes = noteDuration1 * 1.30;
      delay(pauseBetweenNotes);
      noTone(buzzer);
    }
    noTone(buzzer);
    digitalWrite(LED, LOW);
  }

  if ((sensorValue1 > 505 && sensorValue1 < 525)  && (sensorValue2 > 775 && sensorValue2 < 795)) { // if joysstick is held to up
    for (int thisNote = 0 ; thisNote < 25; thisNote++) {
      digitalWrite(LED, HIGH);
      delay(20);
      digitalWrite(LED, LOW);
      // to calculate the note duration, take one second divided by the note type.
      //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
      int noteDuration2 = 1000 / noteDurations2[thisNote];
      tone(buzzer, melody2[thisNote], noteDuration2);

      // to distinguish the notes, set a minimum time between them.
      int pauseBetweenNotes = noteDuration2 * 1.30;
      delay(pauseBetweenNotes);
      noTone(buzzer);
    }
    noTone(buzzer);
    digitalWrite(LED, LOW);
  }

  if ((sensorValue1 > 770 && sensorValue1 < 790)  && (sensorValue2 > 490 && sensorValue2 < 510)) { // if joysstick is held to right
    for (int thisNote = 0 ; thisNote < 25; thisNote++) {
      digitalWrite(LED, HIGH);
      delay(20);
      digitalWrite(LED, LOW);
      // to calculate the note duration, take one second divided by the note type.
      //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
      int noteDuration3 = 1000 / noteDurations3[thisNote];
      tone(buzzer, melody3[thisNote], noteDuration3);

      // to distinguish the notes, set a minimum time between them.
      int pauseBetweenNotes = noteDuration3 * 0.9;
      delay(pauseBetweenNotes);
      noTone(buzzer);
    }
    noTone(buzzer);
    digitalWrite(LED, LOW);
  }

  if ((sensorValue1 > 505 && sensorValue1 < 525)  && (sensorValue2 > 225 && sensorValue2 < 245)) { // if joysstick is held to dowwn
    for (int thisNote = 0 ; thisNote < 25; thisNote++) {
      digitalWrite(LED, HIGH);
      delay(20);
      digitalWrite(LED, LOW);
      // to calculate the note duration, take one second divided by the note type.
      //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
      int noteDuration4 = 1000 / noteDurations4[thisNote];
      tone(buzzer, melody4[thisNote], noteDuration4);

      // to distinguish the notes, set a minimum time between them.
      int pauseBetweenNotes = noteDuration4 * 1.30;
      delay(pauseBetweenNotes);
      noTone(buzzer);
    }
    noTone(buzzer);
    digitalWrite(LED, LOW);
  }

  if ((sensorValue1 > 235 && sensorValue1 < 255)  && (sensorValue2 > 490 && sensorValue2 < 510)) { // if joysstick is held to left
    for (int thisNote = 0 ; thisNote < 25; thisNote++) {
      digitalWrite(LED, HIGH);
      delay(20);
      digitalWrite(LED, LOW);
      // to calculate the note duration, take one second divided by the note type.
      //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
      int noteDuration5 = 1000 / noteDurations5[thisNote];
      tone(buzzer, melody5[thisNote], noteDuration5);

      // to distinguish the notes, set a minimum time between them.
      int pauseBetweenNotes = noteDuration5 * 1.30;
      delay(pauseBetweenNotes);
      noTone(buzzer);
    }
    noTone(buzzer);
    digitalWrite(LED, LOW);
  }

//turning rotary and pressing the button will play the note!
  if (state == HIGH && (degrees > 0 && degrees < 37.5)) {
    tone(buzzer, 264, 300);//C, do
    digitalWrite(LED, HIGH);
  }
  else if (state == HIGH && (degrees > 37.5 && degrees < 75)) {
    tone(buzzer, 297, 300);//D, re
    digitalWrite(LED, HIGH);
  }
  else if (state == HIGH && (degrees > 75 && degrees < 112.5)) {
    tone(buzzer, 330, 300);//E, mi
    digitalWrite(LED, HIGH);
  }
  else if (state == HIGH && (degrees > 112.5 && degrees < 187.5)) {
    tone(buzzer, 352, 300);//F,fa
    digitalWrite(LED, HIGH);
  }
  else if (state == HIGH && (degrees > 187.5 && degrees < 225)) {
    tone(buzzer, 396, 300);//G,sol
    digitalWrite(LED, HIGH);
  }
  else if (state == HIGH && (degrees > 225 && degrees < 262.5)) {
    tone(buzzer, 440, 300);//A,la
    digitalWrite(LED, HIGH);
  }
  else if (state == HIGH && (degrees > 262.5 && degrees < 300)) {
    tone(buzzer, 495, 300);//B,si
    digitalWrite(LED, HIGH);
  }

  else {
    noTone(buzzer);
    digitalWrite(LED, LOW);
  }
}
