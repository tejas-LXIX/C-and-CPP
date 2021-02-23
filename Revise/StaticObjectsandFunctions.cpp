#include<iostream>
using namespace std;
//static functions depend only on the class and are independent of the object.
//whereas virtual functions depend only on the object being pointed to and not on the class.
//This is why a function cannot be both virtual and static.
class Nigga
{
    private:
        static int l;
        int x=64;
    public:
        Nigga()
        {
            cout<<"inside constructor\n";
        }
        static void printMsg() //static member functions are allowed to access only the static data members or other static member functions of a class.
        {
            //l=x+3; will also not work
            cout<<"example of using static member functions without requiring an object\n";
            //print_shit(); not allowed
            cout<<l<<endl;
            //cout<<x; not allowed because x is non static,therefore cannot be accessed by static functions
            print_static_shit(); //allowed because print_static_shit is a static function
        }
        static void print_static_shit()
        {cout<<"print static shit\n";}
        void print_shit()
        {cout<<"print shit\n";
        cout<<l;}  //allowed since static data members can be accessed by normal functions
        ~Nigga()
        {
            cout<<"inside destructor\n";
        }
};
int Nigga::l=71;
int main()
{
    Nigga::printMsg();
    int x=0;
    if(x==0) //try this code without static and see the result
    {
        static Nigga nigga1; //the object nigga1 persists in memory even after we have left its scope(the if statement is the scope of the object)
//this is why end of main comes before destructor because the object is deleted at the end of the program,not at the end of its scope like ordinary variable
        nigga1.print_shit(); //static objects can call all member functions. no restriction
    }
    cout<<"\nEnd of main\n";
}