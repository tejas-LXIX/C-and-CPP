#include<iostream>
using namespace std;

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
