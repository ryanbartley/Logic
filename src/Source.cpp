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
    ofRect(15, -2+getLastElectron(), 20, 4);
    
    ofPopMatrix();
}

float Source::getLastElectron()
{
    int ret;
    
    if (sendCounter > electricity.size()*30)
        return ofRandom(-3, 3);
    
    if (electricity[sendCounter/30] == HIGH)
        ret = 20;
    else
        ret = -20;
    
    return ret;
}


float Source::popNextElectron()
{
    int ret;
    
    if (sendCounter > electricity.size()*30)
        return ofRandom(-3, 3);
    
    if (electricity[sendCounter/30] == HIGH)
        ret = 20;
    else
        ret = -20;
    
    sendCounter++;
    return ret;
}

