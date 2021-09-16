/*
The capability of a class to derive properties and characteristics from another class is called Inheritance. Inheritance is one of the most important feature of Object Oriented Programming. 
Sub Class: The class that inherits properties from another class is called Sub class or Derived Class. 
Super Class:The class whose properties are inherited by sub class is called Base Class or Super class.
class subclass_name : access_mode base_class_name
{
  //body of subclass
};
Here, subclass_name is the name of the sub class, access_mode is the mode in which you want to inherit this sub class for example: public, private etc. and base_class_name is the name of the base class from which you want to inherit the sub class. 
Note: A derived class doesn’t inherit access to private data members. However, it does inherit a full parent object, which contains any private members which that class declares.

Modes of Inheritance

Public mode: If we derive a sub class from a public base class. Then the public member of the base class will become public in the derived class and protected members of the base class will become protected in derived class.
Protected mode: If we derive a sub class from a Protected base class. Then both public member and protected members of the base class will become protected in derived class.
Private mode: If we derive a sub class from a Private base class. Then both public member and protected members of the base class will become Private in derived class. 
*/

// C++ program to explain multiple inheritance
#include <iostream>
using namespace std;
 
// first base class
class Vehicle {
  public:
    Vehicle()
    {
      cout << "This is a Vehicle" << endl;
    }
};
 
// second base class
class FourWheeler {
  public:
    FourWheeler()
    {
      cout << "This is a 4 wheeler Vehicle" << endl;
    }
};
 
// sub class derived from two base classes
class Car: public Vehicle, public FourWheeler {
  private:
    string name;
    int cost;
  public:
    Car(string name1,int cost1)
    {
      name=name1;
      cost=cost1;
    }
    void details()
    {
      cout<<name<<" "<<cost<<endl;
    }
};
 
// main function
int main()
{  
    // creating object of sub class will
    // invoke the constructor of base classes
    Car obj("S class",9500000);
    obj.details();
    return 0;
}