#include<stdio.h>
#include<math.h>
main()
{
    int a,b,c,d,e;
    scanf("%d%d%d%d%d",&a,&b,&c,&d,&e);
    float sum,mean,dev;
    stats(a,b,c,d,e,&sum,&mean,&dev);
    printf("%0.2f   %0.2f   %0.2f",sum,mean,dev);
}
stats(int a,int b,int c,int d,int e,float *sum,float *mean,float *dev)
{
    int a1,b1,c1,d1,e1,q,w,r;
    q=a+b+c+d+e;
    w=q/5;
    a1=pow(a-w,2);
    b1=pow(b-w,2);
    c1=pow(c-w,2);
    d1=pow(d-w,2);
    e1=pow(e-w,2);
    *dev=sqrt((a1+b1+c1+d1+e1)/5);
    *sum=q;
    *mean=w;

}
