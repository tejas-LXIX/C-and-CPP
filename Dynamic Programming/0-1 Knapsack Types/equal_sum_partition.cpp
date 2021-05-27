//JUST LIKE SUBSET SUM.CPP. YAHAN PE YOU HAVE TO FIND A PARTITION WHOSE sum is equal to (SUM OF ARRAY)/2. IF SUCH A PARTITION EXISTS,THEN OBVIOUSLY THE OTHER PARTITION WILL ALSO HAVE sum=SUM/2. SO WE WILL RETURN TRUE.
//AGAR AISA PARTITION NAHI MILTA, SO WE WILL RETURN FALSE.
/*
Partition problem is to determine whether a given set can be partitioned into two subsets such that the sum of elements in both subsets is the same. 

Examples: 

arr[] = {1, 5, 11, 5}
Output: true 
The array can be partitioned as {1, 5, 5} and {11}

arr[] = {1, 5, 3}
Output: false 
The array cannot be partitioned into equal sum sets.*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool isSubsetSum(int arr[],int n,int sum)
{
    bool dp[n+1][sum+1];
    for(int j=0;j<=sum;j++)
        dp[0][j]=false;
    for(int i=0;i<=n;i++)
        dp[i][0]=true;
    
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=sum;j++)
        {
            if(arr[i-1]>j)
                dp[i][j]=dp[i-1][j];
            else
                dp[i][j]=dp[i-1][j-arr[i-1]] || dp[i-1][j];
        }
    }
    return dp[n][sum];
}

bool findPartition(int arr[],int n)
{
    int SUM=0;
    for(int i=0;i<n;i++)
        SUM+=arr[i];
    if(SUM&1!=0)    //if the sum of all elements in the array arr is ODD, then we return false since no such parition is possible whose sum would be SUM/2. EG: SUM=23, then no partition possible whose sum is 11.5
        return false;
    return isSubsetSum(arr,n,SUM/2);
}

int main()
{
    int arr[] = { 3, 1, 5, 9, 12 };             //change 5 to 6. you will get false, since sum is ODD. change 5 to 9, and you will get false, since no valid partition exists.
    int n = sizeof(arr) / sizeof(arr[0]);
   
    // Function call
    if (findPartition(arr, n) == true)
        cout << "Can be divided into two subsets "
                "of equal sum";
    else
        cout << "Can not be divided into two subsets"
                " of equal sum";
    return 0;
}