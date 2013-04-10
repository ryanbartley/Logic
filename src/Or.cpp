//
//  And.cpp
//  Logic
//
//  Created by Ryan Bartley on 4/9/13.
//
//

#include "Or.h"
#include "Wire.h"

Or::Or()
{
    input1 = NULL;
    input2 = NULL;
    output = NULL;
}

bool Or::addInputs(Wire* input1, Wire* input2)
{
    this->input1 = input1;
    this->input2 = input2;
    
    if (this->input1 != NULL && this->input2 != NULL) {
        return true;
    } else {
        return false;
    }
}

bool Or::addOutput(Wire* output1)
{
    this->output = output1;
}