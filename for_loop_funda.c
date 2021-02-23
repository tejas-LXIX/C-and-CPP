#include<stdio.h>

int main()
{
    int i=0;
    for(i;i<5;i++)
    {
        printf("%d ",i);
    }
    printf("\n");
    for(i=0;i<5;i++) /* if you dont put i=0,then will enter this loop with the value 5. this is because i ki value isn't reset when it exits the previous 
    loop and enters the next loop. so, this loop statements are never executed since the test condition fails the first time only.*/
    {
        printf("%d ",i);
    }
}