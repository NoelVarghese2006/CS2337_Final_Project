#include "Store.h"
#include <string>
#include <iostream>
#include <vector>

Store::Store(int m, int c)
{
    maxCapacity = m;
    cash = c;
    currCapacity = 0;
    items.push_back(Item("Electronics", 550.00, 550.00, 500.0));
    items.push_back(Item("Furniture", 330.00, 330.00, 300.0));
    items.push_back(Item("Outdoors", 110.00, 110.00, 100.0));
    items.push_back(Item("Clothes", 55.00, 55.00, 50.0));
    items.push_back(Item("Health", 44.00, 44.00, 40.0));
    items.push_back(Item("Toys", 33.00, 33.00, 30.0));
    items.push_back(Item("Groceries", 22.00, 22.00, 20.0));
    items.push_back(Item("Office", 11.00, 11.00, 10.0));
    
}

string Store::buyItems(string str, int c)
{
    for(int i = 0; i<items.size(); i++)
    {
        if(items.at(i).getName() == str)
        {
            if(currCapacity + c > maxCapacity)
            {
                return "Too many items! Only [" + to_string(maxCapacity - currCapacity) + "] slots left.\n";
            }
            int cost = c * items[i].getSupplyCost();
            if(cash < cost)
            {
                return "Not enough money! Only $[" + to_string(cash) + "] remaining.\n";
            }
            else
            {
                currCapacity += c;
                items[i].addCount(c);
                cash -= cost;
                return "Transaction Completed, Check the summary to check your finances.\n";
            }
        }
    }
    return "Catagory [" + str +  "] DNE!\n";
}

void Store::setPrice(string str, double np)
{
    for(Item& i : items)
    {
        if(i.getName() == str)
        {
            i.setPrice(np);
        }
    }
}

int Store::getCash()
{
    return cash;
}

double Store::getEqualibrium(string str)
{
    for(Item i : items)
    {
        if(i.getName() == str)
        {
            return i.getEqualibrium();
        }
    }
    return -1;
}

void Store::summary()
{
    cout << "STORE\n";
    cout << "=====\n";
    cout << "CASH: " << to_string(cash) << "\n";
    for(Item i : items)
    {
        cout << i.getName() << ": " << i.getCount() << endl;
    }
}

void Store::itemSummary()
{
    cout << "CATAGORY    SUPPLY_PRICE     PRICE    EQUALIBRIUM\n";
    cout << "=================================================\n";
    for(Item i : items)
    {
        cout << i.getName() << ": " << i.getSupplyCost() << ", " << i.getPrice() << ", " << i.getEqualibrium() << endl;
    }
}