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

Deformation::Deformation(ofVec2f _direction, bool init){
    direction.set(_direction);
    direction =direction.rotateRad(PI/2);
    vector<EState> sequence;
    //    int sequence[SEQUENCE_SIZE] ={ 0, 1, 0, 1, 0, -1, 0, -1, 0, -1, 0, 1, 0, 1, 0, 1, 0, 1, 1 ,1};
    if(init){
        
        
        
        sequence.push_back(HIGH);
        sequence.push_back(FLOATING);
        sequence.push_back(FLOATING);
        sequence.push_back(LOW);
        sequence.push_back(FLOATING);
        sequence.push_back(FLOATING);
        sequence.push_back(HIGH);
        sequence.push_back(FLOATING);
        sequence.push_back(FLOATING);
        sequence.push_back(LOW);
        sequence.push_back(FLOATING);
        sequence.push_back(FLOATING);
        sequence.push_back(HIGH);
        //addSquareWave(NUM_OF_FRAMES, sequence);
        
        //  addSine(60);
        addRandom(NUM_OF_FRAMES, 10);
        addSilence(NUM_OF_FRAMES);
    }
    for(int i=0;i<sequence.size();i++){
     //   cout<<sequence[i]<<endl;
    }
    
    
    
}

void Deformation::addRandom(int numFrames, float h){
    for(int i=0;i<numFrames;i++)
    {
        ofVec2f v = ofVec2f(ofRandom(h)-h/2,((ofRandom(h)-h/2)));
        v*=direction;
        frames.push_back(v);
    }
    
    
}

void Deformation::addNoise(int numFrames, float strength, float period){
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

void Deformation::removeSequence(int index){
    
    //SM: Currently assuming that the sequence size will be hardcoded
    
    int remove = index*NUM_OF_FRAMES;
    
    remove--;
    if(frames.size()>NUM_OF_FRAMES){
        frames.erase(frames.begin()+remove, frames.begin()+remove+NUM_OF_FRAMES);
    }
    
}

int Deformation::getNumSequences(){
    return frames.size()/NUM_OF_FRAMES;
}

ofVec2f Deformation::getFrame(int index){
    return frames[index];
}

ofVec2f Deformation::getLastFrame(){
    return frames[frames.size()-1];
}

int Deformation::size(){
    return frames.size();
}



