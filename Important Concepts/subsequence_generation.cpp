/*  C++ code to generate all possible subsequences.
    Time Complexity O(n * 2^n) */
#include<bits/stdc++.h>
using namespace std;
 
void printSubsequences(int arr[], int n)
{
    /* Number of subsequences is (2**n -1)*/
    unsigned int opsize = pow(2, n);        //EG: if 4 elements,then 2^4=16 subsequences.
 
    /* Run from counter 000..1 to 111..1*/
    for (int counter = 1; counter < opsize; counter++)
    {
        for (int j = 0; j < n; j++)
        {
            /* Check if jth bit in the counter is set
                If set then print jth element from arr[] */
            if (counter & (1<<j))       //the counter is responsible for selecting the elements in that specific subarray. For Example: if counter is 1101,then it will select the zeroth,second,and third element of the array in the subsequence.
            //How is it done? for 1101, when j=0 implies 1<<0 is 1. so 1101 & 1 will evaluate to 1. so arr[0] will be printed. when j=2 implies 1<<2 is 100. so 1101 & 100 will evaluate to 1,so arr[2] will also be printed. same for arr[3]. This is just one of the many values of counter that selects the elements to be included in that subsequence.
                cout << arr[j] << " ";
        }
        cout << endl;
    }
}
 
// Driver program
int main()
{
    int arr[] = {1, 2, 3, 4};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << "All Non-empty Subsequences\n";
    printSubsequences(arr, n);
    return 0;
}