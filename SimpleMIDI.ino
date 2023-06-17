/*
Simple MIDI for Schylling Mini Piano
3x8 matrix, 23 keys

Extended version:
Pitch / Tuning - 10K variable pot on A0
Modulation     - 10K variable pot on A1
Octave shift   - momentary buttons on A2, A3
Patch change   - momentary buttons on A4, A5

For no extras connect A0 to A5 to +5V

No libraries or shift register chips needed
Board used - Arduino Nano V3

June 2023 Slider2732
*/


// Variables
int note = 43; // MIDI note for left most key
int looper;
int pitchValue;
int lastValue = 1023;
int modValue;
int lastValue2 = 1023;
int keyOn[100];

// Extended settings
int octave = 1;      // default note values
int instrument = 1;  // First preset of a synth



void setup()
{
  // setup pins output/input mode
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
 
  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);
  pinMode(4, INPUT_PULLUP);
  pinMode(5, INPUT_PULLUP);
  pinMode(6, INPUT_PULLUP);
  pinMode(7, INPUT_PULLUP);
  pinMode(8, INPUT_PULLUP);
  pinMode(9, INPUT_PULLUP);

  pinMode(A0, INPUT); // Pitchbend
  pinMode(A1, INPUT); // Modulation
  pinMode(A2, INPUT_PULLUP); // Octave shift up
  pinMode(A3, INPUT_PULLUP); // Octave shift down
  pinMode(A4, INPUT_PULLUP); // Patch up
  pinMode(A5, INPUT_PULLUP); // Patch down
  
  Serial.begin(31250); // MIDI baud rate
 

  // Play a chromatic scale to check MIDI connection is OK
  // Starting on middle C (60), Channel 1
  for (int note = 60; note < 72; note++)
     {
      Serial.write(0x90);
      Serial.write(note);
      Serial.write(120);
      delay(40);
      Serial.write(0x90);
      Serial.write(note);
      Serial.write(0);
      delay(40);
     }

  // Set all notes to 0 - Off
  for (looper = 1; looper <= 99; looper++)
     {keyOn[looper] = 0;}

  // Reset looper variable
  looper = 1; 
}


