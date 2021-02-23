#include<iostream>
/*SEE MERGE:SORT ANALYSIS in Week 1 of first course of algorithms specialisation. Each level of the recursion tree takes (2^j)*(6n/(2^j)) time,where j is the level. This is basically (Number of recursive calls at each level)*(6(work done per individual element)*size of input to the recursive call at each level), which evaluates to 6n.
There are logn levels to a mergesort function. therefore total running time is 6n*logn,which is basically n*logn. (n per level)*(logn levels).
*/

//This sort uses the Divide and Conquer strategy,dividing problems into sub problems....., this is done by using recursion.
using namespace std;
//Time complexity is O(nlogn) in all 3 cases(wrost,best,average). Space complexity is O(n).
int merge(int arr[],int l,int m,int r,int size)
{
    int i=l,j=m+1,k=l;      // i is to access the left subarray,j=m+1 to access the right subarray. k is to access the temp subarray that we create.
    int inv_count=0;
    int temp[size];     /* create temp array */
    while(i<=m && j<=r)
    {
        if(arr[i]<=arr[j])
        {
            temp[k]=arr[i];
            i++,k++;//i is incremented to point to the next element of the left subarray, if it is less than the jth element of the right subarray. EG: first case mein,it will check if first element of left subarray is greater than the first element of right subarray. if it is,then i is incremented to point to the 2nd element.
        }  //k is incremented to point to the next element of the temp array that we created.
        else
        {
            temp[k]=arr[j];
            j++,k++;
            inv_count+=m+1-i;
        }
    }

    //These below steps happen after one of the above two subarrays has been iterated over,implying that the other subarray can be copied as it is as it will be sorted due to the previous lower level merge call.

    while(i<=m)     // Copy the remaining elements of first half, if there are any. 
    {
        temp[k]=arr[i];
        i++,k++;
    }  
    while(j<=r)     /* Copy the remaining elements of second half, if there are any */
    {
        temp[k]=arr[j];
        j++,k++;
    }

    for(int p=l;p<=r;p++)  /* Copy the temp array to original array */
    {
        arr[p]=temp[p];
    }
    return inv_count;
}

/* l is for left index and r is
right index of the
sub-array of arr to be sorted */
int mergeSort(int arr[],int l,int r,int size)
{
    int inv_count=0;
    if(l<r)
    {
        int m=(l+r)/2;    //Finding the midpoint. Is equal to l+(r-l)/2
        /* recursive mergesort first
  and second halves */
        inv_count+=mergeSort(arr,l,m,size);         //so that in recursive calls ka final merge call koi useful inv_count return kare.
        inv_count+=mergeSort(arr,m+1,r,size);
        
        //merge(where the actual sorting takes place)
        inv_count+=merge(arr,l,m,r,size);       //this is the function which returns the inv_count in each individual sub-array. The sub-array gets sorted and the inv_count is also returned. THEREFORE, WE HAVE o(nlogn) running time.
    }
    return inv_count;
}
int NumberOfInversions(int arr[],int l,int r,int size)
{
    return mergeSort(arr,l,r,size);
}

int main()
{
    cout<<"enter size of the array: \n";
    int size;
    cin>>size;
    int arr[size];          //somehow works with gcc,even though the size is not known at runtime.
    cout <<"Enter "<<size<<" integers in any order: "<<endl;
    for(int i=0;i<size;i++)
    {
        cin>>arr[i];
    }
    cout<<"Before Sorting\n";
    for(int i=0;i<size;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    cout<<"Number of inversions are: "<<NumberOfInversions(arr,0,size-1,size)<<endl;       // mergesort(arr,left,right) called
    cout <<"After Sorting"<<endl;
    for(int i=0;i<size;i++) 
    {
        cout<<arr[i]<<" ";
    }
}