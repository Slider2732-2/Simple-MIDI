# mini-Piano-MIDI
Simple method to convert toy piano type keyboards to MIDI 

See this video:  https://youtu.be/ujRLEiPdv0Y 

Also, for a MIDI Out circuit: https://docs.arduino.cc/built-in-examples/communication/Midi

The method is very straighforward, with code that can be easily debugged and is easy to read. <br>
In the case of the Schylling mini Piano with a 3x8 keyboard matrix, 3 Arduino pins are sequentially set Low (10, 11, 12) and 8 pins are read for changes (2 to 9). Other toy type keyboards will be very similar. <br>
The code is quick enough with a standard Arduino Nano to offer full polyphony and little latency. <br>
Full optimisation could include clever routines for the keyboard matrix and additions such as pitch bend, modulation, octave shifting, function keys and more. This codebase is intended to help people start off on such roads  :)

![MPorig](https://github.com/Slider2732-2/mini-Piano-MIDI/assets/119638809/e31f9035-7ee0-43fc-bef8-ff5cf477ae1f)

![MPMIDI](https://github.com/Slider2732-2/mini-Piano-MIDI/assets/119638809/c9666064-ca6d-44d6-897a-dac432f80a8c)

<br>
<br>
A schematic will be created and posted, if requested in the video comments.
<br>
However, the code itself has been written to easily make changes to suit another keyboard. For example, most have diodes separating each key, so changing pins 10, 11 and 12 to High rather than Low may work. A small amount of experimentation should allow discovery of the circuit path and any changes required.  
