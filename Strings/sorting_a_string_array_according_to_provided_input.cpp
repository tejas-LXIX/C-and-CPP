#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

unordered_map<char,int> alph_order;

bool compare(string x,string y)
{
    for(int i=0;i<min(x.size(),y.size());i++)
    {
        if(alph_order[x[i]]==alph_order[y[i]])
            continue;
        return alph_order[x[i]]<alph_order[y[i]];
    }
    return x.length()<y.length();
}

int main()
{
    vector<string> vec={"hello","geeksforgeeks","kaaficomplex","iaintfuckinwithyou","yolo","westlandwapiti"};
    string str_order="qwertyuiopasdfghjklzxcvbnm";
    for(int i=0;i<str_order.length();i++)
    {
        alph_order[str_order[i]]=i;      //one by one,each letter is allocated a number. ye karne se ek naya alphabetical order banate hai hum jiske according we will sort the string vector vec.
    }
    sort(vec.begin(),vec.end(),compare);

    for(string x:vec)
    {
        cout<<x<<" ";
    }
}