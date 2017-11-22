/*
  ==============================================================================

    Oscillator.h
    Created: 19 Oct 2017 12:51:51pm
    Author:  Petteri Pulkkinen

  ==============================================================================
*/

#pragma once

#ifndef MSWINDOWS
	#define M_PI 3.14159265358979323846
#endif

#include <cmath>
#include "Envelope.h"
 
#include "../JuceLibraryCode/JuceHeader.h"

//#define _USE_MATH_DEFINES // for C++  
//#include <cmath>


class Oscillator
{
public:
    Oscillator() : ADSR() {
    }
    
    void initialize(double sampleRate);
    
    const float getNextValue();
    
    void setFrequency(double freq){
        frequency = freq;
        delta = 2*M_PI*freq/sampleRate;
    };
    
    void setAmplitude(double amp){
        amplitude = amp;
    };
    
    const double getFrequency() const{
        return frequency;
    }
    
    void setGain(double newGain);
    
    const double& getGain() const {
        return gain;
    }
    
	Envelope& getEnvelope() {
		return ADSR;
	}
    
    double getAmplitude() const {
        return amplitude;
    }
    
    void reset();

private:
    
    double amplitude;
    double frequency;
    double phase;
    double sampleRate;
    double delta;
    double gain;
    
    Envelope ADSR;
};