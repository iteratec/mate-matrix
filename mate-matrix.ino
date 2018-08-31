/*
 * MateMatrix
 * Copyright 2017 iteratec GmbH
 */

#include "MateMatrix.h"
#include <avr/pgmspace.h>

int x = 0;
int y = 0;

void setup(){
  Serial.begin(9600); // serial communication initialize
  initialisiereMatrix();
}

void loop(){
  char c = leseZeichen();
  if (c == 'w' && y > 0) {
    y = y - 1;
  }
  if (c == 's' && y < 7) {
    y = y + 1;
  }
  if (c == 'a' && x > 0) {
    x = x - 1;
  }
  if (c == 'd' && x < 7) {
    x = x + 1;
  }
  loescheGespeichertesBild();
  
  setzeGespeichertenPixel(x, y);
  zeigeGespeichertesBild();
  delay(50);
}
