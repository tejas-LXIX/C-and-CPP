#include<stdio.h>
#include<stdlib.h>
//SEE CHAT WITH ROHAN IF YOU DON'T UNDERSTAND
//Taxicab distance is minimum distance of a point (x,y) from you. Diagonal not allowed. so it's mod(x)+ mod(y). Here,it is evaluated everytime peppur moves.
// we can cover one unit in one minute.
//so basically what we do is, we monitor the movement of the peppur everytime. and then based on his taxicab distance from your starting point,figure out  
//if you could have reached him in time or not. this is done by checking if the distance of peppur from you is less than or equal to the time elapsed since
// peppur started moving. this check is done after his every move. if distance is lesser than the time,this implies that you could have reached the point 
//peppurr is at currently,before or at the same time as him,thereby letting you geet a photo with him. the order of the movement is not important,only
//if you can reach him or not is important.
int main()
{
    int x,y;
    scanf("%d %d",&x,&y); //in 2-d x and y co-ordinates
    char path[20];
    scanf("%s",path);
    int n=strlen(path);
    int distance=abs(x)+abs(y);
    int time=0;
    for(int i=0;i<n;i++)
    {
        if(path[i]=='N')
        {
            y++; //since peppur is going away from you
            time++;
        }
        else if(path[i]=='S')
        {
            y--; //since peppur is coming closer to you
            time++;
        }
        else if(path[i]=='E')
        {
            x++; //since peppur is going away from you
            time++;
        }
        else
        {
            x--; //since peppur is coming closer to you
            time++;
        }
        distance=abs(x)+abs(y);
        if(distance<=time)
        {
            printf("%d",time);
            break;
        }
    }
    if(distance>time)
    {
        printf("IMPOSSIBLE");
    }
}