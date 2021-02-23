//When an exception is thrown, all objects created inside the enclosing try block are destructed before the control is transferred to catch block.

/*If both base and derived classes are caught as exceptions then catch block of derived class must appear before the base class.
If we put base class first then the derived class catch block will never be reached.*/
#include<iostream> 
using namespace std; 
  
class Base {}; 
class Derived: public Base {}; 
int main() 
{ 
   Derived d; 
   // some other stuff 
   try { 
       // Some monitored code 
       throw d; 
   } 
   catch(Base b) {  
        cout<<"Caught Base Exception"; 
   } 
   catch(Derived d) {  //This catch block is NEVER executed 
        cout<<"Caught Derived Exception"; //therefore,always the derived class catch block MUST BE WRITTEN BEFORE the base class catch block.
   } 
   return 0; 
} 