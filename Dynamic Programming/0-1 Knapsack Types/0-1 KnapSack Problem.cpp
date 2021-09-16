#include<bits/stdc++.h>
using namespace std;
//https://www.hackerrank.com/contests/srin-aadc03/challenges/classic-01-knapsack/problem
int dp[2002][2002];     //global array of dp with dimensions set a little more than the constraints given in the question. i.e capacity<=2000 AND  no. of items<=2000.
//global array is only required for recursive solutions, not for iterative solutions.

int recursiveKnapsack(int weights[],int values[],int W,int N)       //TOP-DOWN(RECURSIVE APPROACH) OF DP.
{
    if(W==0 || N==0)   //base-condition
        return 0;
    if(dp[W][N]!=-1)    //if value already computed.
        return dp[W][N];
    if(weights[N-1]<=W)
    {
        return dp[W][N]=max(values[N-1]+recursiveKnapsack(weights,values,W-weights[N-1],N-1),recursiveKnapsack(weights,values,W,N-1));
    }
    else
    {
        return dp[W][N]=recursiveKnapsack(weights,values,W,N-1);
    }
}

int iterativeKnapsack(int weights[],int values[],int W,int N)   //BOTTOM-UP(ITERATIVE) APPROACH OF DP. ALSO CALLED TABULATION METHOD.
{
    for(int i=0;i<N+1;i++)
    {
        dp[i][0]=0;
    }
    for(int j=0;j<W+1;j++)
    {
        dp[0][j]=0;
    }
    for(int i=1;i<N+1;i++)
    {
        for(int j=1;j<W+1;j++)
        {
            if(weights[i-1]<=j)     //W of recursive becomes j here. As,in each sub-problem,we need to find the optimal weight of the knapsack subject to the constraint of it being less than the possible weight for that sub-problem (j),
            {
                dp[i][j]=max(values[i-1]+dp[i-1][j-weights[i-1]],dp[i-1][j]);    //max value in both the cases. 1. if the item is included in the knapsack. 2. If item is not included in the knapsack.
            }
            else
            {
                dp[i][j]=dp[i-1][j];    //if item not included in the knapsack,because its weight is more than remaining capacity of knapsack
            }
        }
    }
    for(int i=0;i<N+1;i++)  //just to print out the dp matrix for visualisation
    {
        for(int j=0;j<W+1;j++)
            cout<<dp[i][j]<<" ";
        cout<<endl;
    }
    return dp[N][W];
}
int main()
{
    int T;
    cin>>T;
    while(T)
    {
        memset(dp,-1,sizeof(dp));   //initialise the dp array with values -1.
        int max_weight,N;
        cin>>max_weight>>N;
        int weights[N],values[N];
        for(int i=0;i<N;i++)
        {
            int item_weight,item_value;
            cin>>item_weight>>item_value;
            weights[i]=item_weight;
            values[i]=item_value;
        }
        cout<<recursiveKnapsack(weights,values,max_weight,N)<<endl;
        cout<<iterativeKnapsack(weights,values,max_weight,N);
        T--;
    }
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
    /* SAMPLE INPUT
    1
    10 4
    1 10
    3 40
    4 50
    5 70
    */
}