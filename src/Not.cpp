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
    electricityState1 = this->input1->getWireElectricity();
    
    cout << "electricitystate1 size is " << electricityState1.size() << endl;
    
    for (int i = 0; i < electricityState1.size(); i++) {
        cout << "electricity State 1[i] is " << electricityState1[i] << endl;
    }
    
    if (electricityState1.size() == electricityOutput.size()) {
        this->processElectricity();
    } else {
        cout << "I'm an AND Gate and there's a problem with the size of the returned vector from my input wire " << endl;
    }
    
    cout << "I'm returning electricityOutput" << endl;
    return electricityOutput;
}


void Not::processElectricity()
{
    cout << "i'm about to process electricity" << endl;
    vector<EState>::iterator it1 = electricityState1.begin();
    vector<EState>::iterator itOut = electricityOutput.begin();
    
    int i = 0;
    while (i < electricityOutput.size()) {
        cout << "electricity state1 " << *it1 << endl;
        if (*it1 == HIGH) {
            *itOut = LOW;
            cout << "changing itout to LOW" << endl;
        } else {
            *itOut = HIGH;
            cout << "changing itout to HIGH" << endl;
        }
        it1++;
        itOut++;
        i++;
    }
}

