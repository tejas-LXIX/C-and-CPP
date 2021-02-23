#include<iostream>
using namespace std;

//It is known as Bubble Sort because with every complete iteration,the largest element bubbles up towards the last place or the highest index.
int main()
{
    int arr[11]={1,34,765,84,69,420,23,234,99,11,97};
    int n=11;
    for(int i=0;i<n-1;i++)
    {
        bool swap=false;
        for(int j=0;j<n-i-1;j++)
        {
            if(arr[j]>arr[j+1])  //Bubble Sort is the simplest sorting algorithm that works by repeatedly swapping the adjacent elements if they are in wrong order. 
            //therefore,for each iteration of i,we find the max element in each iteration and put it at the last of the range(limit of j),which reduces after each iteration of i. therefore we sort in
            //ascending order only but from the back. the last element is fixed first,then last-1,and so on....
            {
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
                swap=true;
            }
        }
        cout<<"Element sorted at "<<n-i<<"'th position is "<<arr[n-1-i]<<endl;
        if(swap==false)
            break;
    }
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
}