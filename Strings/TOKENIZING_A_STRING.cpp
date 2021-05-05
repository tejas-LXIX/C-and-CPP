/*Tokenizing a string denotes splitting a string with respect to some delimiter(s). There are many ways to tokenize a string.
Using StringStream and getline() */
#include<iostream>
#include<sstream>
#include<vector>
using namespace std;

int main()
{
    string line="Geeks???For Geeks?is?a must?try.";
    vector<string> tokens;
    stringstream ss(line);
    string intermediate;
    while(getline(ss,intermediate,'?'))     //the data from stringstream ss is copied into string intermediate till the delimiter '?' is encountered. every successive getline() call first clears the string intermediate and then adds new data in it.
    {   //default delimiter is space " "
        tokens.push_back(intermediate);
    }
    for(int i=0;i<tokens.size();i++)
    {
        cout<<tokens[i]<<endl;
    }
    //this is one issue with getline. delimiters agar consecutively aagaye toh woh bhi token ban jaate hai. number of tokens will be number of consecutive delimiters-1

    //this concept can be used for any sort of delimiter.EG: It can be used to extract date,month and year from a string with DD-MM-YYYY format.
}