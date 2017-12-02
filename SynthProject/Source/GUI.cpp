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

//[Headers] You can add your own extra header files here...

//[/Headers]

#include "GUI.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
/*GUI::GUI (Devices* myDevices) : keyboardComponent(myDevices->keyboardState, MidiKeyboardComponent::horizontalKeyboard)*/
//[/MiscUserDefs]

//==============================================================================
GUI::GUI (Devices* myDevices) : keyboardComponent(myDevices->keyboardState, MidiKeyboardComponent::horizontalKeyboard)
{
    //[Constructor_pre] You can add your own custom stuff here..
    devices = myDevices;
    this->synth = &myDevices->FMSynth;
    this->cutoff = &myDevices->cutoff;
    this->Q = &myDevices->Q;
    samplausrate = &myDevices->samplingRate;

    addAndMakeVisible(keyboardComponent);

    //[/Constructor_pre]

    addAndMakeVisible (DMod = new Slider ("decay_modulator"));
    DMod->setRange (0, 2, 0);
    DMod->setSliderStyle (Slider::LinearVertical);
    DMod->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
    DMod->addListener (this);

    addAndMakeVisible (SMod = new Slider ("sustain_modulator"));
    SMod->setRange (0, 1, 0);
    SMod->setSliderStyle (Slider::LinearVertical);
    SMod->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
    SMod->addListener (this);

    addAndMakeVisible (RMod = new Slider ("release_modulator"));
    RMod->setRange (0, 8, 0);
    RMod->setSliderStyle (Slider::LinearVertical);
    RMod->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
    RMod->addListener (this);

    addAndMakeVisible (AMod = new Slider ("attack_modulator"));
    AMod->setRange (0, 2, 0);
    AMod->setSliderStyle (Slider::LinearVertical);
    AMod->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
    AMod->addListener (this);

    addAndMakeVisible (DCarr = new Slider ("decay_carrier"));
    DCarr->setRange (0, 2, 0);
    DCarr->setSliderStyle (Slider::LinearVertical);
    DCarr->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
    DCarr->addListener (this);

    addAndMakeVisible (SCarr = new Slider ("sustain_carrier"));
    SCarr->setRange (0, 1, 0);
    SCarr->setSliderStyle (Slider::LinearVertical);
    SCarr->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
    SCarr->addListener (this);

    addAndMakeVisible (RCarr = new Slider ("release_carrier"));
    RCarr->setRange (0, 8, 0);
    RCarr->setSliderStyle (Slider::LinearVertical);
    RCarr->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
    RCarr->addListener (this);

    addAndMakeVisible (ACarr = new Slider ("attack_carrier"));
    ACarr->setRange (0, 2, 0);
    ACarr->setSliderStyle (Slider::LinearVertical);
    ACarr->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
    ACarr->addListener (this);

    addAndMakeVisible (slider5 = new Slider ("mod_amp"));
    slider5->setRange (0, 20000, 0);
    slider5->setSliderStyle (Slider::Rotary);
    slider5->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
    slider5->addListener (this);
    slider5->setSkewFactor (0.2);

    addAndMakeVisible (slider12 = new Slider ("cutoff"));
    slider12->setRange (80, 16000, 0);
    slider12->setSliderStyle (Slider::Rotary);
    slider12->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 15);
    slider12->addListener (this);
    slider12->setSkewFactor (0.2);

    addAndMakeVisible (slider13 = new Slider ("lpQ"));
    slider13->setRange (1, 10, 0);
    slider13->setSliderStyle (Slider::Rotary);
    slider13->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 15);
    slider13->addListener (this);

    addAndMakeVisible (MGslider = new Slider ("ModulatorGain"));
    MGslider->setTooltip (TRANS("Mood"));
    MGslider->setRange (1, 10, 0);
    MGslider->setSliderStyle (Slider::Rotary);
    MGslider->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    MGslider->addListener (this);

    addAndMakeVisible (CGslider = new Slider ("CarrierGain"));
    CGslider->setRange (1, 10, 0);
    CGslider->setSliderStyle (Slider::Rotary);
    CGslider->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    CGslider->addListener (this);

    addAndMakeVisible (label = new Label ("new label",
                                          TRANS("Modulation Amplitude")));
    label->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    label->setJustificationType (Justification::centredLeft);
    label->setEditable (false, false, false);
    label->setColour (TextEditor::textColourId, Colours::black);
    label->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (label2 = new Label ("new label",
                                           TRANS("Modulator squeeze")));
    label2->setFont (Font (10.00f, Font::plain).withTypefaceStyle ("Regular"));
    label2->setJustificationType (Justification::centredLeft);
    label2->setEditable (false, false, false);
    label2->setColour (TextEditor::textColourId, Colours::black);
    label2->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (label3 = new Label ("new label",
                                           TRANS("Carrier squeeze")));
    label3->setFont (Font (10.00f, Font::plain).withTypefaceStyle ("Regular"));
    label3->setJustificationType (Justification::centredLeft);
    label3->setEditable (false, false, false);
    label3->setColour (TextEditor::textColourId, Colours::black);
    label3->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (label4 = new Label ("new label",
                                           TRANS("Cutoff")));
    label4->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    label4->setJustificationType (Justification::centredLeft);
    label4->setEditable (false, false, false);
    label4->setColour (TextEditor::textColourId, Colours::black);
    label4->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (label5 = new Label ("new label",
                                           TRANS("Q")));
    label5->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    label5->setJustificationType (Justification::centredLeft);
    label5->setEditable (false, false, false);
    label5->setColour (TextEditor::textColourId, Colours::black);
    label5->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (CNote = new Slider ("Carrier_Note"));
    CNote->setRange (-24, 24, 1);
    CNote->setSliderStyle (Slider::IncDecButtons);
    CNote->setTextBoxStyle (Slider::TextBoxLeft, false, 40, 20);
    CNote->addListener (this);

    addAndMakeVisible (MNote = new Slider ("Modulator_note"));
    MNote->setRange (-24, 24, 1);
    MNote->setSliderStyle (Slider::IncDecButtons);
    MNote->setTextBoxStyle (Slider::TextBoxLeft, false, 40, 20);
    MNote->addListener (this);

    addAndMakeVisible (label6 = new Label ("new label",
                                           TRANS("Carrier note")));
    label6->setFont (Font (10.00f, Font::plain).withTypefaceStyle ("Regular"));
    label6->setJustificationType (Justification::centredLeft);
    label6->setEditable (false, false, false);
    label6->setColour (TextEditor::textColourId, Colours::black);
    label6->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (Label7 = new Label ("new label",
                                           TRANS("Modulator note")));
    Label7->setFont (Font (10.00f, Font::plain).withTypefaceStyle ("Regular"));
    Label7->setJustificationType (Justification::centredLeft);
    Label7->setEditable (false, false, false);
    Label7->setColour (TextEditor::textColourId, Colours::black);
    Label7->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (Octave = new Slider ("Octave_slider"));
    Octave->setRange (-4, 4, 1);
    Octave->setSliderStyle (Slider::IncDecButtons);
    Octave->setTextBoxStyle (Slider::TextBoxLeft, false, 40, 20);
    Octave->addListener (this);

    addAndMakeVisible (label8 = new Label ("new label",
                                           TRANS("Octave\n")));
    label8->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    label8->setJustificationType (Justification::centredLeft);
    label8->setEditable (false, false, false);
    label8->setColour (TextEditor::textColourId, Colours::black);
    label8->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (Master = new Slider ("Master_slider"));
    Master->setRange (0, 1, 0.1);
    Master->setSliderStyle (Slider::LinearHorizontal);
    Master->setTextBoxStyle (Slider::TextBoxLeft, false, 40, 20);
    Master->addListener (this);

    addAndMakeVisible (label9 = new Label ("new label",
                                           TRANS("Volume")));
    label9->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    label9->setJustificationType (Justification::centredLeft);
    label9->setEditable (false, false, false);
    label9->setColour (TextEditor::textColourId, Colours::black);
    label9->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (label7 = new Label ("new label",
                                           TRANS("Carrier Envelope")));
    label7->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    label7->setJustificationType (Justification::centred);
    label7->setEditable (false, false, false);
    label7->setColour (TextEditor::textColourId, Colours::black);
    label7->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (label10 = new Label ("new label",
                                            TRANS("Modulation Envelope")));
    label10->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    label10->setJustificationType (Justification::centred);
    label10->setEditable (false, false, false);
    label10->setColour (TextEditor::textColourId, Colours::black);
    label10->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (label11 = new Label ("new label",
                                            TRANS("A")));
    label11->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    label11->setJustificationType (Justification::centred);
    label11->setEditable (false, false, false);
    label11->setColour (TextEditor::textColourId, Colours::black);
    label11->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (label12 = new Label ("new label",
                                            TRANS("D")));
    label12->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    label12->setJustificationType (Justification::centred);
    label12->setEditable (false, false, false);
    label12->setColour (TextEditor::textColourId, Colours::black);
    label12->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (label13 = new Label ("new label",
                                            TRANS("S")));
    label13->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    label13->setJustificationType (Justification::centred);
    label13->setEditable (false, false, false);
    label13->setColour (TextEditor::textColourId, Colours::black);
    label13->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (label14 = new Label ("new label",
                                            TRANS("R")));
    label14->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    label14->setJustificationType (Justification::centred);
    label14->setEditable (false, false, false);
    label14->setColour (TextEditor::textColourId, Colours::black);
    label14->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (label15 = new Label ("new label",
                                            TRANS("A")));
    label15->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    label15->setJustificationType (Justification::centred);
    label15->setEditable (false, false, false);
    label15->setColour (TextEditor::textColourId, Colours::black);
    label15->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (label16 = new Label ("new label",
                                            TRANS("D")));
    label16->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    label16->setJustificationType (Justification::centred);
    label16->setEditable (false, false, false);
    label16->setColour (TextEditor::textColourId, Colours::black);
    label16->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (label17 = new Label ("new label",
                                            TRANS("S")));
    label17->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    label17->setJustificationType (Justification::centred);
    label17->setEditable (false, false, false);
    label17->setColour (TextEditor::textColourId, Colours::black);
    label17->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (label18 = new Label ("new label",
                                            TRANS("R")));
    label18->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    label18->setJustificationType (Justification::centred);
    label18->setEditable (false, false, false);
    label18->setColour (TextEditor::textColourId, Colours::black);
    label18->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (LFOamp = new Slider ("lfo_amp"));
    LFOamp->setRange (0, 2000, 0);
    LFOamp->setSliderStyle (Slider::Rotary);
    LFOamp->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 15);
    LFOamp->addListener (this);
    LFOamp->setSkewFactor (0.25);

    addAndMakeVisible (LFOfreq = new Slider ("lfo_freq"));
    LFOfreq->setRange (0, 100, 0);
    LFOfreq->setSliderStyle (Slider::Rotary);
    LFOfreq->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 15);
    LFOfreq->addListener (this);
    LFOfreq->setSkewFactor (0.25);

    addAndMakeVisible (label19 = new Label ("new label",
                                            TRANS("LFO amplitude\n")));
    label19->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    label19->setJustificationType (Justification::centredLeft);
    label19->setEditable (false, false, false);
    label19->setColour (TextEditor::textColourId, Colours::black);
    label19->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (label20 = new Label ("new label",
                                            TRANS("LFO frequency")));
    label20->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    label20->setJustificationType (Justification::centredLeft);
    label20->setEditable (false, false, false);
    label20->setColour (TextEditor::textColourId, Colours::black);
    label20->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (comboBox = new ComboBox ("new combo box"));
    comboBox->setEditableText (true);
    comboBox->setJustificationType (Justification::centredLeft);
    comboBox->setTextWhenNothingSelected (TRANS("Add sound"));
    comboBox->setTextWhenNoChoicesAvailable (TRANS("Add sound"));
    comboBox->addListener (this);

    addAndMakeVisible (textButton = new TextButton ("new button"));
    textButton->setButtonText (TRANS("Add"));
    textButton->addListener (this);

    addAndMakeVisible (textButton2 = new TextButton ("new button"));
    textButton2->setButtonText (TRANS("Update"));
    textButton2->addListener (this);

    addAndMakeVisible (textButton3 = new TextButton ("new button"));
    textButton3->setButtonText (TRANS("Delete"));
    textButton3->addListener (this);


    //[UserPreSize]

    sliders.push_back(&DMod);
    sliders.push_back(&SMod);
    sliders.push_back(&RMod);
    sliders.push_back(&AMod);
    sliders.push_back(&DCarr);
    sliders.push_back(&SCarr);
    sliders.push_back(&RCarr);
    sliders.push_back(&ACarr);
    sliders.push_back(&slider5);
    sliders.push_back(&slider12);
    sliders.push_back(&slider13);
    sliders.push_back(&MGslider);
    sliders.push_back(&CGslider);
    sliders.push_back(&CNote);
    sliders.push_back(&MNote);
    sliders.push_back(&Octave);
    sliders.push_back(&Master);
    sliders.push_back(&LFOamp);
    sliders.push_back(&LFOfreq);
    //[/UserPreSize]

    setSize (800, 600);


    //[Constructor] You can add your own custom stuff here..
    regenerateCB();

    //[/Constructor]
}

