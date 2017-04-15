/*
 * MateMatrix
 * Copyright 2017 iteratec GmbH
 */

#include "Arduino.h"
#include <binary.h>
#include "MateMatrix.h"
#include "LedControl.h"

int dataPin = 8;    // DIN pin of MAX7219 module
int chipSelectPin = 9;    // CS pin of MAX7219 module
int clockPin = 10;  // CLK pin of MAX7219 module

LedControl lc = LedControl(dataPin, clockPin, chipSelectPin, 1);

void initMateMatrix() {
  int ledBrightness = 3; // dot matix intensity 0-15
  for(int index=0; index<lc.getDeviceCount(); index++) {
    lc.shutdown(index, false); // disable auto shutdown
    lc.setScanLimit(index, 7); // use all digits
    lc.setIntensity(index, ledBrightness); // set brightness
  }
}

void clearMatrix(){
  Serial.println("clearing matrix");
  for(int index=0; index < lc.getDeviceCount(); index++){
    lc.clearDisplay(index);
  }
}

void displayFrame(byte columns[]){
  Serial.println("displaying frame");
  for(int i = 0; i<8; i++){
    lc.setColumn(0, i, columns[i]);
  }
}

