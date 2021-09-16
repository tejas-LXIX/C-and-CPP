#include<iostream>
using namespace std;

class Value
{
    public:
        int i=15;
};
class Test
{
    public:
        int i;
        Value *v,*val;
        void first()
        {
            i=5;
            v=new Value;
            v->i=25;
            second(v,i);
            cout<<v->i<<endl;
        }
        void second(Value *v,int i)
        {
            i=0;
            v->i=20;
            val=new Value;
            v=val;
            cout<<v->i<<" "<<i<<endl;
        }
};

int main()
{
    Test t;
    t.first();
}