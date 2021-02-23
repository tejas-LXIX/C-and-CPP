#include<stdio.h>
int display(int,int[]);
int display1(int,int *);
int main()
{
    int num[6]={1,3,4,6,7,9};
    display(6,num);
    display1(6,num); /*writing the name of the array passes the address of zeroth element of the array. therefore,num passes address of num[0].*/
    for(int i=0;i<6;i++)
    {
        printf("%dth new element is %d ",i,num[i]);
    }
}
int display(int n,int w[])
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("%dth element of the list is %d ",i,w[i]);
    }
    /*but if you want changes to happen in num,you cant do that without pointers because returning a whole array isnt possible in C.
     Only elements can be returned.*/
}
int display1(int n, int *j)
{
    for(int i=0;i<n;i++)
    {
        *j=*j+5;  /*this is how you can change elements of entire array in main. pointers are v important.*/
        j++; /*this incrementation makes j point to the next address */
    }
}