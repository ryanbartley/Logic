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
    
    outputConnection = -1;
}

Wire::~Wire()
{

}

bool Wire::setInput( Gate* input  )
{
    this->input = input;
    
    if (this->input != NULL) {
        return true;
    } else {
        return false;
    }
}

bool Wire::setOutput( Gate* output, int connection )
{
    this->output = output;
    
    this->outputConnection = connection;
    
    if (this->output != NULL) {
        return true;
    } else {
        return false;
    }
}

void Wire::update()
{
    
}

void Wire::draw()
{
    
    
    
}

ofVec2f Wire::getStartPosition() {}
ofVec2f Wire::getEndPosition() {}
bool Wire::setStartPosition(ofVec2f start) {}
bool Wire::setEndPosition() {}