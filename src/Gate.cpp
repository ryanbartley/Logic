//
//  Gate.cpp
//  Logic
//
//  Created by Ryan Bartley on 4/9/13.
//
//

#include "Gate.h"
#include "Wire.h"

bool Gate::addInputs(Wire* input1, Wire* input2)
{
    
    //set the inputs to the wire pointers inside the gate
    this->input1 = input1;
    this->input2 = input2;
    
    //Make sure the inputs are not null anymore
    if (this->input1 != NULL && this->input2 != NULL) {
        return true;
    } else {
        return false;
    }
    
}

bool Gate::addOutput(Wire* output1)
{
    //set the output of the gate
    output = output1;
    
    //set the input of the wire and check that everything is set
    if (output1->setGateInput(this)) {
        if (output != NULL) {
            return true;
        } else {
            return false;
        }
    } else {
        return false;
    }
    
}

bool Gate::addInput(Wire* input)
{
    //set the input wire
    input1 = input;
    
    //make sure it's set
    if (input1 != NULL) {
        return true;
    } else {
        return false;
    }
    
}

vector<EState> Gate::getGateElectricity()
{
    
}

void Gate::sendOutput()
{
    
}

bool Gate::setIncomingElectricity()
{
    
}


void Gate::draw()
{
    
}

void Gate::update()
{
    
}

