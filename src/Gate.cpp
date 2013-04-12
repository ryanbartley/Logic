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
    
    
    if (this->input1 != NULL && this->input2 != NULL) {
        cout << "gate inputs and wire outputs are set correctly" << endl;
        return true;
    } else {
        cout << "the gate inputs are not set correctly" << endl;
        return false;
    }
    
}

bool Gate::addOutput(Wire* output1)
{
    //set the output of the gate
    output = output1;
    
    //set the input of the wire
    if (output1->setGateInput(this)) {
        
        if (output != NULL) {
            cout << "both the output of the gate and the input of the wire were set correctly" << endl;
            return true;
        } else {
            cout << "output wire was not set correctly" << endl;
            return false;
        }
    } else {
        cout << "wire was not set correctly" << endl;
        return false;
    }
    
}

bool Gate::addInput(Wire* input)
{
    
    input1 = input;
    
    if (input1 != NULL) {
        cout << me << " gate's input from wire's output is set up correctly" << endl;
        return true;
    } else {
        cout << me << " gate's input is not set up correctly" << endl;
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

