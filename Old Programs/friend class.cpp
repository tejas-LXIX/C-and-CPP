#include<iostream>
using namespace std;

class sally
{
private:
    int x;
friend class teju;
};

class teju
{
public:
    void good(sally mc)
    {
        mc.x=1234;
        cout<<mc.x;
    }
};

int main()
{
    sally mc;
    teju tatti;
    tatti.good(mc);
}
