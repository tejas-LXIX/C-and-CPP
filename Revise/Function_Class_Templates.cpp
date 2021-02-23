#include<iostream>
using namespace std;
//templates are just like macros,i.e they are also substituted wherever required just like macros. Compiler does type checking before template expansion.
//templates allow functions and classes to operate with generic data types. So that a function/class only has to be written once and it would work for all 
//data types that are passed to in main(). Templates are used for functions that perform ekdum identical operations.
//a template creates a generic data type. See geeksforgeeks.org
//you can write class LMAO too instead of typename LMAO
//When we write any template based function or class, compiler creates a copy of that function
//class whenever compiler sees that being used for a new data type or new set of data types(in case of multiple template arguments).
//copies of the function template are made in the source code for each data type that is used for it in main().therefore,bahot saare data types ke saath use karoge
//toh code bloating will occur.
template <typename LMAO,typename LMAO1> //either use T/U(standard) or use names typed in CAPITALS for templates.
LMAO1 multiply(LMAO x,LMAO1 y)
{
    return x*y;
}

template <typename T,typename U> //class Template. You can assign default data types to the template too.
//<typename T,typename U=int> now,only <float> is enough. <float,int> likhne ki zarurat nahi hogi. But <T,U> ke jagah <T> will NOT WORK.
class Tejas
{
    private:
        T a;
        U b;
    public:
        Tejas(T x,U y)
        {
            a=x;
            b=y;
        }
        T greater();
};

template <typename T,typename U> //whenever you define a function outside a class,you need to write the template all over again.
T Tejas<T,U>::greater() //<T,U> is to tell C++ that the function's template parameter is the same one that we're using for the class.
{
    return a>b?a:b;
}
int main()
{
    cout<<multiply(34.45,57); //we dont need to explicitly tell what type of data we want to substitute when we use function template. khud hi infer ho jaata hai
    Tejas <float,int> obj(69.23,69); //whenever we're working with class template,we need to explicitly tell it what type of data we want to substitute
    //for T and U
    cout<<endl<<obj.greater();
}