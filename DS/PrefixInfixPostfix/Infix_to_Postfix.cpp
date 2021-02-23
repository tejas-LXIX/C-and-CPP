#include<iostream>
#include<stack>
using namespace std;

bool isOperator(char c)
{
    if(c=='+' || c=='-' || c=='*' || c=='/' || c=='^')
        return true;
    return false;
}

int precedence(char c)
{
    if(c=='^')
        return 3;
    else if(c=='*' || c=='/')
        return 2;
    else if(c=='+' || c=='-')
        return 1;
    return -1;
}

string InfixtoPostfix(string infix)    //see the algo in DSA Photos folder
{
    stack<char> s;
    string postfix;
    for(int i=0;i<infix.length();i++)
    {
        if((infix[i]>='a' && infix[i]<='z') || (infix[i]>='A' && infix[i]<='Z'))
        {
            postfix+=infix[i];  //append the character to the postfix string.
        }
        else if(infix[i]=='(')
        {
            s.push(infix[i]);
        }
        else if(infix[i]==')')
        {
            while(!s.empty() && s.top()!='(')
            {
                postfix+=s.top();
                s.pop();
            }
            if(s.top()=='(')
                s.pop();
        }
        else if(isOperator(infix[i]))
        {
            if(s.empty())
                s.push(infix[i]);
            else
            {
                if(precedence(infix[i])>precedence(s.top()))
                {
                    s.push(infix[i]);
                }
                else if((precedence(infix[i])==precedence(s.top())) && infix[i]=='^')
                {
                    s.push(infix[i]);
                }
                else
                {
                    while(!s.empty() && precedence(infix[i])<=precedence(s.top()))
                    {
                       postfix+=s.top();
                       s.pop();
                    }
                    s.push(infix[i]);
                }
            }
        }
    }
    while(!s.empty())    //pop all the remaining characters on the stack.
    {
        postfix+=s.top();
        s.pop();
    }
    return postfix;
}

int main()
{
    string infix,postfix;
    cout<<"Enter an infix expression\n";
    cin>>infix;
    cout<<"INFIX EXPRESSION: "<<infix<<endl;
    postfix=InfixtoPostfix(infix);
    cout<<"POSTFIX EXPRESSION: "<<postfix<<endl;
}