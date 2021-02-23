#include<iostream>
using namespace std;

class sally
{
private:
    int x;
    const int y;
public:
    sally(int no1,int no2);
    void print()
    {
        cout<<"regular variable is: "<<x<<"\n constant variable is: "<<y;
    }
};

int main()
{
    sally bois(3,7);
    bois.print();
}

sally::sally(int no1,int no2)
:y(no2)           /* this syntax of :y(no2) is only written where the function has been defined. not where the function has been prototyped.*/
{
    x=no1;
}


