#include <iostream> 
  
using namespace std; 
  
class Complex{ 
private: 
    double real; 
    double imag; 
    string tejas="nigga";  
public: 
    // Default constructor 
   Complex(double r = 0.0, double i = 0.0) : real(r), imag(i) {} //constructor that accepts a single parameter.
    //Converts other types of objects into your class. explicit keyword nahi hoga toh it becomes an implicit type converter and an explicit type converter.

    operator double() const{return real+imag;} //This is the syntax. operator destinationtype(){}. does not have a return type
    //Convert an object of your class into other types by defining a type conversion function.
    //it should always be avoided as it can lead to unwanted conversions. Don't do it.

    // A method to compare two Complex numbers 
    bool operator == (Complex rhs) { 
       return (real == rhs.real && imag == rhs.imag)? true : false; 
    }
    void printValue()
    {cout<<real<<" "<<imag;} 
}; 
class Rational{
    public:
        int num,den;
        Rational(int numerator=0,int denominator=1){
            num=numerator;den=denominator;
        }
};
const Rational operator*(const Rational &lhs,const Rational &rhs){ //so that it works both ways for r1*7 as well as 7*r1.
return Rational(lhs.num*rhs.num,lhs.den*rhs.den);
}
class Namoona
{
    string Tejas="aisudb";
};

//operator Namoona() {return Namoona();} //string to object does not work. this is done only by one parameter constructor
//ERROR MESSAGE:conversion function must be a nonstatic member function

int main() 
{ 
    // a Complex object 
    Complex com1(3.0, 0.0); 
    /*if (com1 == 3.0) In C++, if a class has a constructor which can be called with a single argument, then this constructor becomes conversion constructor because 
    such a constructor allows conversion of the single argument to the class being constructed. To prevent this,make the constructor explicit
       cout << "Same"; */
    if(com1==Complex(3.0)) //yahan pe Complex(3.0) is required instead of only 3.0 because == defined hai and uske liye fir bhi explicitly mention karna padega
        cout<<"Same";
    else
       cout << "Not Same";
     printf("\nsum of real and imag is %f ",com1); //instead of having to use com1.returnValue()
     Complex com2=7.3; ////if constructor was explicit,then yahan pe Complex(7.3) karne ki zarurat hoti.
     //can't put two values here. sirf ek daal sakte. therefore this will only initialise the value of 'real'.
     com2.printValue();
     Rational r1=23;
     Rational r2=r1*7;
     Rational r3=7*r1;
     return 0;
} 