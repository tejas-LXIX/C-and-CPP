#include<stdio.h>

int main()
{
    int x;
    x=3;
    for(int i=0;i<x;i++)
    {
        printf("only once %d",i);
        goto sos;
    }
    sos:
        printf(" exit hogaya");
}
