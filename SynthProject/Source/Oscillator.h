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

/*#define _USE_MATH_DEFINES // for C++  
#include <cmath>*/ 


class Oscillator
{
public:
    Oscillator(){}
    
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