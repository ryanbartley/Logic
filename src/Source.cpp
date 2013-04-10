//
//  Source.cpp
//  Logic
//
//  Created by Ryan Bartley on 4/9/13.
//
//

#include "Wire.h"
#include "Source.h"

Source::Source(int source)
{
    if (source <= 0) return;
    
    source1Output = NULL;
    source2Output = NULL;
    
    this->source1.resize(source);
    this->source2.resize(source);
    
    cout << "I'm going into the first source" << endl;
    vector<bool>::iterator it = this->source1.begin();
    while (it != this->source1.end()) {
        int random = rand()%100;
        
        if (random > 50) {
            *it = true;
        } else {
            *it = false;
        }
        cout << *it << endl;
        it++;
    }
    
    cout << "i'm going into the second source" << endl;
    it = this->source2.begin();
    while (it != this->source2.end()) {
        int random = rand()%100;
        
        if (random > 50) {
            *it = true;
        } else {
            *it = false;
        }
        cout << *it << endl;
        it++;
    }
    
}

bool Source::setOutputs(Wire* outPutWire1, Wire* outPutWire2)
{
    outPutWire1->setInput(this);
    outPutWire2->setInput(this);
    
}