/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
_2020sw2_assessment1AudioProcessor::_2020sw2_assessment1AudioProcessor()
#ifndef JucePlugin_PreferredChannelConfigurations
     : AudioProcessor (BusesProperties()
                     #if ! JucePlugin_IsMidiEffect
                      #if ! JucePlugin_IsSynth
                       .withInput  ("Input",  AudioChannelSet::stereo(), true)
                      #endif
                       .withOutput ("Output", AudioChannelSet::stereo(), true)
                     #endif
                       ), parameters(*this, nullptr, Identifier("J's Plugin"), {
                            std::make_unique<AudioParameterFloat>("gain",//parameter ID
                                                                  "Gain",//parameter name
                                                                  0.0f, //min value
                                                                  1.0f, //max value
                                                                  0.5f)//default value
         
     })

#endif
{
    //initialisation
    gainParameter = parameters.getRawParameterValue("gain");
}

_2020sw2_assessment1AudioProcessor::~_2020sw2_assessment1AudioProcessor()
{
}

//==============================================================================


const String _2020sw2_assessment1AudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool _2020sw2_assessment1AudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool _2020sw2_assessment1AudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

bool _2020sw2_assessment1AudioProcessor::isMidiEffect() const
{
   #if JucePlugin_IsMidiEffect
    return true;
   #else
    return false;
   #endif
}

double _2020sw2_assessment1AudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int _2020sw2_assessment1AudioProcessor::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
                // so this should be at least 1, even if you're not really implementing programs.
}

int _2020sw2_assessment1AudioProcessor::getCurrentProgram()
{
    return 0;
}

void _2020sw2_assessment1AudioProcessor::setCurrentProgram (int index)
{
}

const String _2020sw2_assessment1AudioProcessor::getProgramName (int index)
{
    return {};
}

void _2020sw2_assessment1AudioProcessor::changeProgramName (int index, const String& newName)
{
}

//==============================================================================
void _2020sw2_assessment1AudioProcessor::updateAngleDelta()
{
    auto cyclesPerSample = rawFreq / currentSampleRate;
    angleDelta = cyclesPerSample * 2.0 * MathConstants<double>::pi;
}
void _2020sw2_assessment1AudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    currentSampleRate = sampleRate;
    updateAngleDelta();
}


void _2020sw2_assessment1AudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
}

#ifndef JucePlugin_PreferredChannelConfigurations
bool _2020sw2_assessment1AudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
{
  #if JucePlugin_IsMidiEffect
    ignoreUnused (layouts);
    return true;
  #else
    // This is the place where you check if the layout is supported.
    // In this template code we only support mono or stereo.
    if (layouts.getMainOutputChannelSet() != AudioChannelSet::mono()
     && layouts.getMainOutputChannelSet() != AudioChannelSet::stereo())
        return false;

    // This checks if the input layout matches the output layout
   #if ! JucePlugin_IsSynth
    if (layouts.getMainOutputChannelSet() != layouts.getMainInputChannelSet())
        return false;
   #endif

    return true;
  #endif
}
#endif

void _2020sw2_assessment1AudioProcessor::processBlock (AudioBuffer<float>& buffer, MidiBuffer& midiMessages)
{
    ScopedNoDenormals noDenormals;
    auto totalNumInputChannels  = getTotalNumInputChannels();
    auto totalNumOutputChannels = getTotalNumOutputChannels();

    // In case we have more outputs than inputs, this code clears any output
    // channels that didn't contain input data, (because these aren't
    // guaranteed to be empty - they may contain garbage).
    // This is here to avoid people getting screaming feedback
    // when they first compile a plugin, but obviously you don't need to keep
    // this code if your algorithm always overwrites all the output channels.
    //rawVolume = 0.015f;
    
    for (auto i = totalNumInputChannels; i < totalNumOutputChannels; ++i)
        buffer.clear (i, 0, buffer.getNumSamples());

    // This is the place where you'd normally do the guts of your plugin's
    // audio processing...
    // Make sure to reset the state if your inner loop is processing
    // the samples and the outer loop is handling the channels.
    // Alternatively, you can process the samples with the channels
    // interleaved by keeping the same state.
    
    
    for (int channel = 0; channel < totalNumInputChannels; ++channel)
    {
        auto* channelData = buffer.getWritePointer(channel);
        
        // ..do something to the data...
        for (auto sample = 0; sample < buffer.getNumSamples(); ++sample)
        {
            auto currentSample = (float) std::sin (currentAngle);
            currentAngle += angleDelta;
            channelData[sample] = currentSample * rawVolume;
        }
       
    }
}

//==============================================================================
bool _2020sw2_assessment1AudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

AudioProcessorEditor* _2020sw2_assessment1AudioProcessor::createEditor()
{
    return new _2020sw2_assessment1AudioProcessorEditor (*this, parameters);
}

//==============================================================================
void _2020sw2_assessment1AudioProcessor::getStateInformation (MemoryBlock& destData)
{
    // You should use this method to store your parameters in the memory block.
    // You could do that either as raw data, or use the XML or ValueTree classes
    // as intermediaries to make it easy to save and load complex data.
}

void _2020sw2_assessment1AudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    // You should use this method to restore your parameters from this memory block,
    // whose contents will have been created by the getStateInformation() call.
}

//==============================================================================
// This creates new instances of the plugin..
AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new _2020sw2_assessment1AudioProcessor();
}
