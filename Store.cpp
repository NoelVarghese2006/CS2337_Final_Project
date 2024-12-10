#include "Store.h"
#include <string>
#include <iostream>
#include <vector>

Store::Store(int m, int c)
{
    maxCapacity = m;
    cash = c;
    currCapacity = 0;
    items.push_back(Item("Electronics", 0.00, 0.00, 500.0));
    items.push_back(Item("Furniture", 0.00, 0.00, 300.0));
    items.push_back(Item("Outdoors", 0.00, 0.00, 100.0));
    items.push_back(Item("Clothes", 0.00, 0.00, 50.0));
    items.push_back(Item("Health", 0.00, 0.00, 40.0));
    items.push_back(Item("Toys", 0.00, 0.00, 30.0));
    items.push_back(Item("Groceries", 0.00, 0.00, 20.0));
    items.push_back(Item("Office", 0.00, 0.00, 10.0));
    
}
bool Store::buyItems(string str, int c)
{
    
}
int Store::getCash()
{
    return cash;
}
void Store::summary()
{
    string a = "";
    cout << "SUMMARY\n";
    cout << "=======\n";
    cout << "CASH: " << to_string(cash) << "\n";
}