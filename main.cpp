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
    }
    return 0;
}