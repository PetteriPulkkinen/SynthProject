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
    
    void updateValues(double newVal, int s_int);
    
    double nextSample();
    
    bool shouldClearNote() {return clearNote;}
    
    void cleared() {clearNote = false;}
    

private:

    Stage currStage;
    double sampleRate;
    double currLevel;
    const double minLevel = 0.01;
    double multiplier;
    unsigned long long int currStageLen; //in samples
    unsigned long long int stageSampleCounter;
    bool clearNote = false;
    
    double values[5] = {0}; //store the values of different stages here
    
    void setMultiplier(double start, double end, unsigned long long int stageLen);
    

};