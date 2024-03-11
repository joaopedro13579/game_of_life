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
    void operator()(string name="none",float Price=0.0,float Quantity=0.0);
    void Price(float price);
    void newPrice(good New_Price);
    void operator+(good new_good);
    void operator=(good new_good);
    void operator++(int new_good);
    void operator*(float size);
    float total();
    friend ostream& operator<<(ostream& os, const good& obj)
    {
          os << "Name: "<<obj.name<<" ; "<<" Price: "<<obj.price<<" ; "<<" Quantity: "<<obj.quantity;
          return os;
    };
    bool operator==(good y);
};//tested
class gl
{
private:
    good x;
    good y;
    good z;
public:
    gl();
    good operator [](int index);//check
    void operator ()(good x,good y,good z);//check
    void operator*(int num);//check
    void operator=(gl list);//check
    float operator/(gl list);//check?
    ~gl();    //check
    friend std::ostream& operator<<(std::ostream& os, const gl& obj);//check
};//tested
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
    build(){};//check
    void operator()(good Production,gl Needs);
    good products(gl atended_needs);
    gl request_needs(good sold_produce);
    void decisionmake();
    ~build();//check
    friend std::ostream& operator<<(std::ostream& os, const build& obj);//check
};
class pop
{
private:
    gl needs;

    good emp;
public:
    float size;
    float money;
    pop();//check
    void operator()(int size,gl Needs);//check
    gl poprequest(gl need_meet);
    void moneygained(good employ);//check
    good New_emp();//check
    friend std::ostream& operator<<(std::ostream& os, const pop& obj);//check
    ~pop();//check
};
class market
{
private:
    good temp; 
public:
    good Good;
    friend ostream& operator<<(ostream& os, const market& obj);//check
    market();//check
    void operator=(market Market);//check
    void operator()(good prod);//check
    void change(good change);//check
    good price_deciding();
    ~market();
};
/*TESTED*/