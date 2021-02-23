#include<stdio.h>
#include<stdlib.h>

void assign(int **,int,int);
int main()
{
    int m,n;
    printf("enter the values of m and n: ");
    scanf("%d %d",&m,&n);
    int **arr=(int**)malloc(m*sizeof(int *)); //to dynamically create array of m pointers. one for each row
    for(int i=0;i<m;i++)
    {
        arr[i]=(int*)malloc(n*sizeof(int)); //to dynamically create 'm' number of arrays of 'n' elements each. yahan pe 2-d array ban gaya.
    }
    
    assign(arr,m,n);
}
void assign(int **arr,int m,int n)
{
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            arr[i][j]=i+j; //simple expression to assign values. no * waali bakchodi required.
            printf("%d ",arr[i][j]);
        }
    }
}