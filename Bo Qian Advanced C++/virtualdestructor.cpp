#include<iostream>
using namespace std;
/*Virtual destructors are useful when you might potentially delete an instance of a derived class through a pointer to base class
In most implementations, the call to the destructor will be resolved like any non-virtual code, meaning that 
the destructor of the base class will be called but not the one of the derived class, resulting in a resources leak.*/

class Dog
{
    public:
        virtual ~Dog() //virtual nahi karoge toh when yd is deleted,only Dog destructor will be called,yellow dog destructor wont be called. this can give memory issue.
        {cout<<"Dog destroyed\n";}
};
class YellowDog:public Dog
{
    public:
        ~YellowDog()
        {cout<<"YellowDof destroyed\n";}
};
class DogFactory
{
    public:
    static Dog* createYellowDog()
    {
        return (new YellowDog);
    }
};

int main()
{
    Dog *yd=DogFactory::createYellowDog();
    delete yd;
}