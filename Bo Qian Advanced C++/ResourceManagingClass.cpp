#include <iostream>
#include<vector>
using namespace std;
//When a class contains a pointer to memory allocated in class, we should write a user defined destructor to release memory before the class instance is destroyed. This must be done to avoid memory leak.

class Person
{
    string *pName_;
    public:
        Person (string name)
        {
            pName_=new string(name);
        }
        ~Person()
        {delete pName_;}
        Person(const Person &rhs)
        {
            pName_=new string(*(rhs.pName_)); //copy constructor for deep copying. now the code will not crash
        }
        /*Person &operator=(const Person &rhs)
        {
            pName_=new string(*(rhs.pName_));
        }    assignment operator for deep copying*/
        void printName()
        {cout<<*pName_<<endl;}
};

int main()
{
    vector<Person> persons;
    persons.push_back(Person("George")); //this is a "shallow copy" done by the copy constructor by default, i.e the pointers of both,the Person George and its copy in the 
    //vector point to the same string object. Also Person("George") is a r-value. therefore it's destroyed at the end of this statement.
    // So,pName_ is deleted(string name is not deleted,since pName_ points to a string whose value is equal to name,it does not point to name itself.).
    //now,pName_ is deleted(basically the object it points to is deleted). so now,pName_ of the person in the vector points to a deleted object. so when we
    //try to access it,crash hojaata hai because we're trying to access a deleted object.
    //to stop this,we need to define our own copy constructor which does deep copying.
    persons.back().printName();
    cout<<"Goodbye";
}