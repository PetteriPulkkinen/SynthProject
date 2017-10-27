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
//[/MiscUserDefs]

//==============================================================================
GUI::GUI () : keyboardComponent(keyboardState,MidiKeyboardComponent::horizontalKeyboard)
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

    addAndMakeVisible (slider5 = new Slider ("new slider"));
    slider5->setRange (0, 10, 0);
    slider5->setSliderStyle (Slider::RotaryHorizontalVerticalDrag);
    slider5->setTextBoxStyle (Slider::TextBoxAbove, false, 80, 20);
    slider5->addListener (this);

    addAndMakeVisible (slider6 = new Slider ("new slider"));
    slider6->setRange (0, 10, 0);
    slider6->setSliderStyle (Slider::RotaryHorizontalVerticalDrag);
    slider6->setTextBoxStyle (Slider::TextBoxAbove, false, 80, 20);
    slider6->addListener (this);

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


    //[UserPreSize]
    //[/UserPreSize]

    setSize (800, 600);


    //[Constructor] You can add your own custom stuff here..
    addAndMakeVisible(keyboardComponent);
    //[/Constructor]
}

GUI::~GUI()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

	//kun paattyy, voidaan poistaa gui:n listener ominaisuus
	slider->removeListener(this);
	slider2->removeListener(this);
	slider3->removeListener(this);
	slider4->removeListener(this);
	slider5->removeListener(this);
	slider6->removeListener(this);
	slider7->removeListener(this);
	slider8->removeListener(this);
	slider9->removeListener(this);
	slider10->removeListener(this);

	//poistaa sliderit (vapauttaa resursseja)
    slider = nullptr;
    slider2 = nullptr;
    slider3 = nullptr;
    slider4 = nullptr;
    slider5 = nullptr;
    slider6 = nullptr;
    slider7 = nullptr;
    slider8 = nullptr;
    slider9 = nullptr;
    slider10 = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void GUI::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colour (0xff13c4df));

    {
        int x = 470, y = 310, width = 200, height = 30;
        String text (TRANS("ADSR Envelope"));
        Colour fillColour = Colours::black;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font ("Abadi MT Condensed Extra Bold", 20.00f, Font::plain).withTypefaceStyle ("Regular"));
        g.drawText (text, x, y, width, height,
                    Justification::centred, true);
    }

    {
        int x = 112, y = 430, width = 200, height = 30;
        String text (TRANS("ADSR Envelope"));
        Colour fillColour = Colours::black;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font ("Abadi MT Condensed Extra Bold", 20.00f, Font::plain).withTypefaceStyle ("Regular"));
        g.drawText (text, x, y, width, height,
                    Justification::centred, true);
    }

	//vasen puoli varitetaan tummansiniseksi
    {
        int x = 0, y = 0, width = 400, height = 600;
        Colour fillColour = Colour (0xff2a7ca5);
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.fillRect (x, y, width, height);
    }

    {
        int x = 70, y = 310, width = 200, height = 30;
        String text (TRANS("ADSR Envelope"));
        Colour fillColour = Colours::black;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font ("Abadi MT Condensed Extra Bold", 20.00f, Font::plain).withTypefaceStyle ("Regular"));
        g.drawText (text, x, y, width, height,
                    Justification::centred, true);
    }

    {
        int x = 0, y = -20, width = 400, height = 100;
        String text (TRANS("Carrier oscillator"));
        Colour fillColour = Colours::black;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font ("Abadi MT Condensed Extra Bold", 40.50f, Font::plain).withTypefaceStyle ("Regular"));
        g.drawText (text, x, y, width, height,
                    Justification::centred, true);
    }

    {
        int x = 400, y = -20, width = 400, height = 100;
        String text (TRANS("Modulator oscillator"));
        Colour fillColour = Colours::black;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font ("Abadi MT Condensed Extra Bold", 40.50f, Font::plain).withTypefaceStyle ("Regular"));
        g.drawText (text, x, y, width, height,
                    Justification::centred, true);
    }

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void GUI::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

	//gui on koko maincomponentin paalla toisin sanottuna koko ikkuna, sitten asetetaan sliderit
	//setBounds(int x, int y, int width, int height), width ja height ikaan kuin maarittelee suorakulmion

	//slider1-4 on modulaattorin envelopeja (oikealla puolella)
    slider->setBounds (550, 350, 40, 110);
    slider2->setBounds (598, 350, 40, 110);
    slider3->setBounds (646, 350, 40, 110);
    slider4->setBounds (502, 350, 40, 110);

	//slider5 kantoaallon oskillaattori (maaritellaan sen Hz taajuus)
    slider5->setBounds (150, 80, 200, 200);
	//slider6 modulaattorin oskillaattori
    slider6->setBounds (550, 80, 200, 200);

	//slider7-10 on kantoaallon envelopjea (vasemmalla)
    slider7->setBounds (150, 350, 40, 100);
    slider8->setBounds (198, 350, 40, 100);
    slider9->setBounds (246, 350, 40, 100);
    slider10->setBounds (102, 350, 40, 100);
    //[UserResized] Add your own custom resize handling here..
    keyboardComponent.setBounds(0, getHeight()-getHeight()/6, getWidth(), getHeight()/6);
    //[/UserResized]
}

