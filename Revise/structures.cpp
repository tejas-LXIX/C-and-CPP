#include<iostream>
using namespace std;
//structures represent entities that are a collection of dissimilar data types. structures are derived data types(derived from the user)
struct book //structure type declaration does not tell the compiler to reserve any memory. memory is reserved only when variables are created that 
//are of the type struct book
{
    char name[10]; //elements of the structure
    float price;
    int pages;
};
void swap_pages(book &a,book &b) //pass by reference
{
    int temp=a.pages;
    a.pages=b.pages;
    b.pages=temp;
}
int main()
{
    book b2,b1={"HelloShit",25.6778,201};
    cout<<"Enter the details of book: ";
    cin>>b2.name;
    cin>>b2.price;
    cin>>b2.pages;
    swap_pages(b1,b2);
    cout<<b1.pages<<endl;
    cout<<b2.pages;
}