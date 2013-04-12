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

class Not : public Gate {
    
    bool addInputs(Wire* input1, Wire* input2) { };
public:
    
    Not();
    ~Not();
    
    

    
};
