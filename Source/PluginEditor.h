/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"

//==============================================================================
/**
*/
class _2020sw2_assessment1AudioProcessorEditor  : public AudioProcessorEditor, public Slider::Listener
{
public:
    _2020sw2_assessment1AudioProcessorEditor (_2020sw2_assessment1AudioProcessor&, AudioProcessorValueTreeState&);
    ~_2020sw2_assessment1AudioProcessorEditor();

    //==============================================================================
    void paint (Graphics&) override;
    void resized() override;
    void sliderValueChanged (Slider * slider) override;
    

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    _2020sw2_assessment1AudioProcessor& processor;
    AudioProcessorValueTreeState& valueTreeState;
std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> gainAttachment;
    
    
    Image bgImg;
    Slider gainSlider;
    Slider freqSlider;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (_2020sw2_assessment1AudioProcessorEditor)
};
