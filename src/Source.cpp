//
//  Source.cpp
//  Logic
//
//  Created by Ryan Bartley on 4/9/13.
//
//

#include "Wire.h"
#include "Source.h"

Source::Source(int howManySources)
{
    
    if (howManySources <= 0) return;
    
    me = SOURCE;
    
    output = NULL;
    
    this->electricity.resize(howManySources);
    
    cout << "I'm going into the source" << endl;
    vector<EState>::iterator it = this->electricity.begin();
    
    while (it != this->electricity.end()) {
        int random = rand()%100;
        
        if (random > 50) {
            *it = HIGH;
        } else {
            *it = LOW;
        }
        cout << *it << " ";
        it++;
    }
    cout << endl;
}

vector<EState> Source::getGateElectricity()
{
    return electricity;
}

bool Source::addSourceOutputs(Wire* wireOutput)
{
    //set the output of the gate
    outputs.push_back(wireOutput);
    
    //set the input of the wire and make sure everything
    //is set before you return.
    if (wireOutput->setGateInput(this)) {
        if(outputs.back() != NULL) {
            return true;
        } else {
            return false;
        }
    } else {
        return false;
    }
}
