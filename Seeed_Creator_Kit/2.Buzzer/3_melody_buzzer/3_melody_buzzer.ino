
// initalise the frequency of the notes
#define NOTE_A4  440
#define NOTE_AS4 466
#define NOTE_C4  262
#define NOTE_D4  294
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_G4  392
#define NOTE_C5  523

//assign buzzer as pin 6
#define buzzer 6

// notes in the melody:
int melody[] = {
  NOTE_C4, NOTE_C4, NOTE_D4, NOTE_C4, NOTE_F4, NOTE_E4,
  NOTE_C4, NOTE_C4, NOTE_D4, NOTE_C4, NOTE_G4, NOTE_F4,
  NOTE_C4, NOTE_C4, NOTE_C5, NOTE_A4, NOTE_F4, NOTE_E4, NOTE_D4,
  NOTE_AS4, NOTE_AS4, NOTE_A4, NOTE_F4, NOTE_G4, NOTE_F4
};

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = {
  8, 8, 4, 4, 4, 2,
  8, 8, 4, 4, 4, 2,
  8, 8, 4, 4, 4, 4, 4,
  8, 8, 4, 4, 4, 2,
};

void setup() {
  // iterate over the notes of the melody:
  for (int thisNote = 0 ; thisNote < 25 ; thisNote++) {

    // to calculate the note duration, take one second divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int noteDuration = 1000 / noteDurations[thisNote];
    tone(buzzer, melody[thisNote], noteDuration);

    // to distinguish the notes, set a minimum time between them.
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    noTone(buzzer);
  }
}

void loop() {
  // no need to repeat the melody.
}
