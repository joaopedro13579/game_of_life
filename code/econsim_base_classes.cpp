#include <iostream>
#include <fstream>
#include <string>
#include <tuple>
#include <unordered_map>
#include "econsim.hpp"
using namespace std;
    good good::operator()(string Name="none",float Price=0.0,float Quantity=0.0){name=Name;price=Price;quantity=Quantity;}
    void good::newPrice(good new_good){price=new_good.price;};
    void good::operator+(good new_good){quantity=quantity+new_good.quantity;};
    void good::operator=(good new_good){name=new_good.name;price=new_good.price;quantity=new_good.quantity;};
    void good::operator++(int new_good){price=price+new_good;};
    void good::operator*(float size){quantity=quantity*size;};
    float good::total(){return quantity* price;};
    good::good(string Name,float Price,float Quantity){name=Name;price=Price;quantity=Quantity;};
    
    gl gl::operator()(good X(),good Y(),good Z())
    {
        x=X();
        y=y();
        x=z();
    }
    gl::gl(good um,good two,good three){x=um;y=two;z=three;};
    good gl::operator [](int index)
    {
        if (index==1){
            return x;
        }else if (index==2)
        {
            return y;
        }else if (index==3)
        {
            return z;
        }else
        {
            cout<<"error index out of range"<<endl;
        } 
    }
    void gl::operator*(int num){x*num;y*num,z*num;}
    void gl::operator=(gl list){x=list[1],y=list[2],z=list[3];}
    float gl::operator/(gl list)
    {
        float h=0;
        float h1=0;
        float h2=0;
        float h4=0;
        if (list[1].name!="none")
        {
            h =(x.quantity/list[1].quantity);
            h4++;
        }
        if (list[2].name!="none")
        {
            h1 =(y.quantity/list[2].quantity);
            h4++;
        }
        if (list[3].name!="none")
        {
            h2 =(z.quantity/list[3].quantity);
            h4++;
        }
        int perc=h+h1+h2/h4;
        return perc;
    }
    gl::~gl(){};  
    build::build(good Production(),gl Needs())
    {
        production=Production();
        needs=Needs();
        money=0;
        size=2;
    };
    good build::products(gl atended_needs)
    {
        money=money+needs[1].price*atended_needs[1].quantity+needs[3].price*atended_needs[3].quantity+needs[2].price*atended_needs[2].quantity;
        for (int i = 1; i < 3; i++)
        {
            needs[i].newPrice(atended_needs[i]);
        }
        gl Needs=needs;
        Needs*size;
        float perc =atended_needs/Needs;
        cout<<perc;
        good day_production=production;
        day_production*(size);
        return day_production;
    }
    gl build::request_needs(good sold_produce)
    {
        float gained=(sold_produce.price*sold_produce.quantity);
        money=money+gained;
        float acum=0;
        for (int i = 1; i < 3; i++)
        {
         acum=acum+(needs[i].quantity*needs[i].price);    
        }
        if (acum<money)
        {
            money=money-acum;    
        }else
        {
            float perc=money/acum;
            gl request_needs=needs;
            request_needs*perc;
            return request_needs;
        }
        gl request_needs=needs;
        total=gained-acum;
        request_needs*size;
        return request_needs;
    };
    void build::decisionmake(){
        if (money>15 && total>0){
            size++;
            money=money-10;
        }
    };
    build::~build(){};

    pop::pop(){
        size=10;
        good Epm("employes",1.0,7.5);
        emp=Epm;
        good grain("grains",0,5);
        good def;
        gl Needs(grain,def,def);
        needs=Needs;
        money=10;
        Emp=emp;
    };
    gl pop::poprequest(gl need_meet)
    {
        float acum;
        for (int i = 1; i < 4; i++)
        {
            acum=acum+need_meet[i].total();
        }
        money=money-acum;
        gl nextNeed=needs;
        nextNeed*size;
        float perc=nextNeed/need_meet;
        if (perc>=0.75)
        {
            size++;
        }else if (perc<0.5)
        {
            size--;
        }
        if (money<acum){
            float per=money/acum;
            nextNeed*per;
        }
        Emp=emp;
        Emp*size;
        return nextNeed;
    };
    void pop::moneygained(good employ)
    {
        money=money+employ.total();
    };
    pop::~pop(){};
    market::market(){};
    void market::operator=(good prod){Good=prod;};
    market::market(good prod)
    {
        Good=prod;
    };
    good market:: _good_ (good g,good q)
    {   
        if (g.name!=Good.name && q.name!=Good.name)
        {
            good def;
            return def;
        } 
        g+q;
        G=g;
        return g;
    };
    good market::price_deciding()
    {
        if (Good.quantity>=G.quantity)
        {
            G.price=G.price-1;
        }else
        {
            G.price=G.price+1;
        }
        good next(Good.name,G.price,G.quantity);
        return next;
    }
    market::~market(){};