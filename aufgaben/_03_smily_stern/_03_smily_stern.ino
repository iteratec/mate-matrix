/*
 * MateMatrix
 * Copyright 2017 iteratec GmbH
 */

#include "MateMatrix.h"
#include <avr/pgmspace.h>

byte stern[] = {
  B10011001,
  B01011010,
  B00111100,
  B11111111,
  B11111111,
  B00011100,
  B01011010,
  B10011001
};

byte smily[] = {
  B00111100,
  B01000010,
  B10101001,
  B10101001,
  B10000101,
  B10111001,
  B01000010,
  B00111100
};

void setup(){
  Serial.begin(9600); // serial communication initialize
  initialisiereMatrix();
}

void loop(){
  delay(1000);
  zeigeBild(stern);
  delay(1000);
  zeigeBild(smily);
}
