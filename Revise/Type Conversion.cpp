#include<iostream>
using namespace std;

int main()
{
    char c='a';
    int *p=(int*)&c; //gives random value during runtime. but not an error because normal C style casting does not check type during compilation
    cout<<*p<<endl;
    //int *q=static_cast<int*>(&c); //gives error during compilation because it checks if the casting is possible or not during compilation
    float a=65,b=71;
    int g=(int)a/b; //this clearly shows that casting doesn't actually change the value of a/b. it just displays it 
    //in an integer form by removing all the decimals and then assigning it to g.
    cout<<g<<endl;
    cout<<a/b; //value of a/b is still float type. the (int) did not change the value.
}