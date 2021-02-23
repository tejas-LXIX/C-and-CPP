/*getline() function reads whole line of text that ends with new line or until the maximum limit is reached. getline() is the member function of istream class and has the syntax:

//istream& getline (istream&  is, string& str, char delim);  istream &is basically means that the first parameter must be of stringstream class.
Extracts characters from is and stores them into str until the delimitation character delim is found. agar delimiter naa do toh, \n becomes default delimiter.

//(buffer, stream_size, delimiter)
istream& getline(char*, int size, char='\n')  //char* is basically any C-style array.

// The delimiter character is considered as '\n'
istream& getline(char*, int size)
The function does the following operations:
1. Extracts character up to the delimiter.
2. Stores the characters in the buffer.
3. Maximum number of characters extracted is size – 1.
Note that the terminator(or delimiter) character can be ANY CHARACTER (like ‘ ‘, ‘, ‘ or any special character, etc.). The terminator character is read but not saved into a buffer, instead it is replaced by the null character.
*/
#include<iostream>
#include<sstream>
using namespace std;

int main()
{
    char str[20];
    //cin.getline() is a function to get input from the user and format it as required.
    cin.getline(str,5,',');     //the delimiter is ',' here. Give input Hel,lo. str will only store Hel because after Hel it encounters the delimiter ','. So it stops reading successive characters.
    for(int i=0;i<5;i++)
        cout<<str[i];
    string str1;
    stringstream ss(str);
    //getline() is a function to copy one stringstream into a string following a format.
    getline(ss,str1,',');       //copies the contents of ss into str1 till the delimiter , is encountered.
    cout<<endl<<str1;
}
//SEE TOKENIZING_A_STRING.cpp to see how getline is used.