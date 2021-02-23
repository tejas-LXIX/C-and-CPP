#include<iostream>
#include<sstream>

using namespace std;

int main()
{
// String conversion to ANY DATA TYPE
    string s="123786.98";
    stringstream tatti;  //object of class stringstream
    tatti<<s;       //insertion operator << . inserts the string s into the stream.
    float x;
    tatti>>x;       //extraction operator >> . extracts data from the stream and stores it in the float variable x.
    cout<<x/71.635<<endl;

//converting any data type into a string.
    float y=69.4010;
    stringstream tatti123;
    tatti123<<y;
    string result;
    tatti123>>result;
    cout<<result+"yolo";  //observe that trailing zeroes are not included in the result string. IDK WHY!
}