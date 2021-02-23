#include<stdio.h>
void print_array_pointer(int *,int,int);

int main()
{
    int s[4][2]={
        {1234,56},        /*num[i] is actually converted to *(num+i) by the C compiler internally.*/
        {1235,12},
        {1236,71},
        {1237,93}
                   };
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<2;j++)
        {
            printf(" %d ",s[i][j]); /*gives the value of the array elements. it is the normal way of accessing the elements*/
            printf(" Address is: %lld",&s[i][j]);
        }printf(" Base Address is : %lld",s[i]); /*gives the address of individual one-d arrays(which is the address of the first elements of the 1-d arrays)*/
/* therefore, *s[i] gives the value of the first elements of each 1-d array. it gives addresses wtih difference of 8 bytes between them. 
This is because one element exists between s[0] and s[1]. therefore s[1] is 2(s[0][0] and s[0][1])*4(size of an int)=8 bytes after s[0]*/
        printf("\n");
    }
    printf("%d\n",*(s[2]+1));
    printf("%d\n",*(*(s+2)+1));  /*to access an individual element using addresses.*/
    /*  s[2][1] is converted to *(s[2]+1). s[2] is converted to *(s+2). therefore,we get *(*(s+2)+1)  */
    
    print_array_pointer(s,4,2); //s passes the base address of the array s
}
void print_array_pointer(int *m,int dim1,int dim2) //TO PASS A POINTER TO A 2-D ARRAY TO A FUNCTION
{
    for(int i=0;i<dim1;i++)
    {
        for(int j=0;j<dim2;j++)
        {
            printf("%d ",m[i*dim2+j]); //JUST REMEMBER THIS.
        }
        printf("\n");
    }
}