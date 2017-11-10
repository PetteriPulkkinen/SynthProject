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
    //carrier.ADSR.startStage(Envelope::ATTACK);
    carrierFrequency = MidiMessage::getMidiNoteInHertz(midiNoteNumber);
    // I commented line below out so it only takes values from slider5
    //modulator.setAmplitude(4400);				
    modulator.setFrequency(carrierFrequency);	// sama kuin carrier koska alkutilanne (?)
    carrier.setAmplitude(velocity);
    carrier.setFrequency(carrierFrequency);
}

void FMsynthesis::stopNote(float velocity, bool allowTrailOff)
{
    //Envelope enters release state
    //carrier.ADSR.startStage(Envelope::RELEASE);
    clearCurrentNote();
}

void FMsynthesis::renderNextBlock (AudioBuffer <float> &outputBuffer, int startSample, int numSamples)
{
    if (!isVoiceActive()){
        return;
    }
    
	// ks. getNextvalue Oscillator.cpp:sta. Moduloiva aalto "muokkaa" kantoaaltoo, siksi carrierin freq muokataan
	// toisin sanottuna, kyseessa on fm-aalto
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