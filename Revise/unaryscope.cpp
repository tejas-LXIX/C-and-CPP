#include<iostream>
using namespace std;

int x=36;
class Shitboi
{
    private:
        string s;
        //static int r; //  member "Shitboi::r" (declared at line 21) is inaccessible
    public:
        static int r;
        void printStatement();
        void setString(string e)  //cant have the passed parameter as s too,output nahi aata and confusion hojaayegi
        {
            s=e;
        }
        void printString()
        {
            cout<<" "<<s;
        }
};
void Shitboi::printStatement()
{
    cout<<"this is how it starts"<<endl;
}

int Shitboi::r=63;
/*  int Shitboi::tatti()  YOU CANNOT DECLARE FUNCTIONS OUTSIDE THE CLASS. YOU CAN ONLY DEFINE OUTSIDE.
{
    cout>>"my name is tatti";
}  */

int main()
{
    int x=5;
    cout<<x<<endl;
    cout<<::x<<endl;
    Shitboi tejas,bitch;
    tejas.printStatement();
    tejas.setString("helllo");
    bitch.setString("NIGGA");
    tejas.printString();
    bitch.printString();
    cout<<endl<<bitch.r;
}