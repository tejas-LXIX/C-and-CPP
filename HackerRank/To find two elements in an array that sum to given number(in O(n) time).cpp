#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
    int arr[10]={94,35,67,84,11,234,75,314,69,99};
    int k;
    cin>>k;
    sort(arr,arr+10); //O(nlogn)
    for(int i=0,j=9;i<9;)  //O(n)
    {
        if(arr[i]+arr[j]==k)
        {
            cout<<arr[i]<<" "<<arr[j];
            return 0;
        }
        else if(arr[i]+arr[j]<k)
        {
            i++;
        }
        else
            j--;
    }
    cout<<"no such numbers exist";
}