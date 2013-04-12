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
    Wire* input1;
    Wire* input2;
    
    Wire* output;
    
    //This is for the animation 
    EState state1;
    EState state2;
    
    EState stateOutput;
    
    //This is for the result to quickly send it down
    vector<EState> electricityState1;
    vector<EState> electricityState2;
    
    vector<EState> electricityOutput;
    
    ofVec2f gridPos;
    
    //this is to see what type of gate i am
    Gates me;
    
public:
    
    //These two need a wire
    virtual bool addInputs( Wire* input1, Wire* input2 );
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
    virtual void setGridPosition(ofVec2f grid) { gridPos = grid; };
    virtual ofVec2f getGridPosition() { return gridPos; };
    
    //fix this it's only setting and getting one state but we have two states 
    //and an output
    virtual void setState(EState state) { this->state1 = state; };
    virtual EState getState() { return this->state1; };
    

    
};
