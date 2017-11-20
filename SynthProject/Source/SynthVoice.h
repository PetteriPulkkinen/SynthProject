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
        modulator_noteNum = 0;
        carrier_noteNum = 0;
        master = 1;
        octave = 0;
        changeFlag = 0;
    }
    
    ~FMsynthesis(){
    }
    
    void setCurrentPlaybackSampleRate(double newRate) override
    {
        carrier.initialize(newRate);
        modulator.initialize(newRate);
        sampleRate = newRate;
        DBG("Playback init");
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
    
    /* Used when values need to be changed during the playback */
    void update();
    
    Oscillator& getCarrier() {
        return carrier;
    }
    
    Oscillator& getModulator() {
        return modulator;
    }
    
    void setMasterLevel(float newMaster){
        master = newMaster;
        changeFlag = true;
    }
    
    void setOctave(int newOctave){
        octave = newOctave;
        changeFlag = true;
    }
    
    void setCarrier_noteNum(int noteNum){
        carrier_noteNum = noteNum;
        changeFlag = true;
    }
    
    void setModulator_noteNum(int noteNum){
        modulator_noteNum = noteNum;
        changeFlag = true;
    }
    
    
private:
    Oscillator carrier, modulator;
    double carrierFrequency;
    double sampleRate;
    float level;
    
    bool changeFlag;
    float master;
    int octave;
    int carrier_noteNum; // is used for changing the corresponging note to midi note
    int modulator_noteNum;
};