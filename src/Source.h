//
//  Source.h
//  Logic
//
//  Created by Ryan Bartley on 4/9/13.
//
//

#pragma once

#include "ofMain.h"
#include "Gate.h"

class Wire;

class Source : public Gate {
    
    vector<EState> electricity;
    vector<Wire*> outputs;
    
    int sendCounter;
    bool sendSignal;
    
public:
    
    Source(ofVec2f p, vector<EState> bits);
    ~Source(){};
    
    vector<EState> getGateElectricity();
    
    void draw();
    
    float getLastElectron();
    float popNextElectron();
    
};
