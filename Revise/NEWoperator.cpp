#include<iostream>
using namespace std;
/*The new operator denotes a request for memory allocation on the Free Store. If sufficient memory is available,
new operator initializes the memory and returns the address of the newly allocated and initialized memory to the pointer variable.
pointer_variable=new data-type(value);  new data-type[size]*/

class Collar{};
class Dog
{
    Collar *pCollar;
    Dog &operator=(Dog d1)
    {
        delete pCollar;
        pCollar=new Collar(*d1.pCollar); //pCollar is a pointer to a Collar object. "new" creates an object of Collar class whose value is
        //the value of THE POINTER "d1.pCollar" (which we got using * ) and returns its address to pCollar
    }
};
class NotNormal{};
class Normal
{
    public:
        NotNormal nb1;
        int x=71;
        int setValue(int e)
        {x=e;}
};
int main()
{
    Normal b1;
    b1.setValue(6);
    NotNormal *nb1ptr=new NotNormal(b1.nb1); //nb1ptr is a pointer to a NotNormal object. "new" creates an object of NotNormal class whose value is b1.nb1 and returns its address to nb1ptr
    /*Normal *b2ptr=new Normal;
    b2ptr=&b1;
    cout<<b2ptr->x;*/
    int a=75;
    int *x=new int(a); //x doesn't point to a. it points to another integer which has the value of a,basically points to a copy of a.
    delete x; //only x is deleted. a is not deleted.
    cout<<a;
    int *y=&a;
    delete y; //now even a is deleted.
}