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

    //Cash Manips
    map<string, double> map0;
    map0.emplace("Cash", 1.1);
    randEvs.emplace("Bonus from CEO", map0);
    eventID.emplace(0, "Bonus from CEO");

    map<string, double> map1;
    map1.emplace("Cash", .9);
    randEvs.emplace("IRS Tax Claim", map1);
    eventID.emplace(1, "IRS Tax Claim");

    //Capacity Manips
    map<string, double> map2;
    map2.emplace("Max Capacity", 1.1);
    randEvs.emplace("CEO Expanded the Store", map2);
    eventID.emplace(2, "CEO Expanded the Store");

    map<string, double> map3;
    map3.emplace("Max Capacity", 0.9);
    randEvs.emplace("CEO Wants a Coffee Shop In-Store", map3);
    eventID.emplace(3, "CEO Wants a Coffee Shop In-Store");    

    //Demand Manips
    map<string, double> map4;
    map4.emplace("Demand", 0);
    map4.emplace("Groceries", 1.1);
    map4.emplace("Clothing", 1.1);
    map4.emplace("Electronics", 1.1);
    map4.emplace("Health", 0.9);
    map4.emplace("Furniture", 0.9);
    map4.emplace("Office", 0.9);
    map4.emplace("Toys", 1.1);
    map4.emplace("Outdoors", 0.9);
    randEvs.emplace("Holiday Season", map4);
    eventID.emplace(4, "Holiday Season");
    
    map<string, double> map5;
    map5.emplace("Demand", 0);
    map5.emplace("Groceries", .9);
    map5.emplace("Clothing", .9);
    map5.emplace("Electronics", 1.1);
    map5.emplace("Health", 1.1);
    map5.emplace("Furniture", 1.1);
    map5.emplace("Office", 1.1);
    map5.emplace("Toys", 0.9);
    map5.emplace("Outdoors", 0.9);
    randEvs.emplace("Innovative Technology", map5);
    eventID.emplace(5, "Innovative Technology");

    map<string, double> map6;
    map6.emplace("Demand", 0);
    map6.emplace("Groceries", 1.1);
    map6.emplace("Clothing", 1.1);
    map6.emplace("Electronics", .9);
    map6.emplace("Health", 1.1);
    map6.emplace("Furniture", .9);
    map6.emplace("Office", .9);
    map6.emplace("Toys", 0.9);
    map6.emplace("Outdoors", 1.1);
    randEvs.emplace("Environmental Crisis", map6);
    eventID.emplace(6, "Environmental Crisis");

    map<string, double> map7;
    map7.emplace("Demand", 0);
    map7.emplace("Groceries", .9);
    map7.emplace("Clothing", .9);
    map7.emplace("Electronics", .9);
    map7.emplace("Health", .9);
    map7.emplace("Furniture", 1.1);
    map7.emplace("Office", 1.1);
    map7.emplace("Toys", 1.1);
    map7.emplace("Outdoors", 1.1);
    randEvs.emplace("Disease Elimination", map7);
    eventID.emplace(7, "Disease Elimination");

    //Supply Manips
    map<string, double> map8;
    map8.emplace("Groceries", .9);
    map8.emplace("Clothing", .9);
    map8.emplace("Electronics", .9);
    map8.emplace("Health", 1.1);
    map8.emplace("Furniture", 1.1);
    map8.emplace("Office", 0.9);
    map8.emplace("Toys", 1.1);
    map8.emplace("Outdoors", 1.1);
    randEvs.emplace("Recycling Increase", map8);
    eventID.emplace(8, "Recycling Increase");

    map<string, double> map9;
    map9.emplace("Groceries", .9);
    map9.emplace("Clothing", .9);
    map9.emplace("Electronics", 1.1);
    map9.emplace("Health", .9);
    map9.emplace("Furniture", 1.1);
    map9.emplace("Office", 1.1);
    map9.emplace("Toys", .9);
    map9.emplace("Outdoors", 1.1);
    randEvs.emplace("Large Goods Tarrif", map9);
    eventID.emplace(9, "Large Goods Tarrif");

    map<string, double> map10;
    map10.emplace("Groceries", 1.1);
    map10.emplace("Clothing", 1.1);
    map10.emplace("Electronics", .9);
    map10.emplace("Health", 1.1);
    map10.emplace("Furniture", .9);
    map10.emplace("Office", .9);
    map10.emplace("Toys", 1.1);
    map10.emplace("Outdoors", .9);
    randEvs.emplace("Small Goods Tarrif", map10);
    eventID.emplace(10, "Small Goods Tarrif");

    map<string, double> map11;
    map11.emplace("Groceries", 1.1);
    map11.emplace("Clothing", 1.1);
    map11.emplace("Electronics", 1.1);
    map11.emplace("Health", .9);
    map11.emplace("Furniture", .9);
    map11.emplace("Office", 1.1);
    map11.emplace("Toys", .9);
    map11.emplace("Outdoors", .9);
    randEvs.emplace("Out of Quick-Selling Goods", map11);
    eventID.emplace(11, "Out of Quick-Selling Goods");
    
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
    uniform_int_distribution<int> distribution(7, 8);
    int id = distribution(generator);
    map<string, double> toReturn;
    string event = eventID[id];
    toReturn = randEvs[event];
    cout << "EVENT: " << event << endl;
    return toReturn;
}

void Events::setFrequency(string str, double d)
{
    auto exists = pFrequency.find(str);
    if(exists != pFrequency.end())
    {
        exists->second = d;
    }
}