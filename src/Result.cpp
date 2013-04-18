//
//  Result.cpp
//  Logic
//
//  Created by Ryan Bartley on 4/12/13.
//
//

#include "Result.h"
#include "Wire.h"


Result::Result(ofVec2f p)
{
    pos = p;
    deform = new Deformation(20);
}

Result::~Result()
{
    result.clear();
}

vector<EState> Result::getResult()
{
    if (inputs.size() < 1)
        return;
    
    return inputs[0]->getWireElectricity();
}

void Result::draw()
{
    ofPushMatrix();
    ofTranslate(pos);
    
    ofSetColor(0, 255, 0);
    ofRect(-50, -25, 100, 50);
    
    ofPopMatrix();
}

float Result::suck()
{
    float val = inputs[0]->suck();
    return val;
}