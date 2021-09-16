#include<iostream>
using namespace std;

int minCoins(int coins[],int N,int target)
{
    int dp[N+1][target+1];
    for(int j=0;j<=target;j++)
        dp[0][j]=INT_MAX-1;     //if we have empty coins array,and we need a required target, then MATHEMATICALLY, the number of coins required to get the target would be infinite.
    for(int i=0;i<=N;i++)
        dp[i][0]=0;
    
    for(int i=1;i<=N;i++)
    {
        for(int j=0;j<=target;j++)
        {
            if(coins[i-1]<=j)
                dp[i][j]=min(1+dp[i][j-coins[i-1]],dp[i-1][j]);     //1+ dp[i][j-coins[i-1]] because we are adding the current coin to the number of coins reqd.
            else
                dp[i][j]=dp[i-1][j];
        }
    }
    if(dp[N][target]==INT_MAX-1)    //if the target cannot be obtained by the given coins array, then return -1.
        return -1;
    return dp[N][target];
}

int main()
{
    int T;
    cin>>T;
    while(T)
    {
        int target,N;   //target value, and the size of the coins array(how many types of coins there are).
        cin>>target>>N;
        int coins[N];
        for(int i=0;i<N;i++)
        {
            cin>>coins[i];
        }
        cout<<"Minimum number of coins required is "<<minCoins(coins,N,target);
        T--;
    }
    return 0;
    /*Sample input
    3
    30 3
    25
    10
    5
    11 4
    9
    6
    5
    1
    3 1
    2
    */
}