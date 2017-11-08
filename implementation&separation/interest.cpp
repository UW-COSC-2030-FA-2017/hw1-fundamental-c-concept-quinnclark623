//
// Created by quinn.clark
//

#include "interest.h"
#include <iostream>
using namespace std;

double simpleInterest(double p, double r, int t)
{
    return p * (1 + r * t);
}
