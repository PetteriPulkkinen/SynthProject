/*
  ==============================================================================

    Envelope.h
    Created: 10 Nov 2017 4:56:30pm
    Author:  Emilia Nuppumäki

  ==============================================================================
*/

#pragma once

    
class Envelope {
    
public:

    enum Stage {
        OFF = 0,
        ATTACK,
        DECAY,
        SUSTAIN,
        RELEASE
    };

    Envelope(){}
    
    void init(double fs);
    ~Envelope() { }
    
    //called to start different stages of the envelope
    void startStage(Stage);
    
    void updateValues();
    
    double nextSample();
    
    
    

private:

    Stage currStage;
    double sampleRate;
    double currLevel;
    const double minLevel = 0.001;
    double multiplier;
    unsigned long long int currStageLen; //in samples
    unsigned long long int stageSampleCounter;
    
    double values[5] = {0}; //store the values of different stages here
    
    void setMultiplier(double start, double end, unsigned long long int stageLen);
    

};