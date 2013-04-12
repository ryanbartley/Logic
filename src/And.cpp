//
//  And.cpp
//  Logic
//
//  Created by Ryan Bartley on 4/9/13.
//
//

#include "And.h"
#include "Wire.h"

And::And(int howManySources)
{
    input1 = NULL;
    input2 = NULL;
    output = NULL;
    
    me = AND;
    
    electricityOutput.resize(howManySources);
}

vector<EState> And::getGateElectricity()
{
    electricityState1 = this->input1->getWireElectricity();
    electricityState2 = this->input2->getWireElectricity();
    
    cout << "electricitystate1 size is " << electricityState1.size() << " electricitystate2 size is " << electricityState2.size() << endl;
    
    for (int i = 0; i < electricityState1.size(); i++) {
        cout << "electricity State 1[i] is " << electricityState1[i] << " electricity state 2[i] " << electricityState2[i] << endl;
    }
    
    if (electricityState1.size() == electricityState2.size()) {
        this->processElectricity();
    } else {
        cout << "I'm an AND Gate and there's a problem with the size of the returned vector from my input wire " << endl;
    }
    
    cout << "I'm returning electricityOutput" << endl;
    return electricityOutput;
}

void And::processElectricity()
{
    cout << "i'm about to process electricity" << endl;
    vector<EState>::iterator it1 = electricityState1.begin();
    vector<EState>::iterator it2 = electricityState2.begin();
    vector<EState>::iterator itOut = electricityOutput.begin();
    
    int i = 0;
    while (i < electricityOutput.size()) {
        cout << "electricity state1 " << *it1 << " electricity state2 " << *it2 << endl;
        if (*it1 == HIGH && *it2 == HIGH) {
            *itOut = HIGH;
            cout << "changing itout to HIGH" << endl;
        } else {
            *itOut = LOW;
            cout << "changing itout to LOW" << endl;
        }
        it1++;
        it2++;
        itOut++;
        i++;
    }
}
