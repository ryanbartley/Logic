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
    Wire* input1;
    Wire* input2;
    
    Wire* output;
    
    
    EState state;
    
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
    
    //this isn't a pixel location Vector it's for a column/row
    //position which we can then standardize
    virtual void setGridPosition(ofVec2f grid) { gridPos = grid; };
    virtual ofVec2f getGridPosition() { return gridPos; };
    
    virtual void setState(EState state) { this->state = state; };
    virtual EState getState() { return this->state; };
    
//    virtual ofVec2f getPostion( );
//    virtual void setPosition( ofVec2f pos );
//    
//    //This needs a wire
//    virtual bool getConnection( ofVec2f pos, Wire *wire );
//    
//    virtual bool pick( ofVec2f pos );
//    
//    virtual EState getState();
//    virtual bool setState( EState state );
//    
//    virtual ofVec2f getElectricity();
//    virtual bool setSource(ofVec2f s);
//    virtual ofVec2f getTarget();
//    virtual bool setTarget(ofVec2f t);
    
};
