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

	// olkoon tama (hetkellisesti) amplitudi slider joka muokkaa moduloivan signaalin amplitudia
    addAndMakeVisible (slider5 = new Slider ("new slider"));
	slider5->setRange (0, 80000, 0);	// 0-80000 alustavasti (voisi viela muuttaa kaytannonlaheisemmaksi)
    slider5->setSliderStyle (Slider::Rotary);
    slider5->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);	// dont use "textboxabove" because testing voice becomes painful
    slider5->addListener (this);

	// olkoon tama (hetkellisesti) cut-off slider joka muokkaa filterin cut-off -taajuuden
	// cutoff taajuus on se taajuus-kohta jossa signaali suodatetaan
	// raja-ehto: (frequency > 0.0 && frequency <= sampleRate * 0.5);
	// eli cut-off pitaa olla suurempi kuin 0, mutta korkeintaan puolet sampling ratest 
    addAndMakeVisible (slider12 = new Slider ("new slider"));
    slider12->setRange (0.001, 44100, 0);		// koitetaan CD-laatuisella taajuudella 
												// HUOM! tuo 44100 on liikaa, pitaisi olla puolet sampling ratest. 
												// Error kun slider12 liikutetaan suuremmaksi	

	// slider12->setRange(0.001, (*samplausrate)*0.5, 0);		// jos koittaa talla tavoin, niin tulee buildaus error
    slider12->setSliderStyle (Slider::Rotary);
    slider12->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
	slider12->setValue(1000, dontSendNotification);		// koska alustettiin prepareToPlayssa cutoff=1000 Maincomponent.cpp:s 
    slider12->addListener (this);

	// olkoon tama (hetkellisesti) Q slider joka muokkaa filterin Q-arvon
	// Q measures how good circuit is. the higher the Q -> the sharper the peak
	// ks. esimerkki https://electronics.stackexchange.com/questions/221887/does-q-factor-matter-for-low-pass-and-high-pass-filters
	// Q:n pitaa olla >0 tai muuten tulee erroria slideria liikuttaessa, siksi setrange(0.001, 10, 0);
    addAndMakeVisible (slider13 = new Slider ("new slider"));
    slider13->setRange (0.001, 10, 0);
    slider13->setSliderStyle (Slider::Rotary);
    slider13->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
	slider13->setValue(1, dontSendNotification);		// koska alustettiin prepareToPlayssa Q=1 Maincomponent.cpp:s
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

	// labels for distinguishing sliders better. delete at the end of the project
	
	addAndMakeVisible(label1);
	label1.setText("s1", dontSendNotification);	// s1 refers to slider, s2 refers to slider2, etc.
	label1.attachToComponent(slider, false);	// false so the text goes above

	addAndMakeVisible(label2);
	label2.setText("s2", dontSendNotification);
	label2.attachToComponent(slider2, false);

	addAndMakeVisible(label3);
	label3.setText("s3", dontSendNotification);
	label3.attachToComponent(slider3, false);

	addAndMakeVisible(label4);
	label4.setText("s4", dontSendNotification);
	label4.attachToComponent(slider4, false);

	addAndMakeVisible(label5);
	label5.setText("s5", dontSendNotification);
	label5.attachToComponent(slider5, false);

	addAndMakeVisible(label7);
	label7.setText("s7", dontSendNotification);
	label7.attachToComponent(slider7, false);

	addAndMakeVisible(label8);
	label8.setText("s8", dontSendNotification);
	label8.attachToComponent(slider8, false);

	addAndMakeVisible(label9);
	label9.setText("s9", dontSendNotification);
	label9.attachToComponent(slider9, false);

	addAndMakeVisible(label10);
	label10.setText("s10", dontSendNotification);
	label10.attachToComponent(slider10, false);

	addAndMakeVisible(label12);
	label12.setText("s12", dontSendNotification);
	label12.attachToComponent(slider12, false);

	addAndMakeVisible(label13);
	label13.setText("s13", dontSendNotification);
	label13.attachToComponent(slider13, false);

	addAndMakeVisible(MGlabel);
	MGlabel.setText("MGain", dontSendNotification);
	MGlabel.attachToComponent(MGslider, false);

	addAndMakeVisible(CGlabel);
	CGlabel.setText("CGain", dontSendNotification);
	CGlabel.attachToComponent(CGslider, false);
	

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
            voice->getModulator().setGain(CGslider->getValue());
        }
        //[/UserSliderCode_CGslider]
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
