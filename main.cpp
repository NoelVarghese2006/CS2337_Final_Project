#include <iostream>
#include <string>
#include "Store.h"

using namespace std;

//Staring cash and space
int mC = 100000;

int main()
{
    bool quit = false;
    //Intro Text
    cout << "Hello!\n";
    cout << "This is a simulation of a store. The goal is to gain a profit.\n";
    cout << "Every month, you will be given an option to buy items from the supply chain and set the price of current in stock.\n";
    cout << "There will also be a random event at the end of each month that may affect supply or demand.\n";

    //Max Capacity of 100k items, starting cash of $100k
    Store myStore(mC, mC);

    //Setup of the option text
    string options;
    options = "Options:\n";
    options += "1. Enter [q] to quit\n";
    options += "2. Enter [s] to check your summary\n";
    options += "3. Enter [b] to buy items\n";
    options += "4. Enter [p] to set a price\n";
    options += "Task: ";
    while(!quit)
    {
        string keyword;
        cout << options;
        cin >> keyword;
        

        if(keyword == "q")
        {
            cout << "Profit: " << to_string(myStore.getCash() - mC);
            quit = true;
        }
        else if(keyword == "s")
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
            cout << "Enter the catagory you want to buy: ";
            string cat;
            cin >> cat;
            cout << "How many?: ";
            int count;
            cin >> count;
            cout << myStore.buyItems(cat, count);
        }
        else if(keyword == "p")
        {
            cout << "Enter the catagory you want to set: ";
            string cat;
            cin >> cat;
            double eb = myStore.getEqualibrium(cat);
            if(eb < 0)
            {
                cout << "[" << cat << "] is not a catagory\n";
            }
            else
            {
                cout << "Current Market Value is: " + to_string(eb) << endl;
                cout << "New Price: ";
                int count;
                cin >> count;
                myStore.setPrice(cat, count);
                cout << "Price Change Completed\n";
            }
        }
    }
    return 0;
}