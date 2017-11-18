/*
  ==============================================================================

  This is an automatically generated GUI class created by the Projucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Projucer version: 5.1.2

  ------------------------------------------------------------------------------

  The Projucer is part of the JUCE library - "Jules' Utility Class Extensions"
  Copyright (c) 2015 - ROLI Ltd.

  ==============================================================================
*/

#pragma once

//[Headers]     -- You can add your own extra header files here --
#include "../JuceLibraryCode/JuceHeader.h"
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Projucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class GUI  : public Component,
             public Slider::Listener
{
public:
    //==============================================================================
    GUI ();
    ~GUI();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.

    /* In this method you give all devices you want to modify from MainComponent. */

	// init function for GUI which could be used to transfer device pointers from mainComponent to GUI.
	// synan pointteri, ks. https://juce.com/doc/classSynthesiser
	// tietty luotu aani saadaan synth->getVoice(i)
    void init(Synthesiser* synth){
        this->synth = synth;
    }
	// samalla tavalla tuodaan filterit ja samplin rate
	void init2(IIRFilter* r) {
		this->filterRR = r;
	}
	void init3(IIRFilter* l) {
		this->filterLL = l;
	}
	void init4(double* s) {
		this->samplausrate = s;
	}


    //[/UserMethods]

    void paint (Graphics& g) override;
    void resized() override;
    void sliderValueChanged (Slider* sliderThatWasMoved) override;



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    Synthesiser* synth;

	// testing to pass cutoff and Q for filter


	double cutofff;	// additional f at end to distinguish from mainComponent's variable
	double QQ;
	IIRFilter* filterRR;
	IIRFilter* filterLL;
	double* samplausrate;	// double pointteri ja pelkka "samplausrate" palauttaa muistiosoitteen joka on tyyliin 00x....
							// itse double arvo saadaan ottamalla *samplausrate (?)


    //[/UserVariables]

    //==============================================================================
    ScopedPointer<Slider> DMod;
    ScopedPointer<Slider> SMod;
    ScopedPointer<Slider> RMod;
    ScopedPointer<Slider> AMod;
    ScopedPointer<Slider> DCarr;
    ScopedPointer<Slider> SCarr;
    ScopedPointer<Slider> RCarr;
    ScopedPointer<Slider> ACarr;
    ScopedPointer<Slider> slider5;
    ScopedPointer<Slider> slider12;
    ScopedPointer<Slider> slider13;
    ScopedPointer<Slider> MGslider;
    ScopedPointer<Slider> CGslider;
    ScopedPointer<Label> label;
    ScopedPointer<Label> label2;
    ScopedPointer<Label> label3;
    ScopedPointer<Label> label4;
    ScopedPointer<Label> label5;
    ScopedPointer<Slider> CNote;
    ScopedPointer<Slider> MNote;
    ScopedPointer<Label> label6;
    ScopedPointer<Label> Label7;
    ScopedPointer<Slider> Octave;
    ScopedPointer<Label> label8;
    ScopedPointer<Slider> Master;
    ScopedPointer<Label> label9;
    ScopedPointer<Label> label7;
    ScopedPointer<Label> label10;
    ScopedPointer<Label> label11;
    ScopedPointer<Label> label12;
    ScopedPointer<Label> label13;
    ScopedPointer<Label> label14;
    ScopedPointer<Label> label15;
    ScopedPointer<Label> label16;
    ScopedPointer<Label> label17;
    ScopedPointer<Label> label18;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (GUI)
};

//[EndFile] You can add extra defines here...
//[/EndFile]
