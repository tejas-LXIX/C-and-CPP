#include<iostream>
using namespace std;

template <class T> /*declared a generic data type T. */
class Tejas
{
public:
    Tejas(T x,T  y)
    {
        cout<<x+y<<"\n";
    }
};

template <>
class Tejas<char>
{
public:
    Tejas(char x)
    {
        cout<<x<<" WOOHOOO template specialisation works";
    }
};

int main()
{
    Tejas<int> BOI(4,71);
    Tejas <char>BOI1('w');
}
