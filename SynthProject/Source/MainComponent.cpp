/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h"
#include "GUI.h"
#include "SynthVoice.h"

//==============================================================================
/*
    This component lives inside our window, and this is where you should put all
    your controls and content.
*/

class MainContentComponent   : public AudioAppComponent
{
public:
    //==============================================================================
    MainContentComponent() : keyboardComponent (keyboardState, MidiKeyboardComponent::horizontalKeyboard)
    {
        setAudioChannels(0, 2);
        setSize (800, 600);		//ikkunan koko 800x600
        // specify the number of input and output channels that we want to open
        addAndMakeVisible(GraphicalUI);
		// GUI:n pointterin arvot tahan
        GraphicalUI.init(&FMSynth);
		GraphicalUI.init2(&filterR);
		GraphicalUI.init3(&filterL);
		GraphicalUI.init4(&samplausrate);
        
        addAndMakeVisible(keyboardComponent);
        
        // ks. https://juce.com/doc/classSynthesiser
        FMSynth.addVoice(new FMsynthesis());
        FMSynth.addVoice(new FMsynthesis());
        FMSynth.addVoice(new FMsynthesis());
        FMSynth.addVoice(new FMsynthesis());
        
        FMSynth.clearSounds();
        FMSynth.addSound(new SynthSound());
        
		// listaa kaikki tarjolla olevat midi laitteet
        const StringArray midiInputs(MidiInput::getDevices());
        
		// asettaa midi laitteen tähän että se ottaa sen inputit
        for (int i = 0; i < midiInputs.size(); i++){
            if (!deviceManager.isMidiInputEnabled(midiInputs[i])){
                std::cout << midiInputs[i] << std::endl;
                //if (midiInputs[i]== "nanoPAD2 PAD"){
                deviceManager.setMidiInputEnabled(midiInputs[i], true);
                //}
            }
        }
        deviceManager.addMidiInputCallback(String(), &midiCollector);
    }

    ~MainContentComponent()
    {
        shutdownAudio();
        deviceManager.removeMidiInputCallback(String(), &midiCollector);
        
    }
    
    void prepareToPlay (int samplesPerBlockExpected, double sampleRate) override
    {
        midiCollector.reset(sampleRate);
        FMSynth.setCurrentPlaybackSampleRate(sampleRate);
		// cutoff ja Q ei oo private variable (eli niihin paastaan myos filen ulkopuolella (?))
		// mutta toisaalta tassa on kyse prepareToPlay eli niiden muuttaminen lennosta...?
        double cutoff = 1000;		
        double Q = 1;
		samplausrate = sampleRate;

		// ks. https://juce.com/doc/classIIRCoefficients 
		// palauttaa lowpassin parametrit
        IIRCoefficients coefficients  = IIRCoefficients::makeLowPass(sampleRate, cutoff, Q);
        // luodaan lowpass filterit
        filterR.setCoefficients(coefficients);
        filterL.setCoefficients(coefficients);
    }
    
    void releaseResources() override
    {
    }
    
    void getNextAudioBlock (const AudioSourceChannelInfo& bufferToFill) override
    {
        bufferToFill.clearActiveBufferRegion();
        // midi buffer muuttujan teko koska tarvitaan metodin parametriksi
        MidiBuffer incomingMidi;
        midiCollector.removeNextBlockOfMessages(incomingMidi, bufferToFill.numSamples);
        
        keyboardState.processNextMidiBuffer(incomingMidi, 0, bufferToFill.numSamples, true);
        // audio-äänen teko (renderextBlock jokaisella loopilla, ks. Synthvoice.cpp ja sit oscillator.cpp)
        FMSynth.renderNextBlock(*bufferToFill.buffer, incomingMidi, 0, bufferToFill.numSamples);
        // ja lopuksi niiden filterointi (processSamples)
        filterL.processSamples(bufferToFill.buffer->getWritePointer(0, 0), bufferToFill.numSamples);
        filterR.processSamples(bufferToFill.buffer->getWritePointer(1, 0), bufferToFill.numSamples);
        /*
        for (int i = 0; i < 5; i++){
           std::cout << filterL.getCoefficients().coefficients[i] << std::endl;
        }
        */
    }

    //==============================================================================
    void paint (Graphics& g) override
    {
        // (Our component is opaque, so we must completely fill the background with a solid colour)
        g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId));

        // You can add your drawing code here!
    }

    void resized() override
    {
        GraphicalUI.setBounds(0, 0, getWidth(), getHeight());		//asettaa GUI:n koko ikkunan paalle
        // This is called when the MainContentComponent is resized.
        // If you add any child components, this is where you should
        // update their positions.
        keyboardComponent.setBounds(0, getHeight()-getHeight()/6, getWidth(), getHeight()/6);
    }
    
    
private:
    //==============================================================================

    // Your private member variables go here...
    GUI GraphicalUI;
    MidiKeyboardState keyboardState;			// midi komponentin näppäinten tila
    MidiKeyboardComponent keyboardComponent;	// midi komponentti
    MidiMessageCollector midiCollector;
	// ks. https://juce.com/doc/classSynthesiser
    Synthesiser FMSynth;
    
	// ks. https://juce.com/doc/classIIRFilter 
	// ei luoda konstruktorissa mutta preparetoplayssa (why? samplerate?)
    IIRFilter filterR;
    IIRFilter filterL;
	// otetaan arvo talteen jotta voidaan kasitella GUI:n filterissa
	double samplausrate;
    
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainContentComponent)
};


// (This function is called by the app startup code to create our main component)
Component* createMainContentComponent(){ return new MainContentComponent(); }
