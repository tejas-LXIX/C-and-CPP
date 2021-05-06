#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

// Complete the countTriplets function below.
long countTriplets(vector<long> arr, long r)
{
    long result=0;
    unordered_map<long,long> mp;
    for(long i=0;i<arr.size();i++)
        mp[arr[i]]++;   //input all elements with their frequency in the map.
    unordered_map<long,long>::iterator itr=mp.begin(),itr1;
    for(itr;itr!=mp.end();itr++)
    {
        long val=itr->first;    //get the key value
        if(mp[val*r])   //if second element of gp (val*r) exists in the map.
        {
            if(mp[val*r*r])     //if third element of gp (val*r*r) exists in the map.
            {
                long largest_key=val;   //since the number of pairs possible is dependent on that number which occurs the most number of times.
                if(mp[val*r]>mp[largest_key])
                {
                    largest_key=val*r;
                }
                if(mp[val*r*r]>mp[largest_key])
                {
                    largest_key=val*r*r;
                }   
                result+=mp[largest_key];
                if((largest_key==val*r) || (largest_key==val*r*r))
                    result+=mp[largest_key];
                if((largest_key==val*r) && (largest_key==val*r*r))
                    result+=mp[largest_key];
                cout<<result<<endl;
            }
        }
    }
    return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nr_temp;
    getline(cin, nr_temp);

    vector<string> nr = split(rtrim(nr_temp));

    int n = stoi(nr[0]);

    long r = stol(nr[1]);

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split(rtrim(arr_temp_temp));

    vector<long> arr(n);

    for (int i = 0; i < n; i++) {
        long arr_item = stol(arr_temp[i]);

        arr[i] = arr_item;
    }

    long ans = countTriplets(arr, r);

    fout << ans << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
