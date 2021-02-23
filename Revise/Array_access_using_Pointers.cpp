#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    int arr[10]={0,1,2,3,4,5,6,7,8,9};
    int *p=arr;
    int *end=p+10; //no other way to iterate through an array safely using pointers. this is how STL iterators work too.
    while(p!=end)
    {
        cout<<*p;
        p++;
    }
    p=arr; //reassign p to arr so that you can use pointer to iterate through the array again.
    cout<<endl<<*p;
}