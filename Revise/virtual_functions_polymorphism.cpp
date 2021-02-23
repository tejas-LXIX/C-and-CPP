#include<iostream>
using namespace std;
//USE OF VIRTUAL FUNCTIONS
/*Virtual functions ensure that the correct function is called for an object, regardless of the type of reference (or pointer) used for function call.
Functions are declared with a virtual keyword in base class. The resolving of function call is done at Run-time.*/
//Virtual functions are called according to the type of the object instance pointed to or referenced, not according to the type of the pointer or reference.
/*Virtual functions allow us to create a list of base class pointers and call methods of any of the derived classes without
even knowing kind of derived class object.*/

class Enemy //is an abstract class because it has a pure virtual function.
{//an abstract class is a class that has a pure virtual function.
    private:
        int AttackPower;
    protected:
        int setAttackPower(int a)
        {
            AttackPower=a;
            return AttackPower;
        }
    public:
        virtual void attack(){
            cout<<"you are in enemy class"<<endl;
        } //this is like a template. Whenever an enemy object/pointer calls this function,it checks the object that it points to/refers to and executes the required function
        virtual void Defeated(){
            cout<<"you have been defeated by enemy"<<endl;
        }
        virtual void Shithead()=0; //pure virtual function. No body at all.
//ANY CLASS THAT INHERITS FROM A CLASS THAT HAS A PURE VIRTUAL FUNCTION HAS TO OVERRIDE THAT FUNCTION,i.e IT HAS TO HAVE A DEFINITION FOR THAT FUNCTION.
//normal virtual functions ka agar derived class mein definition nahi hota,toh default function of the base class is called.
//BUT Pure Virtual functions need to compulsorily have a definition in the derived classes,nahi toh compiler error dega.
};

class Ninja:public Enemy
{
    public:
        void attack()
        {
            cout<<"Ninja attack"<<setAttackPower(31);
        }
        void Defeated()
        {
            cout<<"Defeated ninja"; //if you dont define Defeated here, then Enemy1 will execute the default virtual function which has been defined in the Enemy class
        }//comment this function out to see the change
        void Shithead()
        {
            cout<<"you are a shithead from Ninja\n";
        }//comment this function out to see the error that the compiler gives
};
class Monster:public Enemy
{
    public:
        void attack()
        {
            cout<<" Monster attack"<<setAttackPower(87);
        }
        void Defeated()
        {
            cout<<"Defeated monster";
        }
        void Shithead()
        {
            cout<<"you are a shithead from Monster\n";
        }
};
int main()
{
    Ninja n;
    Monster m;
    cout<<endl;
    Enemy *Enemy1=&n; //this is valid because type of n is Enemy also,because Ninja is derived from Enemy.
    Enemy &Enemy2=m; //this lets you use the base class objects/pointers/references to call the function. It checks the object it points to and executes the required function from the required class.
    Enemy1->attack();
    Enemy2.attack();
    n.attack();
    m.attack();
    n.Defeated();
    n.Enemy::Defeated(); //to access the enemy Defeated function rather than the Ninja Defeated function.
    Enemy1->Defeated(); //cant be called because Defeated function is a member of Ninja only, not of Enemy. But this can be solved by making Defeated virtual
}
//Enemy1 is a pointer whereas Enemy2 is a reference.