#include<iostream>
using namespace std;

void printNumber(int x)
{
    cout<<"The int is "<<x;
}
void printNumber(float x)
{
    cout<<"The float is "<<x;
}
int main()
{
    printNumber((int)64.567);
    printNumber((float)71.564); //(float) use nahi karoge toh it will match both the function prototypes.
}