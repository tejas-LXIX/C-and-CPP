#include<iostream>
using namespace std;
/* A friend class can access private and protected members of other class in which it is declared as friend. It is sometimes useful to allow a particular class to access private members of other class.
Following are some important points about friend functions and classes: 
1) Friends should be used only for limited purpose. too many functions or external classes are declared as friends of a class with protected or private data, it lessens the value of encapsulation of separate classes in object-oriented programming.
2) Friendship is not mutual. If class A is a friend of B, then B doesn’t become a friend of A automatically.
3) Friendship is not inherited (See this for more details)
4) The concept of friends is not there in Java. */
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
