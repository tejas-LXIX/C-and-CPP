#include<iostream>
#include<algorithm>
#include<ctime>
using namespace std;
int binarySearch(int arr[],int l,int r,int val) // A recursive binary search function. It returns location of val in given array arr[l..r] if present, otherwise -1.
{
    if(r>=l)
    {
        int mid=l+(r-l)/2;
        if(arr[mid]==val) //If the element is present at the middle itself 
            return mid;
        if(arr[mid]<val)
            return binarySearch(arr,mid+1,r,val);  //if mid element is lesser than val,this means that val is present in right sub array.
        return binarySearch(arr,l,mid-1,val); //if mid element is greater than val,this means that val is present in left sub array.
    }
    return -1;
}
int main()
{
    /*
    int arr[5]={2,3,56,11,97};
    int val=56;
    sort(arr,arr+5);
    cout<<binarySearch(arr,0,4,val);*/
    int array[10000];
    srand(time(0));  //to randomise the inputs given to the array as input
    for(int i=0;i<10000;i++)
    {
        if(i==7243)
            array[i]=764;
        else
        {   
            int val=rand();
            array[i]=val;
        }
    }
    int val=764;
    sort(array,array+10000);
    cout<<binarySearch(array,0,10000-1,val);
}
