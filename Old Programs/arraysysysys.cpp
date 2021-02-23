#include<iostream>
using namespace std;
int main()
{
    int teju[2][4]={ {1,2,3,4},{6,7,66,56} };
    for(int row=0;row<2;row++)
    {
        for(int column=0;column<4;column++)
        {
            cout<<teju[row][column]<<"\t";
        }
    cout<<"\n";
    }
}
