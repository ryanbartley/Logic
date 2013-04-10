//
//  And.h
//  Logic
//
//  Created by Ryan Bartley on 4/9/13.
//
//

#pragma once

#include "Gate.h"

class Wire;

class And : public Gate {
    
    Wire* input1;
    Wire* input2;
    
    Wire* output;
    
public:
    
    And();
    ~And();
    
    bool addInputs( Wire* input1, Wire* input2 );
    bool addOutput( Wire* output1 );
};
