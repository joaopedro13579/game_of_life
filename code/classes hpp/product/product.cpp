
#include <iostream>
#include <string>
#include "product.hpp"

using namespace std;

class product
{
public:
    string name;
    float quantity;
    float price;
    product(string name="none",float quantity=0,float price=0);
    ~product();
};

product::product(string Name,float Quantity,float Price)
{
    name=Name;
    quantity=Quantity;
    price=Price;
}

product::~product()
{
}
