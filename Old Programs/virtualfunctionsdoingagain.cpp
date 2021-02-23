#include<iostream>
#include<string>
using namespace std;

class Military
{
private:
    string x;
public:
    virtual int attackPower(int x) /*just a virtual function which gets overridden by the same function defined in the derived classes.*/
    {
        /* ye braces likhna zaruri hai even if they are blank. you cannot write int attackPower(int x); function prototyping nahi kar rahe hum. hum yahan pe bhi function ko define hi kar rahe hain.
        therefore braces are compulsory.*/
    }
    virtual int attackResult()
    {

    }
    string Vehicle(string p)
    {
        x=p;
        return x;
    }
};

class Army:public Military
{
public:
    Military army;  /*declared only to be able to use the "Vehicle" function.*/
    int a1;
    int attackPower(int a2) /* this is the actual function definition. This function overrides the virtual function defined in Military.
     We don't pass any values here. we only pass values in the main() function */
    {
        a1=a2;
    }
    int attackResult()
    {
        cout<<"the attack was moderate."<<a1<<" Vehicle used was"<<army.Vehicle("Tank");
    }
};

class Airforce:public Military
{
public:
    Military airforceone; /*declared only to be able to use the "Vehicle" function.*/
    int a1;
    int attackPower(int a2) /* this is the actual function definition. This function overrides the virtual function defined in Military.
     We don't pass any values here. we only pass values in the main() function */
    {
        a1=a2;
        return a1;
    }
    int attackResult()
    {
        cout<<"Airforce hai beta. Enemies dont stand a chance.: "<<a1<<"Plane used was"<<airforceone.Vehicle("Mig-29");
    }
};

int main()
{
    Army army;
    Military *military1=&army;
    military1->attackPower(31);
    military1->attackResult();
    Airforce airforceone;
    Military *military2=&airforceone;
    military2->attackPower(99);
    military2->attackResult();
}
