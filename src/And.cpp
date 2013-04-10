//
//  And.cpp
//  Logic
//
//  Created by Ryan Bartley on 4/9/13.
//
//

#include "And.h"
#include "Wire.h"

And::And()
{
    input1 = NULL;
    input2 = NULL;
    output = NULL;
}

bool And::addInputs(Wire* input1, Wire* input2)
{
    this->input1 = input1;
    this->input2 = input2;
    
    if (this->input1 != NULL && this->input2 != NULL) {
        return true;
    } else {
        return false;
    }
}

bool And::addOutput(Wire* output1)
{
    this->output = output1;
}