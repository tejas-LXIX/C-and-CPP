//The idea is to use the fact that the inorder traversal of Binary Search Tree is sorted. So, just check if given array is sorted or not.
#include<iostream>
using namespace std;

bool isInorder(int arr[],int n)
{
    if(n==0 || n==1)
        return true;
    for(int i=0;i<n-1;i++)
        if(arr[i]>arr[i+1])
            return false;
    return true;
}
int main()
{
    int arr[] = { 19, 23, 22, 30, 45 };
    int n = sizeof(arr)/sizeof(arr[0]);
      
    if (isInorder(arr, n))
        cout << "Yes,this array is a preorder traversal of a binary tree.";
    else
        cout << "No,this array is NOT a preorder traversal of a binary tree.";
          
  return 0;
}