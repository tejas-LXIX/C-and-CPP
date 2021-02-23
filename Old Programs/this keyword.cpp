#include<iostream>
using namespace std;

class hannah
{
private:
    int h;
public:
    int setValue(int x)
    {
        h=x;
    }
    void printcrap()
    {//"this" is a keyword that stores the address of the current object that youre working with (gurl is that object here)
        cout<<"value of h is: "<<this ->h<<endl; //arrow pointer is used with a pointer to an object.
        cout<<"value of h is: "<<(*this).h;
    }
};

int main()
{
    hannah gurl;
    gurl.setValue(34);
    gurl.printcrap();
}
