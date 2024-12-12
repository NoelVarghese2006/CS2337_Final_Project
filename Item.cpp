#include "Item.h"


Item::Item(string str, double p, double e, double s)
{
    typeName = str;
    price = p;
    equalibrium = e;
    supplyCost = s;
    count = 0;
}
string Item::getName()
{
    return typeName;
}
double Item::getSupplyCost()
{
    return supplyCost;
}
int Item::getCount()
{
    return count;
}
double Item::getEqualibrium()
{
    return equalibrium;
}
double Item::getPrice()
{
    return price;
}
void Item::addCount(int c)
{
    count += c;
}
void Item::setPrice(double np)
{
    price = np;
}
void Item::setEqualibrium(double e)
{
    equalibrium = e;
}
void Item::setSupplyCost(double s)
{
    supplyCost = s;
}