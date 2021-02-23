#include<iostream>
using namespace std;
class Sally
{
    private:
        int x,y;
    public:
        Sally(int x=0,int y=0):x(x),y(y)
        {}
        void print()
        {
            cout<<x<<" "<<y<<endl;
        }
};

class Complex
{
    private:
        float real,imag;
    public:
        Complex()
        {}
        Complex(float x,float y)
        {
            real=x;
            imag=y;
        }
        void printValue()
        {
            cout<<real<<"+j"<<imag<<endl;
        }
        Complex operator+(Complex); //operator+ is the name of the function. you have to follow this syntax to overload any operator,
        //keyword "operator" followed by the operator you want to overload. Name of an operator function is always operator keyword followed by symbol
        // of operator and operator functions are called when the corresponding operator is used.
        //Complex is the return type of the function as it will return an object of Complex class.
};
Complex Complex::operator+(Complex cp)
{
    //Complex BrandNew;     you dont need to do this. just make the changes in the current object itself and then return. but iska problem ye hai ki c1 will get changed permanently
    //so its preferable to create a new object.
    real=real+cp.real;  //real is the value of variable real of the current object(the object on the left side of +).
    //cp.real is the real value of the other object(on the right side of +).
    imag=imag+cp.imag;
    return *this; //returns a complex object
}
int main()
{
    Complex c1(3.2,4.9);
    Complex c2(7.6,16.69);
    Complex c3;
    c3=c1+c2; //c1 is the current object. c2 is the other object.
    c3.printValue();
    Sally t(35,47);
    t.print();
    t=607; /*Any constructor that can be called with a single argument works as a conversion constructor, means it can also be used for implicit conversion to
    the class being constructed. Basically you can change the object's values without having to make another object and then assign that object to this one.*/
    t.print();
}