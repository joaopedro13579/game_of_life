#include <iostream>
#include <fstream>
#include <string>
#include <tuple>
#include "econsim.hpp"
using namespace std;

int main()
{
    market grain_market;
    good grain("grains",1,10);
    good harvest("grains",1,15);
    good consumption("grains",1,-12.5);
    grain_market(grain);
    market mm;
    good g;
    mm=grain_market;
    mm.change(harvest);
    mm.change(consumption);
    mm.price_deciding();
    cout<<grain_market<<endl;
    cout<<mm<<endl;
}