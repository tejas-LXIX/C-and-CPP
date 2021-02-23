#include<iostream>
#include<string>
using namespace std;

int main()
{
    string bhel[3];
    for(int i=0;i<3;i++)
    {
        getline(cin,bhel[i]);
    }
    for(int i=0;i<3;i++)
    {
        cout<<bhel[i];
    }
}
