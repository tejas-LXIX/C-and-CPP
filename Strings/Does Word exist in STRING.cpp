#include<iostream>
using namespace std;
//string::npos is very important
int main()
{
    string str="Hello How are you Geeks";
    string str1="How ";     //can also be used to find letters,like 'a' or 'y' etc. Just put the single letter in double quotes. Case Sensitive. EG: 'a' is not found in "YAY".
    auto index=str.find(str1);  //use auto if you dont know what type the function returns.
    if(index!=string::npos)
    {
        cout<<"str1 found inside str at index "<<index;
    }
}