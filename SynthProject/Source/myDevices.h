/*
  ==============================================================================

    myDevices.h
    Created: 26 Nov 2017 7:19:28pm
    Author:  Petteri Pulkkinen

  ==============================================================================
*/

#pragma once
#include "../JuceLibraryCode/JuceHeader.h"
#include "Oscillator.h"

typedef struct
{
    Synthesiser FMSynth;
    Oscillator LFO;
    MidiKeyboardState keyboardState;
    double cutoff;
    double Q;
    double samplingRate;
} Devices;