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
    
    vector<bool> source1;
    vector<bool> source2;
    
    Wire* source1Output;
    Wire* source2Output;
    
public:
    
    Source( int source1 );
    ~Source(){};
    
    bool setOutputs(Wire* outPutWire1, Wire* outPutWire2);
    
};