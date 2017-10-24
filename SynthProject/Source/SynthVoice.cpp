/*
  ==============================================================================

    SynthVoice.cpp
    Created: 19 Oct 2017 12:31:10pm
    Author:  Petteri Pulkkinen

  ==============================================================================
*/

#include "SynthVoice.h"

void FMsynthesis::setParameters(double carrierFrequency, double carrierAmlitude, double modulatorFrequency, double modAmplitude)
{
    carrier.setFrequency(carrierFrequency);
    carrier.setAmplitude(carrierAmlitude);
    modulator.setFrequency(modulatorFrequency);
    modulator.setAmplitude(modAmplitude);
}

// in main file:
// FMsynthesis olio;
// olio.setParameters(400, 1, 800, 2);