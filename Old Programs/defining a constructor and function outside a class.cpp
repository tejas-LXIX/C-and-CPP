#include<iostream>
using namespace std;

class sally
{
public:
    sally();   /* A constructor never has any return type. A constructor never returns any data type.*/
    int printcrap();

};

sally::sally()
{
    cout<<"defining a constructor outside class\n";
}

int sally::printcrap()
{
    cout<<"defining a function outside a class";
}
int main()
{
    sally tattu;
    tattu.printcrap();
    return 0;
}
