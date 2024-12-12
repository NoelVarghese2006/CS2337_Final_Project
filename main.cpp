#include <iostream>
#include <string>
#include "Store.h"

using namespace std;

//Staring cash and space
int mC = 100000;

int main()
{
    int week = 4;
    bool quit = false;
    bool eve = false;
    //Intro Text
    cout << "Hello!\n";
    cout << "This is a simulation of a store. The goal is to gain a profit.\n";
    cout << "Every month, you will be given an option to buy items from the supply chain and set the price of current in stock.\n";
    cout << "There will also be a random event at the end of each month that may affect supply or demand.\n\n";

    cout << "Enter [h] for more information on how the game works.\n";
    cout << "Enter any other key to start: ";
    string temp;
    cin >> temp;
    if(temp == "h")
    {
        cout << "Ill do this later\n";
        cout << "Enter any key to continue: ";
        cin >> temp;
    }
    //Max Capacity of 100k items, starting cash of $100k
    Store myStore(mC, mC);

    //Setup of the option text
    string options;
    options = "Week " + to_string(week) + ":\n";
    options += "1. Enter [q] to quit\n";
    options += "2. Enter [c] to check your summary\n";
    options += "3. Enter [b] to buy items\n";
    options += "4. Enter [p] to set a price\n";
    options += "5. Enter [x] to skip forward one week\n";
    
    options += "Task: ";
    while(!quit)
    {
        if(week == 1 && !eve)
        {
            cout << "THIS RAN\n";
            myStore.random();
            eve = true;
        }
        if(week != 1)
        {
            eve = false;
        }
        string keyword;
        options[5] = 48 + week;
        cout << options;
        cin >> keyword;
        

        if(keyword == "q")
        {
            cout << "Profit: " << to_string(myStore.getCash() - mC);
            quit = true;
        }
        else if(keyword == "c")
        {
            cout << "Enter [stocks] to check your shelves.\n";
            cout << "Enter [costs] to check that statistics for the items.\n";
            cout << "Task: ";
            string cat;
            cin >> cat;
            if(cat == "stocks")
            {
                myStore.summary();
            }
            else if(cat == "costs")
            {
                myStore.itemSummary();
            }
        }
        else if(keyword == "b")
        {
            if(week != 4)
            {
                cout << "Wait until week 4.\n";
            }
            else
            {
                cout << "One Catagory? Enter [c]; or all catagories? Enter [a]: ";
                cin >> keyword;
                if(keyword == "c")
                {
                    cout << "Enter the catagory you want to buy: ";
                    string cat;
                    cin >> cat;
                    cout << "How many?: ";
                    int count;
                    cin >> count;
                    myStore.buyItems(cat, count);
                }
                else if(keyword == "a")
                {
                    myStore.buyAll();
                }
            }            
        }
        else if(keyword == "p")
        {
            cout << "Enter the catagory you want to set: ";
            string cat;
            cin >> cat;
            double eb = myStore.getEqualibrium(cat);
            double p = myStore.getPrice(cat);
            if(eb < 0)
            {
                cout << "[" << cat << "] is not a catagory\n";
            }
            else
            {
                cout << "Current Market Value is: " + to_string(eb) << endl;
                cout << "Current Price is: " + to_string(p) << endl;
                cout << "New Price: ";
                int count;
                cin >> count;
                myStore.setPrice(cat, count);
                cout << "Price Change Completed\n";
            }
        }
        else if(keyword == "x")
        {
            myStore.simulation();
            if(week == 4)
            {
                week = 1;
            }
            else
            {
                week++;
            }
        }
    }
    return 0;
}