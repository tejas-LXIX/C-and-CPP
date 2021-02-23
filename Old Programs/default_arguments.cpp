#include<iostream>
using namespace std;

int volume(int l=1,int w=2,int h=5);

int main()
{
    cout<<volume(5,4,1);
}

int volume(int l,int w,int h) /* you have to write datatype in function declaration always, even if datatype has already been declared in the function prototype.
Otherwise it gives you "l not declared in scope" error. */
{
    return l*w*h;
}
