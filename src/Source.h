//
//  Source.h
//  Logic
//
//  Created by Ryan Bartley on 4/9/13.
//
//

#pragma once

#include "ofMain.h"
#include "Gate.h"

class Wire;

class Source : public Gate {
    
    vector<bool> source1;

    
    
    
public:
    
    Source( int source );
    ~Source(){};
    
    
    
};