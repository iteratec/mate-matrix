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

byte left[] = {
  B00011000,
  B00111000,
  B01110000,
  B11111111,
  B11111111,
  B01110000,
  B00111000,
  B00011000
};

byte down[] = {
  B00011000,
  B00011000,
  B00011000,
  B10011001,
  B11011011,
  B01111110,
  B00111100,
  B00011000
};

byte right[] = {
  B00011000,
  B00011100,
  B00001110,
  B11111111,
  B11111111,
  B00001110,
  B00011100,
  B00011000
};

byte smilie[] = {
  B00000000,
  B01000111,
  B01000111,
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
  char zeichen = leseZeichen();
  schalteMatrixAus();
  delay(1000);
  if (zeichen == 'w') {
    zeigeBild(up);
  } else if (zeichen == 'a') {
    zeigeBild(left);
  } else if (zeichen == 'd') {
    zeigeBild(right);
  } else if (zeichen == 's') {
    zeigeBild(down);
  } else {
    zeigeBild(smilie);
  }
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
