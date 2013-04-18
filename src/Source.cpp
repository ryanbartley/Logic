//
//  Source.cpp
//  Logic
//
//  Created by Ryan Bartley on 4/9/13.
//
//

#include "Wire.h"
#include "Source.h"

Source::Source(ofVec2f p, vector<EState> bits)
{
    pos = p;
    electricity = bits;
    
    me = SOURCE;
    
    sendCounter = 0;
    sendSignal = false;
    
    deform = new Deformation(bits);
}

vector<EState> Source::getGateElectricity()
{
    return electricity;
}

void Source::draw()
{
    ofPushMatrix();
    ofTranslate(pos);
    
    float rectHeight = 100 / electricity.size();
    for (int i=0; i<electricity.size(); i++)
    {
        if (electricity[i] == HIGH)
            ofSetColor(255);
        else
            ofSetColor(50);
        
        ofRect(-15, -50+i*rectHeight, 30, rectHeight);
    }
    
    ofSetColor(200);
    ofRect(15, -2+getLastElectron(), 10, 4);
    
    ofPopMatrix();
}

float Source::suck()
{
    return popLastElectron();
}

void Source::emitSignal()
{
    deform = new Deformation(electricity);
}
