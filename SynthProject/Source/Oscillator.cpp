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
	// ottaa siis siniaallon arvoja paloittain. Uusi phase lopussa on seuraavaa kutsua varten
    double retVal = gain*std::sin(phase+delta);
    
    //Do waveform compressing if needed (if gain is over one)
    if (retVal > 1){
        retVal = 1;
    }
    else if (retVal < -1){
        retVal = -1;
    }
    phase += delta;
    
    if (ADSR.zeroValues())
        return 0;
    float ret = ADSR.nextSample()*retVal*amplitude;
    return ret;
    
    //return amplitude*retVal*ADSR.nextSample();
};

void Oscillator::initialize(double sampleRate)
{
    phase = 0;
    setFrequency(0);
    amplitude = 0;
    gain = 1;
    this->sampleRate = sampleRate;
    ADSR.init(sampleRate);
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

