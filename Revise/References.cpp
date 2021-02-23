#include<iostream>
using namespace std;

void swap(int &a,int &b)  //see structures.cpp to see example of passing structures to functions by reference
{
    int temp;
    temp=a;
    a=b;
    b=temp;
}
int main()
{   
    //double &dr=1; //gives an error as a reference must always be an alias for a variable.
    const double &cdr=1;    /*First, implicit type conversion to T is applied if necessary.
    Then, the resulting value is placed in a temporary variable of type T .
    Finally, this temporary variable is used as the value of the initializer.
    therefore this line is actually equal to
    double temp=1;
    const double &cdr=temp;     */
    int x=5;
    int y=31;
    int &p=x;
    /*p=7;
    p=y; this works,im not sure why because online its stated that references are fixed connections.*/
    cout<<p<<endl;
    swap(x,y); //call by reference because these parameters are accepted into the function by assigning them references
    cout<<x<<" "<<y;
}