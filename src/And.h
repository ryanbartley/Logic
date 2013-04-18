//
//  And.h
//  Logic
//
//  Created by Ryan Bartley on 4/9/13.
//
//

#pragma once

#include "Gate.h"

class And : public Gate
{
    
public:
    
    And(ofVec2f p);
    ~And();
    
    vector<EState> getGateElectricity();
    
    void draw();
    float suck();
};
