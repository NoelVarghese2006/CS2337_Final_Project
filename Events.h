#ifndef EVENTS_H
#define EVENTS_H

#include <string>
#include <map>
#include <vector>
#include <random>
#include "Item.h"

using namespace std;

class Events
{
    public:
        Events();
        double runWeek(int ppl, Item& i);
        double getFrequency(string str);
        map<string, double> randomEvent();
        void setFrequency(string str, double d);
    private:
        map<string, double> pFrequency;
        map<string, map<string, double>> randEvs;
        map<int, string> eventID;
};
#endif