#include <iostream>
#include <fstream>
#include <string>
#include <tuple>
#include <unordered_map>
#include "econsim.hpp"
using namespace std;
    //good
    void good::operator()(string Name,float Price,float Quantity)
    {name=Name;price=Price;quantity=Quantity;}
    void good::newPrice(good new_good){price=new_good.price;};
    void good::operator+(good new_good){quantity=quantity+new_good.quantity;};
    void good::operator=(good new_good){name=new_good.name;price=new_good.price;quantity=new_good.quantity;};
    void good::operator++(int new_good){price=price+new_good;};
    void good::operator*(float size){quantity=quantity*size;};
    float good::total(){return quantity* price;};
    good::good(string Name,float Price,float Quantity){name=Name;price=Price;quantity=Quantity;};
    bool good::operator==(good x)
    {
        if (x.quantity==quantity&& x.price==price,x.name==name)
        {
            return true;
        }else
        {
            return false;
        }
        
        
    };
    //good list





    void gl::operator()(good X,good Y,good Z)
    {
        x=X;
        y=Y;
        z=Z;

    }
    gl::gl(){};
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
            good c;
            return c;
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
        if (h==0&& h1==0 && h2==0 && h4==0){h=1;h4=1;}
        float perc=h+h1+h2/h4;
        return perc;
    }
    gl::~gl(){}; 
    std::ostream& operator<<(std::ostream& os, const gl& obj) 
    {
        os << "x: " << obj.x << ";\ny: " << obj.y << ";\nz: " << obj.z<<";";
        return os;
    };
    
    //build class




    std::ostream& operator<<(std::ostream& os, const build& obj){
        os<<"Name:"<<obj.name<<" ;\nneeds\n"<<obj.needs<<";\ngood:"<<obj.production<<";\nmoney:"<<obj.money<<" ;size:"<<obj.size<<";";
        return os;
    }//check
    void build::operator()(good Production,gl Needs)
    {
        name=Production.name;
        production=Production;
        needs=Needs;
        money=0;
        size=1;
    };//check
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
        cout<<size<<endl;
        good day_production=production;
        day_production*(size);
        return day_production;
    }//check
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
    };//check
    void build::decisionmake(){
        if (money>10 && total>0){
            size++;
            money=money-10;
        }
    };//check
    build::~build(){};//check

    // population class


    std::ostream& operator<<(std::ostream& os, const pop& obj)
    {
        os<<"size:"<<obj.size<<" money:"<<obj.money<<"\nneeds:\n"<<obj.needs<<"\nemployees:\n"<<obj.emp<<";";
        return os;
    }
    pop::pop(){};
    void pop::operator()(int Size,gl Needs)
    {
        size=Size;
        emp("employes",1.0,0.75);
        needs=Needs;
        money=10;
    }
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
        return nextNeed;
    };
    good pop::New_emp()
    {
        good Newemp=emp;
        Newemp*size;
        return Newemp;
    };
    void pop::moneygained(good employ)
    {
        money=money+employ.total();
    };
    pop::~pop(){};
    
    
    
    //market class




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