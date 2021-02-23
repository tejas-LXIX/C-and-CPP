#include<iostream>
using namespace std;

class Shithead
{
    public:
        Shithead()
        {
            cout<<"no parameters provided\n";
        }
        Shithead(string x,int y)
        {
            cout<<x<<"\n"<<y<<endl;
        }
        int i=35;
        int sump(int x)
        {
            x=x+i;
            return x;
        }
};
int main()
{   
    Shithead bro;
    Shithead tejas("hello",3);
    cout<<tejas.i;
    cout<<"\nand the sum is\n";
    cout<<tejas.sump(65);
}