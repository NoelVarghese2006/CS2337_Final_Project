#include "Item.h"


Item::Item(string str, double p, double e, double s)
{
    typeName = str;
    price = p;
    equalibrium = e;
    supplyCost = s;
}
string getName();
double getPrice();
void setPrice();
double getEqualibrium();