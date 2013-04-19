//
//  Deformation.cpp
//  wireDrawingTest
//
//  Created by Surya on 12/04/13.
//
//

#include "Deformation.h"
Deformation::Deformation(){
    
}
Deformation::Deformation(int numFrames)
{
    addRandom(numFrames, 5);
}

Deformation::Deformation(vector<EState> seq)
{
    for (int i=0; i<seq.size(); i++)
    {
        for (int j=0; j<3; j++)
            values.push_back(0);
        for (int j=0; j<6; j++)
        {
            if (seq[i] == HIGH)
                values.push_back(-10);
            else
                values.push_back(10);
        }
    }
    
}

void Deformation::addRandom(int numFrames, float h)
{
    for(int i=0;i<numFrames;i++)
    {
        values.push_back(ofRandom(h)-h/2);
    }
    
    
}

void Deformation::setResultDeform(vector<EState> seq){
    values.clear();
    
    for (int i=0; i<seq.size(); i++)
    {
      //  for (int j=0; j<3; j++)
      //      values.push_back(0);
        for (int j=0; j<6; j++)
        {
            //Making it the opposite of the constructor
            if (seq[i] == HIGH){
                values.push_back(-10);
            }
            
            else{
                values.push_back(10);
            }
            
        }
    }
}

/*
 void Deformation::addNoise(int numFrames, float strength, float period)
 {
 float t = ofRandom(10000);
 
 for(int i =0; i< numFrames;i++){
 ofVec2f v = ofVec2f((ofNoise(t)-0.5)*strength,(ofNoise(t)-0.5)*strength);
 v *=direction;
 frames.push_back(v);
 t+=period;
 }
 }
 
 void Deformation::addSilence(int numFrames){
 for(int i=0;i<numFrames;i++){
 frames.push_back(ofVec2f(0, 0));
 }
 }
 
 void Deformation::addSine(int numFrames){
 float t = 0;
 for(int i=0; i<numFrames;i++){
 ofVec2f v = ofVec2f(sin(t)*100,sin(t)*100);
 v*=direction;
 frames.push_back(v);
 t += PI/10;
 }
 }
 
 void Deformation::addSquareWave(int numFrames, vector<EState> sequence){
 int sequenceSize = sequence.size();
 
 int sequencePeriod = numFrames/sequenceSize;
 
 for(int bit =0;bit<sequenceSize;bit++){
 for(int i=0; i<sequencePeriod; i++){
 
 ofVec2f v = ofVec2f(-(int)sequence[bit]*10,-(int)sequence[bit]*10);
 // cout<<sequence[bit]<<endl;
 v*=direction;
 frames.push_back(v);
 
 }
 }
 }
 */

float Deformation::popLastElectron(){
    int size = values.size();
    
    if (size > 0)
    {
        float last = values[0];
        values.erase(values.begin());
        return last;
    }
    
    return ofRandom(-2.5, 2.5);
}

float Deformation::getLastElectron()
{
    int size = values.size();
    
    if (size > 0)
    {
        return values[0];
    }
    
    return ofRandom(-2.5, 2.5);
}

void Deformation::pushElectron(float val)
{
    values.push_back(val);
}

float Deformation::getAt(int index)
{
    return values[index];
}

int Deformation::size(){
    return values.size();
}



