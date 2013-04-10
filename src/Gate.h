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

class Wire;

class Gate {

protected:
    Wire* input1;
    Wire* input2;
    
    Wire* output;
    
public:
    
    //These two need a wire
    virtual bool addInputs( Wire* input1, Wire* input2 );
    virtual bool addInput(Wire* input);
    virtual bool addOutput( Wire* output );
    
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
