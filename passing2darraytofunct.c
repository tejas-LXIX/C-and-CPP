#include<stdio.h>

int main()
{
    int a[3][4]={
1, 2, 3, 4,
5, 6, 7, 8,
9, 0, 1, 6
};
show(a,3,4);
}
show(int (*q)[4],int row,int col) /* (*q)[4] makes q a pointer to an array of 4 integers.
() nahi hota toh q wouldve become an array of 4 integer pointers. q holds the base address of the zeroth 1-d array.*/
{
    int *p;
    for(int i=0;i<row;i++)
    {
        p=q+i; /*for each value of i,p will point to the base address of a 1-d array. Eg: for i=2, p will point to the 2nd 1-d array(9,0,1,6)*/
        /*it doesnt point to second element of zeroth array because pointers ka scene hi ye hai that when they are incremented,they point to 
        the next instance of the quantity that they are pointing to.Therefore,here q+2 makes it point to second 1-d array.*/
        for(int j=0;j<col;j++)
        {
            printf("%d",*(p+j));
            printf("\n");
        }    
    }
}
