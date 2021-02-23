#include<iostream>
using namespace std;

class sally
{
private:
    int x;
    int y;
public:
    int goodboi(int x,int y) /*you can have same variable name defined inside the class and also as a parameter. wont have any issues.*/
    {
        x=x;
        y=y;
        return x+y;
    }
};

int main()
{
    sally boi;
    cout<<boi.goodboi(3,5);
}
