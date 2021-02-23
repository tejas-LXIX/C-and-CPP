#include<iostream>
#include<stack>
#include<algorithm>
using namespace std;

bool isOperand(char c)
{
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
        return true;
    return false;
}

bool isOperator(char c)
{
    if(c=='+' || c=='-' || c=='*' || c=='/' || c=='^')
        return true;
    return false;
}

string PrefixtoPostfix(string prefix)
{
    reverse(prefix.begin(),prefix.end());
    stack<string> s;
    for(int i=0;i<prefix.length();i++)
    {
        if(isOperand(prefix[i]))
        {
            s.push(string(1,prefix[i]));
        }
        else if(isOperator(prefix[i]))
        {
            string operand1=s.top();
            s.pop();
            string operand2=s.top();
            s.pop();
            s.push(operand1+operand2+prefix[i]);
        }
    }
    return s.top();
}

int main()
{
    string prefix,postfix;
    cout<<"Enter a POSTFIX Expression :"<<endl;
    cin>>prefix;
    cout<<"PREFIX EXPRESSION: "<<prefix<<endl;
    postfix=PrefixtoPostfix(prefix);
    cout<<"POSTFIX EXPRESSION: "<<postfix;
}