#include<iostream>
using namespace std;
/*This is the difference between friend function/class and derived class. Friend function/class can access the private members of the base class too,but not
directly. It can access only through an object of the base class.
Whereas derived class cannot access private members of base class,but it can access the protected members of the base class directly without requiring an
object of the base class.*/

class Sally
{
    private:
        int x;
    protected:
        int y=35;
    public:
        Sally()
        {cout<<"Constructor for sally base class"<<endl;}
        Sally(int,int);
        void printInfo()
        {
            cout<<x<<" "<<y<<endl;
        }
    friend class Sally_son;
};

class Sally_son
{
    private:
        int g;
    public:
        Sally_son()
        {}
        void PrintsonValue(Sally obj)
        {
            cout<<obj.x<<" "<<obj.y;
        }
};
Sally::Sally(int x,int y):x(x),y(y)
{}

class Sally_daughter : public Sally{
    private:
        int a;
    public:
        Sally_daughter()
        {cout<<"Constructor for sally daughter"<<endl;}
        void printValue()
        {
            //cout<<x;  wont work because x is private and derived classes dont inherit access to private members.
            cout<<y<<endl; //y is protected and therefore it's access is inherited by the derived class. so directly use kar sakte hai without requiring an object. if multiple classes have same name for a variable,then you can use cout<<Sally::y;
            printInfo();
        }
};
int main()
{
    Sally_daughter amyra;
    //cout<<mehak.y; y protected hai. so you cant use it in main obviously. but you can call the function printValue and then access y;
    amyra.printValue();
    Sally Leah_Gotti(61,69);
    Sally_son Johnny;
    Johnny.PrintsonValue(Leah_Gotti);
}