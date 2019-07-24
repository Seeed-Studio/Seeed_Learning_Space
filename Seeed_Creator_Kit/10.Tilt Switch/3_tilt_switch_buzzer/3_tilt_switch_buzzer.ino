// initalise the frequency of the notes
#define NOTE_A4  440
#define NOTE_AS4 466
#define NOTE_C4  262
#define NOTE_D4  294
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_G4  392
#define NOTE_C5  523

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

//set title of pin 5 as tiltSwitch
#define tiltSwitch 5
//set title of pin 6 as buzzer
#define buzzer 6
// set variable currentNote to store latest note played
int currentNote;

void setup()
{
  //set pin 5(tilt switch) as input pin
  pinMode(tiltSwitch, INPUT);
}

void loop()
{
  /*read the status of tilt switch
    if the logic level of tilt switch
    is high, start play music */
  if (HIGH == digitalRead(tiltSwitch)) {

    for (int thisNote = currentNote ; thisNote < 25 ; thisNote++) {
      // to calculate the note duration, take one second divided by the note type.
      //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
      int noteDuration = 1000 / noteDurations[thisNote];
      tone(buzzer, melody[thisNote], noteDuration);

      // to distinguish the notes, set a minimum time between them.
      int pauseBetweenNotes = noteDuration * 1.30;
      delay(pauseBetweenNotes);

      /*reset the currentNote to the 0
        is the music is finished*/
      if (thisNote >= 24) {
        currentNote = 0;
      }

      /*druing the music read the status
        of tilt switch if the logic level
        of tilt switch is LOW, stop play
        music and store the previous played
        tone and jump to next tone*/
      if (LOW == digitalRead(tiltSwitch)) {

        //store the current note(thisNote) to currentNote
        currentNote = thisNote;
        //set the next note ready to play by increase currentNote by 1 increament
        currentNote ++;
        /*reset the currentNote to the beginning
          is the music is finished*/
        if (currentNote >= 25)
        {
          //restart the music from beginning by reset the currentNote to 0,
          currentNote = 0;
        }
        //if the tilt switch is set to logic level low, stop play music
        break;
      }
    }
  }
}
