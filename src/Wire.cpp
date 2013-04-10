//
//  Wire.cpp
//  Logic
//
//  Created by Ryan Bartley on 4/9/13.
//
//

#include "Gate.h"
#include "Wire.h"

Wire::Wire()
{
    input = NULL;
    output = NULL;
    
    mState = FLOATING;
    mStateInProgress = FLOATING;
    
    mLength = 0.0f;
    mElecPos = 0.0f;
    
    visible = false;
}

Wire::~Wire(){}


ofVec2f getStartPosition();
ofVec2f getEndPosition();
bool setStartPosition(ofVec2f start);
bool setEndPosition();

bool Wire::setInput( Gate* input )
{
    this->input = input;
    
    if (this->input != NULL) {
        return true;
    } else {
        return false;
    }
}

bool Wire::setOutput( Gate* output )
{
    this->output = output;
    
    if (this->output != NULL) {
        return true;
    } else {
        return false;
    }
}