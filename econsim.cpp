#include <iostream>
#include <fstream>
#include <string>
#include <tuple>
using namespace std;
class good
{
public:
    string name;
    float price;
    float quantity;
    void newPrice(good new_good){price=new_good.price;};
    void operator+(good new_good){quantity=quantity+new_good.quantity;};
    void operator=(good new_good){name=new_good.name;price=new_good.price;quantity=new_good.quantity;};
    void operator=(tuple<string,float,float> new_good){name=get<0>(new_good);price=get<1>(new_good);quantity=get<2>(new_good);};
    void operator++(int new_good){price=new_good+price;};
    void operator*(float size){quantity=quantity*size;};
    friend ostream& operator<<(ostream& os, const good& obj)
    {
          os << "Name: "<<obj.name<<" ; "<<" Price: "<<obj.price<<" ; "<<" Quantity: "<<obj.quantity;
          return os;
    }
    good(string Name="none",float Price=0,float Quantity=0){name=Name;price=Price;quantity=Quantity;};

};
class gl
{
private:
    good _01_;
    good _02_;
    good _03_;
public:
    gl(){good _default_;good _default2_;good _default3_; _01_=_default_;_02_=_default2_;_03_=_default3_;};
    gl(good um,good two,good three){_01_=um;_02_=two;_03_=three;};
    good operator [](int index)
    {
        if (index==1){
            return _01_;
        }else if (index==2)
        {
            return _02_;
        }else if (index==3)
        {
            return _03_;
        }else
        {
            cout<<"error index out of range"<<endl;
        } 
    }
    void operator*(int num){_01_*num;_02_*num,_03_*num;}
    void operator=(gl list){_01_=list[1],_02_=list[2],_03_=list[3];}
    int operator/(gl list)
    {
        float h=0;
        float h1=0;
        float h2=0;
        float h4=0;
        if (list[1].name!="none")
        {
            h =(_01_.quantity/list[1].quantity);
            h4++;
        }
        if (list[2].name!="none")
        {
            h1 =(_02_.quantity/list[2].quantity);
            h4++;
        }
        if (list[3].name!="none")
        {
            h2 =(_03_.quantity/list[3].quantity);
            h4++;
        }
        int perc=h+h1+h2/h4;
        return perc;
    }
    ~gl(){};  
};
class build
{
private:
    gl needs;

    good production;
    float money;
    float total;
public:
    int size;
    build(good Production,gl Needs)
    {
        production=Production;
        needs=Needs;
        money=0;
        size=1;
    };
    good products(gl atended_needs)
    {
        money=money+needs[1].price*atended_needs[1].quantity+needs[3].price*atended_needs[3].quantity+needs[2].price*atended_needs[2].quantity;
        for (int i = 1; i < 3; i++)
        {
            needs[i].newPrice(atended_needs[i]);
        }
        
        int perc =needs/atended_needs;
        good day_production=production;
        day_production*(size*perc);
        return day_production;
    }
    gl request_needs(good sold_produce)
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
    void decisionmake(){
        if (money>15 && total>0){
            size++;
            money=money-10;
        }
    };
    ~build(){};
};


int main(){
    ofstream textFile;
    textFile.open("econsim.csv");
    good grains("grain",1.5,2.5);
    good fertilizer("fertilizer",2,0.1);
    good def;
    gl farm_needs(fertilizer,def,def);
    good farm_productions;
    build farm(grains,farm_needs);
    for (int i = 1; i < 15; i++)
    {
    farm_needs*farm.size;
    farm_productions=farm.products(farm_needs);
    grains*farm.size;
    farm_needs= farm.request_needs(grains);
    textFile<<farm_productions<<endl;
    farm.decisionmake();
    }
    bool is =def.name!="none";
    cout<<is<<endl;
}