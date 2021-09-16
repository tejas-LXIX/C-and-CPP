#include<bits/stdc++.h>
using namespace std;
//JUST LIKE 0-1, Only change is that one item can be taken again and again as long as it satisfies the constraint.
// So, when the item is included, in 0-1 knapsack we reduce the input array size (i becomes i-1) so that the current item that was included cannot be included again.
//but unbounded mein, i remains i since we can take that item again.
int dp[2002][2002];     //global array of dp with dimensions set a little more than the constraints given in the question. i.e capacity<=2000 AND  no. of items<=2000.
//global array is only required for recursive solutions, not for iterative solutions.

int recursiveUnboundedKnapsack(int weights[],int values[],int W,int N)       //TOP-DOWN(RECURSIVE APPROACH) OF DP.
{
    if(W==0 || N==0)   //base-condition
        return 0;
    if(dp[W][N]!=-1)    //if value already computed.
        return dp[W][N];
    if(weights[N-1]<=W)
    {
        return dp[W][N]=max(values[N-1]+recursiveUnboundedKnapsack(weights,values,W-weights[N-1],N),recursiveUnboundedKnapsack(weights,values,W,N-1));
    }
    else
    {
        return dp[W][N]=recursiveUnboundedKnapsack(weights,values,W,N-1);
    }
}

int iterativeUnboundedKnapsack(int weights[],int values[],int W,int N)   //BOTTOM-UP(ITERATIVE) APPROACH OF DP. ALSO CALLED TABULATION METHOD.
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
                dp[i][j]=max(values[i-1]+dp[i][j-weights[i-1]],dp[i-1][j]);    //max value in both the cases. 1. if the item is included in the knapsack. 2. If item is not included in the knapsack.
                //values[i-1]+dp[i-1][j-weights[i-1]]    became values[i-1]+dp[i][j-weights[i-1]] here. 
            }
            else
            {
                dp[i][j]=dp[i-1][j];    //if item not included in the knapsack,because its weight is more than remaining capacity of knapsack
            }
        }
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
        cout<<recursiveUnboundedKnapsack(weights,values,max_weight,N)<<endl;
        cout<<iterativeUnboundedKnapsack(weights,values,max_weight,N);
        T--;
    }
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
    /*SAMPLE INPUT
    1
    10 4
    1 10
    3 40
    4 50
    5 70
    */
   //Unbounded knapsack gives 140 as answer, whereas 0-1 knapsack gives 130 as answer.
}
