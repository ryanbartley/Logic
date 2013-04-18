//
//  Gate.cpp
//  Logic
//
//  Created by Ryan Bartley on 4/9/13.
//
//

#include "Gate.h"
#include "Wire.h"

bool Gate::addOutput(Wire* wire)
{
    if (!wire)
        return false;
    
    //set the output of the gate
    outputs.push_back(wire);
    wire->setInput(this);

    return true;
}

bool Gate::addInput(Wire* wire)
{
    if (!wire)
        return false;
    
    //set the input wire
    inputs.push_back(wire);
    wire->setOutput(this);
    
    return true;
}

float Gate::getLastElectron()
{
    return deform->getLastElectron();
}


float Gate::popLastElectron()
{
    return deform->popLastElectron();
}

void Gate::pushElectron(float val)
{
    deform->pushElectron(val);
}

float Gate::suck()
{
    return 0;
}


vector<EState> Gate::getGateElectricity()
{
    
}

void Gate::sendOutput()
{
    
}

bool Gate::setIncomingElectricity()
{
    
}


void Gate::draw()
{
    
}

void Gate::update()
{
    
}

