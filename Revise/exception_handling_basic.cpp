#include<iostream>
using namespace std;

float divide(float &a,float &b)
{
    if(b==0)
    {
        //throw 0;
        //throw (float) 0; try these two also.
        throw "Math error:Divide by zero undefined";
        cout<<"This never executes";
    }
    return a/b;
}
int main()
{
    float n1,n2;
    cin>>n1>>n2;
    try{
        float result=divide(n1,n2);
        cout<<"the result is "<<result;
    }catch(const char *s) //reading from R to L, s is a pointer to a char const. const char *const s means, s is a const pointer to a char const.
    {
        cout<<s;
    }
    catch(int x)
    {
        cout<<"cannot divide by "<<x;
    }
    catch(...) //always write this general handler at the end of the all the other catch statements
    {
        cout<<"exception handler to handle all the generic cases that dont satisfy the above two handlers";
    }
}