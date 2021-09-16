#include<iostream>
#include<string>
using namespace std;

class Address
{
    public:
        string House,Colony,City;
    public:
        int x=73;
        Address(string a,string b,string c)
        {
            House=a; Colony=b; City=c;
        }
        void printData()
        {
            cout<<House<<" "<<Colony<<" "<<City<<endl;
        }
};
class Person
{
    private:
        string name;
        int age;
    public:
        Person(string a,int b)
        {
            name=a;
            age=b;
            cout<<"constructor called\n";
        }
        void printData()
        {
            cout<<name<<" "<<age;
        }
};
class BioData
{
    private:
        Address address1;
        Person person1;
    public:
        BioData(Person a,Address b):person1(a),address1(b) //has to be assigned like this. since,no default constuctor exists.
        //this is simple assignment,the constructor is not called here
        // Yes, you can assign one object to other,all the members of first object become equal to second object.
        {
        }
        void printInfo()
        {
            cout<<address1.x<<endl;
            address1.printData();
            person1.printData();
        }
};
int main()
{
    Person Tejas("Tejas",18);
    Address AddressofTejas("B-401","Green Park","Secunderabad"); //you have to create objects of the smaller classes,and then pass it to the bigger class
    BioData Person1(Tejas,AddressofTejas);
    Person1.printInfo();
    /*AddressofTejas.printData(); these work too
    Tejas.printData();*/
}