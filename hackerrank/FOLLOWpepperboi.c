#include<stdio.h>
#include<stdlib.h>

int main()
{
    int east,north;
    scanf("%d %d",&east,&north);
    char path[20];
    scanf("%s",path);
    int n=strlen(path);
    int time=0;
    for(int i=0;i<n;i++)
    {
        if(north==0 && east==0)
        {
            break;
        }
        else if(north==1 && path[i]=='S') //for the condition when you stay still and the next move of peppurr gets him to you
        {
            if(east!=0)
            {
                east--;
            }
            time++;
            north--;
        }
        else if(east==1 && path[i]=='W') //for the condition when you stay still and the next move of peppurr gets him to you
        {
            if(north!=0)
            {
                north--;
            }
            time++;
            east--;
        }
        else if(north!=0 && path[i]=='S')
        {
            north-=2;
            time++;
        }
        else if(east!=0 && path[i]=='W')
        {
            east-=2;
            time++;
        }
        else if(east!=0)
        {
            east--;
            time++;
        }
        else if(north!=0)
        {
            north--;
            time++;
        }
        else if(path[i]=='S') //normal condition if any of the above arent satisfied
        {
            north--;
        }        
        else if(path[i]=='W') //normal condition if any of the above arent satisfied
        {
            east--;
        }      
    }
    if(north==0 && east==0)
    {
        printf("%d",time);
    }
    else
    {
        printf("IMPOSSIBLE");
    }
}