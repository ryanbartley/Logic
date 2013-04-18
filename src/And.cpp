//
//  And.cpp
//  Logic
//
//  Created by Ryan Bartley on 4/9/13.
//
//

#include "And.h"
#include "Wire.h"

And::And(ofVec2f p)
{
    pos = p;
    deform = new Deformation(30);
    
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
    ofTranslate(pos);
    
    ofSetColor(150);
    ofRect(-25, -25, 50, 50);
    
    ofPopMatrix();
}

float And::suck()
{
    int e0 = inputs[0]->getLastElectron();
    int e1 = inputs[1]->getLastElectron();
    
    if (abs(e0) < 5)
        inputs[0]->suck();

    if (abs(e1) < 5)
        inputs[1]->suck();
    
    // case 3: wire1 has no data, wire0 has no data
    if (abs(e0) < 5 && abs(e1) < 5)
        return ofRandom(-2.5, 2.5);

    // we have signal in both wires
    inputs[0]->suck();
    inputs[1]->suck();
    if (e0 == 0 && e1 == 0)
        return 0;
    else if (e0 < -3 && e1 < -3)
        return -10;
    else
        return 10;
}
