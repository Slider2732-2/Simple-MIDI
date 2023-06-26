/*
Simple MIDI for Yamaha PSR-77 
Based on Schylling Mini Piano code
6x9 matrix, 49 keys

No libraries or shift register chips needed
Board used - Arduino Nano V3

June 2023 Slider2732
*/


// Variables
int note = 36; // MIDI C3 
int looper;
int keyOn[100];


void setup()
{
  // Setup pin modes input/output
  pinMode(11, INPUT);
  pinMode(12, INPUT);
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(A3, INPUT);
   
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  
    
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
 // Bunch of "if's" - can be optimised
 if(looper >= 10) {looper = 1;} 

      // Each previous output pin set HIGH, then next pin set LOW    
      if(looper == 1) 
        {digitalWrite(10, HIGH); digitalWrite(2, LOW);}
      if(looper == 2) 
        {digitalWrite(2, HIGH); digitalWrite(3, LOW);}
      if(looper == 3) 
        {digitalWrite(3, HIGH); digitalWrite(4, LOW);}
      if(looper == 4) 
        {digitalWrite(4, HIGH); digitalWrite(5, LOW);}
      if(looper == 5) 
        {digitalWrite(5, HIGH); digitalWrite(6, LOW);}
      if(looper == 6) 
        {digitalWrite(6, HIGH); digitalWrite(7, LOW);}
      if(looper == 7) 
        {digitalWrite(7, HIGH); digitalWrite(8, LOW);}
      if(looper == 8) 
        {digitalWrite(8, HIGH); digitalWrite(9, LOW);}
      if(looper == 9) 
        {digitalWrite(9, HIGH); digitalWrite(10, LOW);}
        
      delay (1); // Settling time for 5V to switch on and go around circuit
 
    // Check each keyboard key, from left to right 
    if (looper == 5 && digitalRead(A3) == LOW && keyOn[36] == 0) 
       {note = 36; keyOn[36] = 1; noteOn();}
    if (looper == 5 && digitalRead(A3) == HIGH && keyOn[36] == 1) 
       {note = 36; keyOn[36] = 0; noteOff();} 
    if (looper == 3 && digitalRead(11) == LOW && keyOn[37] == 0) 
       {note = 37; keyOn[37] = 1; noteOn();}
    if (looper == 3 && digitalRead(11) == HIGH && keyOn[37] == 1) 
       {note = 37; keyOn[37] = 0; noteOff();}  
    if (looper == 3 && digitalRead(12) == LOW && keyOn[38] == 0) 
       {note = 38; keyOn[38] = 1; noteOn();}
    if (looper == 3 && digitalRead(12) == HIGH && keyOn[38] == 1) 
       {note = 38; keyOn[38] = 0; noteOff();}   
    if (looper == 3 && digitalRead(A0) == LOW && keyOn[39] == 0) 
       {note = 39; keyOn[39] = 1; noteOn();}
    if (looper == 3 && digitalRead(A0) == HIGH && keyOn[39] == 1) 
       {note = 39; keyOn[39] = 0; noteOff();}  
    if (looper == 3 && digitalRead(A1) == LOW && keyOn[40] == 0) 
       {note = 40; keyOn[40] = 1; noteOn();}
    if (looper == 3 && digitalRead(A1) == HIGH && keyOn[40] == 1) 
       {note = 40; keyOn[40] = 0; noteOff();}
    if (looper == 3 && digitalRead(A2) == LOW && keyOn[41] == 0) 
       {note = 41; keyOn[41] = 1; noteOn();}
    if (looper == 3 && digitalRead(A2) == HIGH && keyOn[41] == 1) 
       {note = 41; keyOn[41] = 0; noteOff();}
    if (looper == 3 && digitalRead(A3) == LOW && keyOn[42] == 0) 
       {note = 42; keyOn[42] = 1; noteOn();}
    if (looper == 3 && digitalRead(A3) == HIGH && keyOn[42] == 1) 
       {note = 42; keyOn[42] = 0; noteOff();}
    
    if (looper == 1 && digitalRead(11) == LOW && keyOn[43] == 0) 
       {note = 43; keyOn[43] = 1; noteOn();}
    if (looper == 1 && digitalRead(11) == HIGH && keyOn[43] == 1) 
       {note = 43; keyOn[43] = 0; noteOff();}
    if (looper == 1 && digitalRead(12) == LOW && keyOn[44] == 0) 
       {note = 44; keyOn[44] = 1; noteOn();}
    if (looper == 1 && digitalRead(12) == HIGH && keyOn[44] == 1) 
       {note = 44; keyOn[44] = 0; noteOff();}   
    if (looper == 1 && digitalRead(A0) == LOW && keyOn[45] == 0) 
       {note = 45; keyOn[45] = 1; noteOn();}
    if (looper == 1 && digitalRead(A0) == HIGH && keyOn[45] == 1) 
       {note = 45; keyOn[45] = 0; noteOff();}
    if (looper == 1 && digitalRead(A1) == LOW && keyOn[46] == 0) 
       {note = 46; keyOn[46] = 1; noteOn();}
    if (looper == 1 && digitalRead(A1) == HIGH && keyOn[46] == 1) 
       {note = 46; keyOn[46] = 0; noteOff();}
    if (looper == 1 && digitalRead(A2) == LOW && keyOn[47] == 0) 
       {note = 47; keyOn[47] = 1; noteOn();}
    if (looper == 1 && digitalRead(A2) == HIGH && keyOn[47] == 1) 
       {note = 47; keyOn[47] = 0; noteOff();}
    if (looper == 1 && digitalRead(A3) == LOW && keyOn[48] == 0) 
       {note = 48; keyOn[48] = 1; noteOn();}
    if (looper == 1 && digitalRead(A3) == HIGH && keyOn[48] == 1) 
       {note = 48; keyOn[48] = 0; noteOff();}
    
    if (looper == 9 && digitalRead(11) == LOW && keyOn[49] == 0) 
       {note = 49; keyOn[49] = 1; noteOn();}
    if (looper == 9 && digitalRead(11) == HIGH && keyOn[49] == 1) 
       {note = 49; keyOn[49] = 0; noteOff();}
    if (looper == 9 && digitalRead(12) == LOW && keyOn[50] == 0) 
       {note = 50; keyOn[50] = 1; noteOn();}
    if (looper == 9 && digitalRead(12) == HIGH && keyOn[50] == 1) 
       {note = 50; keyOn[50] = 0; noteOff();}
    if (looper == 9 && digitalRead(A0) == LOW && keyOn[51] == 0) 
       {note = 51; keyOn[51] = 1; noteOn();}
    if (looper == 9 && digitalRead(A0) == HIGH && keyOn[51] == 1) 
       {note = 51; keyOn[51] = 0; noteOff();}
    if (looper == 9 && digitalRead(A1) == LOW && keyOn[52] == 0) 
       {note = 52; keyOn[52] = 1; noteOn();}
    if (looper == 9 && digitalRead(A1) == HIGH && keyOn[52] == 1) 
       {note = 52; keyOn[52] = 0; noteOff();}
    if (looper == 9 && digitalRead(A2) == LOW && keyOn[53] == 0) 
       {note = 53; keyOn[53] = 1; noteOn();}
    if (looper == 9 && digitalRead(A2) == HIGH && keyOn[53] == 1) 
       {note = 53; keyOn[53] = 0; noteOff();}
    if (looper == 9 && digitalRead(A3) == LOW && keyOn[54] == 0) 
       {note = 54; keyOn[54] = 1; noteOn();}
    if (looper == 9 && digitalRead(A3) == HIGH && keyOn[54] == 1)
       {note = 54; keyOn[54] = 0; noteOff();}

    if (looper == 8 && digitalRead(11) == LOW && keyOn[55] == 0) 
       {note = 55; keyOn[55] = 1; noteOn();}
    if (looper == 8 && digitalRead(11) == HIGH && keyOn[55] == 1) 
       {note = 55; keyOn[55] = 0; noteOff();}
    if (looper == 8 && digitalRead(12) == LOW && keyOn[56] == 0) 
       {note = 56; keyOn[56] = 1; noteOn();}
    if (looper == 8 && digitalRead(12) == HIGH && keyOn[56] == 1) 
       {note = 56; keyOn[56] = 0; noteOff();}
    if (looper == 8 && digitalRead(A0) == LOW && keyOn[57] == 0) 
       {note = 57; keyOn[57] = 1; noteOn();}
    if (looper == 8 && digitalRead(A0) == HIGH && keyOn[57] == 1) 
       {note = 57; keyOn[57] = 0; noteOff();}
    if (looper == 8 && digitalRead(A1) == LOW && keyOn[58] == 0) 
       {note = 58; keyOn[58] = 1; noteOn();}
    if (looper == 8 && digitalRead(A1) == HIGH && keyOn[58] == 1) 
       {note = 58; keyOn[58] = 0; noteOff();}
    if (looper == 8 && digitalRead(A2) == LOW && keyOn[59] == 0) 
       {note = 59; keyOn[59] = 1; noteOn();}
    if (looper == 8 && digitalRead(A2) == HIGH && keyOn[59] == 1) 
       {note = 59; keyOn[59] = 0; noteOff();}
    if (looper == 8 && digitalRead(A3) == LOW && keyOn[60] == 0) 
       {note = 60; keyOn[60] = 1; noteOn();}
    if (looper == 3 && digitalRead(A3) == HIGH && keyOn[60] == 1) 
       {note = 60; keyOn[60] = 0; noteOff();}
       
    if (looper == 6 && digitalRead(11) == LOW && keyOn[61] == 0) 
       {note = 61; keyOn[61] = 1; noteOn();}
    if (looper == 6 && digitalRead(11) == HIGH && keyOn[61] == 1) 
       {note = 61; keyOn[61] = 0; noteOff();}
    if (looper == 6 && digitalRead(12) == LOW && keyOn[62] == 0) 
       {note = 62; keyOn[62] = 1; noteOn();}
    if (looper == 6 && digitalRead(12) == HIGH && keyOn[62] == 1) 
       {note = 62; keyOn[62] = 0; noteOff();}
    if (looper == 6 && digitalRead(A0) == LOW && keyOn[63] == 0) 
       {note = 63; keyOn[63] = 1; noteOn();}
    if (looper == 6 && digitalRead(A0) == HIGH && keyOn[63] == 1) 
       {note = 63; keyOn[63] = 0; noteOff();}
    if (looper == 6 && digitalRead(A1) == LOW && keyOn[64] == 0) 
       {note = 64; keyOn[64] = 1; noteOn();}
    if (looper == 6 && digitalRead(A1) == HIGH && keyOn[64] == 1) 
       {note = 64; keyOn[64] = 0; noteOff();}
    if (looper == 6 && digitalRead(A2) == LOW && keyOn[65] == 0) 
       {note = 65; keyOn[65] = 1; noteOn();}
    if (looper == 6 && digitalRead(A2) == HIGH && keyOn[65] == 1) 
       {note = 65; keyOn[65] = 0; noteOff();}
    if (looper == 6 && digitalRead(A3) == LOW && keyOn[66] == 0) 
       {note = 66; keyOn[66] = 1; noteOn();}
    if (looper == 6 && digitalRead(A3) == HIGH && keyOn[66] == 1) 
       {note = 66; keyOn[66] = 0; noteOff();}
       
    if (looper == 4 && digitalRead(11) == LOW && keyOn[67] == 0) 
       {note = 67; keyOn[67] = 1; noteOn();}
    if (looper == 4 && digitalRead(11) == HIGH && keyOn[67] == 1) 
       {note = 67; keyOn[67] = 0; noteOff();}
    if (looper == 4 && digitalRead(12) == LOW && keyOn[68] == 0) 
       {note = 68; keyOn[68] = 1; noteOn();}
    if (looper == 4 && digitalRead(12) == HIGH && keyOn[68] == 1) 
       {note = 68; keyOn[68] = 0; noteOff();}
    if (looper == 4 && digitalRead(A0) == LOW && keyOn[69] == 0) 
       {note = 69; keyOn[69] = 1; noteOn();}
    if (looper == 4 && digitalRead(A0) == HIGH && keyOn[69] == 1) 
       {note = 69; keyOn[69] = 0; noteOff();}
    if (looper == 4 && digitalRead(A1) == LOW && keyOn[70] == 0) 
       {note = 70; keyOn[70] = 1; noteOn();}
    if (looper == 4 && digitalRead(A1) == HIGH && keyOn[70] == 1) 
       {note = 70; keyOn[70] = 0; noteOff();}
    if (looper == 4 && digitalRead(A2) == LOW && keyOn[71] == 0) 
       {note = 71; keyOn[71] = 1; noteOn();}
    if (looper == 4 && digitalRead(A2) == HIGH && keyOn[71] == 1) 
       {note = 71; keyOn[71] = 0; noteOff();}    
    if (looper == 4 && digitalRead(A3) == LOW && keyOn[72] == 0) 
       {note = 72; keyOn[72] = 1; noteOn();}
    if (looper == 4 && digitalRead(A3) == HIGH && keyOn[72] == 1) 
       {note = 72; keyOn[72] = 0; noteOff();}
       
    if (looper == 2 && digitalRead(11) == LOW && keyOn[73] == 0) 
       {note = 73; keyOn[73] = 1; noteOn();}
    if (looper == 2 && digitalRead(11) == HIGH && keyOn[73] == 1) 
       {note = 73; keyOn[73] = 0; noteOff();}
    if (looper == 2 && digitalRead(12) == LOW && keyOn[74] == 0) 
       {note = 74; keyOn[74] = 1; noteOn();}
    if (looper == 2 && digitalRead(12) == HIGH && keyOn[74] == 1) 
       {note = 74; keyOn[74] = 0; noteOff();}
    if (looper == 2 && digitalRead(A0) == LOW && keyOn[75] == 0) 
       {note = 75; keyOn[75] = 1; noteOn();}
    if (looper == 2 && digitalRead(A0) == HIGH && keyOn[75] == 1) 
       {note = 75; keyOn[75] = 0; noteOff();}
    if (looper == 2 && digitalRead(A1) == LOW && keyOn[76] == 0) 
       {note = 76; keyOn[76] = 1; noteOn();}
    if (looper == 2 && digitalRead(A1) == HIGH && keyOn[76] == 1) 
       {note = 76; keyOn[76] = 0; noteOff();}
    if (looper == 2 && digitalRead(A2) == LOW && keyOn[77] == 0) 
       {note = 77; keyOn[77] = 1; noteOn();}
    if (looper == 2 && digitalRead(A2) == HIGH && keyOn[77] == 1) 
       {note = 77; keyOn[77] = 0; noteOff();}
    if (looper == 2 && digitalRead(A3) == LOW && keyOn[78] == 0) 
       {note = 78; keyOn[78] = 1; noteOn();}
    if (looper == 2 && digitalRead(A3) == HIGH && keyOn[78] == 1) 
       {note = 78; keyOn[78] = 0; noteOff();}
       
    if (looper == 7 && digitalRead(11) == LOW && keyOn[79] == 0) 
       {note = 79; keyOn[79] = 1; noteOn();}
    if (looper == 7 && digitalRead(11) == HIGH && keyOn[79] == 1) 
       {note = 79; keyOn[79] = 0; noteOff();}
    if (looper == 7 && digitalRead(12) == LOW && keyOn[80] == 0) 
       {note = 80; keyOn[80] = 1; noteOn();}
    if (looper == 7 && digitalRead(12) == HIGH && keyOn[80] == 1) 
       {note = 80; keyOn[80] = 0; noteOff();} 
    if (looper == 7 && digitalRead(A0) == LOW && keyOn[81] == 0) 
       {note = 81; keyOn[81] = 1; noteOn();}
    if (looper == 7 && digitalRead(A0) == HIGH && keyOn[81] == 1)
       {note = 81; keyOn[81] = 0; noteOff();}
    if (looper == 7 && digitalRead(A1) == LOW && keyOn[82] == 0) 
       {note = 82; keyOn[82] = 1; noteOn();}
    if (looper == 7 && digitalRead(A1) == HIGH && keyOn[82] == 1) 
       {note = 82; keyOn[82] = 0; noteOff();}
    if (looper == 7 && digitalRead(A2) == LOW && keyOn[83] == 0) 
       {note = 83; keyOn[83] = 1; noteOn();}
    if (looper == 7 && digitalRead(A2) == HIGH && keyOn[83] == 1) 
       {note = 83; keyOn[83] = 0; noteOff();}
    if (looper == 7 && digitalRead(A3) == LOW && keyOn[84] == 0) 
       {note = 84; keyOn[84] = 1; noteOn();}
    if (looper == 7 && digitalRead(A3) == HIGH && keyOn[84] == 1) 
       {note = 84; keyOn[84] = 0; noteOff();}

  
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
