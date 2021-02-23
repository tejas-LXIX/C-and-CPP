#include<stdio.h>

void swapr(int *,int **); 
int main()
{
    int a=10,b=20;
    int *c;
    c=&b;
    swapr(&a,&c); /*passing the addresses of a and b*/
    printf("%d %d ",a,b);
}
void swapr(int *x,int **y) /*pointer variables x and y store the addresses of a and b*/
{
    int t;
    t=*x;
    *x=**y;
    **y=t;
}