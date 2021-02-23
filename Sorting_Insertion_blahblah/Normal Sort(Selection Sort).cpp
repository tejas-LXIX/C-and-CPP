#include<iostream>
using namespace std;
//it is also called Selection Sort.
//O(n^2) sorting algorithm

void selectionSort(int arr[],int size)
{
    for(int i=0;i<size;i++) //after each iteration of the 'i' loop,one element from the array is sorted(placed at its appropriate position.)
    {
        for(int j=i+1;j<size;j++) //each element is compared with the elements after it. if the below condition is satisfied,then the elements swap places.
        {
            if(arr[i]>arr[j])  //just write arr[i]<arr[j] for sorting in descending order.
            {
                int temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
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
    selectionSort(arr,size);       // mergesort(arr,left,right) called
    cout <<"After Sorting"<<endl;
    for(int i=0;i<size;i++) 
    {
        cout<<arr[i]<<" ";
    }
}
