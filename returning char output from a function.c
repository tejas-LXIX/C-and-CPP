#include<stdio.h>
char prime(int);
main()
{
    int a;
    char g;
    scanf("%d",&a);
    g=prime(a);
    if(g=='Y')
    {
        printf("the number is prime");
    }
    else
    {
        printf("the number is not prime");
    }
}
char prime(int x)
{
    int i;
    char c;
    for(i=2;i<x;i++)
    {
        if(x%i==0)
        {
            c='N';
            break;
        }
    }
    if(i==x)
    {
        c='Y';
    }

    return(c);
}
