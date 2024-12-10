#ifndef ITEM_H
#define ITEM_H

#include <string>
#include <map>


using namespace std;

class Item
{
    public:
        Item(string str = "", double p = 0.00, double e = 0.00, double s = 0.00);
        string getName();
        double getSupplyCost();
        double getPrice();
        double getEqualibrium();
        int getCount();

        void setPrice();
        void addCount(int c);

        



    private:
        string typeName;
        double price;
        double equalibrium;
        double supplyCost;
        int count;
        map<string, double> events;

};
#endif