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
#include "SynthVoice.h"
//[/Headers]

#include "GUI.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
GUI::GUI ()
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    addAndMakeVisible (slider = new Slider ("new slider"));
    slider->setRange (0, 10, 0);
    slider->setSliderStyle (Slider::LinearVertical);
    slider->setTextBoxStyle (Slider::NoTextBox, true, 80, 20);
    slider->addListener (this);

    addAndMakeVisible (slider2 = new Slider ("new slider"));
    slider2->setRange (0, 10, 0);
    slider2->setSliderStyle (Slider::LinearVertical);
    slider2->setTextBoxStyle (Slider::NoTextBox, true, 80, 20);
    slider2->addListener (this);

    addAndMakeVisible (slider3 = new Slider ("new slider"));
    slider3->setRange (0, 10, 0);
    slider3->setSliderStyle (Slider::LinearVertical);
    slider3->setTextBoxStyle (Slider::NoTextBox, true, 80, 20);
    slider3->addListener (this);

    addAndMakeVisible (slider4 = new Slider ("new slider"));
    slider4->setRange (0, 10, 0);
    slider4->setSliderStyle (Slider::LinearVertical);
    slider4->setTextBoxStyle (Slider::NoTextBox, true, 80, 20);
    slider4->addListener (this);

    addAndMakeVisible (slider7 = new Slider ("new slider"));
    slider7->setRange (0, 10, 0);
    slider7->setSliderStyle (Slider::LinearVertical);
    slider7->setTextBoxStyle (Slider::NoTextBox, true, 80, 20);
    slider7->addListener (this);

    addAndMakeVisible (slider8 = new Slider ("new slider"));
    slider8->setRange (0, 10, 0);
    slider8->setSliderStyle (Slider::LinearVertical);
    slider8->setTextBoxStyle (Slider::NoTextBox, true, 80, 20);
    slider8->addListener (this);

    addAndMakeVisible (slider9 = new Slider ("new slider"));
    slider9->setRange (0, 10, 0);
    slider9->setSliderStyle (Slider::LinearVertical);
    slider9->setTextBoxStyle (Slider::NoTextBox, true, 80, 20);
    slider9->addListener (this);

    addAndMakeVisible (slider10 = new Slider ("new slider"));
    slider10->setRange (0, 10, 0);
    slider10->setSliderStyle (Slider::LinearVertical);
    slider10->setTextBoxStyle (Slider::NoTextBox, true, 80, 20);
    slider10->addListener (this);

    addAndMakeVisible (slider5 = new Slider ("new slider"));
    slider5->setRange (0, 20000, 0);
    slider5->setSliderStyle (Slider::Rotary);
    slider5->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 15);
    slider5->addListener (this);

    addAndMakeVisible (slider12 = new Slider ("new slider"));
    slider12->setRange (80, 16000, 0);
    slider12->setSliderStyle (Slider::Rotary);
    slider12->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 15);
    slider12->addListener (this);

    addAndMakeVisible (slider13 = new Slider ("new slider"));
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

    addAndMakeVisible (CNote = new Slider ("Carrier Note"));
    CNote->setRange (-24, 24, 1);
    CNote->setSliderStyle (Slider::IncDecButtons);
    CNote->setTextBoxStyle (Slider::TextBoxLeft, false, 40, 20);
    CNote->addListener (this);

    addAndMakeVisible (MNote = new Slider ("Modulator note"));
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

    addAndMakeVisible (Octave = new Slider ("Octave slider"));
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

    addAndMakeVisible (Master = new Slider ("Master slider"));
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


    //[UserPreSize]
    slider12->setValue(1);
    Master->setValue(1);
    //[/UserPreSize]

    setSize (800, 600);


    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

