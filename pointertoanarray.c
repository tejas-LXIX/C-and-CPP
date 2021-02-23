#include<stdio.h>

int main()
{

    int s[4][2]={
        {1234,56},
        {1235,12},
        {1236,71},
        {1237,93}
                };
    int (*p)[2]; /* p is a pointer to an array of two integers. agar () absent hote,then it wouldve made p an array of two integer pointers.*/
    for(int i=0;i<4;i++)
    {
        int *pint;
        p=&s[i]; /*passing the address of 1-d array(address of first element of the 1-d array) to the pointer. */
        pint=p;
        for(int j=0;j<2;j++)
        {
            printf("%d ",*pint); /* *p cant be used because it isnt a pointer to a single integer. its a pointer to an array of two ints */
            pint++;
        }
        printf("\n");
    }
}