#include<iostream>
using namespace std;
/* we have to shift elements to the right for insertion as it will make up a new space for an element to be inserted.*/

int main()
{
    cout<<"enter number of elements in array :";
    int n;
    cin>>n;
    int boi[n];
    cout<<"enter all the elements :"<<"\n";
    for(int i=0;i<n;i++)
    {
        cin>>boi[i];
    }
    int p;
    cout<<"enter index of array where you want to insert an element :";
    cin>>p;
    for(int i=n;i>p;i--)
    {
       boi[i]=boi[i-1]; /*eg: third index element will go to fourth index and so on.... therefor the whole array ONLY from where we want to insert is shifted one place to the right.*/
    }
    cout<<"enter value of element you want to insert :";
    cin>>boi[p];
    for(int i=0;i<n+1;i++)
    {
        cout<<boi[i]<<"\n";
    }

}