GUI::~GUI()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    sliders.clear();
    //[/Destructor_pre]

    DMod = nullptr;
    SMod = nullptr;
    RMod = nullptr;
    AMod = nullptr;
    DCarr = nullptr;
    SCarr = nullptr;
    RCarr = nullptr;
    ACarr = nullptr;
    slider5 = nullptr;
    slider12 = nullptr;
    slider13 = nullptr;
    MGslider = nullptr;
    CGslider = nullptr;
    label = nullptr;
    label2 = nullptr;
    label3 = nullptr;
    label4 = nullptr;
    label5 = nullptr;
    CNote = nullptr;
    MNote = nullptr;
    label6 = nullptr;
    Label7 = nullptr;
    Octave = nullptr;
    label8 = nullptr;
    Master = nullptr;
    label9 = nullptr;
    label7 = nullptr;
    label10 = nullptr;
    label11 = nullptr;
    label12 = nullptr;
    label13 = nullptr;
    label14 = nullptr;
    label15 = nullptr;
    label16 = nullptr;
    label17 = nullptr;
    label18 = nullptr;
    LFOamp = nullptr;
    LFOfreq = nullptr;
    label19 = nullptr;
    label20 = nullptr;
    comboBox = nullptr;
    textButton = nullptr;
    textButton2 = nullptr;
    textButton3 = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void GUI::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colour (0xff453434));

    {
        int x = -10, y = 480, width = 820, height = 130;
        Colour fillColour = Colour (0xff262020);
        Colour strokeColour = Colour (0xff3e323c);
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.fillRect (x, y, width, height);
        g.setColour (strokeColour);
        g.drawRect (x, y, width, height, 6);

    }

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void GUI::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    DMod->setBounds (598, 362, 40, 110);
    SMod->setBounds (646, 362, 40, 110);
    RMod->setBounds (694, 362, 40, 110);
    AMod->setBounds (550, 362, 40, 110);
    DCarr->setBounds (86, 370, 40, 100);
    SCarr->setBounds (134, 370, 40, 100);
    RCarr->setBounds (182, 370, 40, 100);
    ACarr->setBounds (40, 370, 40, 100);
    slider5->setBounds (56, 80, 150, 150);
    slider12->setBounds (480, 200, 180, 100);
    slider13->setBounds (616, 200, 180, 100);
    MGslider->setBounds (240, 200, 65, 65);
    CGslider->setBounds (240, 56, 65, 65);
    label->setBounds (56, 48, 150, 24);
    label2->setBounds (240, 176, 150, 24);
    label3->setBounds (240, 40, 112, 24);
    label4->setBounds (536, 176, 48, 24);
    label5->setBounds (664, 176, 150, 24);
    CNote->setBounds (32, 280, 100, 25);
    MNote->setBounds (152, 280, 100, 25);
    label6->setBounds (24, 256, 64, 24);
    Label7->setBounds (144, 256, 72, 24);
    Octave->setBounds (688, 8, 100, 24);
    label8->setBounds (632, 8, 56, 16);
    Master->setBounds (488, 8, 125, 25);
    label9->setBounds (424, 8, 150, 16);
    label7->setBounds (56, 320, 150, 24);
    label10->setBounds (568, 314, 150, 24);
    label11->setBounds (48, 350, 24, 24);
    label12->setBounds (96, 350, 24, 24);
    label13->setBounds (144, 350, 24, 24);
    label14->setBounds (192, 350, 24, 24);
    label15->setBounds (556, 340, 24, 24);
    label16->setBounds (604, 340, 24, 24);
    label17->setBounds (652, 340, 24, 24);
    label18->setBounds (700, 340, 24, 24);
    LFOamp->setBounds (480, 72, 180, 100);
    LFOfreq->setBounds (616, 72, 180, 100);
    label19->setBounds (520, 48, 112, 24);
    label20->setBounds (656, 48, 150, 24);
    comboBox->setBounds (56, 8, 150, 24);
    textButton->setBounds (216, 8, 48, 24);
    textButton2->setBounds (272, 8, 48, 24);
    textButton3->setBounds (328, 8, 48, 24);
    //[UserResized] Add your own custom resize handling here..
    keyboardComponent.setBounds(0, getHeight()-getHeight()/6, getWidth(), getHeight()/6);
    //[/UserResized]
}

