/*
  ==============================================================================

    ModDelay.cpp
    Created: 21 Jun 2021 1:39:14pm
    Author:  Dan Hirlinger

  ==============================================================================
*/

#include "ModDelay.h"

ModDelay::ModDelay(){
    
};

ModDelay::~ModDelay(){
    
};

float ModDelay::processSample(float x, int c){

    // buffer(wI,1) = x;
    buffer[c][wI[c]] = x;
    delay = (depth/2)*sin(angle) + (depth/2) + 1 + preD;

    int r1 = wI[c] - floor(delay);
    if (r1 < 1) {
        r1 = r1 + BUFFERSIZE;
    }
    int r2 = r1 - 1;
    if (r2 < 1){
        r2 = r2 + BUFFERSIZE;
    }
    float g2 = delay - floor(delay);
    float g1 = 1 - g2;

    float y = (g1 * buffer[c][r1]) + (g2 * buffer[c][r2]);
    wI[c] = wI[c] + 1;
    if (wI[c] > BUFFERSIZE){
        wI[c] = 0;
    }
    
    phi = rate * Ts * (2*M_PI);
    angle = angle + phi;
    if (angle > 2*M_PI){
        angle = angle - (2*M_PI);
    }
    
    return y;
};

void ModDelay::processBlock(juce::AudioBuffer<float> &bufferIn){
    int cN = bufferIn.getNumChannels();
    
    for (int c = 0; c < cN; c++){
        for (int n = 0; n < bufferIn.getNumSamples(); n++){
            float x = bufferIn.getReadPointer(c)[n];
            float y = processSample(x,c);
            bufferIn.getWritePointer(c)[n] = y;
        }
    }
}

//void ModDelay::processBlock(juce::AudioBuffer<float>&){
//    
//};

void ModDelay::setFs(float newFs){
    Fs = newFs;
    Ts = 1/Fs;
};

void ModDelay::setDepth(float newDepth){
    depth = newDepth;
};

void ModDelay::setPredelay(float newPreD){
    preD = newPreD;
};

void ModDelay::setRate(float newRate){
    rate = newRate;
};

