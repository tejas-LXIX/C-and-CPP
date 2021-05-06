#include<iostream>
using namespace std;
class Test2
{
    int y;
    public:
        Test2()
        {cout<<"Test2 constructor ";}
};
class Test
{
    Test2 t2;
    int x;
    public:
        Test()
        {cout<<"Test constructor\n";}
        operator Test2() {return t2;} //agar ye dono comment kardiye aur run kara. toh invalid type cast error aata hai. (could not convert t from 'Test' to 'Test2')
        operator int() {return x;}
};
void fun(int x) 
{cout<<"fun(int) called";}
void fun(Test2 t)
 {cout<<" funTest2 called";}
int main()
{
    Test t;
    //DONT THINK t IS OF TYPE t2 or vice versa. THIS IS NOT INHERITANCE
   //fun(t);//gets converted to either fun(int(t)) or fun(Test2(t)) because Upar we have done operator overloading so that for int(), 'x' of object 't' is returned to fun(),so it becomes fun(x) which therefore calls fun(int x). 
    //For Test2(), 't2' of object 't' is returned to fun(),so it becomes fun(t2) which therefore calls fun(Test2 t).
    //but yahan pe obviously ambiguous hai so error aata hai.
    fun(int(t)); //works. because we have overloaded the operator int() upar. nahi karte toh invalid type cast error aata hai.
    fun(Test2(t));
    return 0;
}