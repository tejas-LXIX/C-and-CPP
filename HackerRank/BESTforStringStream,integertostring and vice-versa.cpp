#include <bits/stdc++.h>
#include<cmath>
//solution for Modified Kaprekar Numbers Question.

using namespace std;

// Complete the kaprekarNumbers function below.
void kaprekarNumbers(int p, int q)
{
    long long squared;
    string s,s1,s2;
    bool nigga=false;
    int x1,x2;
    for(long long num=p;num<=q;num++)
    {
        squared=pow(num,2);
        s=to_string(squared);
        if(s.length()==1)
        {
            s1="0";
            s2=s;
        }
        else
        {
            int mid=s.length()/2;
            s1=s.substr(0,mid); //starts from first digit. takes "mid" number of digits and puts it in s1. so,if 3 digit number hai squared,then mid is 1 (3/2). so s1 becomes s.substr(0,1) meaning that length of substring is only 1. so, starts at first digit(0 index) and only stores that single digit in s1.
            s2=s.substr(mid,s.length()-1); //(1,3-1) i.e (1,2). starts at index 1(second digit) and length of the substring is 3-1 i.e 2
        }
        x1=stoi(s1);
        x2=stoi(s2);
        if(x1+x2==num)
        {   nigga=true;
            cout<<num<<" ";
        }
    }
    if(nigga==false)
        cout<<"INVALID RANGE";
}

int main()
{
    int p;
    cin >> p;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    kaprekarNumbers(p, q);

    return 0;
}
