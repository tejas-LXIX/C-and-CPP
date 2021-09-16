#include<iostream>
using namespace std;

/* ":" must be used for     1.For initialization of non-static "const" data members. 2.For initialization of reference members (&x) type ke
3. For initialization of member objects which do not have default constructor(they have parameterized constructor).(See Composition.cpp). Use initializer
list always for default constructor types too to avoid confusion. Also,this is faster too than assigning values in the body.
4. When constructor’s parameter name is same as data member
5. For initialisation of base class members. The parameterized constructor of the base class can only be called using Initializer List.*/
class Yapral
{
    private:
        mutable int po; //now,const functions can change the value of po.
        int lt;
        int x,y;
        const int z=10,r;
        int list[3]={3,5,2};
        int *v2=list;
    public:
        void setv2Item(int index,int x) const //but usually to prevent confusion,dont use const in such places where youre gonna change the values.
        {
            v2[index]=x; //this works because even though it is a const function,this function has maintained bitwise constness of the class,
            //since it does not change any of the members inside it directly.
        }
        //Yapral(){} not allowed because it does not initialise the const variable
        int g;
        Yapral(int a,int b,int c,int d,int e=0):z(c),r(1)//this is called member initialiser list.
         //this can change the value of const even if it has already been initialised
        {
            //z=c; expression must be a modifiable l-value
            x=a;
            y=b;
            g=e;
        }
        void setValx(int f)
        {x=f;} 
        void printValue() const //can be called on non const objects too.
        {//const functions can only call other const functions
            //x=11;  not allowed. const functions can't edit any data members. to do this,you have to use const_cast
            po=35;//is allowed because po is mutable. or just let po be normal variable and edit its value using const_cast
            const_cast<Yapral*>(this)->lt=71; //used to cast away the constness of the pointer this which is of type Yapral* since it points to current object of Yapral class
            cout<<x<<" "<<y<<" "<<z<<" "<<r<<endl;
        } 
        void printShiz() const {cout<<"this is a const function\n";} //The idea of const functions is TO NOT ALLOW THEM to modify the object
        // on which they are called. A const function can be called on any object.
        void printShiz()
        {
            cout<<"Hello"; //const can be used to overload functions. which function will be invoked now depends on the type of object you have declared.
            //const object will invoke printShiz() const, non const will invoke printShiz()
        }
        void notConst() {cout<<"not a const function\n";} //Non Const functions can only be called on non const objects.
};

int main()
{
    /*const int x; const variables have to be initialised when declared.
    x=10;  gives error.*/
    const Yapral Greenpark(34,45,77,765,699); //Whenever an object is declared as const, it needs to be initialized at the time of declaration.
    //and this is possible only with the help of constructors.
    // However, the object initialization while declaring is possible only with the help of constructors.
    //Greenpark.setValx(54); doesn't work because initialisation sirf constructor se kar sakte ho. uske baad you cannot change the value.
    Yapral Greenpark12(1,2,3,4);
    Greenpark12.setValx(11);
    Greenpark12.g=71; //works because Greenpark12 is not const
    //Greenpark.g=87123; error because Greenpark is a const object
    Greenpark.printValue();
    Greenpark.printShiz();
    Greenpark12.printValue(); //const functions can be called upon any object
    //Greenpark.notConst(); since non const function cannot be called on const objects.
    Greenpark12.notConst();
}