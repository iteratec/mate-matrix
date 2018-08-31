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


byte currentMatrix[] = {
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000
};

byte reverse(byte b) {
   b = (b & 0xF0) >> 4 | (b & 0x0F) << 4;
   b = (b & 0xCC) >> 2 | (b & 0x33) << 2;
   b = (b & 0xAA) >> 1 | (b & 0x55) << 1;
   return b;
}

void initialisiereMatrix() {
  int ledBrightness = 3; // dot matix intensity 0-15
  for(int index=0; index<lc.getDeviceCount(); index++) {
    lc.shutdown(index, false); // disable auto shutdown
    lc.setScanLimit(index, 7); // use all digits
    lc.setIntensity(index, ledBrightness); // set brightness
  }

  for(int i = 0;i<8;i++) {
    currentMatrix[i] = B00000000;
  }
}

void loescheGespeichertesBild() {
  for(int i = 0;i<8;i++) {
    currentMatrix[i] = B00000000;
  }
}

void schalteMatrixAus(){
  Serial.println("clearing matrix");
  for(int index=0; index < lc.getDeviceCount(); index++){
    lc.clearDisplay(index);
  }
  loescheGespeichertesBild();
}

void zeigeGespeichertesBild(){
  Serial.println("displaying frame");
  for(int i = 0; i<8; i++){
    lc.setColumn(0, i, reverse(currentMatrix[i]));
  }
}

void speichereBild(byte columns[]){
  Serial.println("displaying frame");
  for(int i = 0; i<8; i++){
    currentMatrix[i] = columns[i]|currentMatrix[i];
    lc.setColumn(0, i, reverse(currentMatrix[i]));
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
    lc.setColumn(0, i, reverse(columns[i]));
  }
}


void setzeGespeichertenPixel(int x, int y) {
  currentMatrix[y] |= B00000001 << (7-x);
}


char leseZeichen() {
  if (Serial.available()) {
   return Serial.read();
  }
  return 0;
}
