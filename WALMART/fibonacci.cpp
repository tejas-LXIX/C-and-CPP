#include<iostream>
using namespace std;

void fibonacci(int n)
{
    int arr[n];
    arr[0]=0,arr[1]=1;
    cout<<arr[0]<<" "<<arr[1]<<" ";
    for(int i=2;i<n;i++)
    {
        arr[i]=arr[i-1]+arr[i-2];
        cout<<arr[i]<<" ";
    }
}

int main()
{
    int n;
    cin>>n;
    fibonacci(n);
}

SELECT CONTACTS.NAMES FROM CONTACTS WHERE CONTACTS.NAMES NOT IN ((SELECT ATTENDANCE.NAMES FROM ATTENDANCE) AND (SELECT REGISTRY.NAMES FROM REGISTRY))