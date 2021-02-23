#include<iostream>
using namespace std;

class Dog
{
    string name;
    public:
        Dog(string s)
        {name=s;
        cout<<name<<" is created\n";}
        ~Dog()
        {
        try{throw 20;}
        catch(int e)
        {cout<<e<<this->name<<" got destroyed\n";}
        }
        /*
        ~Dog()
        {cout<<name<<" is destroyed\n";
        throw 20;} 
        Program crashes. because when execution reaches end of try block,the stack unwinds and all the local variables need to be destroyed.
        Tejas is destroyed first,and it throws an exception 20. Now,before exception is caught by catch block,Henry needs to be destroyed too.so henry's destructor executes
        and throws an exception too. c++ can only handle one exception at a time,but we have given it two at the same time. so it crashes.
        To stop this, 1. the destructor should also CATCH all the exceptions it throws. This is easier and preferable
        2. Move the exception prone code to a separate function*/

        void toDestroy()
        {throw 20;}
};
int main()
{
    try{
    Dog d1("Henry");
    Dog d2("Tejas"); //destroyed before Henry because stack is LIFO(last in first out).
    //throw 20; //before this goes to the catch block,all the local objects/variables blah blah inside the try block are destroyed
    d1.toDestroy(); //this guy throws the exception to catch. but before exception is thrown,objects need to be destroyed. therefore,destructor is called.
    //and har object ka khud ka try catch fir execute hota.
    d2.toDestroy();
    }catch(int e)
    {
        cout<<e<<" is caught";
    }
}