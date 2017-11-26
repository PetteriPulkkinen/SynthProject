/*
  ==============================================================================

    Envelope.cpp
    Created: 10 Nov 2017 5:21:50pm
    Author:  Emilia Nuppumäki

  ==============================================================================
*/

#include "Envelope.h"
#include <cmath>
#include <iostream>

void Envelope::init(double fs)
{
    //change these
    sampleRate = fs;
    currLevel = minLevel;
    multiplier = 1.0;
    currStageLen = 0;
    stageSampleCounter = 0;
    values[OFF] = 0.0;
    values[ATTACK] = 0.5;
    values[DECAY] = 0.5;
    values[SUSTAIN] = 0.5;
    values[RELEASE] = 1;
    std::cout << "Envelope init" << std::endl;
}

bool Envelope::zeroValues() const{
    for (unsigned int i = 0; i < 5; i++) {
        if (values[i] != 0) {
            return false;
        }
    }
    return true;
} //zeroValues


void Envelope::startStage(Stage s) {
    currStage = s;
    currStageLen = 0;
	stageSampleCounter = 0;
	
    if (currStage == ATTACK || currStage == DECAY || currStage == RELEASE) {
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
            std::cout<< "CurrLevel: " << currLevel << "values: " << values[SUSTAIN] << "currStageLen: " << currStageLen << std::endl;
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
    if  (!(currStage == OFF || currStage == SUSTAIN)) {
        if (stageSampleCounter == currStageLen) {
			Stage next = static_cast<Stage>((currStage + 1) % 5);
            startStage(next);
            if (next == OFF)
                clearNote = true;
        }
        else {
            currLevel *= multiplier;
            stageSampleCounter++;
        }
    }
    if (currLevel >= 0){
        return currLevel;
    }
    else {
        return 0;
    }
} // nextSample

void Envelope::setMultiplier(double start, double end, unsigned long long int stageLen) {
    multiplier = 1 + (std::log(end/start)/(stageLen - 1));
} // setMultiplier

void Envelope::updateValues(double newVal, int s_int) {
	Stage s = static_cast<Stage>(s_int);
    if (s == SUSTAIN && newVal < 1e-10){
        newVal = 1e-10;
    }
    values[s] = newVal;
} // updateValues


const double Envelope::getValue(Envelope::Stage stage) const
{
    return values[stage];
}