#include<iostream>
using namespace std;

/*
Given a value target, if we want to make change for target cents, and we have infinite supply of each of S = { S1, S2, .. , Sm} valued coins, how many ways can we make the change? The order of coins doesn’t matter.
For example, for target = 4 and S = {1,2,3}, there are four solutions: {1,1,1,1},{1,1,2},{2,2},{1,3}. So output should be 4. For target = 10 and S = {2, 5, 3, 6}, there are five solutions: {2,2,2,2,2}, {2,2,3,3}, {2,2,6}, {2,3,5} and {5,5}. So the output should be 5.
*/

int coinCount(int coins[],int N,int target)
{
    int dp[N+1][target+1];
    for(int j=0;j<=target;j++)  //empty coins array,but we require a sum!=0, then obv its not possible
    {
        dp[0][j]=0;
    }
    for(int i=0;i<=N;i++)   //coins array has some coins,but required sum=0, then its possible by using empty set.
    {
        dp[i][0]=1;
    }
    
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=target;j++)
        {
            if(coins[i-1]<=j)
                dp[i][j]=dp[i][j-coins[i-1]]+dp[i-1][j];    //If coin is included,then dp[i][j-coins[i-1]] and not dp[i-1] because this same coin can be used again and again. if coin not included at all, then dp[i-1][j] as we reduce the size of the array.
            else
                dp[i][j]=dp[i-1][j];
        }
    }
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
        cout<<coinCount(coins,N,target);
        T--;
    }
    return 0;
    /*SAMPLE INPUT
    1
    10 4
    2
    5
    3
    6
    */
}