#include <iostream>
#include <fstream>
#include <string>
#include <tuple>
#include "econsim.hpp"
using namespace std;

int main()
{
    good def;
    good grain("grain",1,7.5);
    gl n(grain,def,def);
    pop farmer;
    build farm;
    market grain_market;
    gl farmer_needs=farmer.poprequest(n);

}