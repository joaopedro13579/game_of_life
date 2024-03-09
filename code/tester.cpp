#include <iostream>
#include <fstream>
#include <string>
#include <tuple>
#include "econsim.hpp"
using namespace std;

int main()
{
    pop farmers;
    good grain("grains",1,7.0);
    gl farmer_needs;
    good def;
    farmer_needs(grain,def,def);
    farmers(10,farmer_needs);
    good emp;
    emp=farmers.New_emp();
    farmers.moneygained(emp);
    cout<<farmers.poprequest(farmer_needs)<<endl;
    cout<<endl;
    cout<<farmers;
}