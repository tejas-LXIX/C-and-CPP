#include<iostream>
using namespace std;

class Point
{
    private:
        int x,y;
    public:
        Point()
        {

        }
        Point(int x1,int y1){x=x1;y=y1;}
        Point(const Point &p2) //the parameter passed to this in main is accepted as a reference here. const so that we dont mistakenly change the value of p2
        {
            x=p2.x;
            y=p2.y;
        }
        int getx(){return x;}
        int gety(){return y;};
};

int main()
{
    Point p1(10,15); //Normal Constructor is called here
    Point p2(p1); //Copy Constructor is called here. Point p2=p1 is also valid.
    cout<<p1.getx()<<" "<<p1.gety()<<endl;
    cout<<p2.getx()<<" "<<p2.gety()<<endl;
    Point p3;
    p3=p1; //assignment operator.
    //both the copy constructor and the assignment operator are used for the same purpose i.e to initialise one object to another object.
    cout<<p3.getx()<<" "<<p3.gety();
}