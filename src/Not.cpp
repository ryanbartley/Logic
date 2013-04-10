//
//  And.cpp
//  Logic
//
//  Created by Ryan Bartley on 4/9/13.
//
//

#include "Not.h"
#include "Wire.h"

Not::Not()
{
    input1 = NULL;
    output = NULL;
}

bool Not::addInput( Wire* input1 )
{
    this->input1 = input1;
    
    if (this->input1 != NULL) {
        return true;
    } else {
        return false;
    }
}

bool Not::addOutput(Wire* output1)
{
    this->output = output1;
}