#include<iostream>
using namespace std;

class School
{
    public:
        int a;
        School()
        {cout<<"This is School class "<<endl; //this is called twice,once by each of its derived class(APS AND Aakash),which have been respectively called
        //by Tejas object of class Student
        }
};
class APS:public School{
    public:
        int b;
        APS()
        {cout<<"This is APS "<<endl;}
};
class Aakash:public School{
    public:
        int c;
        Aakash()
        {cout<<"This is Aakash "<<endl;}
};
class Student:public Aakash,public APS{ //first aakash will be constructed,then aps will be constructed. orderwise as written here
    public:
        int d;
        Student()
        {
            cout<<"this is Student "<<endl;
        }
};
int main()
{
    Student Tejas;
    //Tejas.a=12; ambiguous because class Student has two copies of class School,one from APS and one from Aakash. therefore has two copies of int a.
    Tejas.APS::a=10;//does not change the value of a for all objects. only changes value of a for the object Tejas of class Student.
    cout<<Tejas.APS::a<<endl;
    Tejas.Aakash::a=156; //use scope resolution operator to resolve the ambiguity. But it still has two copies of class School in class Student. which is a waste
    cout<<Tejas.Aakash::a;
    //TO RESOLVE THIS ISSUE WE USE VIRTUAL BASE CLASS. THIS RESULTS IN ONLY ONE COPY IN STUDENT.
    //see diamond_problem_virtual.cpp
}