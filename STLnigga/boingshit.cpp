#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    vector<int> vec;
    vec.push_back(7);
    vec.push_back(7);
    vec.push_back(7);
    vec.push_back(7);
    vec.push_back(7);
    vec.push_back(7);
    int n=vec.end()-vec.begin();
    int l=vec.size();
    cout<<n<<" "<<l;
}