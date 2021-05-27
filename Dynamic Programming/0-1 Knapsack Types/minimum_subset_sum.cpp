#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int findMin(int arr[],int n)
{
    int SUM=0;
    for(int i=0;i<n;i++)
        SUM+=arr[i];
    bool dp[n+1][SUM+1];
    for(int j=0;j<=SUM;j++)
        dp[0][j]=false;
    for(int i=0;i<=n;i++)
        dp[i][0]=true;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=SUM;j++)
        {
            if(arr[i-1]>j)
                dp[i][j]=dp[i-1][j];
            else
                dp[i][j]=dp[i-1][j-arr[i-1]] || dp[i-1][j];
        }
    }

    ///Minimum sum difference will be obtained for that value of 'j', which is closest to SUM/2, and for which dp[n][j] is TRUE.
    //since the subset at dp[n][j] will have sum 'j', implies that the subset of the remaining elements will have sum=SUM-j. therefore the difference between the two will (SUM-j)-j i.e SUM-2*j;
    int diff=INT_MAX;
    for(int j=SUM/2;j>=0;j--)
    {
        if(dp[n][j])
        {
            diff=SUM-2*j;
            break;
        }
    }
    return diff;
}

int main()
{
    int arr[] = {3, 1, 4, 2, 2, 1};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << "The minimum difference between the 2 sets is "
         << findMin(arr, n);
    return 0;
}