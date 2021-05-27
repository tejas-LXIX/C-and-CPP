#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//JUST LIKE COUNT OF SUBSETS WITH A GIVEN SUM, WHERE THE SUM IS EQUAL TO (difference+sum(arr))/2.
//SEE NOTES FOR EXPLANATION.
int countOfSubsetsWithGivenDiff(int arr[],int n,int diff)
{
    int SUM=0;
    for(int i=0;i<n;i++)
        SUM+=arr[i];
    if((diff+SUM)%2!=0)     //if((diff+SUM)%2!=0)  i.e if diff+SUM is ODD,   then we would NEVER get the difference diff by partitioning the array into two subsets.
        return 0;
    int target=(diff+SUM)/2;
    int dp[n+1][target+1];
    for(int j=0;j<=target;j++)
        dp[0][j]=0;
    for(int i=0;i<=n;i++)
        dp[i][0]=1;
    
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=target;j++)
        {
            if(arr[i-1]>j)
                dp[i][j]=dp[i-1][j];
            else
                dp[i][j]=dp[i-1][j-arr[i-1]] + dp[i-1][j];
        }
    }
    return dp[n][target];
}

int main()
{
    int set[] = {1,1,2,3};
    int diff = 1;
    int n = sizeof(set) / sizeof(set[0]);
    cout<<countOfSubsetsWithGivenDiff(set,n,diff);
    return 0;
}