/*
  ==============================================================================

    Oscillator.cpp
    Created: 19 Oct 2017 12:51:51pm
    Author:  Petteri Pulkkinen

  ==============================================================================
*/

#include "Oscillator.h"


double Oscillator::getNextValue()
{
    double retVal = std::sin(phase+delta);
    phase += delta;
    return retVal;
};

void Oscillator::initialize(double sampleRate)
{
    setType(SINEWAVE);
    phase = 0;
    setFrequency(0);
    amplitude = 0;
    this->sampleRate = sampleRate;
};