void GUI::sliderValueChanged (Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
    //[/UsersliderValueChanged_Pre]

    if (sliderThatWasMoved == DMod)
    {
        //[UserSliderCode_DMod] -- add your slider handling code here..
        for (int i = 0; i < synth->getNumVoices(); i++){
            FMsynthesis* voice = (FMsynthesis*) synth->getVoice(i);
            voice->getModulator().getEnvelope().updateValues(DMod->getValue(), 2);
        }
        //[/UserSliderCode_DMod]
    }
    else if (sliderThatWasMoved == SMod)
    {
        //[UserSliderCode_SMod] -- add your slider handling code here..
        for (int i = 0; i < synth->getNumVoices(); i++){
            FMsynthesis* voice = (FMsynthesis*) synth->getVoice(i);
            voice->getModulator().getEnvelope().updateValues(SMod->getValue(), 3);
        }
        //[/UserSliderCode_SMod]
    }
    else if (sliderThatWasMoved == RMod)
    {
        //[UserSliderCode_RMod] -- add your slider handling code here..
        for (int i = 0; i < synth->getNumVoices(); i++){
            FMsynthesis* voice = (FMsynthesis*) synth->getVoice(i);
            voice->getModulator().getEnvelope().updateValues(RMod->getValue(), 4);
        }
        //[/UserSliderCode_RMod]
    }
    else if (sliderThatWasMoved == AMod)
    {
        //[UserSliderCode_AMod] -- add your slider handling code here..
        for (int i = 0; i < synth->getNumVoices(); i++){
            FMsynthesis* voice = (FMsynthesis*) synth->getVoice(i);
            voice->getModulator().getEnvelope().updateValues(AMod->getValue(), 1);
        }
        //[/UserSliderCode_AMod]
    }
    else if (sliderThatWasMoved == DCarr)
    {
        //[UserSliderCode_DCarr] -- add your slider handling code here..
        for (int i = 0; i < synth->getNumVoices(); i++){
            FMsynthesis* voice = (FMsynthesis*) synth->getVoice(i);
            voice->getCarrier().getEnvelope().updateValues(DCarr->getValue(), 2);
        }
        //[/UserSliderCode_DCarr]
    }
    else if (sliderThatWasMoved == SCarr)
    {
        //[UserSliderCode_SCarr] -- add your slider handling code here..
        for (int i = 0; i < synth->getNumVoices(); i++){
            FMsynthesis* voice = (FMsynthesis*) synth->getVoice(i);
            voice->getCarrier().getEnvelope().updateValues(SCarr->getValue(), 3);
        }
        //[/UserSliderCode_SCarr]
    }
    else if (sliderThatWasMoved == RCarr)
    {
        //[UserSliderCode_RCarr] -- add your slider handling code here..
        for (int i = 0; i < synth->getNumVoices(); i++){
            FMsynthesis* voice = (FMsynthesis*) synth->getVoice(i);
            voice->getCarrier().getEnvelope().updateValues(RCarr->getValue(), 4);
        }
        //[/UserSliderCode_RCarr]
    }
    else if (sliderThatWasMoved == ACarr)
    {
        //[UserSliderCode_ACarr] -- add your slider handling code here..
        for (int i = 0; i < synth->getNumVoices(); i++){
            FMsynthesis* voice = (FMsynthesis*) synth->getVoice(i);
            voice->getCarrier().getEnvelope().updateValues(ACarr->getValue(), 1);
        }
        //[/UserSliderCode_ACarr]
    }
    else if (sliderThatWasMoved == slider5)
    {
        //[UserSliderCode_slider5] -- add your slider handling code here..
		// ks. SynthVoice.h (getModulator palauttaa moduloivan aallon) ja sitten Oscillator.h
		// getVoice on Synthesiser luokan metodi, palauttaa luodun aanen MainComponentissa (4kpl)
		// getModulator() palauttaa sita vastaavan moduloivan signaalin (ks.oscillator.h metodi) ja sitten muokataan sen amplitudia

		for (int i = 0; i < synth->getNumVoices(); i++) {
			FMsynthesis* voice = (FMsynthesis*)synth->getVoice(i);
			voice->getModulator().setAmplitude(slider5->getValue());
		}

		// the sound changes while dragging but becomes original after pressed the midi button again?
		// maybe because in synthvoice.cpp in ::startnote the amplitude is set back to 4400?
		// solution: i commented out the ::startnote line that gives amplitude for modulating signal

        //[/UserSliderCode_slider5]
    }
    else if (sliderThatWasMoved == slider12)
    {
        //[UserSliderCode_slider12] -- add your slider handling code here..
		// uudet filterit luodaan taman muutoksen myota
		/*
		error tulee kun koittaa liikuttaa slideria, tassa ovat raja-ehdot:
		(sampleRate > 0.0);
		(frequency > 0.0 && frequency <= sampleRate * 0.5);
		jassert (Q > 0.0);
		*/
		// nyt on suurin osa erroreista hoidettu slidereiden setRangedilla PAITSI tuo <= sampleRate*0.5,
		// eli errorii tulee jos slider12 vaannetaan yli 0.5*samplerate
        *cutoff = slider12->getValue();
        //[/UserSliderCode_slider12]
    }
    else if (sliderThatWasMoved == slider13)
    {
        //[UserSliderCode_slider13] -- add your slider handling code here..
		// hieman sama homma kuin slider12 tapauksessa
        *Q = slider13->getValue();
        //[/UserSliderCode_slider13]
    }
    else if (sliderThatWasMoved == MGslider)
    {
        //[UserSliderCode_MGslider] -- add your slider handling code here..
        for (int i = 0; i < synth->getNumVoices(); i++){
            FMsynthesis* voice = (FMsynthesis*) synth->getVoice(i);
            voice->getModulator().setGain(MGslider->getValue());
        }
        //[/UserSliderCode_MGslider]
    }
    else if (sliderThatWasMoved == CGslider)
    {
        //[UserSliderCode_CGslider] -- add your slider handling code here..
        for (int i = 0; i < synth->getNumVoices();i++){
            FMsynthesis* voice = (FMsynthesis*) synth->getVoice(i);
            voice->getCarrier().setGain(CGslider->getValue());
        }
        //[/UserSliderCode_CGslider]
    }
    else if (sliderThatWasMoved == CNote)
    {
        //[UserSliderCode_CNote] -- add your slider handling code here..
        for (int i = 0; i < synth->getNumVoices(); i++){
            FMsynthesis* voice = (FMsynthesis*) synth->getVoice(i);
            voice->setCarrier_noteNum(CNote->getValue());
        }
        //[/UserSliderCode_CNote]
    }
    else if (sliderThatWasMoved == MNote)
    {
        //[UserSliderCode_MNote] -- add your slider handling code here..
        for (int i = 0; i < synth->getNumVoices(); i++){
            FMsynthesis* voice = (FMsynthesis*) synth->getVoice(i);
            voice->setModulator_noteNum(MNote->getValue());
        }
        //[/UserSliderCode_MNote]
    }
    else if (sliderThatWasMoved == Octave)
    {
        //[UserSliderCode_Octave] -- add your slider handling code here..
        for (int i = 0; i < synth->getNumVoices(); i++){
            FMsynthesis* voice = (FMsynthesis*) synth->getVoice(i);
            voice->setOctave(Octave->getValue());
        }
        //[/UserSliderCode_Octave]
    }
    else if (sliderThatWasMoved == Master)
    {
        //[UserSliderCode_Master] -- add your slider handling code here..
        for (int i = 0; i < synth->getNumVoices(); i++){
            FMsynthesis* voice = (FMsynthesis*) synth->getVoice(i);
            voice->setMasterLevel(Master->getValue());
        }
        //[/UserSliderCode_Master]
    }
    else if (sliderThatWasMoved == LFOamp)
    {
        //[UserSliderCode_LFOamp] -- add your slider handling code here..
        devices->LFO.setAmplitude(LFOamp->getValue());
        //[/UserSliderCode_LFOamp]
    }
    else if (sliderThatWasMoved == LFOfreq)
    {
        //[UserSliderCode_LFOfreq] -- add your slider handling code here..
        devices->LFO.setFrequency(LFOfreq->getValue());
        //[/UserSliderCode_LFOfreq]
    }

    //[UsersliderValueChanged_Post]
    //[/UsersliderValueChanged_Post]
}

