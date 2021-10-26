/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
ModDelayAudioProcessorEditor::ModDelayAudioProcessorEditor (ModDelayAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (400, 300);
    
    depthKnob.setBounds(25, 25, 50, 50);
    depthKnob.setRange(1.f, 20.f);
    depthKnob.setTextBoxStyle(Slider::TextBoxBelow, false, 75, 25);
    depthKnob.setSliderStyle(Slider::SliderStyle::RotaryHorizontalVerticalDrag);
    depthKnob.setSize(80,100);
    addAndMakeVisible(depthKnob);
    
    preDKnob.setBounds(25, 100, 50, 50);
    preDKnob.setRange(0.f, 20.f);
    preDKnob.setTextBoxStyle(Slider::TextBoxBelow, false, 75, 25);
    preDKnob.setSliderStyle(Slider::SliderStyle::RotaryHorizontalVerticalDrag);
    preDKnob.setSize(80,100);
    addAndMakeVisible(preDKnob);
    
    rateKnob.setBounds(25, 175, 50, 50);
    rateKnob.setRange(0.1f, 10.f);
    rateKnob.setTextBoxStyle(Slider::TextBoxBelow, false, 75, 25);
    rateKnob.setSliderStyle(Slider::SliderStyle::RotaryHorizontalVerticalDrag);
    rateKnob.setSize(80, 100);
    addAndMakeVisible(rateKnob);
    
}

ModDelayAudioProcessorEditor::~ModDelayAudioProcessorEditor()
{
}

//==============================================================================
void ModDelayAudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));

    g.setColour (juce::Colours::white);

}

void ModDelayAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
}

void ModDelayAudioProcessorEditor::sliderValueChanged(Slider *slider){
    if (slider == &depthKnob){
        delay.depth = depthKnob.getValue();
    } if (slider == &preDKnob){
        delay.preD = preDKnob.getValue();
    } if (slider == &rateKnob){
        delay.rate = rateKnob.getValue();
    }
}

