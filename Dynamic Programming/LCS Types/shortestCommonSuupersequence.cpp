// https://leetcode.com/problems/delete-operation-for-two-strings/
#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'lcs' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. STRING s1
 *  2. STRING s2
 */

int scs(string s1, string s2) {
    int n=s1.length(),m=s2.length();
    int dp[n+1][m+1];     //dp[i][j] represents the length of the longest common subsequence till index i-1 of s1, and index j-1 of s2
    for(int i=0;i<=n;i++)
        dp[i][0]=0;
    for(int j=0;j<=m;j++)
        dp[0][j]=0;
    for(int i=1;i<n+1;i++)
    {
        for(int j=1;j<m+1;j++)
        {
            if(s1[i-1]==s2[j-1])
                dp[i][j]=1+dp[i-1][j-1];
            else
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
    return n+m-dp[n][m];    //length of shortest common supersequence is sum of lengths of s1 and s2,minus the length of the lcs of s1 and s2.
    //see notes or watch https://www.youtube.com/watch?v=823Grn4_dCQ&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=25    
}

int main()
{
    string s1;
    cin>>s1;

    string s2;
    cin>>s2;

    cout<<scs(s1, s2);
}
