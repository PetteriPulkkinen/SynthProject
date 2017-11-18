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
    
    int carrierNote = midiNoteNumber+carrier_noteNum+octave*12;
    int modulatorNote = midiNoteNumber+modulator_noteNum+octave*12;
    
    carrierFrequency = MidiMessage::getMidiNoteInHertz(carrierNote);
    double modulatorFrequency = MidiMessage::getMidiNoteInHertz(modulatorNote);
    
    modulator.setFrequency(modulatorFrequency);
    carrier.setAmplitude(master*velocity);
    
    //Envelope enters attack state
    carrier.getEnvelope().startStage(Envelope::ATTACK);
}

void FMsynthesis::update()
{
    int note = getCurrentlyPlayingNote();
    int carrierNote, modulatorNote;
    carrierNote = note+carrier_noteNum+octave*12;
    modulatorNote = note+modulator_noteNum+octave*12;
    carrierFrequency = MidiMessage::getMidiNoteInHertz(carrierNote);
    modulator.setFrequency(MidiMessage::getMidiNoteInHertz(modulatorNote));
    changeFlag = false;
}

void FMsynthesis::stopNote(float velocity, bool allowTrailOff)
{
    //Envelope enters release state
    carrier.getEnvelope().startStage(Envelope::RELEASE);
    clearCurrentNote();
}

void FMsynthesis::renderNextBlock (juce::AudioBuffer <float> &outputBuffer, int startSample, int numSamples)
{
    if (!isVoiceActive()){
        return;
    }
    if (changeFlag == true){
        update();
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