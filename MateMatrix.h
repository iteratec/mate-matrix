/*
 * MateMatrix
 * Copyright 2017 iteratec GmbH
 */
 
#ifndef _MateMatrix_H_
#define _MateMatrix_H_

#include "Arduino.h"

class MateMatrix
{
 public:
  /**
   * Creates and initializes a new Matrix instance
   */
  MateMatrix();

  /**
   * Blanks out all of the matrix's LEDs
   */
  void clear();

  /**
   * Displays a frame on the matrix
   */
  void displayFrame(byte columns[]);

};
#endif


