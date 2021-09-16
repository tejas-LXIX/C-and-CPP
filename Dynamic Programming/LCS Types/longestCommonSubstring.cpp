#include<iostream>
using namespace std;

int longestCommonSubstring(string s1,string s2)
{
    int n=s1.length(),m=s2.length();
    int dp[n+1][m+1];
    for(int i=0;i<=n;i++)
        dp[i][0]=0;
    for(int j=0;j<=m;j++)
        dp[0][j]=0;
    
    int ans=0;      //returns the final answer. goes thru all the possible substring's lengths and stores the max.

    for(int i=1;i<n+1;i++)
    {
        for(int j=1;j<m+1;j++)
        {
            if(s1[i-1]==s2[j-1])
            {
                dp[i][j]=1+dp[i-1][j-1];
                ans=max(ans,dp[i][j]);
            }
            else    //set the dp[i][j] value to 0 at all points of discontinuity in the strings.
                dp[i][j]=0;
        }
    }
    for(int i=0;i<n+1;i++)
    {
        for(int j=0;j<m+1;j++)
        {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    return ans;
}

int main()
{
    string s1;
    cin>>s1;

    string s2;
    cin>>s2;

    cout<<longestCommonSubstring(s1, s2);
}