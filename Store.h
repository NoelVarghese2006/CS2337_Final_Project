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
        void buyItems(string str = "", int i = 0);
        //accessors
        int getCash();

        void summary();
    private:
        vector<Item> items;
        int maxCapacity;
        int currCapacity;
        int cash;
};
#endif