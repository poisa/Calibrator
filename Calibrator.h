/*
  Calibrator.h - Library for calibrating sensors hooked to analog inputs.
  Calibrator is released under the Apache 2.0 license. See the included LICENSE file.
  Copyright 2013 Julian Vidal
  https://github.com/poisa/Calibrator
*/

#ifndef Calibrator_h
#define Calibrator_h

#include "Arduino.h"

class Calibrator
{
	public:
		Calibrator();
		void setValue(int currentValue);
		int getValue(int currentValue);
		int getMin();
		int getMax();
		void reset();
	private:
		int _minValue;
		int _maxValue;
};

#endif