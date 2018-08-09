/*
 * MateMatrix
 * Copyright 2017 iteratec GmbH
 */
 
#ifndef _MateMatrix_H_
#define _MateMatrix_H_

#include "Arduino.h"

/**
 * read serial input
 */
char leseZeichen();
 
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

#endif
