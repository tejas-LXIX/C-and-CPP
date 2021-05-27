#include<iostream>
#include<stack>
#include<algorithm>
using namespace std;

bool isOperator(char c)
{
    if(c=='+' || c=='-' || c=='*' || c=='/' || c=='^')
        return true;
    return false;
}

bool isOperand(char c)
{
    if((c>='a' && c<='z') || (c>='A' && c<='Z'))
        return true;
    return false;
}

string PostfixtoInfix(string postfix)    //see the rules and pseudocode from the DSA Photos folder.
{
    stack <string> s;
    for(int i=0;i<postfix.length();i++)
    {
        if(isOperand(postfix[i]))
        {
            //s.push(postfix[i]);    does not work.
            string op(1,postfix[i]); //one of the constructors of "string" class. takes the character postfix[i],makes 1 copy of it, and then puts it into the string op. Done because we cannot directly push a character into a string stack.
            s.push(op);
            //s.push(string(1,postfix[i]));  short form of the above two statements together.
        }
        else if(isOperator(postfix[i]))
        {
            string operand1=s.top();
            s.pop();
            string operand2=s.top();
            s.pop();
            s.push("("+operand2+postfix[i]+operand1+")");  //EG: "ab+". here b is on top of the stack,so op1 is b,op2 is a. this is why we first write op2 and then op1 with the operator in between.
        }
    }
    return s.top();
}
int main()
{
    string infix,postfix;
    cout<<"Enter a POSTFIX Expression :"<<endl;
    cin>>postfix;
    cout<<"POSTFIX EXPRESSION: "<<postfix<<endl;
    infix=PostfixtoInfix(postfix);
    cout<<"INFIX EXPRESSION: "<<infix;
}