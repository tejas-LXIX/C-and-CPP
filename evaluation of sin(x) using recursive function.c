#include<stdio.h>
#include<math.h>
float sinx(float,int);
main()
{
    float x;
    float g;
    scanf("%f",&x);
    g=sinx(x,1);
    printf("%f",g);
    for(int i=0;i<3;++i) /*in the for loop(not the for loop body),i++ is same as ++i because the incrementation statement is always executed
     after the end of the loop. but in the for loop body, i++ is different from ++i */
    {
        int j=i+1; /*j=i++ mein j is assigned the value of i first. just after that i is incremented,not after the loop ends
        j=++i mein i is incremented first and then assigned to j*/
        /*therefore agar sirf j=i+1 karna hai without incrementing i, then write j=i+1 only*/
        printf("\n%d %d",j,i); 
    }
}
float sinx(float x,int b)
{
        int c=b;
        float sum=0;
        float a;
        if(c==11)
        {
            return(0);
        }
        else
        {
            a=(pow(x,c))/factorial(c);
            c+=2;
            sum=sum+a;
            sum=sum+sinx(x,c);
        }
        return(sum);
}
factorial(int y)
{
    int f=0;
    if(y==1)
    {
        return(1);   /*The return statement exits the called function and returns control back to the calling function. Once a return statement is executed, no further instructions within the function are executed.*/
    }
    else
    {
        f=y*factorial(y-1);
    }
    return(f);
}
