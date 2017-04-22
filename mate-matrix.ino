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

byte smilie[] = {
  B00000000,
  B01100110,
  B01100110,
  B00000000,
  B00000000,
  B11000011,
  B01100110,
  B00111100
};

void setup(){
  Serial.begin(9600); // serial communication initialize
  initialisiereMatrix();
}

void loop(){
  schalteMatrixAus();
  delay(1000);
  zeigeBild(up);
  delay(1000);

  //  clearMatrix();
  //delay(1000);
  //displayFrame(up);
  //delay(1000);
  //clearMatrix();
  //delay(1000);

  //int i = 1000;
  //while(i>0){
  //  displayFrame(smilie);
  //  delay(i);
  //  clearMatrix();
  //  delay(i);
  //  i = i * 0.9;
  //  Serial.println(i);
  // }
}
