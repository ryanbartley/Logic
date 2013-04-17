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
    me = AND;
}

vector<EState> And::getGateElectricity()
{
    vector<EState> result;
    
    if (inputs.size() < 2) {
        // for now, on error, return empty vector
        return result;
    }
    
    vector<EState> e1 = inputs[0]->getWireElectricity();
    vector<EState> e2 = inputs[1]->getWireElectricity();
    
    if (e1.size() != e2.size()) {
        // for now, on error, return empty vector
        return result;
    }
    
    for (int i=0; i<e1.size(); i++)
    {
        if (e1[i] == HIGH && e2[i] == HIGH)
            result.push_back(HIGH);
        else
            result.push_back(LOW);
    }
    
    return result;
}

void And::draw()
{
    ofPushMatrix();
    ofTranslate(300, 300);
    
    ofSetColor(150);
    ofRect(-25, -25, 50, 50);
    
    ofPopMatrix();
    
}
