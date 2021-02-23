#include<iostream>
using namespace std;

int main()
{
    int bricks,steps;
    cin>>bricks>>steps;
    for(int i=1;i<bricks;i++)
    {
        int b=steps+2;
        steps=steps+b;
        if(steps==bricks)
        {
            cout<<"can be built";
            break;
        }
    }
}
