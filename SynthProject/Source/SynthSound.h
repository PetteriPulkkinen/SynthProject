/*
  ==============================================================================

    SynthSound.h
    Created: 19 Oct 2017 12:30:46pm
    Author:  Petteri Pulkkinen

  ==============================================================================
*/

#pragma once
#include "../JuceLibraryCode/JuceHeader.h"

struct SynthSound : public SynthesiserSound
{
    bool appliesToNote(int) override { return true; }
    bool appliesToChannel(int) override { return true; }
};