/*
 * MateMatrix
 * Copyright 2017 iteratec GmbH
 */
 
#ifndef _MateMatrix_H_
#define _MateMatrix_H_

#include "Arduino.h"
 
/**
 * Creates and initializes a new Matrix instance
 */
void initialisiereMatrix();

/**
 * Blanks out all of the matrix's LEDs
 */
void schalteMatrixAus();

/**
 * Displays a frame on the matrix
 */
void zeigeBild(byte columns[]);

/**
 * concatenate the new matrix with the old one and save and show the result
 */
void speichereBild(byte columns[]);

/**
 * displays the internally saved matrix
 */
void zeigeGespeichertesBild();

/**
 * read serial input
 */
char leseZeichen();

#endif
