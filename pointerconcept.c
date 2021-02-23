#include<stdio.h>

void main()
{
int arr[]={10,20,36,72,45,36}; /*addresses are in bytes,not bits.*/
/* for one-d arrays, s[i] is actually converted to *(num+i) in the compiler.
int *j,*k,*l;
j=&arr[4];
k=(arr+4); /*when pointer is incremented by 4,it now points to an address 4(increment)*4(size of an int)=16 locations after the current location.
run the code to see.*/
l=arr; /*this pointer points to the start of the array i.e to the start of address arr[0]*/
printf("%lld ",j);
printf("%lld ",k);
printf("%lld",l); 
if(j==k)
printf("The two pointers point to the same location");
else
printf("The two pointers do not point to the same location");
}

// int j[]={1,2,3,4,5};
// int *p=j;
// p[1]=7; 
// this code works because p[1] is actually converted to *(p+1). therefore jaise normal array access karte hai waise hi pointers pe bhi kar sakte hai.
//VERY VERY IMPORTANT