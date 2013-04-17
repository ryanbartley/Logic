//
//  Result.h
//  Logic
//
//  Created by Ryan Bartley on 4/12/13.
//
//

#pragma once 

#include "Gate.h"

class Wire;

class Result : public Gate {
    
    vector<EState> result;
    
public:
    
    Result();
    ~Result();
    
    vector<EState> getResult();
    
    void draw();
    
};
