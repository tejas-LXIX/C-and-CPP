//https://www.careercup.com/question?id=5970560803143680 LINK FOR QUESTION
#include <iostream>

using namespace std;

int main()
{
    string s="abcde";
    int n=s.size();
    int k=2;
    int arr[2]={0}; //arr[0] will give count of normal characters,and arr[1] will give count of special characters CURRENTLY IN THE SLIDING WINDOW.
    string charValue = "10101111111111111111111111";
    int i=0,j=0,maxlen=0,specialCharFreq=0;
    while(j<n)
    {
        arr[charValue[s[j]-'a'] -'0']++;    //[s[j]-'a']-'0' isliye karna padhta hai kyunki s[j]-'a' returns the value of '0' or '1' as a character. that gets converted into int because of arr and so we get arr[48] for s[j]-'a'=0 and arr[49] for s[j]-'a'=1. iss reason ke liye we need to subtract '0' at the end to convert it into proper integer.
        specialCharFreq=arr[1];
        if(j-i+1-specialCharFreq>k)
        {
            arr[charValue[s[i]-'a']-'0']--; //remove the ith index from the window. So, the frequency of the type of this character reduces.
            i++;
        }
        maxlen=max(maxlen,j-i+1);
        j++;
    }
    cout<<maxlen;
}