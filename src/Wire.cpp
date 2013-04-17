//
//  Wire.cpp
//  Logic
//
//  Created by Ryan Bartley on 4/9/13.
//
//

#include "Wire.h"
#include "Gate.h"

Wire::Wire()
{
    input = NULL;
    output = NULL;
}

Wire::~Wire()
{

}

//This is so we can check up the line fast
bool Wire::setInput( Gate* input )
{
    if (!input)
        return false;
    
    this->input = input;
    
    return true;
}

bool Wire::setOutput( Gate* output )
{
    if (!output)
        return false;
    
    this->output = output;
    
    return true;
}


vector<EState> Wire::getWireElectricity()
{
    //get the states up the line
    return input->getGateElectricity();
}

void Wire::update()
{
    
    
}

void Wire::draw()
{
    
}

