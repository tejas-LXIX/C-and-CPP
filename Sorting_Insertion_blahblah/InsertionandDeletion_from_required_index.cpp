/* VERY IMPORTANT. DIFFERENCE BETWEEN VECTOR AND LL

Vector is another name for dynamic arrays. It is the name used for the dynamic array data structure in C++.
Vectors are good for random read access and insertion and deletion in the back (takes amortized constant time), but bad for insertions and deletions in the front or any other position (linear time, as items have to be moved). 
Vectors are usually laid out contiguously in memory, so traversing one is efficient because the CPU memory cache gets used effectively.
Linked lists on the other hand are good for inserting and deleting items in the front or back (constant time), but not particularly good for much else: For example deleting an item at an arbitrary index in the middle of the list takes linear time because you must first find the node. On the other hand, once you have found a particular node you can delete it or insert a new item after it in constant time, something you cannot do with a vector. Linked lists are also very simple to implement, which makes them a popular data structure.*/
#include <iostream>
using namespace std;
///O(n) insertion
int insertintoarray(int *p,int value,int index,int length)      //p is a pointer to the array (to the first element of the array).
{
    p=(int*)realloc(p,sizeof(int)*(length+1));
    for(int i=length;i>index;i--) //i=length means i now points to the last element of ptr. since new length is length+1. therefore,starting from 0,last index of a (length+1) sized array will be length.
    {
        p[i]=p[i-1];
    }
    p[index]=value;
    return length+1;    //returns the new length of the array after insertion.
}

int deletefromarray(int *p,int value,int length)
{
    int i=0;
    for(i;i<length;i++)
    {
        if(p[i]==value)
        {
            break;
        }
    }
    if(i<length)
    {
        for(int j=i;j<length;j++)
        {
            p[j]=p[j+1];    //moving elements back one by one starting from the index "i"(where the element has been found). in the end,last value of the array will be useless(so the size reduces by 1),and the value at index "i" would have been removed.
        }
    
    p=(int*)realloc(p,sizeof(int)*(length-1));
    return length-1;
    }
    cout<<"Element does not exist in the array. No deletion done\n";
    return length;
}

int main()
{
    cout<<"enter the number of elements in your array: ";
    int n,value,index;
    cin>>n;
    cout<<"enter the value you want to insert: ";
    cin>>value;
    cout<<"enter the location(indexed) at which you want to enter the element: ";
    cin>>index;
    int* p=new int[n];
    int* q=p;
    for(int i=0;i<n;i++)
    {
        *q=i;        //to fill the array with values.
        q++;
    }
    
    n=insertintoarray(p,value,index,n);  //to get the new length of the array.
    for(int i=0;i<n;i++)
    {
        cout<<p[i]<<" ";
    }
    cout<<"Insertion done\n";
    cout<<"enter the value you want to delete: ";
    cin>>value;
    n=deletefromarray(p,value,n);
    for(int i=0;i<n;i++)
    {
        cout<<p[i]<<" ";
    }
}
