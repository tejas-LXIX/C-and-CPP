#include<iostream>
using namespace std;
/*Like friend class, a friend function can be given a special grant to access private and protected members. A friend function can be: 
a) A member of another class 
b) A global function */
class sally
{
public:
    sally()
    {
        x=0;
    }
private:
    int x;

friend void changer(sally sallyobject);
};

void changer(sally sallyobject)
{
    sallyobject.x=123;
    cout<<sallyobject.x;
}

int main()
{
    sally hey;
    changer(hey);
}
