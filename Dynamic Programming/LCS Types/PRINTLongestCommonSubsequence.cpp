#include<bits/stdc++.h>
using namespace std;

string lcs(string s1,string s2)
{
    int n=s1.length(),m=s2.length();
    int dp[n+1][m+1];
    for(int i=0;i<n+1;i++)
        dp[i][0]=0;
    for(int j=0;j<m+1;j++)
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
    //the dp array for the length of the lcs has been created here. now to start from dp[n][m] and trace back to dp[0][0] to print the LCS.
    //in each iteration,we check from where we have reached the current state. if the characters are same, then add it to the answer. otherwise check whether we reached current state from s1 or s2.
    // https://www.geeksforgeeks.org/printing-longest-common-subsequence/ to undestand. See how they have traced the dp matrix to print the lcs.
    string answer="";
    int i=n,j=m;
    while(i!=0 && j!=0)
    {
        if(s1[i-1]==s2[j-1])
        {
            answer+=s1[i-1];
            i--,j--;
        }
        else if(dp[i-1][j]>dp[i][j-1])
            i--;
        else
            j--;
    }
    reverse(answer.begin(),answer.end());   //reverse because the characters are being added from the last in the above loop. isliye final answer reverse karke return karna hai.
    return answer;
}

int main()
{
    string s1,s2;
    cin>>s1>>s2;
    cout<<lcs(s1,s2);
}