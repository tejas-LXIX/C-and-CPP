/* A stringstream associates a string object with a stream allowing you to read from the string as if it were a stream (like cin).
Basic methods are –
clear() — to clear the stream
str() — to get and set string object whose content is present in stream.
operator << — add a string to the stringstream object.
operator >> — read something from the stringstream object,

stringstream class is extremely useful in parsing input. */
#include<iostream>
#include<sstream>  //to include the stringstream header file
#include<fstream>  //Stream class to both read and write from/to files.
using namespace std;

int main()
{

// C++ Input/Output Library -- Stream cout << "Hello" << endl;

// cout: a global object of ostream (typedef basic_ostream char> ostream)

// <<: ostream& ostream::operator<< (string v);

// endl: 'In + flush

// what is stream? Serial 10 Interface to external devices (file, stdin/stdout, network,

string s("Hello");

s[3] = 't'; // Random access

//String Stream

stringstream ss; // Stream without IO operation. Used to manipulate strings,formatting them in a specific way etc.

// read/write of string

ss<<89<<" HEX: "<<hex<<89<<" Oct: "<<oct<<89;
cout<<ss.str()<<endl; // ss now contains   89 Hex: 59 Oct: 131

int a, b, c;
string s1;

ss>>hex>>a; //Will read the first word,parse it as a hex number and then save it to a.
// FORMATTED INPUT WORKS TOKEN BY TOKEN. TOKENS ARE SEPRATED BY SPACES, TABS, NEWLINES. Therefore, a will get the hex value 89. Now,since a is int, therefore it will store a==137(int value of hex 89). It wont go further because after the token 89,we have a space so the input from the stringstream to variable a is stopped.

ss>>s1; // s1: "Hex:"   The token Hex: is passed into s1. Hex: ke baad ek space hai toh the input passing from ss to s1 is stopped.
ss>>dec>>b; // b=59

ss.ignore(6);       //ignore the next 6 characters in the stringstream.

ss>>oct>>c; //c==89
ss.str("");   //to clear a stringstream.
}


//Use ostringstream for formatted output. Use istringstream for formatted input. They convey the intent better,nothing else. SO, Best to use stringstream everywhere.





//cout(3] = 't'; // Error

/*{
ofstream of("MyLog.txt"); // Creates a new file for write, if the file didn't exist. sstream or fstream or ostream is just a matter of conveying intention. Open file for write after clearing the content of the file.
ofstream of("MyLog.txt",ofstream::app);    //Append text to the end of the file. Moves the output pointer to the end of the file.

of<<"Experience is the mother of wisdom"<<endl;

of<<234<<endl;
of<<2.3<<endl;
cout<<"HELLO";
}    //these brackets are to establish the scope of the ofstream object of. the file is opened here,and when it goes out of scope(after reaching the second bracket),of is destroyed leading to closing of the file.
}
/* RAII

1 IO Operation:

formatting the data <----> communicating the data with external devices

17 Software Engineer Principle: Low Coupling 1

etc.) */