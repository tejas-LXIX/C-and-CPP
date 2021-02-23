#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
//Complete the following function.
void calculate_the_maximum(int,int);

void calculate_the_maximum(int n, int k) 
{
    int s[n];
    int max_and=0,max_or=0,max_xor=0;
    int i=0;
    for(i;i<n;i++)
    {
        s[i]=i+1;
    }  /* for a */
    for(i=0;i<n;i++) /* if i=0 nahi karoge, toh it will continue with the value 
    i=n which it got when it exited the above for loop. get your scope ka funda right.
    the value of i doesnt become 0 on its own just because it exited the for loop.
    the value remains cause you have made changes in the loop.*/
    {
        for(int j=i+1;j<n;j++)  /* for b */
        {
            if((s[i]&s[j])>max_and && ((s[i]&s[j])<k))
            {
                max_and=s[i]&s[j];
            }
            if((s[i]|s[j])>max_or && ((s[i]|s[j])<k))
            {
                max_or=s[i]|s[j];
            }
            if((s[i]^s[j])>max_xor && ((s[i]^s[j])<k))
            {
                max_xor=s[i]^s[j];
            }
        }
    }
    printf("%d",max_and);
    printf("\n%d",max_or);
    printf("\n%d",max_xor);
}

int main() {
    int n, k;
  
    scanf("%d %d", &n, &k); /*since inputs are in one line*/
    calculate_the_maximum(n, k);
 
    return 0;
}
