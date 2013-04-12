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
    
    vector<float> animationOut;
    
public:
    
    Source( int howManySources );
    ~Source(){};
    
    vector<EState> getGateElectricity();
    
};
