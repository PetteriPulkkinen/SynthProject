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
#include "SynthSound.h"

// ks. https://juce.com/doc/classSynthesiserVoice


class FMsynthesis : public SynthesiserVoice
{
    
public:
    FMsynthesis(){
    }
    
    ~FMsynthesis(){
    }
    
    void setCurrentPlaybackSampleRate(double newRate) override
    {
        carrier.initialize(newRate);
        modulator.initialize(newRate);
        sampleRate = newRate;
    }
    
    void setOutputLevel(float outLevel){
        level = outLevel;
    }
    
    bool canPlaySound(SynthesiserSound*) override;
    void startNote(	int 	midiNoteNumber,
                   float 	velocity,
                   SynthesiserSound * 	sound,
                   int 	currentPitchWheelPosition 
                   ) override;
    void stopNote(float velocity, bool allowTrailOff) override;
    void pitchWheelMoved(int newPitchWheel) override{};
    void controllerMoved(int controllerNumber, int newControllerValue) override{};
    void renderNextBlock (AudioBuffer < float > &outputBuffer, int startSample, int numSamples) override;
    
    Oscillator& getCarrier() {
        return carrier;
    }
    
    Oscillator& getModulator() {
        return modulator;
    }
    
private:
    Oscillator carrier, modulator;
    double carrierFrequency;
    double sampleRate;
    float level;
};