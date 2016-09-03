#include "AlphaFive-Control.h"



void AlphaClockFive::writeTime(uint32_t millistosend) {
	uint8_t minutes = millistosend / 60000;
	uint8_t seconds = (millistosend % 60000) / 1000;
	uint8_t fracts = (millistosend % 1000) / 100;
	//only to the 10th of a second. Milliseconds are a bit too much.
	_stream->write(headerbyte);
	_stream->print("A0");
	if (minutes < 10) {
		_stream->print(" ");
	}
	_stream->print(minutes);
	if (seconds < 10) {
		_stream->print("0");//leading zero
	}
	_stream->print(seconds);
	_stream->print(fracts);
	_stream->print("01210");//placement of dots for colons etc
						   //1 is bottom dot
						   //2 is top dot
						   //3 is both dots
						   //any other value turns dots off
}

void AlphaClockFive::writeWord(String theword) {
	_stream->write(headerbyte);
	_stream->print("A0");
	_stream->print(theword);
	_stream->print("     ");
}

void AlphaClockFive::writeWord(String theword, String dots) {
	_stream->write(headerbyte);
	_stream->print("A0");
	_stream->print(theword);
	_stream->print(dots);
}

void AlphaClockFive::writeNumber(uint8_t number) {
	_stream->write(headerbyte);
	_stream->print("A0");
	_stream->print(number);
	if (number < 10000) {
		_stream->print(" ");
		if (number < 1000) {
			_stream->print(" ");
			if (number < 100) {
				_stream->print(" ");
				if (number < 10) {
					_stream->print(" ");
				}
			}
		}

	}
	_stream->print("     ");
}

void AlphaClockFive::clear() {
	_stream->write(headerbyte);
	_stream->print("A0");
	_stream->print("     ");
	_stream->print("     ");
}

void AlphaClockFive::setBrightness(uint8_t brightness) {
	//range is 0-11
	brightness = constrain(brightness, 0, 11);
	_stream->write(headerbyte);
	_stream->print("B");
	_stream->print(00);
	if (brightness < 10) {//leading zero is neccessary
		_stream->print(0);
	}
	_stream->print(brightness);
	_stream->print("*******");//remaining 7 bytes are ignored
}

void AlphaClockFive::setFont(uint8_t font) {
	font = constrain(font, 0, 9);
	_stream->write(headerbyte);
	_stream->print("B");
	_stream->print(01);
	_stream->print(font);
	_stream->print("********");//remaining 8 bytes are ignored
}