void GUI::sliderValueChanged (Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
    //[/UsersliderValueChanged_Pre]

	//tassa tarkoituksena kasitella slidereiden arvoja
	//oskillaattorit antavat Hz arvoja, joilla luodaan output aallot
	//envelopet kasittelee naiden aaltojen output voimakkuuksia

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
    else if (sliderThatWasMoved == slider5)
    {
        //[UserSliderCode_slider5] -- add your slider handling code here..
        //[/UserSliderCode_slider5]
    }
    else if (sliderThatWasMoved == slider6)
    {
        //[UserSliderCode_slider6] -- add your slider handling code here..
        //[/UserSliderCode_slider6]
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
  <BACKGROUND backgroundColour="ff13c4df">
    <TEXT pos="470 310 200 30" fill="solid: ff000000" hasStroke="0" text="ADSR Envelope"
          fontname="Abadi MT Condensed Extra Bold" fontsize="20" kerning="0"
          bold="0" italic="0" justification="36"/>
    <TEXT pos="112 430 200 30" fill="solid: ff000000" hasStroke="0" text="ADSR Envelope"
          fontname="Abadi MT Condensed Extra Bold" fontsize="20" kerning="0"
          bold="0" italic="0" justification="36"/>
    <RECT pos="0 0 400 600" fill="solid: ff2a7ca5" hasStroke="0"/>
    <TEXT pos="70 310 200 30" fill="solid: ff000000" hasStroke="0" text="ADSR Envelope"
          fontname="Abadi MT Condensed Extra Bold" fontsize="20" kerning="0"
          bold="0" italic="0" justification="36"/>
    <TEXT pos="0 -20 400 100" fill="solid: ff000000" hasStroke="0" text="Carrier oscillator"
          fontname="Abadi MT Condensed Extra Bold" fontsize="40.5" kerning="0"
          bold="0" italic="0" justification="36"/>
    <TEXT pos="400 -20 400 100" fill="solid: ff000000" hasStroke="0" text="Modulator oscillator"
          fontname="Abadi MT Condensed Extra Bold" fontsize="40.5" kerning="0"
          bold="0" italic="0" justification="36"/>
  </BACKGROUND>
  <SLIDER name="new slider" id="63bd38afd51ecc43" memberName="slider" virtualName=""
          explicitFocusOrder="0" pos="550 350 40 110" min="0" max="10"
          int="0" style="LinearVertical" textBoxPos="NoTextBox" textBoxEditable="0"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1" needsCallback="1"/>
  <SLIDER name="new slider" id="405706fe9d67c034" memberName="slider2"
          virtualName="" explicitFocusOrder="0" pos="598 350 40 110" min="0"
          max="10" int="0" style="LinearVertical" textBoxPos="NoTextBox"
          textBoxEditable="0" textBoxWidth="80" textBoxHeight="20" skewFactor="1"
          needsCallback="1"/>
  <SLIDER name="new slider" id="f8ae9f1895e9f7cb" memberName="slider3"
          virtualName="" explicitFocusOrder="0" pos="646 350 40 110" min="0"
          max="10" int="0" style="LinearVertical" textBoxPos="NoTextBox"
          textBoxEditable="0" textBoxWidth="80" textBoxHeight="20" skewFactor="1"
          needsCallback="1"/>
  <SLIDER name="new slider" id="55065483c5cfda78" memberName="slider4"
          virtualName="" explicitFocusOrder="0" pos="502 350 40 110" min="0"
          max="10" int="0" style="LinearVertical" textBoxPos="NoTextBox"
          textBoxEditable="0" textBoxWidth="80" textBoxHeight="20" skewFactor="1"
          needsCallback="1"/>
  <SLIDER name="new slider" id="4bfad33959fb91f3" memberName="slider5"
          virtualName="" explicitFocusOrder="0" pos="150 80 200 200" min="0"
          max="10" int="0" style="RotaryHorizontalVerticalDrag" textBoxPos="TextBoxAbove"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"
          needsCallback="1"/>
  <SLIDER name="new slider" id="85b696850eea04b4" memberName="slider6"
          virtualName="" explicitFocusOrder="0" pos="550 80 200 200" min="0"
          max="10" int="0" style="RotaryHorizontalVerticalDrag" textBoxPos="TextBoxAbove"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"
          needsCallback="1"/>
  <SLIDER name="new slider" id="4ff5356e4f65685c" memberName="slider7"
          virtualName="" explicitFocusOrder="0" pos="150 350 40 100" min="0"
          max="10" int="0" style="LinearVertical" textBoxPos="NoTextBox"
          textBoxEditable="0" textBoxWidth="80" textBoxHeight="20" skewFactor="1"
          needsCallback="1"/>
  <SLIDER name="new slider" id="57947018b5f68fb1" memberName="slider8"
          virtualName="" explicitFocusOrder="0" pos="198 350 40 100" min="0"
          max="10" int="0" style="LinearVertical" textBoxPos="NoTextBox"
          textBoxEditable="0" textBoxWidth="80" textBoxHeight="20" skewFactor="1"
          needsCallback="1"/>
  <SLIDER name="new slider" id="a84ab44e65d8e2a3" memberName="slider9"
          virtualName="" explicitFocusOrder="0" pos="246 350 40 100" min="0"
          max="10" int="0" style="LinearVertical" textBoxPos="NoTextBox"
          textBoxEditable="0" textBoxWidth="80" textBoxHeight="20" skewFactor="1"
          needsCallback="1"/>
  <SLIDER name="new slider" id="8b3f507f3e828678" memberName="slider10"
          virtualName="" explicitFocusOrder="0" pos="102 350 40 100" min="0"
          max="10" int="0" style="LinearVertical" textBoxPos="NoTextBox"
          textBoxEditable="0" textBoxWidth="80" textBoxHeight="20" skewFactor="1"
          needsCallback="1"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
