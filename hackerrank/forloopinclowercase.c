#include <stdio.h>
int main() 
{
    int a, b;
    scanf("%d\n%d", &a, &b);
    int n[b-a+1];
    for(int i=0;i<=b-a;i++)
    {
        n[i]=a+i;
    }
    for(int i=0;i<=(b-a);i++)
    {   
        int j;
        j=n[i];
        if(j>9)
        {
            if((j%2)==0)
            {
                printf("even\n");
            }
            else
            {
                printf("odd\n");
            }
        }
        else
        {
            switch(j)
            {
                case 1:
                    printf("one\n");
                    break;
                case 2:
                    printf("two\n");
                    break;
                case 3:
                    printf("three\n");
                    break;
                case 4:
                    printf("four\n");
                    break;
                case 5:
                    printf("five\n");
                    break;
                case 6:
                    printf("six\n");
                    break;
                case 7:
                    printf("seven\n");
                    break;
                case 8:
                    printf("eight\n");
                    break;
                case 9:
                    printf("nine\n");
            }
        }
    }
  	// Complete the code.

    return 0;
}

