#include<stdio.h>

int main()
{
    int r;
    printf("enter the number of rows: ");
    scanf("%d",&r);
    int space;
    space=r-1; /*since ill start the loop from 0*/
    for(int i=0;i<r;i++) /*iterates over the rows*/
    {
        for(int j=0;j<space;j++)   /* < is used because if r is 10, then space is 9. so we want 9 spaces from 0 to 8. so that on the 10th space * is written*/
        {                          /*gives spaces for each row*/
            printf(" ");
        }
        space--; /*this will reduce the number of blank spaces in each iteration */
        for(int c=0;c<(2*i+1);c++)
        {
            printf("*");
        }
        printf("\n"); /* yahan tak code is chill. now you just have to reduce the number of *'s printed and increase the spaces */
    }
    space=1; /*because we need space as 1 to get one space just after the middle row when we start increasing the spaces again.*/
    for (int i=0;i<r-1;i++)  /*because if r=3 we've already got 3 rows from the above code so we need only 2 more rows. here itll be 0 and 1.*/
        {
            for(int j=0;j<space;j++)
            {
                printf(" ");
            }
            space++; /*the first time the above loop runs, it runs only once. therefore we get the required 1 space. second time, it runs twice, therefore we get the required 2 spaces. so on*/
            for(int c=0;c<2*(r-i-1)-1;c++) /* this reduces the number of prints by 2 everytime.*/ /*got it by hit and trial by using r as 3*/
            {
                printf("*");
            }
            printf("\n");
        }
}
