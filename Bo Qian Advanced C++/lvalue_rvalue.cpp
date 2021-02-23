#include<iostream>
using namespace std;
//lvalue is an object that occupies some identifiable location in memory. Most variables in c++ are lvalues
//rvalue is any object that is not a lvalue
class dog{

};
int sum(int x,int y)
{return x+y;}
int square(const int &x)
{return x*x;}

int &foo()
    {
        int myglobal;
        return myglobal;
    }
int main()
{
    int i; //i is a lvalue. i+2 is rvalue(aage dekho)
    int *p=&i;//can get the address of a lvalue
    i=2;//can assign values to a lvalue               these two are the conditions for something to be lvalue
    dog d1; //d1 is also a lvalue



    int x=2; //2 is rvalue
    int x=i+2; //i+2 is an rvalue because address of i+2 does not exist. int *g=&(i+2); gives an error
    //i+2=4; cannot assign different value to r value
    int i=sum(3,4); //sum(3,4) is rvalue
    int i=sum(x,i); //sum(x,i) is also rvalue. because you cannot assign a value to sum(x,i),also its address does not exist
    int &r=i;// is an lvalue reference. known as a normal reference
    //int &e=5; error
    const int &r=5;//exception to the above error. constant lvalue reference can be assigned a rvalue. is actually broken up into two parts
    //first a temp lvalue variable is created with value 5, then the temp variable is assigned to the const reference
    int e=square(4); //this wont work if the parameter in square wasn't const reference
    
    //lvalue can be used to create an rvalue
    int x=i+2; //obviously wont work here because x is already defined above and blah blah error. but these are just examples
    int x=i; //i is an lvalue,but in this context it behaves like an rvalue

    //rvalue can be used to create an lvalue
    int v[3];
    *(v+2)=4; //v+2 is an rvalue,but dereference of v+2 is an lvalue which can be assigned a value.
    foo()=50; //this works too,although aise koi code nahi karta. it works because foo returns an int myglobal which then gets assigned the value 50.
}
