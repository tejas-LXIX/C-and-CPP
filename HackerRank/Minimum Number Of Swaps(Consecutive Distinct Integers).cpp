#include <bits/stdc++.h>
//IF you have non consecutive distinct integers,then no OPTION. SELECTION SORT LAGANA PADEHAGA WHICH IS O(n^2).
//https://www.hackerrank.com/challenges/minimum-swaps-2/problem?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=arrays
using namespace std;

vector<string> split_string(string);

// Complete the minimumSwaps function below.
int minimumSwaps(vector<int> arr)
{
    int n=arr.size(),swapcount=0,swapindex;
    map<int,int> mp;    //key is index. element value is number present at that index
    for(int i=1;i<=n;i++)
    {
        mp[i]=arr[i-1];
    }
    bool visited[n+1];
    memset(visited,false,sizeof(visited)/sizeof(visited[0]));
    /*logic for the loop is:
    Iterate through 1 to n. if the index i is not equal to the value stored at that index,then use the value at that index as the NEW INDEX(swapindex).
    IF swapindex has not been visited yet i.e visited[swapindex] is FALSE,then increment swapcount.
    Continue this process till you reach an element that has already been visited.(while loop does this job). YE HAI ALGORITHM. IDK YE KAISE AAYA BUT LMAOOOOOOO.
    */
    for(int i=1;i<=n;i++)
    {
        visited[i]=true;
        if(i!=mp[i])
        {
            swapindex=mp[i];
            if(!visited[swapindex])
            {
                visited[swapindex]=true;
                swapcount++;
                swapindex=mp[swapindex];
                while(!visited[swapindex])
                {
                    visited[swapindex]=true;
                    swapcount++;
                    swapindex=mp[swapindex];
                }
            }
        }
    }
    return swapcount;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split_string(arr_temp_temp);

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    int res = minimumSwaps(arr);

    fout << res << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
