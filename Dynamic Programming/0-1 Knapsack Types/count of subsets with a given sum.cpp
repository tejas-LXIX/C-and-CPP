#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int countOfSubsets(int elements[],int n,int sum)
{   //n is no. of elements in the array. sum is the required sum.
    // i iterates over n. j iterates over sum.
    //dp[i][j] represents the situation when 'i' elements are present in the array, and the required sum is 'j'. 
    int dp[n+1][sum+1];
    //initialisation
    for(int j=0;j<=sum;j++)     //if array is empty (i=0) and we require a sum!=0, then it is obv not possible since empty array cannot give any positive sum.
        dp[0][j]=0;
    for(int i=0;i<=n;i++)       //if array is not empty (i!=0) but sum required is 0, then it is possible, since we can always return an empty set to get sum=0.
        dp[i][0]=1;
    //special case when array empty, and sum required is 0 (i=0 and j=0). This is also possible (return empty set), therefore dp[0][0] is true.
    
    // THE DP ARRAY IS FILLED ROW BY ROW.
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=sum;j++)
        {
            if(elements[i-1]>j)
                dp[i][j]=dp[i-1][j];  //since the element cannot be included, so the value of dp[i][j] is equal to the value of dp[i-1][j], which is basically the previous state when the number of elements is i-1 AND the current element is not included in the set (so, the sum value 'j' remains unaffected).
            else
                dp[i][j]=dp[i-1][j-elements[i-1]] + dp[i-1][j];    //ADDING THE TWO CASES
            /* 1. The current element is selected. So, the number of subsets when current element is selected is equal to the number of subsets taken from the first 'i-1' elements of the main array, where the sum of this subset equals j-elements[i-1]. So that, when the current element is added to the subset,the sum becomes j-elements[i-1]+elements[i-1] i.e 'j', and the number of elements is 'i'.
            2. Current element not selected, then its the same case as the above IF condition, when no. of elements is i-1 and the sum remains the same j. basically, aise kitne subsets hai from the first 'i-1' elements of the main array, whose sum is already equal to 'j'.
            SEE MATRIX IN NOTEBOOK TO UNDERSTAND KYA SCENE HAI*/
        }
    }

    //to visualise the dp array.
    for (int i = 0; i <= n; i++)
     {
       for (int j = 0; j <= sum; j++)
          printf ("%4d", dp[i][j]);
       printf("\n");
     }
    
    return dp[n][sum];
}

int main()
{
    int set[] = { 3, 34, 4, 12, 5, 2 };
    int sum = 9;
    int n = sizeof(set) / sizeof(set[0]);
    cout<<countOfSubsets(set,n,sum);
    return 0;
}