/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"
#include "ModDelay.h"

//==============================================================================
/**
*/
class ModDelayAudioProcessorEditor  : public juce::AudioProcessorEditor,
                                      public Slider::Listener
{
public:
    ModDelayAudioProcessorEditor (ModDelayAudioProcessor&);
    ~ModDelayAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;
    
    void sliderValueChanged(Slider * slider) override;

private:
    ModDelayAudioProcessor& audioProcessor;
    
    Slider depthKnob;
    Slider preDKnob;
    Slider rateKnob;
    
    ModDelay delay;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ModDelayAudioProcessorEditor)
};
