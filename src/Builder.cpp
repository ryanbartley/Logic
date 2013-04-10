//
//  Builder.cpp
//  Logic
//
//  Created by Ryan Bartley on 4/9/13.
//
//

#include "Builder.h"
#include <iostream>

using namespace std;

Builder::Builder(int howManyGates, int howManySources, int howManyLevels)
{
    if (howManyGates <= 0 || howManySources <= 1 || howManyLevels > 0) return;
    
    Source* s = new Source(howManySources);
    
    Gates g[howManyGates];
    
    for (int i = 0; i < howManyGates; i++) {
        int random;
        
        //check my logic here if, only if there are more than one
        //can we have a not gate
        if (howManyGates > 1)
            random = rand()%3;
        else
            random = rand()%2;
        
        cout << random << " is the random number" << endl;
        
        if (random == 0) {
            g[i] = AND;
        } else if (random == 1) {
            g[i] = AND; // this is where or would go
        } else {
            g[i] = AND; // this is where not would go
        }
    }
    
    //construct the gates
    vector<Gate*> gates;
    
    for (int i = 0; i < howManyGates; i++) {
        if (g[i] == AND) {
            cout << "i'm pushing stuff back" << endl;
            gates.push_back(new And());
        } else if (g[i] == OR) {
            gates.push_back(new Or());
        } else {
            gates.push_back(new Not());
        }
    }
    
    //construct the levels
    vector<Gate*>::iterator it = gates.begin();
    
    Wire* w1 = new Wire();
    Wire* w2 = new Wire();
    
    s->setOutputs( w1, w2);
    (*it)->addInputs(w1, w2);
    
}

