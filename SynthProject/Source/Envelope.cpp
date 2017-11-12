/*
  ==============================================================================

    Envelope.cpp
    Created: 10 Nov 2017 5:21:50pm
    Author:  Emilia Nuppumäki

  ==============================================================================
*/

#include "Envelope.h"


void Envelope::init(double fs)
{
    //change these
    sampleRate = fs;
    currLevel = minLevel;
    multiplier = 1.0;
    currStageLen = 0;
    stageSampleCounter = 0;
    values[OFF] = 0.0;
    values[ATTACK] = 0.05;
    values[DECAY] = 0.5;
    values[SUSTAIN] = 0.5;
    values[RELEASE] = 0.5;
}


void Envelope::startStage(Stage s) {
    currStage = s;
    currStageLen = 0;
    
    if (currStage == ATTACK || currStage == DECAY || currStage == RELEASE) {
        updateValues();
        currStageLen = values[currStage] * sampleRate;
        
    }
    
    switch (currStage) {
        case OFF:
            currLevel = 0;
            multiplier = 1.0;
            break;
            
        case ATTACK:
            currLevel = minLevel;
            setMultiplier(currLevel, 1.0, currStageLen);
            break;
            
        case DECAY:
            currLevel = 1.0;
            setMultiplier(currLevel, values[SUSTAIN], currStageLen);
            break;
            
        case SUSTAIN:
            currLevel = values[SUSTAIN];
            multiplier = 1.0;
            break;
            
        case RELEASE:
            //currLevel = values[SUSTAIN];
            setMultiplier(currLevel, minLevel, currStageLen);
            break;
    
        default : break;
    }
    
} // startStage

double Envelope::nextSample() {
    if (!(currStage == OFF || currStage == SUSTAIN)) {
        if (stageSampleCounter == currStageLen) {
			Stage next = static_cast<Stage>((currStage + 1) % 5);
            startStage(next);
        }
        else {
            currLevel *= multiplier;
            stageSampleCounter++;
        }
    }
    
    return currLevel;
} // nextSample

void Envelope::setMultiplier(double start, double end, unsigned long long int stageLen) {
    multiplier = (end - start) / (stageLen - 1);

} // setMultiplier

void Envelope::updateValues() {
    return;
} // updateValues
