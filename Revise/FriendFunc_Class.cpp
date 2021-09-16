#include<iostream>
using namespace std;

class Sally
{
    private:
        int x=10;
    public:
        void printx()
        {
            cout<<x;
        }
    
    friend void Sally_friend(Sally); //it can access all the private and protected members of Sally class
    friend class Nigga;
};

void Sally_friend(Sally obj)
{
    obj.x=35; //if friend nahi hota,you wouldnt have been able to access x using obj.x you'd have to write a function through which you could print out the
//value of x. so remember,friend functions/classes still do need an object of the class through which they can access the private members directly. 
    cout<<obj.x;
}
class Nigga
{
    public:     //Friend class also requires a base class object to be able to access the data members and methods of the base class through the base class object.
        void showSecret(Sally sa)
        {
            sa.x=1069;
            cout<<endl<<sa.x;
        }
};

int main()
{   
    Sally Tejas;
    Sally_friend(Tejas);
    Nigga Tejas1;
    Tejas1.showSecret(Tejas);
}