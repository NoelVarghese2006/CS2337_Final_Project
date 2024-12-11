#include "Events.h"

Events::Events()
{
    pFrequency.insert({"Groceries", 5.00});
    pFrequency.insert({"Clothing", 1.019});
    pFrequency.insert({"Electronics", 0.077});
    pFrequency.insert({"Health", 0.5});
    pFrequency.insert({"Furniture", 0.038});
    pFrequency.insert({"Office", 0.962});
    pFrequency.insert({"Toys", 0.192});
    pFrequency.insert({"Outdoors", 0.115});


    map<string, double> map0;
    map0.emplace("Cash", 1.5);
    randEvs.emplace("Bonus from CEO", map0);
    eventID.emplace(0, "Bonus from CEO");

    map<string, double> map1;
    map1.emplace("Cash", .5);
    randEvs.emplace("IRS Tax Claim", map1);
    eventID.emplace(1, "IRS Tax Claim");

}

double Events::getFrequency(string str)
{
    return pFrequency.at(str);
}

double Events::runWeek(int ppl, Item& item)
{
    double e = item.getEqualibrium();
    double p = item.getPrice();
    double m = -0.5/e;
    double diff = (p - e) * m;
    double percentDiff = diff/.5;
    
    //RNG
    random_device rd;
    default_random_engine generator(rd());
    uniform_real_distribution<double> distribution(0.0, 1.0);

    int numSold = 0;
    for(int i=0; i<ppl; i++)
    {
        double probs = pFrequency.at(item.getName());
        probs += probs * percentDiff;
        while(probs >= 1)
        {
            double rFloat = distribution(generator);
            if(rFloat <= .5)
            {
                numSold++;
            }
            probs -= .5;
        }

        double rFloat = distribution(generator);
        if(rFloat <= probs)
        {
            //cout << "ADD\n";
            numSold++;
        }
    }
    return numSold;
}

map<string, double> Events::randomEvent()
{
    random_device rd;
    default_random_engine generator(rd());
    uniform_int_distribution<int> distribution(0, 1);
    cout << distribution(generator);
    map<string, double> hey;
    return hey;
}