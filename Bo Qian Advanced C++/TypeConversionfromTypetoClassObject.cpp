#include <iostream>
using namespace std;

class Namoona
{
    string Tejas="aisudb";
    public:
        Namoona(string s)
        {Tejas=s;}
        operator string() const{ //type conversion from Class object to string
            return Tejas;
        }
};

operator Namoona() {return Namoona();}
int main()
{

}