void GUI::comboBoxChanged (ComboBox* comboBoxThatHasChanged)
{
    //[UsercomboBoxChanged_Pre]
    //[/UsercomboBoxChanged_Pre]

    if (comboBoxThatHasChanged == comboBox)
    {
        //[UserComboBoxCode_comboBox] -- add your combo box handling code here..
        int id = comboBoxThatHasChanged->getSelectedId();
        if (id){
            loadSliderValues(id);
        }
        //[/UserComboBoxCode_comboBox]
    }

    //[UsercomboBoxChanged_Post]
    //[/UsercomboBoxChanged_Post]
}

void GUI::buttonClicked (Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == textButton)
    {
        //[UserButtonCode_textButton] -- add your button handler code here..
        int id = comboBox->getNumItems()+1;
        std::cout << id << std::endl;
        saveSliderValues(id);
        comboBox->clear();
        regenerateCB();
        //[/UserButtonCode_textButton]
    }
    else if (buttonThatWasClicked == textButton2)
    {
        //[UserButtonCode_textButton2] -- add your button handler code here..
        //update button
        int id = comboBox->getSelectedId();
        if (id){
            updateSliderValues(id);
            std::cout << id << std::endl;
        }
        //[/UserButtonCode_textButton2]
    }
    else if (buttonThatWasClicked == textButton3)
    {
        //[UserButtonCode_textButton3] -- add your button handler code here..
        //remove button
        int id = comboBox->getSelectedId();
        if (id){
            removeSliderValues(id);
            comboBox->clear();
            regenerateCB();
        }
        //[/UserButtonCode_textButton3]
    }

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
void GUI::setSliderValues(){
    slider12->setValue(devices->cutoff);
    Master->setValue(1);
    std::cout << "Set slider values " << std::endl;
    for (int i = 0; i < synth->getNumVoices(); i++){
        FMsynthesis* voice = (FMsynthesis*) synth->getVoice(i);
        Envelope cenv = voice->getCarrier().getEnvelope();
        std::cout << "gey" << std::endl;
        ACarr->setValue(cenv.getValue(Envelope::Stage::ATTACK));
        DCarr->setValue(cenv.getValue(Envelope::Stage::DECAY));
        SCarr->setValue(cenv.getValue(Envelope::Stage::SUSTAIN));
        RCarr->setValue(cenv.getValue(Envelope::Stage::RELEASE));

        Envelope menv = voice->getModulator().getEnvelope();
        AMod->setValue(menv.getValue(Envelope::Stage::ATTACK));
        DMod->setValue(menv.getValue(Envelope::Stage::DECAY));
        SMod->setValue(menv.getValue(Envelope::Stage::SUSTAIN));
        RMod->setValue(menv.getValue(Envelope::Stage::RELEASE));
    }
    this->LFOamp->setValue(devices->LFO.getAmplitude());
    this->LFOfreq->setValue(devices->LFO.getFrequency());
}

