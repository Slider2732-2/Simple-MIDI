# mini-Piano-MIDI
Simple method to convert toy piano type keyboards to MIDI 
<br>
No libraries, shift registers or opto-couplers needed!
<br>

See this video:  https://youtu.be/ujRLEiPdv0Y <br>
Also, this short video of the extended functionality: https://www.youtube.com/watch?v=RAbyoZBtSxY  

For a MIDI Out circuit: https://docs.arduino.cc/built-in-examples/communication/Midi

The method is very straighforward, with code that can be easily debugged and is easy to read. <br>
Download mini Piano Midi.ino for a basic polyphonic MIDI solution for a 2 octave toy keyboard. <br>
*NEW* Download Yamaha PSR-77 MIDI.ino for a 4 octave basic polyphonic MIDI solution for the YAMAHA PSR-77 <br>
Download SimpleMIDI.ino for an extended feature set - which adds pitchbend, modulation, octave shifting and patch selection controls. <br>

In the case of the Schylling mini Piano with a 3x8 keyboard matrix, 3 Arduino pins are sequentially set Low (10, 11, 12) and 8 pins are read for changes (2 to 9). Other toy type keyboards will be very similar. <br>
The code is quick enough with a standard Arduino Nano to offer full polyphony and little latency. <br>
Full optimisation could include clever routines for the keyboard matrix and faster routines for other functions... this codebase is intended to help people start off on such roads  :)

![MPorig](https://github.com/Slider2732-2/mini-Piano-MIDI/assets/119638809/e31f9035-7ee0-43fc-bef8-ff5cf477ae1f)

![MPMIDI](https://github.com/Slider2732-2/mini-Piano-MIDI/assets/119638809/c9666064-ca6d-44d6-897a-dac432f80a8c)

<br>
<br>
How to wire up is only a case of reading which pins are connected in the Setup function.
To make your keyboard run - Most toy keyboards have diodes separating each key, so changing pins 10, 11 and 12 to High rather than Low may work. A small amount of experimentation should allow discovery of the circuit path and any changes required. <br> 

An alternative codebase for the YAMAHA PSR-77 has been uploaded, to show how such differences can be made with a larger keyboard that has a diode matrix. In that keyboards version, pins 10 - 15 from the keyboard matrix have 10K resistors connected to +5V.<br><br><br> 
Microcontroller used : Arduino Nano V3 <br>
Extra components are 10K variable pots to A0 and A1 (+5V, input pin, Gnd to pot leg connections) <br>
4x momentary buttons to A2, A3, A4, A5 (one leg connected to Gnd) <br>
Any or all of the extra components can be omitted if using the extended functionality code (SimpleMidi.ino). Just connect any unused pins of A0 to A5 to +5V. <br>
