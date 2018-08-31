/*
 * MateMatrix
 * Copyright 2017 iteratec GmbH
 */

#include "MateMatrix.h"
#include <avr/pgmspace.h>

byte up[] = {
  B00011000,
  B00111100,
  B01111110,
  B11011011,
  B10011001,
  B00011000,
  B00011000,
  B00011000
};

void setup(){
  Serial.begin(9600); // serial communication initialize
  initialisiereMatrix();
}

void loop(){

}
