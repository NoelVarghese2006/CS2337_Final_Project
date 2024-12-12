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
    map0.emplace("Cash", 1.1);
    randEvs.emplace("Bonus from CEO", map0);
    eventID.emplace(0, "Bonus from CEO");

    map<string, double> map1;
    map1.emplace("Cash", .9);
    randEvs.emplace("IRS Tax Claim", map1);
    eventID.emplace(1, "IRS Tax Claim");

    map<string, double> map2;
    map2.emplace("Max Capacity", 1.1);
    randEvs.emplace("CEO Expanded the Store", map2);
    eventID.emplace(2, "CEO Expanded the Store");

    map<string, double> map3;
    map3.emplace("Max Capacity", 0.9);
    randEvs.emplace("CEO Wants a Coffee Shop In-Store", map3);
    eventID.emplace(3, "CEO Wants a Coffee Shop In-Store");    

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
    uniform_int_distribution<int> distribution(0, 3);
    int id = distribution(generator);
    map<string, double> toReturn;
    string event = eventID[id];
    toReturn = randEvs[event];
    cout << "EVENT: " << event << endl;
    return toReturn;
}