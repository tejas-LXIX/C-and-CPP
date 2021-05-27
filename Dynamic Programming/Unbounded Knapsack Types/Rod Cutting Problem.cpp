#include<bits/stdc++.h>
using namespace std;
//JUST LIKE 0-1, Only change is that one item can be taken again and again as long as it satisfies the constraint.
// So, when the item is included, in 0-1 rod we reduce the input array size (i becomes i-1) so that the current item that was included cannot be included again.
//but unbounded mein, i remains i since we can take that item again.

int iterativeUnboundedrod(int lengths[],int prices[],int L,int N)   //BOTTOM-UP(ITERATIVE) APPROACH OF DP. ALSO CALLED TABULATION METHOD.
{
    int dp[N+1][L+1];
    for(int i=0;i<N+1;i++)
    {
        for(int j=0;j<L+1;j++)
        {
            if(i==0 || j==0)
                dp[i][j]=0;
        }
    }
    for(int i=1;i<N+1;i++)
    {
        for(int j=1;j<L+1;j++)
        {
            if(lengths[i-1]<=j)     //L of recursive becomes j here. As,in each sub-problem,we need to find the optimal length of the rod subject to the constraint of it being less than the possible length for that sub-problem (j),
            {
                dp[i][j]=max(prices[i-1]+dp[i][j-lengths[i-1]],dp[i-1][j]);    //max value in both the cases. 1. if the length of sub-rod is included in the rod. 2. If length of sub-rod is not included in the rod.
                //prices[i-1]+dp[i-1][j-lengths[i-1]]    became prices[i-1]+dp[i][j-lengths[i-1]] here. (i-1 -> i)
            }
            else
            {
                dp[i][j]=dp[i-1][j];    //if length not included as one of the cuts of rod,because its length is more than remaining length of rod.
            }
        }
    }
    return dp[N][L];
}
int main()
{
    int T;
    cin>>T;
    while(T)
    {
        int max_length,N;
        cin>>max_length>>N;
        int lengths[N],prices[N];
        for(int i=0;i<N;i++)
        {
            int rod_length,rod_price;
            cin>>rod_length>>rod_price;
            lengths[i]=rod_length;
            prices[i]=rod_price;
        }
        cout<<iterativeUnboundedrod(lengths,prices,max_length,N);
        T--;
    }
    return 0;
    /*SAMPLE INPUT
    1
    8 8
    1 1
    2 5
    3 8
    4 9
    5 10
    6 17
    7 17
    8 20
    */
}
