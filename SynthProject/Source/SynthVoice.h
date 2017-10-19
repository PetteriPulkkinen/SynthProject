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
        carrier.initialize(sampleRate);
        modulator.initialize(sampleRate);
    }
    
    void setParameters(double carrierFreq, double carrierAmplitude, double modFreq, double modAmplitude);
    
    void setOutputLevel(float outLevel){
        level = outLevel;
    }
    
private:
    Oscillator carrier, modulator;
    float level;
};