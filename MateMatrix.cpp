/*
 * MateMatrix
 * Copyright 2017 iteratec GmbH
 */

#include "Arduino.h"
#include "MateMatrix.h"

MateMatrix::MateMatrix(byte _data, byte _load, byte _clock) 
{
	data = _data;
	load = _load;
	clock = _clock;
	for (int i=0; i<80; i++)
		buffer[i] = 0;
}

void MateMatrix::setCommand(byte command, byte value)
{
	digitalWrite(load, LOW);    
	for (int i=0; i<num; i++) 
	{
		shiftOut(data, clock, MSBFIRST, command);
		shiftOut(data, clock, MSBFIRST, value);
	}
	digitalWrite(load, LOW);
	digitalWrite(load, HIGH);
}

void MateMatrix::setIntensity(byte intensity)
{
	setCommand(max7219_reg_intensity, intensity);
}

void MateMatrix::displayFrame(byte columns[]){
   for(int i=0; i<8; i++){
     columns[i];
   } 
}
