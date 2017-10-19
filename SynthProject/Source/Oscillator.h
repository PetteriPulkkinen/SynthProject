/*
  ==============================================================================

    Oscillator.h
    Created: 19 Oct 2017 12:51:51pm
    Author:  Petteri Pulkkinen

  ==============================================================================
*/

#pragma once
#include <cmath>

class Oscillator
{
public:
    Oscillator(){}
    
    void initialize(double sampleRate);
    
    enum wavetype {
        SINEWAVE = 0,
        RECTWAVE,
        TRIANGLEWAVE,
    };
    
    void setType(wavetype waveType){
        type = waveType;
    };
    
    double getNextValue();
    
    void setFrequency(double freq){
        frequency = freq;
        delta = 2*M_PI*freq/sampleRate;
    };
    
    void setAmplitude(double amp){
        amplitude = amp;
    };

private:
    
    float amplitude;
    double frequency;
    double phase;
    double sampleRate;
    double delta;
    wavetype type;
};