void loop()
{
 // Bunch of "if's" - works fine, can be optimised
    if(looper >= 4) {looper = 1;}
    
    if(looper == 1) 
      {digitalWrite(10, LOW); digitalWrite(11, HIGH); digitalWrite(12, HIGH);}
    if(looper == 2) 
      {digitalWrite(11, LOW); digitalWrite(12, HIGH); digitalWrite(10, HIGH);}
    if(looper == 3) 
      {digitalWrite(12, LOW); digitalWrite(10, HIGH); digitalWrite(11, HIGH);}

    delay (1); // Settling time for 5V to switch on and go around circuit

    if (looper == 1 && digitalRead(2) == LOW && keyOn[43] == 0) 
       {note = 43; keyOn[43] = 1; noteOn();}
    if (looper == 1 && digitalRead(2) == HIGH && keyOn[43] == 1) 
       {note = 43; keyOn[43] = 0; noteOff();}
    if (looper == 1 && digitalRead(3) == LOW && keyOn[44] == 0) 
       {note = 44; keyOn[44] = 1; noteOn();}
    if (looper == 1 && digitalRead(3) == HIGH && keyOn[44] == 1) 
       {note = 44; keyOn[44] = 0; noteOff();}
    if (looper == 1 && digitalRead(4) == LOW && keyOn[45] == 0) 
       {note = 45; keyOn[45] = 1; noteOn();}
    if (looper == 1 && digitalRead(4) == HIGH && keyOn[45] == 1) 
       {note = 45; keyOn[45] = 0; noteOff();}
    if (looper == 1 && digitalRead(5) == LOW && keyOn[46] == 0) 
       {note = 46; keyOn[46] = 1; noteOn();}
    if (looper == 1 && digitalRead(5) == HIGH && keyOn[46] == 1) 
       {note = 46; keyOn[46] = 0; noteOff();}
    if (looper == 1 && digitalRead(6) == LOW && keyOn[47] == 0) 
       {note = 47; keyOn[47] = 1; noteOn();}
    if (looper == 1 && digitalRead(6) == HIGH && keyOn[47] == 1) 
       {note = 47; keyOn[47] = 0; noteOff();}
    if (looper == 1 && digitalRead(7) == LOW && keyOn[48] == 0) 
       {note = 48; keyOn[48] = 1; noteOn();}
    if (looper == 1 && digitalRead(7) == HIGH && keyOn[48] == 1) 
       {note = 48; keyOn[48] = 0; noteOff();}
    if (looper == 1 && digitalRead(8) == LOW && keyOn[49] == 0) 
       {note = 49; keyOn[49] = 1; noteOn();}
    if (looper == 1 && digitalRead(8) == HIGH && keyOn[49] == 1) 
       {note = 49; keyOn[49] = 0; noteOff();}
    if (looper == 1 && digitalRead(9) == LOW && keyOn[50] == 0) 
       {note = 50; keyOn[50] = 1; noteOn();}
    if (looper == 1 && digitalRead(9) == HIGH && keyOn[50] == 1) 
       {note = 50; keyOn[50] = 0; noteOff();}
       
    if (looper == 2 && digitalRead(2) == LOW && keyOn[51] == 0) 
       {note = 51; keyOn[51] = 1; noteOn();}
    if (looper == 2 && digitalRead(2) == HIGH && keyOn[51] == 1) 
       {note = 51; keyOn[51] = 0; noteOff();}
    if (looper == 2 && digitalRead(3) == LOW && keyOn[52] == 0) 
       {note = 52; keyOn[52] = 1; noteOn();}
    if (looper == 2 && digitalRead(3) == HIGH && keyOn[52] == 1) 
       {note = 52; keyOn[52] = 0; noteOff();}
    if (looper == 2 && digitalRead(4) == LOW && keyOn[53] == 0) 
       {note = 53; keyOn[53] = 1; noteOn();}
    if (looper == 2 && digitalRead(4) == HIGH && keyOn[53] == 1) 
       {note = 53; keyOn[53] = 0; noteOff();}
    if (looper == 2 && digitalRead(5) == LOW && keyOn[54] == 0) 
       {note = 54; keyOn[54] = 1; noteOn();}
    if (looper == 2 && digitalRead(5) == HIGH && keyOn[54] == 1) 
       {note = 54; keyOn[54] = 0; noteOff();}
    if (looper == 2 && digitalRead(6) == LOW && keyOn[55] == 0) 
       {note = 55; keyOn[55] = 1; noteOn();}
    if (looper == 2 && digitalRead(6) == HIGH && keyOn[55] == 1) 
       {note = 55; keyOn[55] = 0; noteOff();}
    if (looper == 2 && digitalRead(7) == LOW && keyOn[56] == 0) 
       {note = 56; keyOn[56] = 1; noteOn();}
    if (looper == 2 && digitalRead(7) == HIGH && keyOn[56] == 1) 
       {note = 56; keyOn[56] = 0; noteOff();}
    if (looper == 2 && digitalRead(8) == LOW && keyOn[57] == 0) 
       {note = 57; keyOn[57] = 1; noteOn();}
    if (looper == 2 && digitalRead(8) == HIGH && keyOn[57] == 1) 
       {note = 57; keyOn[57] = 0; noteOff();}
    if (looper == 2 && digitalRead(9) == LOW && keyOn[58] == 0) 
       {note = 58; keyOn[58] = 1; noteOn();}
    if (looper == 2 && digitalRead(9) == HIGH && keyOn[58] == 1) 
       {note = 58; keyOn[58] = 0; noteOff();}
       
    if (looper == 3 && digitalRead(2) == LOW && keyOn[59] == 0) 
       {note = 59; keyOn[59] = 1; noteOn();}
    if (looper == 3 && digitalRead(2) == HIGH && keyOn[59] == 1)
       {note = 59; keyOn[59] = 0; noteOff();}
    if (looper == 3 && digitalRead(3) == LOW && keyOn[60] == 0) 
       {note = 60; keyOn[60] = 1; noteOn();}
    if (looper == 3 && digitalRead(3) == HIGH && keyOn[60] == 1) 
       {note = 60; keyOn[60] = 0; noteOff();}
    if (looper == 3 && digitalRead(4) == LOW && keyOn[61] == 0) 
       {note = 61; keyOn[61] = 1; noteOn();}
    if (looper == 3 && digitalRead(4) == HIGH && keyOn[61] == 1) 
       {note = 61; keyOn[61] = 0; noteOff();}
    if (looper == 3 && digitalRead(5) == LOW && keyOn[62] == 0) 
       {note = 62; keyOn[62] = 1; noteOn();}
    if (looper == 3 && digitalRead(5) == HIGH && keyOn[62] == 1) 
       {note = 62; keyOn[62] = 0; noteOff();}
    if (looper == 3 && digitalRead(6) == LOW && keyOn[63] == 0) 
       {note = 63; keyOn[63] = 1; noteOn();}
    if (looper == 3 && digitalRead(6) == HIGH && keyOn[63] == 1) 
       {note = 63; keyOn[63] = 0; noteOff();}
    if (looper == 3 && digitalRead(7) == LOW && keyOn[64] == 0) 
       {note = 64; keyOn[64] = 1; noteOn();}
    if (looper == 3 && digitalRead(7) == HIGH && keyOn[64] == 1) 
       {note = 64; keyOn[64] = 0; noteOff();}
    if (looper == 3 && digitalRead(8) == LOW && keyOn[65] == 0) 
       {note = 65; keyOn[65] = 1; noteOn();}
    if (looper == 3 && digitalRead(8) == HIGH && keyOn[65] == 1) 
       {note = 65; keyOn[65] = 0; noteOff();}
    if (looper == 3 && digitalRead(9) == LOW && keyOn[66] == 0) 
       {note = 66; keyOn[66] = 1; noteOn();}
    if (looper == 3 && digitalRead(9) == HIGH && keyOn[66] == 1) 
       {note = 66; keyOn[66] = 0; noteOff();}


  // Pitch / Tuning
  pitchValue = (analogRead(A0) / 1024.0) * 127;
  if (pitchValue < 53 || pitchValue > 56) 
     {
      byte LSB = pitchValue & 0x7F;
      Serial.write(0xE0);
      Serial.write(0x01);
      Serial.write(LSB);  
      Serial.write(pitchValue);    
     }
  

  // Modulation
  modValue = analogRead(A1);
  if(modValue <= 1020 && modValue >= 10) // Not connected to +5V
    {
     modValue = map(modValue, 0, 1023, 1023, 0);
     modValue = 127-(modValue/8);
     if (modValue != lastValue2)
     {
       Serial.write(0xB0);
       Serial.write(0x01);
       Serial.write(modValue);
       lastValue2 = modValue; 
     }
    }

      
  // Octave up
  if (digitalRead(A2) == LOW) {octave++; delay(250);}
  if (octave >= 3) {octave = 3;}


  // Octave down
  if (digitalRead(A3) == LOW) {octave--; delay(250);}
  if (octave <= -3) {octave = -3;}


  // Patch change up
  if (digitalRead(A4) == LOW)
     { 
      instrument++;
      delay(250); // debounce
      if (instrument == 128) {instrument = 1;} // wrap around to first patch of 127
       Serial.write(0xC0);
       Serial.write(instrument);
     }


  // Patch change down
  if (digitalRead(A5) == LOW)
     { 
      instrument--;
      delay(250); // debounce
      if (instrument == -1) {instrument = 127;} // wrap around to last patch of 127
       Serial.write(0xC0);
       Serial.write(instrument);
     }


  looper++;
}


void noteOn()
{
  if (octave == -3) {note = note -36;}
  if (octave == -2) {note = note -24;}
  if (octave == -1) {note = note -12;}
  if (octave == 2) {note = note +12;}
  if (octave == 3) {note = note +24;}
  Serial.write(0x90);
  Serial.write(note);
  Serial.write(120);
}

void noteOff()
{
  if (octave == -3) {note = note -36;}
  if (octave == -2) {note = note -24;}
  if (octave == -1) {note = note -12;}
  if (octave == 2) {note = note +12;}
  if (octave == 3) {note = note +24;}
  Serial.write(0x80);
  Serial.write(note);
  Serial.write(0);
}
