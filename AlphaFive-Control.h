/***************************************************
This is a library for the Alpha Clock Five by EvilMadScientist

It is designed to be implemented on an Arduino or similar which communiates 
with the Alpha Clock Five over serial. Different Serial ports can be called 
in the .begin function so that a single Arduino with multiple ports (such
as the Mega) can control multiple clocks.

Created By Lucas McCallister
Special Thanks to SA Forums Member Mod Sassinator for helping with creating the constructor.
****************************************************/

#if (ARDUINO >= 100)
#include "Arduino.h"
#else
#include "WProgram.h"
#endif
#include <Stream.h>

#define headerbyte 0xFF

class AlphaClockFive {
public:
	//Constructor
	AlphaClockFive(Stream* stream) : _stream(stream) {
	};
	// To create an instance using hardware serial port 0:
	// AlphaFive FirstClock(&Serial);
	//  Or, to create using a different port: 
	// AlphaFive SecondClock(&Serial1);
	void clear();//clean that clock!
	void writeWord(String theword);//Display a 5-letter word
	void writeWord(String theword, String dots);//dispaly a 5 letter word and draw the dots
	void writeNumber(uint8_t number); //Draw a Raw Number
	
	void writeTime(uint32_t millistosend);//Send the clock the current time in millis, displays as MM:SS
	void setBrightness(uint8_t brightness);
	void setFont(uint8_t font);

private:
Stream* _stream;

};


