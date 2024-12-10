#include <iostream>
#include "Store.h"

using namespace std;

int mC = 100000;

int main()
{
    //Max Capacity of 100k items, starting cash of $100k
    Store myStore(mC, mC);
    myStore.summary();
    return 0;
}