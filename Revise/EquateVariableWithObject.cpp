#include <iostream>
using namespace std;

class Dog
{
    string name="shit";
    int x;
    public:
        Dog(){}
        //Dog(string name):name(name){}
        string getName()
        {cout<<name;}
};

int main()
{
    string dogname="Tejas kutta hai";
    Dog d1=dogname; //equating object with string. Doesn't work if suitable constructor does not exist.
    d1.getName();
}