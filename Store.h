#ifndef STORE_H
#define STORE_H
#include <vector>
#include "Item.h"

using namespace std;

class Store
{
    public:
        Store(int m=0, int c=0);
        //modifiers
        string buyItems(string str = "", int i = 0);
        void setPrice(string str = "", double np = 0);
        //accessors
        int getCash();
        double getEqualibrium(string str = "");

        void summary();
        void itemSummary();
    private:
        vector<Item> items;
        int maxCapacity;
        int currCapacity;
        int cash;
};
#endif