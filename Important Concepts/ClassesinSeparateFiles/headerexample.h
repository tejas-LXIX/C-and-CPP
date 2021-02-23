#include<iostream>
using namespace std;   //we always define the class in the header files along with the function prototypes.
#ifndef HEADEREXAMPLE_H
#define HEADEREXAMPLE_H

class arithmetic
{
    public:
        arithmetic();
        static int r;
        void func();
        int getNumber();
        int addNumber(int y=0); //default argument
    private:
        const int x=71;
        int y;
};
#endif