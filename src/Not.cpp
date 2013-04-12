//
//  And.cpp
//  Logic
//
//  Created by Ryan Bartley on 4/9/13.
//
//

#include "Not.h"
#include "Wire.h"

Not::Not(int howManySources)
{
    input1 = NULL;
    output = NULL;
    me = NOT;
    
    electricityOutput.resize(howManySources);
}

vector<EState> Not::getGateElectricity()
{
    //First get Any Electricity from the wire
    electricityState1 = this->input1->getWireElectricity();
    
    //We should figure out how to catch this if it's not true
    if (electricityState1.size() == electricityOutput.size()) {
        this->processElectricity();
    } else {
        
    }
    
    return electricityOutput;
}


void Not::processElectricity()
{
    //The not gate only has one input
    vector<EState>::iterator it1 = electricityState1.begin();
    vector<EState>::iterator itOut = electricityOutput.begin();
    
    int i = 0;
    while (i < electricityOutput.size()) {
        //NOT LOGIC
        if (*it1 == HIGH) {
            *itOut = LOW;
        } else {
            *itOut = HIGH;
        }
        it1++;
        itOut++;
        i++;
    }
}

