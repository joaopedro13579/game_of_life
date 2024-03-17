#include <iostream>
#include <fstream>
#include <string>
#include <tuple>
#include <unordered_map>
#include "econsim.hpp"
using namespace std;
class building
{
public:
    float size;
    string good_name;
    float productivity;
    float employes;
    string need1;
    float need_1;
    string need2;
    float need_2;
    string need3;
    float need_3;
    float money;
    float gain;
    building();
    void operator()(float size = 1, string good_name = "none", float productivity = 1.5, float employes = 0, string need1 = "none", float need_1 = 0, string need2 = "none", float need_2 = 0, string need3 = "none", float need_3 = 0);
    void growth_deciding();
    ~building();
};

building::building()
{
}
void building::operator()(float Size, string Good_name, float Productivity, float Employes, string Need1, float Need_1, string Need2, float Need_2, string Need3, float Need_3)
{
    size=Size;
    good_name=Good_name;
    productivity=Productivity;
    employes=Employes;
    need1=Need1;
    need2=Need2;
    need3=Need3;
    need_1=Need_1;
    need_2=Need_2;
    need_3=Need_3;
}
void building::growth_deciding()
{
    if (money>100 && gain>1)
    {
        size++;
    }else if (money<=10&&gain<0)
    {
        size--;
    }
    money=money+gain;
}
building::~building()
{
}
class pop
{
public:
    float size;
    float productivity;
    float money;
    float gain;
    string need1;
    string need2;
    string need3;
    float need_1;
    float need_2;
    float need_3;
    void operator()(float size,float Productivity,float money,float gain,string need1,string need2,string need3,float need_1,float need_2,float need_3);
    pop();
    ~pop();
};
void pop::operator()(float Size,float Productivity,float Money,float Gain,string Need1,string Need2,string Need3,float Need_1,float Need_2,float Need_3)
{
    size=Size;
    productivity=Productivity;
    need1=Need1;
    need2=Need2;
    need3=Need3;
    need_1=Need_1;
    need_2=Need_2;
    need_3=Need_3;
}
pop::pop()
{
}

pop::~pop()
{
}
