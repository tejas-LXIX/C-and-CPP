#include<iostream>
#include<string.h>
#include<cmath>
using namespace std;

int main()
{
    int n;
    cin>>n;
    string S[n];
    for(int i=0;i<n;i++)
    {
        cin>>S[i];
    }
    string W;
    cin>>W;
    int sumvalues[n];
    for(int i=0;i<n;i++)
    {
        int sum=0;
        for(int j=0;j<sizeof((S[i]));j++)
        {
            char m=S[i][j];    /*access each individual letter of every string.*/
            int l=W.find(m);
            if(l!=-1)
            {
                sum=sum+abs((j+1)*(l+1));
            }
        }
        sumvalues[i]=sum;
    }
    int max=0;
    for(int i=0;i<n;i++)
    {
        if(sumvalues[i]>max)
        {
            max=sumvalues[i];
        }
    }
    for(int i=0;i<n;i++)
    {
        if(sumvalues[i]==max)
        {
            cout<<S[i];
        }
    }
}
