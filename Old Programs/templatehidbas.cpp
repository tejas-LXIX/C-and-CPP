#include<iostream>
using namespace std;

template<class bucky,class teju>
teju addBoth(bucky x, teju y)
{
    return x+y;
}

int main()
{
    double x=73.4;
    int y=7;
    cout<<addBoth(x,y);
}
