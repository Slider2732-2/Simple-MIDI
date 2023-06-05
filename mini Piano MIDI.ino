/*
Simple MIDI for Schylling Mini Piano
3x8 matrix, 23 keys

June 2023 Slider2732
*/


int note;
int looper;
int keyOn[100];


void setup()
{
  // C2 is MIDI 36
  int note = 43; // Left-most MIDI note key on mini Piano

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

  Serial.begin(31250); // MIDI baud rate

  //Play a chromatic scale starting on middle C (60)
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

  // Set all notes triggered to 0 - Off
  for (looper = 1; looper <= 99; looper++)
     {keyOn[looper] = 0;}

  // Reset looper variable
  looper = 1; 
}


void loop()
{
 // Bunch of "if's" - to be optimised
    if(looper >= 4) {looper = 1;}
    
    if(looper == 1) 
      {digitalWrite(10, LOW); digitalWrite(11, HIGH); digitalWrite(12, HIGH);}
    if(looper == 2) 
      {digitalWrite(11, LOW); digitalWrite(12, HIGH); digitalWrite(10, HIGH);}
    if(looper == 3) 
      {digitalWrite(12, LOW); digitalWrite(10, HIGH); digitalWrite(11, HIGH);}

    delay (1); // Settling time for 5V. Pin high, around circuit

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
   
   looper++;
}


void noteOn()
{
  Serial.write(0x90);
  Serial.write(note);
  Serial.write(120);
}

void noteOff()
{
  Serial.write(0x80);
  Serial.write(note);
  Serial.write(0);
}
