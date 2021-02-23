#include <iostream>
#include <string>

using namespace std;

class Tejas
{
public:
    Tejas(string z)
    {
        setName(z);
    }
private:
    string x;
public:
    void setName(string name)
    {
        x=name;
    }
    string getName()
    {
        return x;
    }
};

int main()
{
    Tejas boing("HELLO");
    cout<<boing.getName();
    Tejas boing2("\nyayayaya");
    cout<<boing2.getName();
    return 0;
}
