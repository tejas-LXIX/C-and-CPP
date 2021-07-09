#include<iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int list12[n][n];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>list12[i][j];
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(list12[i][j]>list12[i][j+1])
            {
                int temp;       /*rows have been sorted.*/
                temp=list12[i][j];
                list12[i][j]=list12[i][j+1];
                list12[i][j+1]=temp;
            }
        }
    }
    for(int j=0;j<n;j++)
    {
        for(int i=0;i<n;i++)
        {
            if(list12[i][j]>list12[i+1][j])
            {
                int temp;   /*columns have been sorted*/
                temp=list12[i][j];
                list12[i][j]=list12[i+1][j];
                list12[i+1][j]=temp;
            }
        }
    }
    /* the whole array has been sorted. */
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<list12[i][j]<<" ";
        }
        cout<<endl;
    }
}
