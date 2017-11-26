/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h"
#include "GUI.h"
#include "SynthVoice.h"
#include "Oscillator.h"
#include "myDevices.h"

//==============================================================================
/*
    This component lives inside our window, and this is where you should put all
    your controls and content.
*/

class MainContentComponent   : public AudioAppComponent
{
public:
    //==============================================================================
    MainContentComponent() : GraphicalUI(&myDevices)
    {
        setAudioChannels(0, 2);
        setSize (800, 600);		//ikkunan koko 800x600
        // specify the number of input and output channels that we want to open
        
        // ks. https://juce.com/doc/classSynthesiser
        myDevices.FMSynth.addVoice(new FMsynthesis());
        myDevices.FMSynth.addVoice(new FMsynthesis());
        myDevices.FMSynth.addVoice(new FMsynthesis());
        myDevices.FMSynth.addVoice(new FMsynthesis());
        myDevices.FMSynth.clearSounds();
        myDevices.FMSynth.addSound(new SynthSound());
        
        addAndMakeVisible(GraphicalUI);
        //
        
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
        GraphicalUI.setSliderValues();
    }

    ~MainContentComponent()
    {
        shutdownAudio();
        deviceManager.removeMidiInputCallback(String(), &midiCollector);
        
    }
    
    void prepareToPlay (int samplesPerBlockExpected, double sampleRate) override
    {
        midiCollector.reset(sampleRate);
        myDevices.FMSynth.setCurrentPlaybackSampleRate(sampleRate);
		// cutoff ja Q ei oo private variable (eli niihin paastaan myos filen ulkopuolella (?))
		// mutta toisaalta tassa on kyse prepareToPlay eli niiden muuttaminen lennosta...?
        myDevices.cutoff = 1000;
        myDevices.Q = 1;
		myDevices.samplingRate = sampleRate;

		// ks. https://juce.com/doc/classIIRCoefficients 
		// palauttaa lowpassin parametrit
        //IIRCoefficients coefficients  = IIRCoefficients::makeLowPass(sampleRate, cutoff, Q);
        // luodaan lowpass filterit
        //filterR.setCoefficients(coefficients);
        //filterL.setCoefficients(coefficients);
        myDevices.LFO.initialize(sampleRate);
        myDevices.LFO.setAmplitude(1000);
        myDevices.LFO.setFrequency(10);
        myDevices.LFO.getEnvelope().updateValues(1, Envelope::SUSTAIN);
        myDevices.LFO.getEnvelope().startStage(Envelope::SUSTAIN);
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
        
        myDevices.keyboardState.processNextMidiBuffer(incomingMidi, 0, bufferToFill.numSamples, true);
        // audio-äänen teko (renderextBlock jokaisella loopilla, ks. Synthvoice.cpp ja sit oscillator.cpp)
        myDevices.FMSynth.renderNextBlock(*bufferToFill.buffer, incomingMidi, 0, bufferToFill.numSamples);
        // ja lopuksi niiden filterointi (processSamples)
        for (int i = 0; i < bufferToFill.buffer->getNumSamples(); i++){
            IIRCoefficients coeff = IIRCoefficients::makeLowPass(myDevices.samplingRate, std::abs(myDevices.cutoff+myDevices.LFO.getNextValue()),myDevices.Q);
            filterR.setCoefficients(coeff);
            filterL.setCoefficients(coeff);
            *bufferToFill.buffer->getWritePointer(0, i) = filterL.processSingleSampleRaw(*bufferToFill.buffer->getReadPointer(0, i));
            *bufferToFill.buffer->getWritePointer(1, i) = filterR.processSingleSampleRaw(*bufferToFill.buffer->getReadPointer(1, i));
        }

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
    }
    
    
private:
    //==============================================================================

    // Your private member variables go here...
    GUI GraphicalUI;
    //MidiKeyboardState keyboardState;			// midi komponentin näppäinten tila	// midi komponentti
    MidiMessageCollector midiCollector;
	// ks. https://juce.com/doc/classSynthesiser
    /*
    Synthesiser FMSynth;
    Oscillator LFO;
	// ks. https://juce.com/doc/classIIRFilter 
	// ei luoda konstruktorissa mutta preparetoplayssa (why? samplerate?)*/
    IIRFilter filterR;
    IIRFilter filterL;
    /*
    double cutoff;
    double Q;
    
	// otetaan arvo talteen jotta voidaan kasitella GUI:n filterissa
	double samplausrate;*/
    
    Devices myDevices;
    

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainContentComponent)
};


// (This function is called by the app startup code to create our main component)
Component* createMainContentComponent(){ return new MainContentComponent(); }
