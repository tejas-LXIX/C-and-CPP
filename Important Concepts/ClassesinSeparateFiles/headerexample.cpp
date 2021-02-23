#include<iostream>
#include "headerexample.h"
using namespace std;  //the cpp file includes the .h file and defines the function bodies.

arithmetic::arithmetic()  // :: is the unary scope resolution operator. and this is how you define a function of a class outside the class
{
    cout<<"this is how it starts"<<endl;
}
int arithmetic::r=763;
int arithmetic::getNumber()
{
    cout<<x<<endl;
}
int arithmetic::addNumber(int y)
{
    int sum;
    sum=x+y;
    return sum;
}
void arithmetic::func()
{
    cout<<"\nthis is how it ends";
}
