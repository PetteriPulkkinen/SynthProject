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
        addAndMakeVisible(keyboardComponent);
        
        FMSynth.addVoice(new FMsynthesis());
        FMSynth.addVoice(new FMsynthesis());
        FMSynth.addVoice(new FMsynthesis());
        FMSynth.addVoice(new FMsynthesis());
        
        FMSynth.clearSounds();
        FMSynth.addSound(new SynthSound());
        
        const StringArray midiInputs(MidiInput::getDevices());
        
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
        double cutoff = 1000;
        double Q = 1;
        IIRCoefficients coefficients  = IIRCoefficients::makeLowPass(sampleRate, cutoff, Q);
        
        filterR.setCoefficients(coefficients);
        filterL.setCoefficients(coefficients);
    }
    
    void releaseResources() override
    {
    }
    
    void getNextAudioBlock (const AudioSourceChannelInfo& bufferToFill) override
    {
        bufferToFill.clearActiveBufferRegion();
        
        MidiBuffer incomingMidi;
        midiCollector.removeNextBlockOfMessages(incomingMidi, bufferToFill.numSamples);
        
        keyboardState.processNextMidiBuffer(incomingMidi, 0, bufferToFill.numSamples, true);
        
        FMSynth.renderNextBlock(*bufferToFill.buffer, incomingMidi, 0, bufferToFill.numSamples);
        
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
    MidiKeyboardState keyboardState;
    MidiKeyboardComponent keyboardComponent;
    MidiMessageCollector midiCollector;
    Synthesiser FMSynth;
    IIRFilter filterR;
    IIRFilter filterL;
    
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainContentComponent)
};


// (This function is called by the app startup code to create our main component)
Component* createMainContentComponent(){ return new MainContentComponent(); }
