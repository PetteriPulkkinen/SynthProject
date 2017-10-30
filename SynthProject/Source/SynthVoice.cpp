/*
  ==============================================================================

    SynthVoice.cpp
    Created: 19 Oct 2017 12:31:10pm
    Author:  Petteri Pulkkinen

  ==============================================================================
*/

#include "SynthVoice.h"


bool FMsynthesis::canPlaySound(SynthesiserSound* sound)
{
    return dynamic_cast<SynthSound*>(sound) != nullptr;
}

void FMsynthesis::startNote(int midiNoteNumber, float velocity, SynthesiserSound* sound, int currentPitchWheelPosition)
{
    //Envelope enters attack state
    carrierFrequency = MidiMessage::getMidiNoteInHertz(midiNoteNumber);
    
    modulator.setAmplitude(4400);
    modulator.setFrequency(carrierFrequency);
    carrier.setAmplitude(velocity);
    carrier.setFrequency(carrierFrequency);
}

void FMsynthesis::stopNote(float velocity, bool allowTrailOff)
{
    //Envelope enters release state
    clearCurrentNote();
}

void FMsynthesis::renderNextBlock (AudioBuffer <float> &outputBuffer, int startSample, int numSamples)
{
    if (!isVoiceActive()){
        return;
    }
    
    while (--numSamples>=0){
        carrier.setFrequency(carrierFrequency+modulator.getNextValue());
        const float sample = carrier.getNextValue();
        for (int channel = outputBuffer.getNumChannels(); --channel >= 0;){
            outputBuffer.addSample(channel, startSample, sample);
        }
        startSample++;
    }
}





// in main file:
// FMsynthesis olio;
// olio.setParameters(400, 1, 800, 2);