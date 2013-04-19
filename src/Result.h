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
private:
    vector<float> wireResult;
    bool gotResult;
    bool resultSet;
public:
    Deformation resultDeform;    
    Result(ofVec2f p);
    ~Result();
    
    vector<EState> getResult();
    
    void draw();
    float suck();
    
};
