#include <iostream>
#include <fstream>
#include <string>
#include <tuple>

using namespace std;

#define econsim_HPP

class good
{
public:
    string name;
    float price;
    float quantity;
    good(string Name="none",float price=0,float quantity=0);
    good operator()(string name="none",float Price=0.0,float Quantity=0.0);
    void newPrice(good new_good);
    void operator+(good new_good);
    void operator=(good new_good);
    void operator=(tuple<string,float,float> new_good);
    void operator++(int new_good);
    void operator*(float size);
    float total();
    friend ostream& operator<<(ostream& os, const good& obj)
    {
          os << "Name: "<<obj.name<<" ; "<<" Price: "<<obj.price<<" ; "<<" Quantity: "<<obj.quantity;
          return os;
    };
};
class gl
{
private:
    good x;
    good y;
    good z;
public:
    gl();
    gl(good um,good two,good three);
    good operator [](int index);
    gl operator ()(good x(),good y(),good z());
    void operator*(int num);
    void operator=(gl list);
    float operator/(gl list);
    ~gl();    
};
class build
{
private:
    gl needs;
    good production;
    float money;
    float total;
    string name="none";
public:
    int size;
    build(good Production(),gl Needs());
    good products(gl atended_needs);
    gl request_needs(good sold_produce);
    void decisionmake();
    ~build();
};
class pop
{
private:
    gl needs;
    float money;
    good emp;
public:
    good Emp;
    float size;
    pop();
    gl poprequest(gl need_meet);
    void moneygained(good employ);
    ~pop();
};
class market
{
private:
    good Good;
    good G; 
public:
    market();
    market(good prod);
    good _good_ (good g,good q);
    good price_deciding();
    void operator=(good prod);
    ~market();
};