/*Quick sort is considered as an in-place sorting algorithm(like selection sort,bubble sort,insertion sort). 
In-Place sorting algo: a sort algo in which the sorted items occupy the same storage as the original ones. This is achieved by swapping,shuffling,replacing and shifting of elements
in the same array/list. Merge sort requires an extra temporary array to be maintained which increases its space complexity to O(n). so,quicksort is better.
Time complexity is O(nlogn) in best and average case, O(n^2) in worst case. Space complexity is O(logn). */

//we can take first element,last element or random element as the pivot for quicksort.
//QuickSort works by choosing a pivot in each recursive call,and shifting all the smaller elements to its left,and the greater elements to its right before finally putting the pivot element in the appropriate partition (pIndex) position. 

#include<iostream>

using namespace std;
int Partition(int arr[],int s,int e)
{
    int pivot=arr[e];       //in this type of quicksort,we take the last element as the pivot.
    int pIndex=s;      //starting from the first element. It is used to monitor the position at which we partition the array. Used to insert the pivot element at the appropriate position after it has been compared with all the other elements of the array. 
    for(int i=s;i<e;i++)        //i<=e nahi hai because we take the last element as the pivot.
    {
        if(arr[i]<=pivot)
        {
            swap(arr[i],arr[pIndex]);    //This is done only to make all the elements lesser than the pivot appear on the left side of the pivot. meaning that all greater elements appear on the right side of the pivot.
            pIndex++;
        }
    }
    swap(arr[e],arr[pIndex]);            //to get the pivot to its appropriate position (partition position i.e pIndex) in the array,with smaller elements on its left,and larger elements on its right.
    return pIndex;
}

int QuickSort(int arr[],int s,int e)
{
    if(s<e)
    {
        int p=Partition(arr,s,e);
        QuickSort(arr,s,p-1);   // recursive QS call for left partition
        QuickSort(arr,p+1,e);   // recursive QS call for right partition
    }
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
    QuickSort(arr,0,size-1);       // quicksort(arr,left,right) called
    cout <<"After Sorting"<<endl;
    for(int i=0;i<size;i++) 
    {
        cout<<arr[i]<<" ";
    }
}