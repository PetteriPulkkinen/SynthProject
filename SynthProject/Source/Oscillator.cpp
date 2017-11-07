/*
  ==============================================================================

    Oscillator.cpp
    Created: 19 Oct 2017 12:51:51pm
    Author:  Petteri Pulkkinen

  ==============================================================================
*/

#include "Oscillator.h"


const float Oscillator::getNextValue()
{
    double retVal = gain*std::sin(phase+delta);
    
    //Do waveform compressing if needed (if gain is over one)
    if (retVal > 1){
        retVal = 1;
    }
    else if (retVal < -1){
        retVal = -1;
    }
    phase += delta;
    return amplitude*retVal;
};

void Oscillator::initialize(double sampleRate)
{
    phase = 0;
    setFrequency(0);
    amplitude = 0;
    gain = 1;
    this->sampleRate = sampleRate;
};

void Oscillator::reset()
{
    phase = 0;
};


void Oscillator::setGain(double newGain)
{
    if (newGain < 1){
        throw "Parameter for oscillator gain under one.";
    }
    else {
        gain = newGain;
    }
};

