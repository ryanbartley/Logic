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
#define SEQUENCE_SIZE 6
#define NUM_OF_FRAMES 20

class Deformation{
    public:
    Deformation();
    Deformation(ofVec2f _direction, bool init);
    void addRandom(int numFrames, float h);
    void addNoise(int numFrames, float strength, float period);
    void addSilence(int numFrames);
    void addSine(int numFrames);
    void addSquareWave(int numFrames,vector<EState> sequence);
    void removeSequence(int index);
    int getNumSequences();
    ofVec2f getFrame(int index);
    ofVec2f getLastFrame();
    void setFrame(int index);
    int size();
    
    vector <ofVec2f> frames;
    ofVec2f direction;
    
};



