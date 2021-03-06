//
//  Level.cpp
//  Logic
//
//  Created by Gal Sasson on 4/16/13.
//
//

#include "Level.h"
#include "Source.h"
#include "Result.h"
#include "Gate.h"
#include "Wire.h"
#include "And.h"

Level::Level()
{
    vector<EState> s1;
    s1.push_back(HIGH);
    s1.push_back(LOW);
    s1.push_back(HIGH);
    
    vector<EState> s2;
    s2.push_back(HIGH);
    s2.push_back(LOW);
    s2.push_back(LOW);
    
    result = new Result(ofVec2f(700, 175));

    gates.push_back(new Source(ofVec2f(50, 100), s1));
    gates.push_back(new Source(ofVec2f(50, 250), s2));
    gates.push_back(new And(ofVec2f(400, 175)));
    gates.push_back(result);
    
    
    Wire *w = new Wire(ofVec2f(75, 100), ofVec2f(375, 170));
    connect(gates[0], w, gates[2]);
    wires.push_back(w);
    
    w = new Wire(ofVec2f(75, 250), ofVec2f(375, 180));
    connect(gates[1], w, gates[2]);
    wires.push_back(w);
    
    w = new Wire(ofVec2f(425, 175), ofVec2f(675, 175));
    connect(gates[2], w, result);
    wires.push_back(w);
    
    vector<EState> res = result->getResult();
    for (int i=0; i<res.size(); i++)
    {
        cout<<"result: "<<i<<" = "<<res[i]<<endl;
    }
}

void Level::draw()
{
    for (int i=0 ; i<gates.size(); i++)
    {
        gates[i]->draw();
    }
    
    for (int i=0 ; i<wires.size(); i++)
    {
        wires[i]->draw();
    }

}

void Level::update()
{
    for (int i=0 ; i<gates.size(); i++)
    {
        gates[i]->update();
    }
    
    result->suck();
}


void Level::connect(Gate* g1, Wire* w, Gate* g2)
{
    g1->addOutput(w);
    g2->addInput(w);
}

void Level::emitSignal()
{
    Source *s = (Source*)gates[0];
    s->emitSignal();
    
    s = (Source*)gates[1];
    s->emitSignal();
    
}