#include <iostream>
#include <fstream>
#include <string>
#include <tuple>
#include "econsim.hpp"
using namespace std;

string market_spreedsheet_maker(market market)
{
    string mm;
    mm=to_string(market.Good.price)+";"+to_string(market.Good.quantity);
    return mm;
}
int main()
{
    
    //textfiles
    ofstream grainFile;
    grainFile.open("grain.csv");
    ofstream employesFile;
    employesFile.open("emp.csv");
    ofstream markets("markets.csv");

    // good settings
    good employes;
    good def;
    good grains;
    employes("employes", 5, 1);
    grains("grain", 1.0, 10);

    // farm setting
    gl farm_needs;
    build farms;
    good farmproductions;
    farm_needs(employes, def, def);
    farms(grains, farm_needs);
    farm_needs(employes,def,def);   
    
    // farmers needs
    pop farmers;
    gl farmer_needs;
    farmer_needs(grains, def, def);
    farmers(2, farmer_needs);
    farmer_needs(grains,def,def);    
    
    // market
    market grain_market;
    grain_market(grains);
    good grains_cons;
    market work_market;
    good used_employes;
    work_market(employes);


    
    //gameloop
    for (int i = 0; i < 5; i++)
    {
        farmproductions=farms.products(farm_needs);
        farm_needs=farms.request_needs(farmproductions);
        farms.decisionmake();
        work_market.change(farm_needs[1],1);
        grain_market.change(farmproductions,0);
        employesFile<<farm_needs<<endl;
        grainFile<<farmproductions<<endl;
        markets<<grain_market<<work_market<<endl;
        grain_market.price_deciding();
        work_market.price_deciding();
    }
}