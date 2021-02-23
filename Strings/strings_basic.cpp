// Constructors

string s1("Hello");
string s2("Hello", 3); // s2: Hel
string s3(s1, 2); // s3: 1lo
string s4(s1, 2, 2); // s4: 11
string s5(5, 'a'); // s5: "aaaaa"
string s6({'a', 'b', 'c'}); // s6: "abc"

// Size
s1 = "Goodbye";
s1. size(); s1.length(); // Synonymous, both returns 7
s1.capacity(); // size of storage space currently allocated to si
s1.reserve(100); // 100 chars
s1.reserve(5); // s1: Goodbye $1.size() ==> s1.capacity() ==7
s1. shrink_to_fit(); // shrink the capacity to hold the content
s1.resize(9); // s1: Goodbye\0\0
s1.resize(12, 'x'); // s1: Goodbye\0\0xxx       s1.size() ==12
s1.resize(3); // s1: Goo


//Single Element Access

s1 = "Goodbye";

s1[2]; // 'o'

s1[2] = 'x'; // Goxdbye

s1. at (2) = 'y'; // Goydbye

s1. at(20); // throw exception of out_of_range s1[20]; // undefined behavior

s1. front(); // 'G'

s1. back(); // 'e'
s1. push_back('z');

s1. pop_back ();

s1. begin();

s1.end ();

// Like vector, string doesn't have push_front and pop_front()

string s3(s1.begin(), s1.begin()+3); //s3: Goo


// Ranged Access

// assign, append, insert, replace
string s2 = "Dragon Land";

s1.assign(s2); // s1 = s2;
s1.assign(s2, 2, 4); // s1: agon            3 parameters pass karoge toh, the second one is index,third one is size.

s1. assign("wisdom"); // s1: Wisdom
s1.assign("Wisdom", 3); // s1: Wis          2 parameters pass karoge toh, the second one is size.
//s1.assign(s2, 3); // Error

s1. assign(3, 'x'); // s1: "XXX" 
s1. assign({'a', 'b', 'c'}); // s1: abc

s1. append (" def"); // s1: abc def 
s1.insert(2, "mountain", 4); // s1: abmounc def 
s1.replace(2, 5, s2, 3, 3); // s1: abgon def      starting from index 2,5 letters of s1 are replaced by (starting from index 3,3 letters of s2).

s1.erase(1, 4); // s1: a def 
s2. substr(2, 4); // agon

s1 = "abc";

s1.c_str(); // "abcle"

s1.data(); // "abc"

s1. swap(s2);


// Member Function Algorithms: copy, find, compare

s1 = "abcdefg"; char buf[20];

size_t len = s1.copy(buf, 3); // buf: abc len==3 
len = s1.copy(buf, 4, 2); // buf: cdef and len == 4    Only this is an exception to the above rule of THE SECOND PARAMETER BEING INDEX,THIRD PARAMETER BEING SIZE(NUMBER OF LETTERS). 


s1 = "If a job is worth doing, it's worth doing well";

size_t found = s1.find("doing"); // found == 17
found = s1.find("doing", 20); // found == 35

found = s1.find("doing well", 0); // found == 35

found = s1.find("doing well", 0, 5); // found == 17

found = s1.find_first_of("doing"); // found == 6   first character in s1 that is 'd' or 'o' or 'i' or 'n' or 'g'.

found = si.find_first_of("doing", 10); // found == 12 found = s1.find_first_of("doing", 10, 1); // found == 17

found = s1.find_last_of("doing"); // found == 39 s1.find first not of("doing"); // found

found found = s1.find_last_not_of("doing"); // found == 44  //returns last character if it is not in "doing".

s1.compare(s2); // return postive if (si > s2); negative if (s1 < s2); e if ($2 == s2) if ($1 > s2) {} // if (s1.compare(s2) > e)

s1.compare(3, 2, s2);

string ss = s1+ s2;



// Non-member functions 
cout << s1 << endl;

cin >> s1; 
getline(cin, s1); // default delimeter of '\n'
getline(cin, s1, ';'); // delimeter is ';"

// convert a number into a string

s1 = to string(8);

s1 = to_string(2.3e7); // s1: 2300ee00.eeeeee si = to string(exa4); // s1: 164

s1 = to string (034); // s1: 28

// convert a string into a number s1 = "198";

int i = stoi(51); // i: 190

s1 = "199 monkeys";

size_t pos;

i = stoi(si, &pos); // i: 19e

si = "a monkey";

pos==3

i = stoi(51, &pos); // exception of invalid argument i = stoi(si, &pos, 16); // i=-10

// stol, stod, stof, etc