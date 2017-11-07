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
#include "SynthVoice.h"


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
    slider5->setRange (0, 10, 0);
    slider5->setSliderStyle (Slider::Rotary);
    slider5->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    slider5->addListener (this);

    addAndMakeVisible (slider12 = new Slider ("new slider"));
    slider12->setRange (0, 10, 0);
    slider12->setSliderStyle (Slider::Rotary);
    slider12->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    slider12->addListener (this);

    addAndMakeVisible (slider13 = new Slider ("new slider"));
    slider13->setRange (0, 10, 0);
    slider13->setSliderStyle (Slider::Rotary);
    slider13->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    slider13->addListener (this);

    addAndMakeVisible (MGslider = new Slider ("ModulatorGain"));
    MGslider->setRange (1, 10, 0);
    MGslider->setSliderStyle (Slider::Rotary);
    MGslider->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    MGslider->addListener (this);

    addAndMakeVisible (CGslider = new Slider ("CarrierGain"));
    CGslider->setRange (1, 10, 0);
    CGslider->setSliderStyle (Slider::Rotary);
    CGslider->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    CGslider->addListener (this);


    //[UserPreSize]
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
    slider12->setBounds (472, 200, 65, 65);
    slider13->setBounds (592, 200, 65, 65);
    MGslider->setBounds (240, 200, 65, 65);
    CGslider->setBounds (240, 56, 65, 65);
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
        //[/UserSliderCode_slider5]
    }
    else if (sliderThatWasMoved == slider12)
    {
        //[UserSliderCode_slider12] -- add your slider handling code here..
        //[/UserSliderCode_slider12]
    }
    else if (sliderThatWasMoved == slider13)
    {
        //[UserSliderCode_slider13] -- add your slider handling code here..
        //[/UserSliderCode_slider13]
    }
    else if (sliderThatWasMoved == MGslider)
    {
        //[UserSliderCode_MGslider] -- add your slider handling code here..
        
        for (int i = 0; i < synthesizer->getNumVoices(); i++){
            FMsynthesis* voice = (FMsynthesis*) synthesizer->getVoice(i);
            voice->getModulator().setGain(MGslider->getValue());
        }
        //[/UserSliderCode_MGslider]
    }
    else if (sliderThatWasMoved == CGslider)
    {
        //[UserSliderCode_CGslider] -- add your slider handling code here..
        for (int i = 0; i < synthesizer->getNumVoices();i++){
            FMsynthesis* voice = (FMsynthesis*) synthesizer->getVoice(i);
            voice->getModulator().setGain(CGslider->getValue());
        }
        //[/UserSliderCode_CGslider]
    }

    //[UsersliderValueChanged_Post]
    //[/UsersliderValueChanged_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
void GUI::init(Synthesiser* synth){
    this->synthesizer = synth;
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
          max="10" int="0" style="Rotary" textBoxPos="NoTextBox" textBoxEditable="1"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1" needsCallback="1"/>
  <SLIDER name="new slider" id="67919200e11f9bf" memberName="slider12"
          virtualName="" explicitFocusOrder="0" pos="472 200 65 65" min="0"
          max="10" int="0" style="Rotary" textBoxPos="NoTextBox" textBoxEditable="1"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1" needsCallback="1"/>
  <SLIDER name="new slider" id="b1e16e36f222738c" memberName="slider13"
          virtualName="" explicitFocusOrder="0" pos="592 200 65 65" min="0"
          max="10" int="0" style="Rotary" textBoxPos="NoTextBox" textBoxEditable="1"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1" needsCallback="1"/>
  <SLIDER name="ModulatorGain" id="c16b303c43bf1bf5" memberName="MGslider"
          virtualName="" explicitFocusOrder="0" pos="240 200 65 65" min="1"
          max="10" int="0" style="Rotary" textBoxPos="NoTextBox" textBoxEditable="1"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1" needsCallback="1"/>
  <SLIDER name="CarrierGain" id="c7e3cca1ca161860" memberName="CGslider"
          virtualName="" explicitFocusOrder="0" pos="240 56 65 65" min="1"
          max="10" int="0" style="Rotary" textBoxPos="NoTextBox" textBoxEditable="1"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1" needsCallback="1"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
