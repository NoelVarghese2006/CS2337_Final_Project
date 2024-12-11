#ifndef EVENTS_H
#define EVENTS_H

#include <string>
#include <map>
#include <random>
#include "Item.h"

using namespace std;

class Events
{
    public:
        Events();
        double runWeek(int ppl, Item& i);
    private:
        map<string, double> pFrequency;

};
#endif