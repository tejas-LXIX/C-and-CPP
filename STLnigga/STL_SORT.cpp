/*How to sort in particular order? 
We can also write our own comparator function and pass it as a third parameter. This “comparator” function returns a value; convertible to bool, which basically tells us whether the passed “first” argument
should be placed before the passed “second” argument or not. 
For eg: In the code below, suppose 6 and 1 are passed as arguments in the “comparator" function. 
Now as i1=6 > i2=1, so our function returns “false”, 
which tells us that “first” argument should NOT be placed before “second” argument and so sorting will be done in order like 1 first and then 6 as next.*/

#include<iostream>
#include<algorithm>
using namespace std;

bool comparator(int i1,int i2)
{
    return (i1<i2);    //if first parameter(i1) is less than second parameter(i2),then return true. 
}
int main()
{
    int arr[]={6,1,2,4};
    int n=sizeof(arr)/sizeof(arr[0]);
    sort(arr,arr+n,comparator);  //if comparator returns true,then first parameter(i1) will be placed before second parameter(i2).If false,then first parameter(i1) will NOT be placed before second parameter(i2). 
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
}

/*
// C++ program to demonstrate descending order sort using
// greater<>().
#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    int arr[] = { 1, 5, 8, 9, 6, 7, 3, 4, 2, 0 };
    int n = sizeof(arr) / sizeof(arr[0]);
 
    sort(arr, arr + n, greater<int>());
 
    cout << "Array after sorting : \n";
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
 
    return 0;
}*/