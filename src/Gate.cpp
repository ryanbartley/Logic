//
//  Gate.cpp
//  Logic
//
//  Created by Ryan Bartley on 4/9/13.
//
//

#include "Gate.h"

bool Gate::addInputs(Wire* input1, Wire* input2)
{
    this->input1 = input1;
    this->input2 = input2;
    
    if (this->input1 != NULL && this->input2 != NULL) {
        return true;
    } else {
        return false;
    }
}

bool Gate::addOutput(Wire* output1)
{
    
}

bool Gate::addInput(Wire* input)
{
    
}