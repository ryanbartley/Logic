//
//  Deformation.h
//  wireDrawingTest
//
//  Created by Surya on 12/04/13.
//
//

#pragma once
#include <iostream>
#include "ofMain.h"
#include "State.h"

class Deformation{
    public:
    Deformation();
    Deformation(int numFrames);
    Deformation(vector<EState> seq);
    void addRandom(int numFrames, float h);
    void addNoise(int numFrames, float strength, float period);
    void addSilence(int numFrames);
    void addSine(int numFrames);
    void addSquareWave(int numFrames,vector<EState> sequence);
    void setResultDeform(vector<EState> seq);
    int getNumSequences();
    float getAt(int index);
    float popLastElectron();
    float getLastElectron();
    void pushElectron(float val);

    int size();
    
    vector<float> values;
    bool emitSequence;
    int emitSequenceCounter;
};



