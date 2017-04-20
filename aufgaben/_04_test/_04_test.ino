/*
 * MateMatrix
 * Copyright 2017 iteratec GmbH
 */

#include "MateMatrix.h"
#include <avr/pgmspace.h>

byte rahmen[] = {
  B11111111,
  B10000001,
  B10000001,
  B10000001,
  B10000001,
  B10000001,
  B10000011,
  B11111111
};

byte smily[] = {
  B00000000,
  B00000000,
  B00101000,
  B00101000,
  B00000100,
  B00111000,
  B01000000,
  B00000000
};

void setup(){
  Serial.begin(9600); // serial communication initialize
  initialisiereMatrix();
}

void loop(){
  delay(1000);
  zeigeBild(rahmen);
  zeigeBild(smily);
}
