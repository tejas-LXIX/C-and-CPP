#include<stdio.h>

int main()
{
    int n;
    scanf("%d",&n);
    int count=0;
    //for(int i=0;i<n;) //the value of n in the test condition keeps changing because of n/2 in the loop. thats why even without i++, the loop comes to an end
    //better to use a while loop here. while(n>0) is same as for(int i=0;i<n;) but faster
    while(n>0)
    {
    if(n%2!=0)
    {
        count++;
    }
    n=n/2;
    }
    printf("%d",count);
}