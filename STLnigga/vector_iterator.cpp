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
}
