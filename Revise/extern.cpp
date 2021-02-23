#include <iostream>
using namespace std;

int main()
{
    int a; //definition and declaration takes place at the same time.
    /*Here, the information such as the variable name: a, and data type: int, which is sent to the compiler which will be stored in the data structure known as symbol table. 
    Along with this, a memory of size 2 bytes(depending upon the type of compiler) will be allocated.*/
    int*x=nullptr;
    cout<<x<<endl;
    int *y=&a;
    cout<<y<<endl;
    extern int b;
    int *z=&b; //undefined reference to b error aata hai. this is because only the information about the variable is sent and no memory allocation is done.
    //The above information tells the compiler that the variable a is declared now while memory for it will be defined later in the same file or in different file.
    cout<<z;
}