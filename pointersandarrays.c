#include<stdio.h>
int main()
{
    int i,*x;
    float j,*y;
    char k,*z;
    x=&i;
    y=&j;
    z=&k;
    printf("%d",x);
    printf("\n%d",y);
    printf("\n%d",z);
    x++;
    y++;
    z++;
    printf("\n%d",x);
    printf("\n%d",y);
    printf("\n%d",z);
    return(0);
}
