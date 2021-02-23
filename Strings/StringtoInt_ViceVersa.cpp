#include <iostream>
#include<sstream>

using namespace std;

int main()
{
    //string to number
   string s="765.12361";
   stringstream ss;   //or just write stringstream ss(s).
   ss<<s;
   float x=0;
   ss>>x;
   cout<<x<<endl;
   
   //number to string
   int y=71;
   stringstream ss1;
   ss1<<y;
   string s1=ss1.str();
   cout<<s1<<endl;
   
   
   //do this. This is much easier.
   cout<<"EASIER WAY\n";
   s1=to_string(x);
   cout<<s1<<endl;
   float z=stof(s);   //stoi,stod bhi hai.
   cout<<z;
}