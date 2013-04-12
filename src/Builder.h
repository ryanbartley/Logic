//
//  Builder.h
//  Logic
//
//  Created by Ryan Bartley on 4/9/13.
//
//

#pragma once

#include "Wire.h"
#include "And.h"
#include "Or.h"
#include "Not.h"
#include "Source.h"
#include "State.h"
#include "Result.h"


class Builder {
    
    vector<Gate> circuit;
    
public:
    
    Builder(int howManyGates, int howManySources, int howManyLevels);
    ~Builder();
    
   
    
};
