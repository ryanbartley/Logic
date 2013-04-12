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
    
    //set the output connections from inside the wires
    if (input1->setOutput(this, 0) && input2->setOutput(this, 1)) {
        if (this->input1 != NULL && this->input2 != NULL) {
            cout << "gate inputs and wire outputs are set correctly" << endl;
            return true;
        } else {
            cout << "the gate inputs are not set correctly" << endl;
            return false;
        }
    } else {
        cout << "the wire outputs are not set correctly" << endl;
        return false;
    }
    
}

bool Gate::addOutput(Wire* output1)
{
    //set the output of the gate
    output = output1;
    
    //set the input of the wire
    if (output1->setInput(this)) {
        if (output != NULL) {
            cout << "both the output of the gate and the input of the wire were set correctly" << endl;
            return true;
        } else {
            cout << "output wire was not set correctly" << endl;
            return false;
        }
    } else {
        cout << "the wires input was not set correctly" << endl;
        return false;
    }
        
}

bool Gate::addInput(Wire* input)
{
    if (me == NOT) {
        input1 = input;
        
        if (input->setOutput(this, 1)) {
            if (input1 != NULL) {
                cout << me << " gate's input from wire's output is set up correctly" << endl;
                return true;
            } else {
                cout << me << " gate's input is not set up correctly" << endl;
                return false;
            }
        } else {
            cout << me << " gate's wire output is not set up correctly" << endl;
            return false;
        }
    }
    
}

void Gate::draw()
{
    
}

void Gate::update()
{
    
}