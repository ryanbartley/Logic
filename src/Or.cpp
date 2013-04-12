//
//  And.cpp
//  Logic
//
//  Created by Ryan Bartley on 4/9/13.
//
//

#include "Or.h"
#include "Wire.h"

Or::Or(int howManySources)
{
    input1 = NULL;
    input2 = NULL;
    output = NULL;
    me = OR;
    
    electricityOutput.resize(howManySources);
}

vector<EState> Or::getGateElectricity()
{
    //First get Any Electricity from the wire
    electricityState1 = this->input1->getWireElectricity();
    electricityState2 = this->input2->getWireElectricity();
    
    //We should figure out how to catch this if it's not true
    if (electricityState1.size() == electricityState2.size()) {
        this->processElectricity();
    } else {
        
    }
    
    return electricityOutput;
}

void Or::processElectricity()
{
    //The two inputs and the output combo
    vector<EState>::iterator it1 = electricityState1.begin();
    vector<EState>::iterator it2 = electricityState2.begin();
    vector<EState>::iterator itOut = electricityOutput.begin();
    
    int i = 0;
    while (i < electricityOutput.size()) {
        //OR LOGIC
        if (*it1 == HIGH || *it2 == HIGH) {
            *itOut = HIGH;
        } else {
            *itOut = LOW;
        }
        it1++;
        it2++;
        itOut++;
        i++;
    }}
