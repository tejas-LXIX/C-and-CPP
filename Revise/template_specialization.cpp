#include<iostream>
using namespace std;

template<class T>
class Spunky
{
    public:
        Spunky(T x)
        {
            cout<<x<<" is not a character ";
        }
};

template<> //If a specialized version is present, compiler first checks with the specialized version and then the main template.
//Compiler first checks with the most specialized version by matching the passed parameter with the data type(s) specified in a specialized version.
class Spunky<char> //performs same stuff for any data type,but for the special case of char it performs differently.
{
    public:
        Spunky(char x)
        {
            cout<<x<<" is a character ";
        }
};
int main()
{
    Spunky <int>obj(64.57);
    Spunky <char>obj1('X');
}