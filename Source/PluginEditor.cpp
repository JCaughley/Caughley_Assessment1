/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
_2020sw2_assessment1AudioProcessorEditor::_2020sw2_assessment1AudioProcessorEditor (_2020sw2_assessment1AudioProcessor& p)
    : AudioProcessorEditor (&p), processor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (400, 300);
    ImageCache::addImageToCache(bgImg, 1);
    
    //gainsliderstuff
    gainSlider.setSliderStyle(Slider::SliderStyle::LinearVertical);
    gainSlider.setTextBoxStyle(Slider::TextBoxBelow, true, 100, 25);
    gainSlider.setRange(0.0, 1.0);
    gainSlider.setValue(0.5);
    gainSlider.addListener(this);
    addAndMakeVisible(gainSlider);
    
    //freqsliderstuff - slider not working yet
    freqSlider.setSliderStyle(Slider::SliderStyle::LinearVertical);
    freqSlider.setTextBoxStyle(Slider::TextBoxBelow, true, 100, 25);
    freqSlider.setRange(50, 10000);
    freqSlider.setValue(4750);
    freqSlider.addListener(this);
    addAndMakeVisible(freqSlider);
}

_2020sw2_assessment1AudioProcessorEditor::~_2020sw2_assessment1AudioProcessorEditor()
{
}

//==============================================================================
void _2020sw2_assessment1AudioProcessorEditor::paint (Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (Colours::black);
    g.setColour (Colours::darkslategrey);
    g.setFont (15.0f);
   // g.drawFittedText ("Plugin Test!", getLocalBounds(), Justification::centred, 1);
    

    
}

void _2020sw2_assessment1AudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
    //position slider here
    gainSlider.setBounds(getLocalBounds());
    freqSlider.setBounds(10, 10, 100, 200);
}

void _2020sw2_assessment1AudioProcessorEditor::sliderValueChanged (Slider * slider){
    if (slider == &gainSlider)
    {
        processor.rawVolume = gainSlider.getValue();
    }
   // if (slider == &freqSlider)
  //  {
  //      processor.rawFreq = freqSlider.getValue();
   // }
    
}

