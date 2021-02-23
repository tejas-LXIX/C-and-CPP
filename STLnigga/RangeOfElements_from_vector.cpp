#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    vector<int> vec={1,2,3,4,5,6,7,8,9};
    vector<int>::iterator itr;
    vector<int> vec2(vec.begin(),vec.begin()+3); // vec2 gets elements in the range [vec.begin(),vec.begin()+3)
    cout<<vec2.back()<<endl;
    cout<<vec2.front()<<endl;
    for(itr=vec2.begin();itr!=vec2.end();itr++)
    {cout<<*itr;}
}