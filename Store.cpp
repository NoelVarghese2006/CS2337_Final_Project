#include "Store.h"
#include <string>
#include <iostream>
#include <vector>
#include <map>

Store::Store(int m, int c)
{
    maxCapacity = m;
    cash = c;
    currCapacity = 0;
    people = 100;
    items.push_back(Item("Electronics", 550.00, 550.00, 500.0));
    items.push_back(Item("Furniture", 330.00, 330.00, 300.0));
    items.push_back(Item("Outdoors", 110.00, 110.00, 100.0));
    items.push_back(Item("Clothing", 77.00, 77.00, 70.0));
    items.push_back(Item("Health", 66.00, 66.00, 60.0));
    items.push_back(Item("Toys", 33.00, 33.00, 30.0));
    items.push_back(Item("Groceries", 16.5, 16.5, 15.0));
    items.push_back(Item("Office", 11.00, 11.00, 10.0));
    
}

void Store::buyItems(string str, int c)
{
    for(int i = 0; i<items.size(); i++)
    {
        if(items.at(i).getName() == str)
        {
            if(currCapacity + c > maxCapacity)
            {
                cout << "Too many items! Only [" + to_string(maxCapacity - currCapacity) + "] slots left.\n";
                return;
            }
            int cost = c * items[i].getSupplyCost();
            if(cash < cost)
            {
                cout << "Not enough money! Only $[" + to_string(cash) + "] remaining.\n";
                return;
            }
            else
            {
                currCapacity += c;
                items[i].addCount(c);
                cash -= cost;
                cout << "Transaction Completed, $[" + to_string(cash) + "] remaining.\n";
                return;
            }
        }
    }
    cout << "Catagory [" + str +  "] DNE!\n";
    return;
}

void Store::buyAll()
{
    string cat = "";
    int count;
    for(Item& i : items)
    {
        cat = i.getName();
        cout << "How many [" << cat << "] do you want: ";
        cin >> count;
        buyItems(cat, count);
    }
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

void Store::setPeople(int c)
{
    people = c;
}

void Store::addPeople(int c)
{
    people += c;
}

void Store::simulation()
{
    int oldCash = cash;
    int oldCounts[8];
    int oldPeople = people;
    int pplChanges[8];
    for(int i = 0; i<items.size(); i++)
    {
        oldCounts[i] = items.at(i).getCount();
        int sales = event.runWeek(people, items[i]);
        pplChanges[i] = (items.at(i).getCount() - sales)/(10 * event.getFrequency(items.at(i).getName()));
        if(sales > items.at(i).getCount())
        {
            sales = items.at(i).getCount();
        }
        items.at(i).addCount(-sales);
        cash += sales * items.at(i).getPrice();
    }
    string catLow;
    int lowC = 0;
    string catHigh;
    int highC = 0;
    for(int i = 0; i < 8; i++)
    {
        people += pplChanges[i];
        if(pplChanges[i] < lowC)
        {
            catLow = items.at(i).getName();
            lowC = pplChanges[i];
        }
        if(pplChanges[i] > highC)
        {
            catHigh = items.at(i).getName();
            highC = pplChanges[i];
        }   
    }
    if(people < 1)
        people = 1;
    cout << "SIMULATION RESULTS\n";
    cout << "==================\n";
    cout << "Cash: $" << oldCash << " -> $" << cash << endl;
    for(int i = 0; i<8; i++)
    {
        cout << items[i].getName() << ": " << oldCounts[i] << " -> " << items[i].getCount() << endl;
    }
    cout << "Shoppers: " << oldPeople << " -> " << people << endl;
    if(highC > 0)
        cout << "Shoppers love the abundance of [" << catHigh << "] +" << highC << " people!\n";
    if(lowC < 0)
        cout << "Shoppers couldn't find [" << catLow <<  "] " << lowC << " people.\n";

}

void Store::random()
{
    map<string, double> mods = event.randomEvent();
    auto isCash = mods.find("Cash");
    auto isMaxCap = mods.find("Max Capacity");
    auto isDemand = mods.find("Demand");
    if(isCash != mods.end())
    {
        cout << "Cash: " << cash;
        cash *= isCash->second;
        cout << " -> " << cash << endl;
    }
    else if(isMaxCap != mods.end())
    {
        cout << "Max Capacity: " << maxCapacity;
        maxCapacity *= isMaxCap->second;
        cout << " -> " << maxCapacity << endl;
    }
    else if(isDemand != mods.end())
    {
        string ups = "/\\ Value: ";
        string downs = "\\/ Value: ";
        for(Item& i : items)
        {
            i.setEqualibrium(i.getEqualibrium() * mods.at(i.getName()));
            event.setFrequency(i.getName(), event.getFrequency(i.getName()) * mods.at(i.getName()));
            if(mods.at(i.getName()) > 1)
            {
                ups += i.getName() + " ";
            }
            else
            {
                downs += i.getName() + " ";
            }
        }
        cout << ups << endl;
        cout << downs << endl;
    }
    else
    {
        string ups = "\\/ Cost: ";
        string downs = "/\\ Cost: ";
        for(Item& i : items)
        {
            i.setSupplyCost(i.getSupplyCost() * mods.at(i.getName()));
            if(mods.at(i.getName()) < 1)
            {
                ups += i.getName() + " ";
            }
            else
            {
                downs += i.getName() + " ";
            }
        }
        cout << ups << endl;
        cout << downs << endl;
    }
}

int Store::getPeople()
{
    return people;
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