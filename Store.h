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
        void buyItems(string str = "", int c = 0);
        void buyAll();
        void setPrice(string str = "", double np = 0);
        void simulation();
        void random();
        void setPeople(int c);
        void addPeople(int c);
        //accessors
        double getCash();
        int getPeople();
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