#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


int main()
{
    vector<int> vec={1,2,3,4,5};
    vector<int>::iterator itr;
    for(itr=vec.begin();itr!=vec.end();itr++)
    {
        if(itr==vec.begin()+1)
        {}
        else
            cout<<*itr<<endl;
    }

/*In C++11, you say auto it1 = std::next(it, 1);.
Prior to that, you have to say something like:*/

    vector<int>::iterator itr1 = itr;   //if you want to set itr1 to point to the element after itr. itr1=itr+1 is not possible,hence we use advance.
    advance(itr1,1);
}
