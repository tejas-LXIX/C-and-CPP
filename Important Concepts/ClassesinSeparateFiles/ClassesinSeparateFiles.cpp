#include<iostream>
#include "headerexample.cpp" //only including .cpp is enough. .h ki zarurat nahi hai because its already included in the .cpp file that we are using here
using namespace std;

int main()
{
    arithmetic tejas1;
    tejas1.getNumber();
    cout<<tejas1.addNumber();
    tejas1.func();
    cout<<endl<<tejas1.r;
}