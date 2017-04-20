/*
 * MateMatrix
 * Copyright 2017 iteratec GmbH
 */

#include "MateMatrix.h"
#include <avr/pgmspace.h>

byte rahmen1[] = {
  B11001100,
  B00000001,
  B00000001,
  B10000000,
  B10000000,
  B00000001,
  B00000001,
  B11001100
};

byte rahmen2[] = {
  B01100110,
  B00000000,
  B10000001,
  B10000001,
  B00000000,
  B00000000,
  B10000001,
  B10011001
};

byte rahmen3[] = {
  B00110011,
  B10000000,
  B10000000,
  B00000001,
  B00000001,
  B10000000,
  B10000000,
  B00110011
};

byte rahmen4[] = {
  B10011001,
  B10000001,
  B00000000,
  B00000000,
  B10000001,
  B10000001,
  B00000000,
  B01100110
};

byte smily[] = {
  B00000000,
  B00000000,
  B00111100,
  B00111100,
  B00111100,
  B00111100,
  B00000000,
  B00000000
};

void setup(){
  Serial.begin(9600); // serial communication initialize
  initialisiereMatrix();
}

void loop(){
  schalteMatrixAus();
  speichereBild(smily);
  speichereBild(rahmen1);
  zeigeGespeichertesBild();
  delay(500);
  schalteMatrixAus();
  speichereBild(smily);
  speichereBild(rahmen2);
  zeigeGespeichertesBild();
  delay(500);
  schalteMatrixAus();
  speichereBild(smily);
  speichereBild(rahmen3);
  zeigeGespeichertesBild();
  delay(500);
  schalteMatrixAus();
  speichereBild(smily);
  speichereBild(rahmen4);
  zeigeGespeichertesBild();
  delay(500);
}
