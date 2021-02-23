#include<iostream>
using namespace std;

class Tejas
{
    public:
        Tejas()
        {
            cout<<"hello ";
        }
        ~Tejas()
        {
            cout<<"BYE"<<endl;
        }

};

int main()
{
    for(int i=0;i<3;i++)
    {
        Tejas tejas1; //the object tejas 1 is destroyed in each iteration. and a new object is created for the next iteration.
    }
}