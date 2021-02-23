#include<stdio.h>
#include<math.h>
void stats(int,int,int,int,int,float *,float *,float *);
void main()
{
    int a,b,c,d,e;
    printf("please enter the values of the 5 numbers: ");
    scanf("%d%d%d%d%d",&a,&b,&c,&d,&e);
    float sum,mean,dev;
    stats(a,b,c,d,e,&sum,&mean,&dev);
    printf("%0.2f   %0.2f   %0.2f",sum,mean,dev);
}
void stats(int a,int b,int c,int d,int e,float *sum,float *mean,float *dev)
{
    int a1,b1,c1,d1,e1;
    *sum=a+b+c+d+e;
    *mean=(*sum)/5;
    a1=pow(a-*mean,2);
    b1=pow(b-*mean,2);
    c1=pow(c-*mean,2);
    d1=pow(d-*mean,2);
    e1=pow(e-*mean,2);
    *dev=sqrt((a1+b1+c1+d1+e1)/5);
}
