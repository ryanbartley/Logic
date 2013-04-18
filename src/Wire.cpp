//
//  Wire.cpp
//  Logic
//
//  Created by Ryan Bartley on 4/9/13.
//
//

#include "Wire.h"
#include "Gate.h"

#define POINTS_NUM  100

Wire::Wire(ofVec2f s, ofVec2f e)
{
    input = NULL;
    output = NULL;

    start = s;
    end = e;

    deform = new Deformation(POINTS_NUM);
}

Wire::~Wire()
{
}

//This is so we can check up the line fast
bool Wire::setInput( Gate* input )
{
    if (!input)
        return false;
    
    this->input = input;
    
    return true;
}

bool Wire::setOutput( Gate* output )
{
    if (!output)
        return false;
    
    this->output = output;
    
    return true;
}


vector<EState> Wire::getWireElectricity()
{
    //get the states up the line
    return input->getGateElectricity();
}

float Wire::suck()
{
    deform->pushElectron(input->suck());
    
    return deform->popLastElectron();
}

float Wire::getLastElectron()
{
    return deform->getLastElectron();
}


void Wire::draw()
{
    ofPushMatrix();
    
    ofTranslate(start);
    ofRotate(ofRadToDeg(atan2((end-start).y, (end-start).x)));

    float inc = (end-start).length() / POINTS_NUM;
    
    
    ofSetColor(8, 10, 26);
    ofSetLineWidth(8);
    ofNoFill();
    
    ofBeginShape();
    for (int i=0; i<POINTS_NUM; i++)
    {
        ofVertex((float)i*inc, deform->getAt(POINTS_NUM-i));
    }
    ofEndShape();

    ofSetColor(37, 48, 155);
    ofSetLineWidth(6);
    ofBeginShape();
    for (int i=0; i<POINTS_NUM; i++)
    {
        ofVertex((float)i*inc, deform->getAt(POINTS_NUM-i));
    }
    ofEndShape();

    ofSetColor(200);
    ofSetLineWidth(2);
    ofBeginShape();
    for (int i=0; i<POINTS_NUM; i++)
    {
        ofVertex((float)i*inc, deform->getAt(POINTS_NUM-i));
    }
    ofEndShape();

    ofPopMatrix();
}

