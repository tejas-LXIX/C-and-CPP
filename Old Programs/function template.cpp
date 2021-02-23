#include<iostream>
using namespace std;

template <class Hey,class Bye>
Hey Larger(Hey x,Bye y)
{
    return(x>y?x:y);
}

int main()
{
    int x=10;
    double y=15.67;
    cout<<Larger(x,y);
}
