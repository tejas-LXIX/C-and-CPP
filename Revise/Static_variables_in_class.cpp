#include<iostream>
using namespace std;

class Tejas
{
    public:
        //static int x=11; YOU JUST CANNOT DO THIS
        static int x;
        int y=3;

};
int main()
{
    Tejas object1;
    Tejas object2;
    cout<<object1.x<<" "<<object2.x<<endl;
    object1.x=6;
    cout<<object1.x<<endl;
    cout<<object2.x<<endl;
    object2.x=71;
    cout<<object2.x<<endl;
    object1.y=4;
    cout<<object1.y<<endl;
    cout<<object2.y;
}
/*the static variables in a class are shared by the objects. Therefore,only one variable exists for the class and therefore for all the objects.
so changing the value of static variable for one object actually changes it for the entire class and for all the objects.*/
int Tejas::x=35; //VERY VERY IMPORTANT.a static variable inside a class should be initialized explicitly by the user using the class name and 
//scope resolution operator outside the class