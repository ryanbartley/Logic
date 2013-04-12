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
    
    me = SOURCE;
    
    output = NULL;
    
    this->source1.resize(source);
    
    
    cout << "I'm going into the first source" << endl;
    vector<bool>::iterator it = this->source1.begin();
    while (it != this->source1.end()) {
        int random = rand()%100;
        
        if (random > 50) {
            *it = true;
        } else {
            *it = false;
        }
        cout << "the value of the source " << *it << " ";
        it++;
    }
    cout << endl;
}

