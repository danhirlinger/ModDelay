/*
  ==============================================================================

    ModDelay.h
    Created: 21 Jun 2021 1:39:14pm
    Author:  Dan Hirlinger

  ==============================================================================
*/

#pragma once
#include <JuceHeader.h>

class ModDelay{
    
public:
    ModDelay();
    ~ModDelay();
    
//    void prepare(float Fs, float depth, float preDelay, float rate);
    void setFs(float newFs);
    void setDepth(float newDepth);
    void setPredelay(float newPreD);
    void setRate(float newRate);
    
    float processSample(float x, int c);
    void processBlock(juce::AudioBuffer<float> &buffer);
    
    float delay; // LFO
    float depth = 1.f; // samples
    float preD = 0.f; // samples
    float rate = 5.f; // Hz
    
    AudioBuffer<float> bufferIn;
    
private:
    
    float Fs = 48000.f; float Ts = 1/Fs;
    
    float delayMS;
    
    static const int BUFFERSIZE = 96000;
    float buffer[2][BUFFERSIZE] = {0.f}; // buffer
    int wI[2] = {47999}; // write index
    float angle = 0; float phi;
    
    
    
    
};
