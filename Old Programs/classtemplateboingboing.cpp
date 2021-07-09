#include<iostream>
using namespace std;

template <class T>
class Teju
{
private:
    T age1,age2;
public:
    Teju(T x,T y)
    {
        age1=x;
        age2=y;
    }
    T compareAge()
    {
        return(age1>age2?age1:age2);
    }
};

template<>
class Teju<char>
{

public:
    Teju(char x)
    {
        cout<<x<<" is a character";
    }
};

int main()
{
    Teju <int> tej(71,35);
    cout<<"The Bigger Age is : "<<tej.compareAge()<<"\n";
    Teju <float> tejas(71.1232321,35.9726392);
    cout<<"The Bigger Age is : "<<tejas.compareAge()<<"\n";
    Teju <char> tejaschar('a');
}
