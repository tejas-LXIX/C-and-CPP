#include<iostream>
using namespace std;

int main()  //for no confusion, always read RIGHT TO LEFT TO UNDERSTAND THE DECLARATION AS WELL AS MAKE YOUR OWN
{
    int j[]={1,2,3,4,5};
    const int *pc1=j; //pointer to an integer constant
    int *p1=&j[1];
    pc1=p1; //no error because pointer is not constant. it only points to integer constant. therefore the pointer can be modified
    
    int *const y=j; //constant pointer to a normal integer
    y[3]=91; //valid
    //y=p1; //invalid because p1 is a const pointer
    
    const int *const pc=j; //read right to left. pc is a const pointer to an integer const
    j[2]=7; //no error because j hasnt been declared a constant
    // pc[1]=7;  gives an error because pc points to constant. POINTER SE BHI AISE ACCESS KAR SAKTE HAI JAISE NORMAL ARRAY SE KARTE HAI. BECAUSE pc[1] is
    //actually converted to *(pc+1) just like j[1] becomes *(j+1).
    int *p=&j[1];
    // pc=p;  gives an error because pc is a constant pointer.

}