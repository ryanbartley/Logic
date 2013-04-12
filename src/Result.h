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
    
    int howManySources;
    
public:
    
    Result(int howManySources);
    ~Result();
    
    void getResult();
    
};
