#include<iostream>
#include<set>
#include<algorithm>
#include<typeinfo>

using namespace std;

int lengthOfLongestSubstring(string s)
    {
        set<char> s1;
        set<char>::iterator itr;
        int n=s.length();
        int length=0,i=0,j=0;
        while(i<n && j<n)
        {
            itr=find(s1.begin(),s1.end(),s[j]);
            if(itr==s1.end())
            {
                s1.insert(s[j++]);
                cout<<s[j-1];
                length=max(length,j-i);
            }
            else
            {
                s1.erase(s[i++]);
            }
        }
        return length;
    }

int main()
{
    string s="dvdf";
    cout<<lengthOfLongestSubstring(s);
}