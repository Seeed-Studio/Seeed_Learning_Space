#define SPEAKER 3 //Assign speaker as pin 3

int BassTab[]={1911,1702,1516,1431,1275,1136,1012};//bass 1~7
//For the Frequency to Tone table, please visit our wiki

void setup()
{
    pinInit(); // Calling the funtion that defined speaker as outout
}
void loop()
{
        /*sound bass 1~7*/
    for(int note_index=0;note_index<7;note_index++)
    {
        sound(note_index);
        delay(500);
    }
}
void pinInit()
{
    pinMode(SPEAKER,OUTPUT);
    digitalWrite(SPEAKER,LOW);
}
void sound(uint8_t note_index)
{
  /*
   The different sounds are based on the frequency of the input signal.
   You can supply different frequency signal to this module with Arduino. 
   Arduino generates these signal via PWM or even digital write and delay.
   Here we are going to show you how to generate these signals using delay()
   the speaker sound bass 1~7.
   */
    for(int i=0;i<100;i++)
    {
        digitalWrite(SPEAKER,HIGH);
        delayMicroseconds(BassTab[note_index]); 
        digitalWrite(SPEAKER,LOW);
        delayMicroseconds(BassTab[note_index]);
    }
}
