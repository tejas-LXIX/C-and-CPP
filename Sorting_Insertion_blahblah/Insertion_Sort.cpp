#include<iostream>
#include<ctime>
using namespace std;

//Time Complexity is O(n^2). best case is O(n).
/*Insertion sort is a simple sorting algorithm that works similar to the way you sort playing cards in your hands. 
The array is virtually split into a sorted and an unsorted part.
Values from the unsorted part are picked and placed at the correct position in the sorted part*/

/*To sort an array of size n in ascending order:
1: Iterate from arr[1] to arr[n] over the array.
2: Compare the current element (key) to its predecessor.
3: If the key element is smaller than its predecessor, compare it to the elements before. Move the greater elements one position up to make space for the swapped element.*/

//see GFG to understand how this works
void insertionsort(int arr[],int n)
{
    int val;
    for(int i=1;i<n;i++)
    {
        val=arr[i];
        int j=i-1;
        while(j>=0 && arr[j]>val)
        {
            arr[j+1]=arr[j]; //shifting all elements greater than val one position forward to make space for val. The loopn exits as soon as one value is lesser than val. This is because the left side array is always sorted. so,if the condition fails for one element,then it will fail for all elementfs before it too.
            j--;
        }
        arr[j+1]=val;
    }
}

int main()
{
    int array[19];
    srand(time(0));  //to randomise the inputs given to the array as input
    for(int i=0;i<19;i++)
    {
        int val=rand();
        array[i]=val;
    }
    insertionsort(array,19);    //array is passed as a pointer to functions by default.
    for(int i=0;i<19;i++)
    {
        cout<<array[i]<<" ";
    }
}