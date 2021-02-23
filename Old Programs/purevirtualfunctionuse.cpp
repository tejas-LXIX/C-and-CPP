#include<iostream>
using namespace std;

class Shape
{
public:
    int l1;
    int l2;
    virtual int area(int x,int y)
    {

    }
};

class Rectangle:public Shape
{
public:
    int area(int x, int y)
    {
        l1=x;
        l2=y;
        cout<<l1*l2<<"\n";
    }
};

class Triangle:public Shape
{
public:
    int area(int x,int y)
    {
        l1=x;
        l2=y;
        cout<<(l1*l2)/2;
    }
};

int main()
{
    Shape boi;
    Rectangle rectangle;
    Triangle triangle;
    Shape *rectangle1=&rectangle;
    Shape *triangle1=&triangle;
    rectangle1->area(7,10);
    triangle1->area(7,10);
}

