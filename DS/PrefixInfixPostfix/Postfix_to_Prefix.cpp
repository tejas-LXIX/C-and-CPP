#include<iostream>
#include<stack>
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

string PostfixtoPrefix(string postfix)
{
    stack<string> s;
    for(int i=0;i<postfix.length();i++)
    {
        if(isOperand(postfix[i]))
        {
            s.push(string(1,postfix[i]));
        }
        else if(isOperator(postfix[i]))
        {
            string operand1=s.top();
            s.pop();
            string operand2=s.top();
            s.pop();
            s.push(postfix[i]+operand2+operand1);
        }
    }
    return s.top();
}

int main()
{
    string prefix,postfix;
    cout<<"Enter a POSTFIX Expression :"<<endl;
    cin>>postfix;
    cout<<"POSTFIX EXPRESSION: "<<postfix<<endl;
    prefix=PostfixtoPrefix(postfix);
    cout<<"PREFIX EXPRESSION: "<<prefix;
}