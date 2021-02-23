#include<iostream>
using namespace std;
//Virtual base classes are used in virtual inheritance in a way of preventing multiple “instances” of a given class appearing in an inheritance hierarchy when using multiple inheritances.
//here d inherits from both b and c.so,when data/function member of A is called through D,ambiguity arises as to which data/function should be called. the one inherited through B or the other inherited trhrough C.

class ClassA 
     { 
            public: 
            int a; 
     }; 
 
class ClassB : virtual public ClassA //Now only one copy of data/function member will be copied to class B and class C and class A becomes the virtual base class
     { 
            public: 
            int b; 
     }; 
class ClassC : virtual public ClassA //When a base class is specified as a virtual base, it can act as an indirect base more than once without duplication of its data members. 
//A single copy of its data members is shared by all the base classes that use virtual base.
     { 
            public: 
            int c; 
     }; 
 
class ClassD : public ClassB, public ClassC 
     { 
            public: 
            int d; 
     }; 
 
int main() 
{  
    ClassD obj; 
    obj.a = 10;        //Statement 3 
    obj.a = 100;      //Statement 4 
    obj.b = 20; 
    obj.c = 30; 
    obj.d = 40;
    cout<< "A : "<< obj.a; 
    cout<< "\nB : "<< obj.b; 
    cout<< "\nC : "<< obj.c; 
    cout<< "\nD : "<< obj.d; 
}
// ClassD has only one copy of ClassA, therefore, statement 4 will overwrite the value of a, given at statement 3.