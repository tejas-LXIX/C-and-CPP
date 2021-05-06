#include <iostream>
#include <string>
#include <sstream>
#include <exception>
using namespace std;

class BadLengthException:public exception //user defined exception class. inherits from the predefined "exception" class.
{
    int n;
    public:
        BadLengthException(int s)
        {
            n=s;
        }
        string what() //overloading the virtual function what() defined in the class exception
        {
            stringstream s;
            s<<n;
            return s.str();
        }

};


bool checkUsername(string username) {
	bool isValid = true;
	int n = username.length();
	if(n < 5) {
		BadLengthException lmao(n);
		throw lmao;
		//throw BadLengthException(n);   instead of the above,you can also do this. Implicitly creates an object of BadLengthException class.
		//Just simply throw a BadLengthException object without having to explicitly create its object. So,always do this.
	}
	for(int i = 0; i < n-1; i++) {
		if(username[i] == 'w' && username[i+1] == 'w') {
			isValid = false;
		}
	}
	return isValid;
}

int main() {
	int T; cin >> T;
	while(T--) {
		string username;
		cin >> username;
		try {
			bool isValid = checkUsername(username);
			if(isValid) {
				cout << "Valid" << '\n';
			} else {
				cout << "Invalid" << '\n';
			}
		} catch (BadLengthException e) {
			cout << "Too short: " << e.what() << '\n'; //e.what() will print the value of 'n' which is basically the number of letters in the username.
		}
	}
	return 0;
}