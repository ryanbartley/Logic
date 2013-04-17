//
//  Result.cpp
//  Logic
//
//  Created by Ryan Bartley on 4/12/13.
//
//

#include "Result.h"
#include "Wire.h"


Result::Result()
{
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
    ofTranslate(300, 500);
    
    ofSetColor(0, 255, 0);
    ofRect(-50, -25, 100, 50);
    
    ofPopMatrix();
}