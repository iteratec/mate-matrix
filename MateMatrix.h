/*
 * MateMatrix
 * Copyright 2017 iteratec GmbH
 */
 
#ifndef _MateMatrix_H_
#define _MateMatrix_H_

#include "Arduino.h"
#include "MaxMatrix.h"
 
/**
 * Creates and initializes a new Matrix instance
 */
void initMateMatrix();

/**
 * Blanks out all of the matrix's LEDs
 */
void clearMatrix();

/**
 * Displays a frame on the matrix
 */
void displayFrame(byte columns[]);

#endif
