#ifndef STORE_H
#define STORE_H
#include <vector>
#include "Item.h"
#include "Events.h"

using namespace std;

class Store
{
    public:
        Store(int m=0, int c=0);
        //modifiers
        string buyItems(string str = "", int i = 0);
        void setPrice(string str = "", double np = 0);
        void simulation();
        //accessors
        double getCash();
        double getEqualibrium(string str = "");
        double getPrice(string str);

        void summary();
        void itemSummary();
    private:
        Events event;
        vector<Item> items;
        int maxCapacity;
        int currCapacity;
        double cash;
        int people;
};
#endif