#include<iostream>
using namespace std;
/*we have to shift elements to the left for deletion as it will occupy a space.*/

int main()
{
    int boi[6];
    int newboi[5];
    for(int i=0;i<6;i++)
    {
        cin>>boi[i];
    }
    int n;
    cout<<"enter index of element that has to be removed :";
    cin>>n;
    for(int i=n;i<6;i++)
    {
        boi[i]=boi[i+1]; /* eg: boi[3] will become boi[2]. therefore the third index element will shift to second index and fourth to third and so on....*/
        /* starting from the index of the element to be deleted,shifting each element to the right of the element to be deleted one place to the left. */
    } /* therefore at the end, the values of the last and the second last element become the same since boi[6] doesnt have any boi[7] it can become equal to.*/
    boi[6]=0;  /* setting the last element to zero so that you get the required list with the deleted element with a zero at the end.*/
    cout<<sizeof(boi)<<"\n";
    for(int i=0;i<5;i++) /* making a new array that will take all the values of the new array boi without taking the last value of zero. */
    {                    /* therefore we get the new array newboi which is the required array. */
        newboi[i]=boi[i];
        cout<<newboi[i]<<"\n";
    }
}
