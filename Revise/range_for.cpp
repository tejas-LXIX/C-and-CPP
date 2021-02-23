#include<iostream>
using namespace std;
/*
It executes a for loop over a range. 


for ( range_declaration : range_expression ) 
    loop_statement

Parameters :
range_declaration : 
a declaration of a named variable, whose type is the 
type of the element of the sequence represented by 
range_expression, or a reference to that type.
Often uses the auto specifier for automatic type 
deduction.

range_expression : 
any expression that represents a suitable sequence 
or a braced-init-list.

loop_statement : 
any statement, typically a compound statement, which
is the body of the loop.

*/
int main()
{
    int v[]={1,2,3,4,5,6,7,8,9,0};
    for(int x:v)
    {
        x++;
        cout<<x<<" ";
    }

    string str="Niigaah";
    for(auto x:str)         //auto results in automatic type deduction,obtained from the data type of the second value(after the colon).
        cout<<x<<" ";
}