void GUI::saveSliderValues(int ID)
{
    std::cout << "Saving sounds to ID: " << ID << std::endl;
    std::cout << "Combobox elements: " << comboBox->getNumItems() << std::endl;

    for (auto i : sliders){

        //db.updateValue(ID, (*i)->getName().toStdString(), (*i)->getValue());

        db.insertToDB(ID, (*i)->getName().toStdString(), (*i)->getValue());

    }
}

void GUI::loadSliderValues(int ID)
{
    for (auto i : sliders){
        try{
            double value = db.getFromDB(ID, (*i)->getName().toStdString());
            (*i)->setValue(value);
        }
        catch(string e){
            DBG("Can't load the slider values");
        }
    }
}

void GUI::updateSliderValues(int ID)
{
    for (auto i : sliders){
        try {
            db.updateValue(ID, (*i)->getName().toStdString(), (*i)->getValue());
        }
        catch(string e){
            DBG("Can't update the slider value.");
        }
    }
}

void GUI::removeSliderValues(int ID)
{
    try{
        db.removeSound(ID);
    }
    catch(string msg){
        std::cout << msg << std::endl;
    }
}

void GUI::regenerateCB()
{
    vector<int> vec = db.getIDs();
    for (int i : vec){
        comboBox->addItem("Sound "+std::to_string(i), i);
    }
}
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="GUI" componentName="" parentClasses="public Component"
                 constructorParams="" variableInitialisers="" snapPixels="8" snapActive="1"
                 snapShown="1" overlayOpacity="0.330" fixedSize="1" initialWidth="800"
                 initialHeight="600">
  <BACKGROUND backgroundColour="ff453434">
    <RECT pos="-10 480 820 130" fill="solid: ff262020" hasStroke="1" stroke="6.2, mitered, butt"
          strokeColour="solid: ff3e323c"/>
  </BACKGROUND>
  <SLIDER name="decay_modulator" id="63bd38afd51ecc43" memberName="DMod"
          virtualName="" explicitFocusOrder="0" pos="598 362 40 110" min="0"
          max="2" int="0" style="LinearVertical" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"
          needsCallback="1"/>
  <SLIDER name="sustain_modulator" id="405706fe9d67c034" memberName="SMod"
          virtualName="" explicitFocusOrder="0" pos="646 362 40 110" min="0"
          max="1" int="0" style="LinearVertical" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"
          needsCallback="1"/>
  <SLIDER name="release_modulator" id="f8ae9f1895e9f7cb" memberName="RMod"
          virtualName="" explicitFocusOrder="0" pos="694 362 40 110" min="0"
          max="8" int="0" style="LinearVertical" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"
          needsCallback="1"/>
  <SLIDER name="attack_modulator" id="55065483c5cfda78" memberName="AMod"
          virtualName="" explicitFocusOrder="0" pos="550 362 40 110" min="0"
          max="2" int="0" style="LinearVertical" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"
          needsCallback="1"/>
  <SLIDER name="decay_carrier" id="4ff5356e4f65685c" memberName="DCarr"
          virtualName="" explicitFocusOrder="0" pos="86 370 40 100" min="0"
          max="2" int="0" style="LinearVertical" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"
          needsCallback="1"/>
  <SLIDER name="sustain_carrier" id="57947018b5f68fb1" memberName="SCarr"
          virtualName="" explicitFocusOrder="0" pos="134 370 40 100" min="0"
          max="1" int="0" style="LinearVertical" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"
          needsCallback="1"/>
  <SLIDER name="release_carrier" id="a84ab44e65d8e2a3" memberName="RCarr"
          virtualName="" explicitFocusOrder="0" pos="182 370 40 100" min="0"
          max="8" int="0" style="LinearVertical" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"
          needsCallback="1"/>
  <SLIDER name="attack_carrier" id="8b3f507f3e828678" memberName="ACarr"
          virtualName="" explicitFocusOrder="0" pos="40 370 40 100" min="0"
          max="2" int="0" style="LinearVertical" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"
          needsCallback="1"/>
  <SLIDER name="mod_amp" id="c00cedec3bec0b3a" memberName="slider5" virtualName=""
          explicitFocusOrder="0" pos="56 80 150 150" min="0" max="20000"
          int="0" style="Rotary" textBoxPos="TextBoxBelow" textBoxEditable="1"
          textBoxWidth="80" textBoxHeight="20" skewFactor="0.2000000000000000111"
          needsCallback="1"/>
  <SLIDER name="cutoff" id="67919200e11f9bf" memberName="slider12" virtualName=""
          explicitFocusOrder="0" pos="480 200 180 100" min="80" max="16000"
          int="0" style="Rotary" textBoxPos="TextBoxBelow" textBoxEditable="1"
          textBoxWidth="80" textBoxHeight="15" skewFactor="0.2000000000000000111"
          needsCallback="1"/>
  <SLIDER name="lpQ" id="b1e16e36f222738c" memberName="slider13" virtualName=""
          explicitFocusOrder="0" pos="616 200 180 100" min="1" max="10"
          int="0" style="Rotary" textBoxPos="TextBoxBelow" textBoxEditable="1"
          textBoxWidth="80" textBoxHeight="15" skewFactor="1" needsCallback="1"/>
  <SLIDER name="ModulatorGain" id="c16b303c43bf1bf5" memberName="MGslider"
          virtualName="" explicitFocusOrder="0" pos="240 200 65 65" tooltip="Mood"
          min="1" max="10" int="0" style="Rotary" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"
          needsCallback="1"/>
  <SLIDER name="CarrierGain" id="c7e3cca1ca161860" memberName="CGslider"
          virtualName="" explicitFocusOrder="0" pos="240 56 65 65" min="1"
          max="10" int="0" style="Rotary" textBoxPos="NoTextBox" textBoxEditable="1"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1" needsCallback="1"/>
  <LABEL name="new label" id="e01e4267bc176f75" memberName="label" virtualName=""
         explicitFocusOrder="0" pos="56 48 150 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Modulation Amplitude" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" kerning="0" bold="0" italic="0" justification="33"/>
  <LABEL name="new label" id="217d3b45dfd7e65e" memberName="label2" virtualName=""
         explicitFocusOrder="0" pos="240 176 150 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Modulator squeeze" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="10" kerning="0" bold="0" italic="0" justification="33"/>
  <LABEL name="new label" id="6ca0987724a3d3d8" memberName="label3" virtualName=""
         explicitFocusOrder="0" pos="240 40 112 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Carrier squeeze" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="10" kerning="0" bold="0" italic="0" justification="33"/>
  <LABEL name="new label" id="f5078fbc9271d49f" memberName="label4" virtualName=""
         explicitFocusOrder="0" pos="536 176 48 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Cutoff" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         kerning="0" bold="0" italic="0" justification="33"/>
  <LABEL name="new label" id="456e730c95b7b6c3" memberName="label5" virtualName=""
         explicitFocusOrder="0" pos="664 176 150 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Q" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         kerning="0" bold="0" italic="0" justification="33"/>
  <SLIDER name="Carrier_Note" id="44cf394519a99d3c" memberName="CNote"
          virtualName="" explicitFocusOrder="0" pos="32 280 100 25" min="-24"
          max="24" int="1" style="IncDecButtons" textBoxPos="TextBoxLeft"
          textBoxEditable="1" textBoxWidth="40" textBoxHeight="20" skewFactor="1"
          needsCallback="1"/>
  <SLIDER name="Modulator_note" id="29f6189d75cefb5e" memberName="MNote"
          virtualName="" explicitFocusOrder="0" pos="152 280 100 25" min="-24"
          max="24" int="1" style="IncDecButtons" textBoxPos="TextBoxLeft"
          textBoxEditable="1" textBoxWidth="40" textBoxHeight="20" skewFactor="1"
          needsCallback="1"/>
  <LABEL name="new label" id="6cdcd4d6b226ee9c" memberName="label6" virtualName=""
         explicitFocusOrder="0" pos="24 256 64 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Carrier note" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="10" kerning="0" bold="0" italic="0" justification="33"/>
  <LABEL name="new label" id="56ac12c85a60c7b2" memberName="Label7" virtualName=""
         explicitFocusOrder="0" pos="144 256 72 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Modulator note" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="10" kerning="0" bold="0" italic="0" justification="33"/>
  <SLIDER name="Octave_slider" id="a20e4f22f1d8e98c" memberName="Octave"
          virtualName="" explicitFocusOrder="0" pos="688 8 100 24" min="-4"
          max="4" int="1" style="IncDecButtons" textBoxPos="TextBoxLeft"
          textBoxEditable="1" textBoxWidth="40" textBoxHeight="20" skewFactor="1"
          needsCallback="1"/>
  <LABEL name="new label" id="b31e365d33e4b659" memberName="label8" virtualName=""
         explicitFocusOrder="0" pos="632 8 56 16" edTextCol="ff000000"
         edBkgCol="0" labelText="Octave&#10;" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" kerning="0" bold="0" italic="0" justification="33"/>
  <SLIDER name="Master_slider" id="a6a0247f868ec1e9" memberName="Master"
          virtualName="" explicitFocusOrder="0" pos="488 8 125 25" min="0"
          max="1" int="0.10000000000000000555" style="LinearHorizontal"
          textBoxPos="TextBoxLeft" textBoxEditable="1" textBoxWidth="40"
          textBoxHeight="20" skewFactor="1" needsCallback="1"/>
  <LABEL name="new label" id="b2a455da84b24907" memberName="label9" virtualName=""
         explicitFocusOrder="0" pos="424 8 150 16" edTextCol="ff000000"
         edBkgCol="0" labelText="Volume" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         kerning="0" bold="0" italic="0" justification="33"/>
  <LABEL name="new label" id="d80292204dbc0ae1" memberName="label7" virtualName=""
         explicitFocusOrder="0" pos="56 320 150 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Carrier Envelope" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" kerning="0" bold="0" italic="0" justification="36"/>
  <LABEL name="new label" id="f61c75d57510852f" memberName="label10" virtualName=""
         explicitFocusOrder="0" pos="568 314 150 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Modulation Envelope" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" kerning="0" bold="0" italic="0" justification="36"/>
  <LABEL name="new label" id="405c0e9e3d721629" memberName="label11" virtualName=""
         explicitFocusOrder="0" pos="48 350 24 24" edTextCol="ff000000"
         edBkgCol="0" labelText="A" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         kerning="0" bold="0" italic="0" justification="36"/>
  <LABEL name="new label" id="461454e442e1f0db" memberName="label12" virtualName=""
         explicitFocusOrder="0" pos="96 350 24 24" edTextCol="ff000000"
         edBkgCol="0" labelText="D" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         kerning="0" bold="0" italic="0" justification="36"/>
  <LABEL name="new label" id="df13ec09dac5d0cf" memberName="label13" virtualName=""
         explicitFocusOrder="0" pos="144 350 24 24" edTextCol="ff000000"
         edBkgCol="0" labelText="S" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         kerning="0" bold="0" italic="0" justification="36"/>
  <LABEL name="new label" id="85c20edd0198df6c" memberName="label14" virtualName=""
         explicitFocusOrder="0" pos="192 350 24 24" edTextCol="ff000000"
         edBkgCol="0" labelText="R" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         kerning="0" bold="0" italic="0" justification="36"/>
  <LABEL name="new label" id="9eb94f55b1fb0b98" memberName="label15" virtualName=""
         explicitFocusOrder="0" pos="556 340 24 24" edTextCol="ff000000"
         edBkgCol="0" labelText="A" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         kerning="0" bold="0" italic="0" justification="36"/>
  <LABEL name="new label" id="ab7df29838214b5b" memberName="label16" virtualName=""
         explicitFocusOrder="0" pos="604 340 24 24" edTextCol="ff000000"
         edBkgCol="0" labelText="D" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         kerning="0" bold="0" italic="0" justification="36"/>
  <LABEL name="new label" id="46221d7eaa6bb7a5" memberName="label17" virtualName=""
         explicitFocusOrder="0" pos="652 340 24 24" edTextCol="ff000000"
         edBkgCol="0" labelText="S" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         kerning="0" bold="0" italic="0" justification="36"/>
  <LABEL name="new label" id="ca4204ff23ce9bb9" memberName="label18" virtualName=""
         explicitFocusOrder="0" pos="700 340 24 24" edTextCol="ff000000"
         edBkgCol="0" labelText="R" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         kerning="0" bold="0" italic="0" justification="36"/>
  <SLIDER name="lfo_amp" id="157fdc80e9c9a930" memberName="LFOamp" virtualName=""
          explicitFocusOrder="0" pos="480 72 180 100" min="0" max="2000"
          int="0" style="Rotary" textBoxPos="TextBoxBelow" textBoxEditable="1"
          textBoxWidth="80" textBoxHeight="15" skewFactor="0.25" needsCallback="1"/>
  <SLIDER name="lfo_freq" id="95af64a224c04263" memberName="LFOfreq" virtualName=""
          explicitFocusOrder="0" pos="616 72 180 100" min="0" max="100"
          int="0" style="Rotary" textBoxPos="TextBoxBelow" textBoxEditable="1"
          textBoxWidth="80" textBoxHeight="15" skewFactor="0.25" needsCallback="1"/>
  <LABEL name="new label" id="980c30226afa9fdd" memberName="label19" virtualName=""
         explicitFocusOrder="0" pos="520 48 112 24" edTextCol="ff000000"
         edBkgCol="0" labelText="LFO amplitude&#10;" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" kerning="0" bold="0" italic="0" justification="33"/>
  <LABEL name="new label" id="7ab0cd232f6cc0ff" memberName="label20" virtualName=""
         explicitFocusOrder="0" pos="656 48 150 24" edTextCol="ff000000"
         edBkgCol="0" labelText="LFO frequency" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" kerning="0" bold="0" italic="0" justification="33"/>
  <COMBOBOX name="new combo box" id="fa3ffdf4bf207e43" memberName="comboBox"
            virtualName="" explicitFocusOrder="0" pos="56 8 150 24" editable="1"
            layout="33" items="" textWhenNonSelected="Add sound" textWhenNoItems="Add sound"/>
  <TEXTBUTTON name="new button" id="878d73b5418e763" memberName="textButton"
              virtualName="" explicitFocusOrder="0" pos="216 8 48 24" buttonText="Add"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="new button" id="1cc6b4734d5c6c11" memberName="textButton2"
              virtualName="" explicitFocusOrder="0" pos="272 8 48 24" buttonText="Update"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="new button" id="f61b06c20c259853" memberName="textButton3"
              virtualName="" explicitFocusOrder="0" pos="328 8 48 24" buttonText="Delete"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
