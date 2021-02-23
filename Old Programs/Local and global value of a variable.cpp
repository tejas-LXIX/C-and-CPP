#include <iostream>
using namespace std;

int i=1;
int tatti();

int main() /* the value of i has only been changed for whatever we do inside the main function. the global value of i=1 is still used for anything outside this function.*/
{
    int i=25;
    cout<<i<<"\n";
    tatti();
}

int tatti()
{
    cout<<i;
}
