/*
  Calibrator.cpp - Library for calibrating sensors hooked to analog inputs.
  Calibrator is released under the Apache 2.0 license. See the included LICENSE file.
  Copyright 2013 Julian Vidal
  https://github.com/poisa/Calibrator
*/

#include "Arduino.h"
#include "Calibrator.h"

Calibrator::Calibrator()
{
	reset();
}

void Calibrator::setValue(int currentValue)
{
	if (currentValue > _maxValue) {
		_maxValue = currentValue;
	}

	if (currentValue < _minValue) {
		_minValue = currentValue;
	}
};

int Calibrator::getValue(int currentValue)
{
	currentValue = map(currentValue, _minValue, _maxValue, 0, 1023);
	currentValue = constrain(currentValue, 0, 1023);
	return currentValue;
}

int Calibrator::getMin() 
{
	return _minValue;
}

int Calibrator::getMax() 
{
	return _maxValue;
}

void Calibrator::reset()
{
	_minValue = 1023;
	_maxValue = 0;
}