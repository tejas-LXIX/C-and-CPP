#include<bits/stdc++.h>
using namespace std;

int lps(string s1)
{
    string s2=s1;
    reverse(s2.begin(),s2.end());   //take the copy of the string s1. store it in s2 and then reverse s2.
    int n=s1.length();
    int dp[n+1][n+1];
    for(int i=0;i<n+1;i++)
        dp[i][0]=0;
    for(int j=0;j<n+1;j++)
        dp[0][j]=0;
    
    for(int i=1;i<n+1;i++)
    {
        for(int j=1;j<n+1;j++)
        {
            if(s1[i-1]==s2[j-1])
                dp[i][j]=1+dp[i-1][j-1];
            else
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
    return dp[n][n];
}

int main()
{
    string s1;
    cin>>s1;
    cout<<lps(s1);
}