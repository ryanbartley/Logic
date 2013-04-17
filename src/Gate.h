//
//  Gate.h
//  Logic
//
//  Created by Ryan Bartley on 4/9/13.
//
//

#pragma once

#include "ofMain.h"
#include "State.h"
#define DEBUG 

class Wire;

class Gate {

protected:
    
    //This is to know who the inputs are
    vector<Wire*> inputs;
    vector<Wire*> outputs;
    
    ofVec2f pos;
    
    //this is to see what type of gate i am
    Gates me;
    
public:
    
    virtual bool addInput(Wire* input);
    virtual bool addOutput( Wire* output );
    
    virtual void update();
    virtual void draw();
    
    virtual bool setIncomingElectricity();
    virtual void sendOutput();
    
    virtual void processElectricity() {};
    
    virtual Gates getMe() { return me; };
    
    virtual vector<EState> getGateElectricity();
    
    //this isn't a pixel location Vector it's for a column/row
    //position which we can then standardize
    virtual void setGridPosition(ofVec2f grid) { pos = grid; };
    virtual ofVec2f getGridPosition() { return pos; };
    
//    //fix this it's only setting and getting one state but we have two states 
//    //and an output
//    virtual void setState(EState state) { this->state1 = state; };
//    virtual EState getState() { return this->state1; };
    

    
};
