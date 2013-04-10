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
    
    Gate* input;
    Gate* output;
    
    EState mState;
    EState mStateInProgress;
    
    float mLength;
    float mElecPos;
    
    bool visible;
    
public:
    
    ofVec2f source;
    ofVec2f target;
    
    Wire();
    ~Wire();
    
    ofVec2f getStartPosition();
    ofVec2f getEndPosition();
    bool setStartPosition(ofVec2f start);
    bool setEndPosition();
    
    bool setInput( Gate* input );
    bool setOutput( Gate* output );

};



