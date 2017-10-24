/*
  ==============================================================================

    SynthVoice.h
    Created: 19 Oct 2017 12:31:10pm
    Author:  Petteri Pulkkinen

  ==============================================================================
*/

#pragma once
#include "../JuceLibraryCode/JuceHeader.h"
#include "Oscillator.h"


class FMsynthesis : public SynthesiserVoice
{
    
public:
    FMsynthesis(double sampleRate){
        carrier.initialize(sampleRate);		// initialize from Oscillator.h, it's class Oscillator's method
        modulator.initialize(sampleRate);	// therefore, carrier and modulator are objects from class Oscillator
    }
    
    void setParameters(double carrierFreq, double carrierAmplitude, double modFreq, double modAmplitude);	// see .cpp
    
    void setOutputLevel(float outLevel){
        level = outLevel;
    }
    
private:
    Oscillator carrier, modulator;
    float level;
};