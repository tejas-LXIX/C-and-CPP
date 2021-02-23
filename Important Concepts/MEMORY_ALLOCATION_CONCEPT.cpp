#include<iostream>
using namespace std;

int main()
{   /* The distinction to figure out if "new"(dynamic memory allocation) has to be used or not is,
    If its possible to find memory requirement at compile time(i.e memory requirement is not a function of runtime),then allocate memory on stack like we normally do
    If the amount of memory to be allocated isnt resolved at compile time,then you'll have to allocate memory in runtime using "new" */
    int n;
    cin>>n;
    int array1[n]; // proper way is int *ptr=new int[n] 
    for(int i=0;i<n;i++)
    {
        cout<<array1[i];
    } /* By the above logic,this code is not supposed to work. C++11 doesn't allow this. But this works because there is a feature in C99 or C11 standards “flexible array members”.
    and GCC compiler provides an extension to support them. But basically,never do this. undefined behaviour hai. */
//Follow this link to understand what "Memory allocated at Compile time" means https://stackoverflow.com/questions/21350478/what-does-memory-allocated-at-compile-time-really-mean
}
/*delete isnt required in the kind of coding I do,because at the end of the program all objects are destroyed and all allocated memroy is freed automatically.
but delete is useful in cases where the program doesn't stop working,for example in Operating System,embed systems with limited memroy etc.
delete ptr  */