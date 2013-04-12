//
//  Wire.cpp
//  Logic
//
//  Created by Ryan Bartley on 4/9/13.
//
//

#include "Wire.h"

Wire::Wire(int howManySources)
{
    outputConnection = -1;
    
    mState.resize(howManySources);
}

Wire::~Wire()
{

}

bool Wire::setOutput( int connection )
{
    
    //This is to tell whether the connection connects to the top or bottom
    //if you're holding the iPhone horizontally
    this->outputConnection = connection;
    
}

void Wire::setWireElectricity(vector<EState> states)
{
    mStateInProgress = states;
    
    if (mState.size() > 0) {
        cout << "received state inputs " << endl;
    } else {
        cout << "there was a problem sending the states" << endl;
    }
    
}



void Wire::update()
{
    
    if (mState != mStateInProgress) {
        cout << "the source has changed the state" << endl;
        mState = mStateInProgress;
        
        
    } else {
        cout << "source hasn't changed" << endl;
    }
    
    
}

void Wire::draw()
{
    
}

