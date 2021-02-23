#include<stdio.h>

short digsum(short);
void main()
{
    short a;
    printf("enter a number: "); /* doesnt work if you put number more than 2147483647. this is because it is a 32 bit compiler and int can only handle 32 bits.*/
    /*here we have used short and therefore range is only -32768 to 32767*/
    scanf("%hd",&a);            /*to scanf a short integer*/
    printf("%hd",digsum(a));
}
short digsum(short x)
{      
    short sum=0;
    if(x==0)
    {
        return 0;
    }
    else
    {
        sum=sum+(x%10)+digsum(x/10); /*integer division hota hai. so we dont get decimal. we get the truncated value. this is because x is an int*/
    }
    return sum;
}