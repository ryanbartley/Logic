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

class Wire {
    
    vector<EState> mState;
    vector<EState> mStateInProgress;
    
    int outputConnection;
    
public:

    Wire( int howManySources );
    ~Wire();
    
    bool setOutput( int connection );
    
    void setWireElectricity( vector<EState> states );
    
    void update();
    void draw();

};



