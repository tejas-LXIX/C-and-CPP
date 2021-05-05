//regex_match() -This function returns true only when the entire sequence matches. Else returns false.

//regex_search() -This function returns true if the expression is found anywhere in the target sequence,even if the sequence contains more characters that are not part of the match before or after the match.

//regex_replace() -This function is used to replace the pattern matching to the regular expression with a string.
#include <iostream>
#include <regex>
  
using namespace std;
int main()
{
    string a = "GeeksForGeeks and GeeksPhorGeeks";
  
    // Here b is an object of regex (regular expression)
    regex b("(Geek)(.*)"); // Geeks followed by any character
  
    // regex_match function matches string a against regex b
    if ( regex_match(a, b) )
        cout << "String 'a' matches regular expression 'b' \n";
  
    // regex_match function for matching a range in string 
    // against regex b
    if ( regex_match(a.begin(), a.end()-3, b) )
        cout << "String 'a' matches with regular expression "
                "'b' in the range from 0 to string end\n";
        


    /*regex_search
    Suppose you create a regex object like : regex re("(geeks)(.*)") 
    Here no of capturing group is = 2 
    [ one is "geeks" and second is any character after "geeks" ].*/
    string sp("geeksforgeeks");
    regex re("(geeks)(.*)");
  
    // flag type for determining the matching behavior
    // && here it is for matches on strings.
    smatch match;   //HOLDS THE MATCHED EXPRESSIONS
  
    // we can use member function on match
    // to extract the matched pattern.
    if (regex_search(sp, match, re) == true) {
  
        // The size() member function indicates the
        // number of capturing groups plus one for the overall match
        // match size = Number of capturing group + 1
        // (.*) which "forgeeks" ).
        cout << "Match size = " << match.size() << endl;
  
        // Capturing group is index from 0 to match_size -1 
        // .....here 0 to 2
        // pattern at index 0 is the overall match "geeksforgeeks"
        // pattern at index 1 is the first capturing group "geeks"
        // pattern at index 2 is the 2nd capturing group "forgeeks"
  
        cout << "Whole match : " << match.str(0) << endl;
        cout << "First capturing group is '" << match.str(1)
             << "' which is captured at index " << match.position(1)
             << endl;
        cout << "Second capturing group is '" << match.str(2)
             << "' which is captured at index " << match.position(2)
             << endl;

        for (auto x : match)
		    cout << x << " ";
    }
    else {
        cout << "No match is found" << endl;
    }



    //regex_replace

    string s = "I am looking for GeeksForGeek GeeksForGeeker123 \n";
	
	// matches words beginning by "Geek"
	regex r("Geek[a-zA-z]+");
	
	string result;
	
	// regex_replace( ) for replacing the match with 'geek'
	regex_replace(back_inserter(result), s.begin(), s.end(),    //RATTA MAARNA PADEGA YE,NO OTHER OPTION!
				r, "geek");

	cout << result;

	return 0;
  
    return 0;
}