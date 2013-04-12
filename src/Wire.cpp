//
//  Wire.cpp
//  Logic
//
//  Created by Ryan Bartley on 4/9/13.
//
//

#include "Wire.h"
#include "Gate.h"

Wire::Wire(int howManySources)
{
    input = NULL;
    mState.resize(howManySources);
}

Wire::~Wire()
{

}

//This is so we can check up the line fast
bool Wire::setGateInput( Gate* input )
{
    this->input = input;
    
    if (this->input != NULL) {
        return true;
    } else {
        return false;
    }
}

void Wire::setWireElectricity(vector<EState> states)
{
    this->mState.clear();
    
    this->mState = states;
    
    if (mState.size() > 0) {
        cout << "received state inputs " << endl;
    } else {
        cout << "there was a problem sending the states" << endl;
    }
    
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

