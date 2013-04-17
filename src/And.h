//
//  And.h
//  Logic
//
//  Created by Ryan Bartley on 4/9/13.
//
//

#pragma once

#include "Gate.h"

class Wire;

class And : public Gate {
    
public:
    
    And();
    ~And();
    
    vector<EState> getGateElectricity();
    
    void draw();
};
