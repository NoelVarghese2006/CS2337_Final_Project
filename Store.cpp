#include "Store.h"
#include <string>
#include <iostream>


Store::Store(int m, int c)
{
    maxCapacity = m;
    cash = c;
    currCapacity = 0;
}
void Store::summary()
{
    string a = "";
    cout << "SUMMARY\n";
    cout << "=======\n";
    cout << "CASH: " << to_string(cash) << "\n";
}