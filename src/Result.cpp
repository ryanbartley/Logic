//
//  Result.cpp
//  Logic
//
//  Created by Ryan Bartley on 4/12/13.
//
//

#include "Result.h"
#include "Wire.h"

#define POINTS 30
#define WIDTH 100
#define HEIGHT 50
Result::Result(ofVec2f p)
{
    pos = p;
    resultDeform =  Deformation(POINTS);
    deform = new Deformation(POINTS);
    gotResult = false;
    resultSet = false;
}

Result::~Result()
{
    result.clear();
}

vector<EState> Result::getResult()
{
    if (inputs.size() < 1)
        return;
    
    result= inputs[0]->getWireElectricity();
    resultDeform.setResultDeform(result);
    return result;
}

void Result::draw()
{
    int inc = WIDTH/POINTS;
    ofPushMatrix();
    ofTranslate(pos);
    if(resultSet){
    ofSetColor(0, 255, 0);
    }
    else{
        ofSetColor(255, 0, 0);
    }
    
    ofRect(-30, -25, WIDTH, HEIGHT);
    
    
    ofSetLineWidth(2);
    ofSetColor(128);
    //result complement
    ofBeginShape();
    for (int i=0; i<POINTS; i++)
    {
        ofVertex((float)i*inc-20, resultDeform.getAt(POINTS-i));
    }
    ofEndShape();
    
    ofSetColor(200);
    ofSetLineWidth(2);
    
    
    //incoming wire
    if (wireResult.size()>0||resultSet) {
        ofBeginShape();
        for (int i=0; i<POINTS; i++)
        {
            ofVertex((float)i*inc-20, deform->getAt(POINTS-i));
        }
        ofEndShape();
        
    }
    
    ofPopMatrix();
    
    if(gotResult){
        gotResult = false;
        int x =0;
        for (int i=0; i<result.size(); i++) {
            
            cout<<result[i]<<" "<<-(wireResult[i*6]/10)<<endl;
            //Update: This will not exist in the final implementation.
            //The result class will get user input form getResult and compare it to result provided by config file
            
            //The draw loop will only be used to draw the wires not check for results.
            
            //this is where the comparison between the incoming value and stored result is happening
            //there are 6 values for each bit in the wireResult and the sign is the complement of the logic as that is whats required for drawing. That is why there is a -ve sign in front of it.
            if(result[i] == -(wireResult[i*6])/10){
                x++;
            }
            
            
        }
        if(x==3){
            cout<<"right answer"<<endl;
            resultSet = true;
            
        }
        wireResult.clear();
        
        
    }
    
    
}

float Result::suck()
{
    float val = inputs[0]->suck();
    
    if (val>5||val<-5) {
        wireResult.push_back(val);
        deform->pushElectron(val);
        deform->popLastElectron();
    }
    if(wireResult.size()>=18){
        cout<<"gotResult"<<endl;
        gotResult = true;
    }
    return val;
}