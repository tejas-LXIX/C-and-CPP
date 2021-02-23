#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    char g='1';
    int y=g; //y becomes equal to the ascii value of '1' which is 49
    cout<<y<<endl;
    y=g-48; //subtracting the ascii value of '0' from g to get the int value of g and store it in y.
    cout<<y<<endl;

    int x=45;
    char c=x; //c becomes equal to the character whose ascii value is 45. that character is -
    cout<<c<<endl;
    c=x+45; //can't do this because 45 is not defined in ascii, only single digits are defined. if x was a single digit,then this would work.
    char f=char(x); //this is equal to char c=x;
    cout<<f<<endl;
    char t=int(x);
    cout<<t<<endl;
}