#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
//works here but youll have to input a 1000 times. time consuming. but works in hackerrank. check "digit frequency" question.
int main()
{
    char num;
    char digsum[10];
    for(int i=0;i<10;i++)
    {
        digsum[i]=0;
    }
    for(int i=0;i<1000;i++)
    {   scanf("%c",&num);
        if(num>='0' && num<='9')
        {
            int x=num;
            digsum[x-'0']+=1;
        }
    }
    for(int i=0;i<10;i++)
        printf("%d ",digsum[i]);
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    return 0;
}
