//
//  Wire.h
//  Logic
//
//  Created by Ryan Bartley on 4/9/13.
//
//

#pragma once

#include "ofMain.h"
#include "State.h"

class Gate;

class Wire {
    
    vector<EState> mState;
    
    EState State;
    
    vector<ofVec2f> points;
    
    Gate* input;
    
public:

    Wire( int howManySources );
    ~Wire();
    
    bool setGateInput(Gate* input);
    
    void setWireElectricity( vector<EState> states );
    vector<EState> getWireElectricity() ;
    
    void setShape(vector<ofVec2f> points) { this->points = points; };
    
    void update();
    void draw();


};



