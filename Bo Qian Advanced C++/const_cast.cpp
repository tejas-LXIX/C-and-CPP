#include<iostream>
using namespace std;

//you should never edit const usually. issues honge.
class Tejas
{
    private:
        int x;
    public:
        void change_value (const int &i) const //to stop any unwanted changes to the variable i
        {const_cast<Tejas*>(this)->x=i;     //use const_cast to change non const variables in const functions.
        //i++;
        }
        //you can have const in the return type too
};
int main()
{
    volatile const int x=75; //volatile keyword is a must if you want to change a const variable using const_cast.
    //This is because you are not allowed to const_cast variables that are actually const. This results in undefined behavior. const_cast is used to remove the const-ness
    //from references and pointers that ultimately refer to something that is NOT CONST.
    //x=11; not allowed
    const_cast<int&>(x)=6; //type in const_cast must be a pointer or a reference
    cout<<x;
    int j;
    //static_cast<const int&>(j)=7; //to make a variable const. cast data into a const. this is why this statement gives error of modifiable l value because j has become const
    Tejas obj1;
    int i=9;
    obj1.change_value(i);
    cout<<endl<<i;
    const char* str="Hello World";
    //char *modifiedval=str;   a value of type "const char *" cannot be used to initialize an entity of type "char *"
    //char *modifiedval=const_cast<char>(str);   the type in a const_cast must be a pointer, reference, or pointer to member to an object type
    char *modifiedval=const_cast<char*>(str); //to cast away the constness of str and make it a simple char*
}