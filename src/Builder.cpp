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
    
    if (howManyGates <= 0 || howManySources <= 1 || howManyLevels < 0) return;
    
    Source* s1 = new Source(howManySources);
    Source* s2 = new Source(howManySources);
    
    Result* r = new Result(howManySources);
    
    Gate* g = new Not(howManySources);
    
    Wire* w1 = new Wire(howManySources);
    Wire* w2 = new Wire(howManySources);
    Wire* w3 = new Wire(howManySources);
    
    s1->addOutput(w1);
    s2->addOutput(w2);
    
    g->addInput(w1);
    g->addOutput(w3);
    
    r->addInput(w3);
    
    r->getResult();
    
//    Gates g[howManyGates];
//    
//    for (int i = 0; i < howManyGates; i++) {
//        int random;
//        
//        //check my logic here if, only if there are more than one
//        //can we have a not gate
//        if (howManyGates > 1)
//            random = rand()%3;
//        else
//            random = rand()%2;
//        
//        cout << random << " is the random number" << endl;
//        
//        if (random == 0) {
//            g[i] = AND;
//        } else if (random == 1) {
//            g[i] = OR; // this is where or would go
//        } else {
//            g[i] = NOT; // this is where not would go
//        }
//    }
//    
//    //construct the gates
//    vector<Gate*> gates;
//    
//    for (int i = 0; i < howManyGates; i++) {
//        if (g[i] == AND) {
//            cout << "i'm pushing stuff back" << endl;
//            gates.push_back(new And());
//        } else if (g[i] == OR) {
//            gates.push_back(new Or());
//        } else {
//            gates.push_back(new Not());
//        }
//    }
//    
//    //construct the levels
//    vector<Gate*>::iterator it = gates.begin();
    
    
}

