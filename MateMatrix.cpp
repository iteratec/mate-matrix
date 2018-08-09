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
unsigned long framecount = 0;
unsigned long time = millis();

LedControl lc = LedControl(dataPin, clockPin, chipSelectPin, 1);

void initialisiereMatrix() {
  int ledBrightness = 3; // dot matix intensity 0-15
  for(int index=0; index<lc.getDeviceCount(); index++) {
    lc.shutdown(index, false); // disable auto shutdown
    lc.setScanLimit(index, 7); // use all digits
    lc.setIntensity(index, ledBrightness); // set brightness
  }
}

void schalteMatrixAus(){
  Serial.println("clearing matrix");
  for(int index=0; index < lc.getDeviceCount(); index++){
    lc.clearDisplay(index);
  }
}

void messeFPS(){
  framecount++;
  unsigned long now = millis();
  int diff = now - time;
  if(diff > 10000){
    int fps = framecount / (diff / 1000);
    Serial.print("Frames per Second: ");
    Serial.println(fps);
    time = now;
    framecount = 0;
  }
}

void zeigeBild(byte columns[]){
  Serial.println("displaying frame");
  messeFPS();
  for(int i = 0; i<8; i++){
    lc.setColumn(0, i, columns[i]);
  }
}

char leseZeichen() {
  if (Serial.available()) {
   return Serial.read();
  }
  return 0;
}

