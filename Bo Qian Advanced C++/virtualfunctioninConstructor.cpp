#include<iostream>
using namespace std;

class Dog
{
    public:
        Dog()  //recommended to have constructor do as little as possible to make an object with basic requirements 
        {cout<<"dog born\n";
        bark();}
        virtual void bark()
        {cout<<"I am dog\n";}
        void seeCat()
        {bark();}
};
class YellowDog:public Dog
{
    public:
        YellowDog()
        {cout<<"yellow dog born\n";}
        void bark()
        {cout<<"I am yellow dog";}
};
int main()
{
    YellowDog d1; //bark is virtual. fir bhi Dog ka bark is called because while constructing d1,first its base class is constructed. therefore when bark() is called,
    //YellowDog object d1 has not yet been constructed. isliye YellowDog ka member function bark() is not called.
    d1.seeCat(); // output is I am dog. this is because Dog ka seeCat function was called,therefore uska hi bark bhi call hoga,because bark is not a virtual function.
}