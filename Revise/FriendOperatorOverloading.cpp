#include <iostream>
using namespace std;

/*Operator function must be either non-static (member function) or friend function.

Operator Overloading can be done by using three approaches, they are

Overloading unary operator.
Overloading binary operator.
Overloading binary operator using a friend function.
Below are some criteria/rules to define the operator function:

In case of a non-static member function, the binary operator should have only one argument and unary should not have an argument.
In the case of a friend function, the binary operator should have only two argument and unary should have only one argument.
Operators that cannot be overloaded are . .* :: ?:
*/
//Friend function implementation of operator overloading. Needs two parameters
class Complex
{
    float real,imag;
    public:
        Complex()
        {}
        Complex(float x,float y)
        {
            real=x;
            imag=y;
        }
        void printValue() const
        {
            cout<<real<<"+j"<<imag<<endl;
        }
        friend Complex operator+(Complex&,Complex&); // The global operator function is made friend of this class so that it can access private members 

        void operator-()    //non-static member function. Unary operator. therefore,no arguments needed.
        {
            real=-real;
            imag=-imag;
            cout<<"Additive inverse of the Complex number is "<<real<<"+j"<<imag;
        }
};

Complex operator+(Complex &c1,Complex &c2)
{
    return Complex(c1.real+c2.real,c1.imag+c2.imag);
}
int main()
{
    Complex c1(7,3.69);
    Complex c2(3.14675,-6.73);
    Complex c3=c1+c2;
    c3.printValue();
    -c3;
}