GUI::~GUI()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    slider = nullptr;
    slider2 = nullptr;
    slider3 = nullptr;
    slider4 = nullptr;
    slider7 = nullptr;
    slider8 = nullptr;
    slider9 = nullptr;
    slider10 = nullptr;
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

    slider->setBounds (598, 350, 40, 110);
    slider2->setBounds (646, 350, 40, 110);
    slider3->setBounds (694, 350, 40, 110);
    slider4->setBounds (550, 350, 40, 110);
    slider7->setBounds (86, 358, 40, 100);
    slider8->setBounds (134, 358, 40, 100);
    slider9->setBounds (182, 358, 40, 100);
    slider10->setBounds (38, 358, 40, 100);
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
    Octave->setBounds (688, 8, 100, 25);
    label8->setBounds (632, 8, 56, 16);
    Master->setBounds (488, 8, 125, 25);
    label9->setBounds (424, 8, 150, 16);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void GUI::sliderValueChanged (Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
    //[/UsersliderValueChanged_Pre]

    if (sliderThatWasMoved == slider)
    {
        //[UserSliderCode_slider] -- add your slider handling code here..
        //[/UserSliderCode_slider]
    }
    else if (sliderThatWasMoved == slider2)
    {
        //[UserSliderCode_slider2] -- add your slider handling code here..
        //[/UserSliderCode_slider2]
    }
    else if (sliderThatWasMoved == slider3)
    {
        //[UserSliderCode_slider3] -- add your slider handling code here..
        //[/UserSliderCode_slider3]
    }
    else if (sliderThatWasMoved == slider4)
    {
        //[UserSliderCode_slider4] -- add your slider handling code here..
        //[/UserSliderCode_slider4]
    }
    else if (sliderThatWasMoved == slider7)
    {
        //[UserSliderCode_slider7] -- add your slider handling code here..
        //[/UserSliderCode_slider7]
    }
    else if (sliderThatWasMoved == slider8)
    {
        //[UserSliderCode_slider8] -- add your slider handling code here..
        //[/UserSliderCode_slider8]
    }
    else if (sliderThatWasMoved == slider9)
    {
        //[UserSliderCode_slider9] -- add your slider handling code here..
        //[/UserSliderCode_slider9]
    }
    else if (sliderThatWasMoved == slider10)
    {
        //[UserSliderCode_slider10] -- add your slider handling code here..
        //[/UserSliderCode_slider10]
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
		cutofff = slider12->getValue();
		QQ = slider13->getValue();		// luetaan samalla QQ:lle arvo, jotta se ois varmasti alustettu (jos ei oo alustettu, niin error)
		IIRCoefficients coefficients = IIRCoefficients::makeLowPass(*samplausrate, cutofff, QQ);
		// right ja left filtereiden teko, nama pitaisi paivittya MainComponenttiin getNextAudioblockin edetessa
		(*filterRR).setCoefficients(coefficients);
		(*filterLL).setCoefficients(coefficients);
        //[/UserSliderCode_slider12]
    }
    else if (sliderThatWasMoved == slider13)
    {
        //[UserSliderCode_slider13] -- add your slider handling code here..
		// hieman sama homma kuin slider12 tapauksessa
		QQ = slider13->getValue();
		cutofff = slider12->getValue();		// luetaan samalla cutoffille arvo, jotta se ois varmasti alustettu
		IIRCoefficients coefficients = IIRCoefficients::makeLowPass(*samplausrate, cutofff, QQ);
		(*filterRR).setCoefficients(coefficients);
		(*filterLL).setCoefficients(coefficients);
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

    //[UsersliderValueChanged_Post]
    //[/UsersliderValueChanged_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
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
  <SLIDER name="new slider" id="63bd38afd51ecc43" memberName="slider" virtualName=""
          explicitFocusOrder="0" pos="598 350 40 110" min="0" max="10"
          int="0" style="LinearVertical" textBoxPos="NoTextBox" textBoxEditable="0"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1" needsCallback="1"/>
  <SLIDER name="new slider" id="405706fe9d67c034" memberName="slider2"
          virtualName="" explicitFocusOrder="0" pos="646 350 40 110" min="0"
          max="10" int="0" style="LinearVertical" textBoxPos="NoTextBox"
          textBoxEditable="0" textBoxWidth="80" textBoxHeight="20" skewFactor="1"
          needsCallback="1"/>
  <SLIDER name="new slider" id="f8ae9f1895e9f7cb" memberName="slider3"
          virtualName="" explicitFocusOrder="0" pos="694 350 40 110" min="0"
          max="10" int="0" style="LinearVertical" textBoxPos="NoTextBox"
          textBoxEditable="0" textBoxWidth="80" textBoxHeight="20" skewFactor="1"
          needsCallback="1"/>
  <SLIDER name="new slider" id="55065483c5cfda78" memberName="slider4"
          virtualName="" explicitFocusOrder="0" pos="550 350 40 110" min="0"
          max="10" int="0" style="LinearVertical" textBoxPos="NoTextBox"
          textBoxEditable="0" textBoxWidth="80" textBoxHeight="20" skewFactor="1"
          needsCallback="1"/>
  <SLIDER name="new slider" id="4ff5356e4f65685c" memberName="slider7"
          virtualName="" explicitFocusOrder="0" pos="86 358 40 100" min="0"
          max="10" int="0" style="LinearVertical" textBoxPos="NoTextBox"
          textBoxEditable="0" textBoxWidth="80" textBoxHeight="20" skewFactor="1"
          needsCallback="1"/>
  <SLIDER name="new slider" id="57947018b5f68fb1" memberName="slider8"
          virtualName="" explicitFocusOrder="0" pos="134 358 40 100" min="0"
          max="10" int="0" style="LinearVertical" textBoxPos="NoTextBox"
          textBoxEditable="0" textBoxWidth="80" textBoxHeight="20" skewFactor="1"
          needsCallback="1"/>
  <SLIDER name="new slider" id="a84ab44e65d8e2a3" memberName="slider9"
          virtualName="" explicitFocusOrder="0" pos="182 358 40 100" min="0"
          max="10" int="0" style="LinearVertical" textBoxPos="NoTextBox"
          textBoxEditable="0" textBoxWidth="80" textBoxHeight="20" skewFactor="1"
          needsCallback="1"/>
  <SLIDER name="new slider" id="8b3f507f3e828678" memberName="slider10"
          virtualName="" explicitFocusOrder="0" pos="38 358 40 100" min="0"
          max="10" int="0" style="LinearVertical" textBoxPos="NoTextBox"
          textBoxEditable="0" textBoxWidth="80" textBoxHeight="20" skewFactor="1"
          needsCallback="1"/>
  <SLIDER name="new slider" id="c00cedec3bec0b3a" memberName="slider5"
          virtualName="" explicitFocusOrder="0" pos="56 80 150 150" min="0"
          max="20000" int="0" style="Rotary" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="15" skewFactor="1"
          needsCallback="1"/>
  <SLIDER name="new slider" id="67919200e11f9bf" memberName="slider12"
          virtualName="" explicitFocusOrder="0" pos="480 200 180 100" min="80"
          max="16000" int="0" style="Rotary" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="15" skewFactor="1"
          needsCallback="1"/>
  <SLIDER name="new slider" id="b1e16e36f222738c" memberName="slider13"
          virtualName="" explicitFocusOrder="0" pos="616 200 180 100" min="1"
          max="10" int="0" style="Rotary" textBoxPos="TextBoxBelow" textBoxEditable="1"
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
  <SLIDER name="Carrier Note" id="44cf394519a99d3c" memberName="CNote"
          virtualName="" explicitFocusOrder="0" pos="32 280 100 25" min="-24"
          max="24" int="1" style="IncDecButtons" textBoxPos="TextBoxLeft"
          textBoxEditable="1" textBoxWidth="40" textBoxHeight="20" skewFactor="1"
          needsCallback="1"/>
  <SLIDER name="Modulator note" id="29f6189d75cefb5e" memberName="MNote"
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
  <SLIDER name="Octave slider" id="a20e4f22f1d8e98c" memberName="Octave"
          virtualName="" explicitFocusOrder="0" pos="688 8 100 25" min="-4"
          max="4" int="1" style="IncDecButtons" textBoxPos="TextBoxLeft"
          textBoxEditable="1" textBoxWidth="40" textBoxHeight="20" skewFactor="1"
          needsCallback="1"/>
  <LABEL name="new label" id="b31e365d33e4b659" memberName="label8" virtualName=""
         explicitFocusOrder="0" pos="632 8 56 16" edTextCol="ff000000"
         edBkgCol="0" labelText="Octave&#10;" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" kerning="0" bold="0" italic="0" justification="33"/>
  <SLIDER name="Master slider" id="a6a0247f868ec1e9" memberName="Master"
          virtualName="" explicitFocusOrder="0" pos="488 8 125 25" min="0"
          max="1" int="0.10000000000000000555" style="LinearHorizontal"
          textBoxPos="TextBoxLeft" textBoxEditable="1" textBoxWidth="40"
          textBoxHeight="20" skewFactor="1" needsCallback="1"/>
  <LABEL name="new label" id="b2a455da84b24907" memberName="label9" virtualName=""
         explicitFocusOrder="0" pos="424 8 150 16" edTextCol="ff000000"
         edBkgCol="0" labelText="Volume" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         kerning="0" bold="0" italic="0" justification="33"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
