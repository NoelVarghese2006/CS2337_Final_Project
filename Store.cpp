#include "Store.h"
#include <string>
#include <iostream>
#include <vector>

Store::Store(int m, int c)
{
    maxCapacity = m;
    cash = c;
    currCapacity = 0;
    people = 500;
    items.push_back(Item("Electronics", 550.00, 550.00, 500.0));
    items.push_back(Item("Furniture", 330.00, 330.00, 300.0));
    items.push_back(Item("Outdoors", 110.00, 110.00, 100.0));
    items.push_back(Item("Clothing", 77.00, 77.00, 70.0));
    items.push_back(Item("Health", 66.00, 66.00, 60.0));
    items.push_back(Item("Toys", 33.00, 33.00, 30.0));
    items.push_back(Item("Groceries", 16.5, 16.5, 15.0));
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

void Store::simulation()
{
    int oldCash = cash;
    int oldCounts[8];
    for(int i = 0; i<items.size(); i++)
    {
        oldCounts[i] = items.at(i).getCount();
        for(int j = 0; j<4; j++)
        {
            int sales = event.runWeek(500, items[i]);
            if(sales > items.at(i).getCount())
            {
                sales = items.at(i).getCount();
            }
            if(sales > 0)
            {
                cout << "SALES: " << sales << endl;
            }
            items.at(i).addCount(-sales);
            cash += sales * items.at(i).getPrice();
        }
    }
    cout << "SIMULATION RESULTS\n";
    cout << "==================\n";
    cout << "Cash: $" << oldCash << " -> $" << cash << endl;
    for(int i = 0; i<8; i++)
    {
        cout << items[i].getName() << ": " << oldCounts[i] << " -> " << items[i].getCount() << endl;
    }

}

double Store::getCash()
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

double Store::getPrice(string str)
{
    for(Item i : items)
    {
        if(i.getName() == str)
        {
            return i.getPrice();
        }
    }
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