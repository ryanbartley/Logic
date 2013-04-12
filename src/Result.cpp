//
//  Result.cpp
//  Logic
//
//  Created by Ryan Bartley on 4/12/13.
//
//

#include "Result.h"
#include "Wire.h"


Result::Result(int howManySources)
{
    this->howManySources = howManySources;
    result.resize(howManySources);
}

Result::~Result()
{
    result.clear();
}

void Result::getResult()
{
    result = input1->getWireElectricity();
    
    if (howManySources == result.size()) {
        for (vector<EState>::const_iterator it = result.begin(); it != result.end(); it++) {
            cout << "The results are " << *it << endl;
        }
    } else {
        cout << "For some reason there aren't enough numbers in the result" << endl;
    }
}
