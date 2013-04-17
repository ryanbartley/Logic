//
//  Level.h
//  Logic
//
//  Created by Gal Sasson on 4/16/13.
//
//

#ifndef __Logic__Level__
#define __Logic__Level__

#include <iostream>
#include "ofMain.h"
#include "Gate.h"
#include "Wire.h"
#include "Result.h"

class Level
{
    
    vector<Gate*> gates;
    vector<Wire*> wires;
    
    Result* result;
    
    
    
public:
    Level();
    
    void update();
    void draw();
    
private:
    void connect(Gate* g1, Wire* w, Gate* g2);
};

#endif /* defined(__Logic__Level__) */
