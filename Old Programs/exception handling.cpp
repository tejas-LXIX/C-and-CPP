#include<iostream>
#include<string>
using namespace std;

int main()
{
    try
    {
        int DadAge;
        cin>>DadAge;
        int DaughterAge;
        cin>>DaughterAge;
        if(DadAge<DaughterAge)
        {
            throw 99;
        }
    }
    catch(int x)
    {
        cout<<"dad isnt the real dad";
    }
}
