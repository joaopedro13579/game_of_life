#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

class Good
{
private:
    string name;
    double price;
    double quantity;

public:
    Good(string n, double p, double q) : name(n), price(p), quantity(q) {}
    string getName() { return name; }
    double getPrice() { return price; }
    double getQuantity() { return quantity; }
    void setQuantity(double q, string Flag = "0", double n = 0)
    {
        if (Flag == "0")
        {
            quantity = quantity + q;
            if (q > 0)
            {
                price = price - 0.5 * q;
            }
            else
            {
                double n = q * -1;
                price = price + 0.5 * n;
            }
        }
        else if (Flag == "1")
        {
            quantity = q;
        }
        else if (Flag == "2")
        {
            quantity = q;
            price = price + 1 * n;
        }
    }
    void setPrice(double newPrice) { price = newPrice; }
};

class Market
{
private:
    vector<Good> goods;

public:
    void addGood(Good good)
    {
        goods.push_back(good);
    }

    vector<Good> SuplyChange(vector<Good> Needs)
    {
        vector<Good> needsMeet = Needs;
        for (int i = 0; i < Needs.size(); i++)
        {
            for (int j = 0; j < goods.size(); j++)
            {
                if (goods[j].getName() == Needs[i].getName())
                {
                    if (goods[j].getQuantity() > (Needs[i].getQuantity() * -1))
                    {
                        goods[j].setQuantity(Needs[i].getQuantity());
                    }
                    else
                    {
                        needsMeet[i].setQuantity((goods[j].getQuantity() * -1), "1");
                        goods[j].setQuantity(0, "2", -1 * Needs[i].getQuantity());
                    }
                }
            }
        }
        return needsMeet;
    }

    void update_prices() {}

    void displayMarket()
    {
        cout << "Current Market Status:" << endl;
        for (int i = 0; i < goods.size(); ++i)
        {
            cout << goods[i].getName() << ":\n"
                 << "Price: $" << goods[i].getPrice() << "\n"
                 << "Supply: " << goods[i].getQuantity() << endl;
        }
    }
};

class Building
{
private:
    Good Production;
    double throughput;
    vector<Good> needs;
    double funds;
    double size = 0;

public:
    Building() : Production("null", 0.0, 0.0), throughput(0.0), funds(0.0) {}
    void setProduction(Good P)
    {
        Production = P;
    }
    void setThroughput(double t)
    {
        throughput = t;
    }
    void setNeed(vector<Good> g)
    {
        needs = g;
    }
    void printNeeds()
    {
        cout << Production.getName() << "--";
        for (int i = 0; i < needs.size(); i++)
        {
            cout << needs[i].getName() << ":" << needs[i].getQuantity() << "\t";
        }
        cout << endl;
    }
    vector<Good> getNeeds()
    {
        return needs;
    }
    Good getProduction() { return Production; }
    Good getProd(vector<Good> N, string print = "P")
    {
        double contractedEmployes = 1;
        double goodsRecieved = 1;
        double neededEmployes = 1;
        int Q = size;
        for (int i = 0; i < N.size(); i++)
        {
            if (N[i].getName() == "employes")
            {
                contractedEmployes = N[i].getQuantity();
            }
            else
            {
                goodsRecieved = N[i].getQuantity();
            }
        }
        double goodsNeeded = 1;
        for (int i = 0; i < N.size(); i++)
        {
            if (N[i].getName() == "employes")
            {
                neededEmployes = needs[i].getQuantity();
            }
            else
            {
                goodsNeeded = needs[i].getQuantity();
            }
        }
        double v = goodsRecieved / (goodsNeeded / 2);
        if (v >= 0.75 && contractedEmployes == neededEmployes)
        {
            if (Production.getName() == "employes" && size > 0)
            {
                size = size * (1 + v) / 2;
                for (int i = 0; i < needs.size(); i++)
                {
                    needs[i].setQuantity(((-10)* size), "1");
                    needs[i].setPrice(0);
                }            
            }else
            {
                size = size + 1;

                for (int i = 0; i < needs.size(); i++)
                {
                    needs[i].setQuantity(((needs[i].getQuantity()) + needs[i].getQuantity() / size), "1");
                    needs[i].setPrice(0);
                }
            }
        }
        else if (size > 1 && v < 0.5)
        {
            if (Production.getName() == "employes")
            {
                size = size * ((1 - v) / 2);
                for (int i = 0; i < needs.size(); i++)
                {
                    needs[i].setQuantity(((-10)* size), "1");
                    needs[i].setPrice(0);
                }     
            }
            else
            {
                size = size - 1;

                for (int i = 0; i < needs.size(); i++)
                {
                    needs[i].setQuantity(((needs[i].getQuantity()) - needs[i].getQuantity() / size), "1");
                    needs[i].setPrice(0);
                }
            }
        }
        double Prod = v * throughput * Production.getQuantity() * size * contractedEmployes / neededEmployes;
        if (print != "Np")
        {
            cout << Production.getName() << " production :" << Prod << " size:" << size << endl;
        }
        printNeeds();
        return Good(Production.getName(), Production.getPrice(), Prod);
    }
};

int main()
{
    srand(time(0)); // Seed random number generator

    // Create a market
    Market market;

    // Making some buildings
    vector<Building> buildings;
    vector<Good> buildingNeeds;
    vector<Good> buildingProds;

    Building orchad;
    orchad.setProduction(Good("Apple", 1.0, 10));
    orchad.setNeed(vector<Good>{Good("fertilizer", 1.0, -10.0), Good("employes", 5, -5.0)});
    Building fert_mines;
    fert_mines.setProduction(Good("fertilizer", 1, 15));
    fert_mines.setNeed(vector<Good>{Good("employes", 5, -1)});
    Building house;
    house.setProduction(Good("employes", 5, 15));
    house.setNeed(vector<Good>{Good("Apple", 10.0, -10.0)});

    buildings.push_back(orchad);
    buildings.push_back(fert_mines);
    buildings.push_back(house);
    for (int i = 0; i < buildings.size(); i++)
    {
        buildingProds.push_back(buildings[i].getProduction());
    }
    // Add some goods to the market
    market.addGood(Good("Apple", 10.0, 20));
    market.addGood(Good("fertilizer", 10.0, 20));
    market.addGood(Good("employes", 30, 20));

    // Simulate market updates for 5 days
    for (int day = 1; day <= 500; ++day)
    {
        for (int i = 0; i < buildings.size(); i++)
        {
            buildingNeeds = buildings[i].getNeeds();
            buildingNeeds = market.SuplyChange(buildingNeeds);
            buildingProds[i] = buildings[i].getProd(buildingNeeds);
            buildings[i].setThroughput(1.0 + ((double)rand() / RAND_MAX));
        }
        market.SuplyChange(buildingProds);
        cout << "Day " << day << ":" << endl;
        market.displayMarket();
        cout << endl;
    }
    cout << "end" << endl;
    return 0;
}
