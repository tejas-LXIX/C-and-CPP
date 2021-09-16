/* C++ code to generate all possible subsequences.
	Time Complexity O(n * 2^n) */
#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> printSubsequences(int arr[], int n)
{
    set<vector<int>> st;    //to generate distinct subsequences. Remove it if you want all subsequences.
  	vector<vector<int>> result;
	/* Number of subsequences is (2**n -1)*/
	unsigned int opsize = pow(2, n);

	/* Run from counter 000..1 to 111..1*/
	for (int counter = 1; counter < opsize; counter++)
	{
      vector<int> temp;
		for (int j = 0; j < n; j++)
		{
			/* Check if jth bit in the counter is set
				If set then print jth element from arr[] */
			if (counter & (1<<j))
				temp.push_back(arr[j]);
		}
        if(st.find(temp)==st.end())
        {
            st.insert(temp);
		    result.push_back(temp);
        }
	}
    return result;
}

// Driver program
int main()
{
	int arr[] = {1, 2, 3, 3};
	int n = sizeof(arr)/sizeof(arr[0]);
	cout << "All Non-empty Subsequences\n";
	vector<vector<int>> result=printSubsequences(arr, n);
  	for(int i=0;i<result.size();i++)
    {
        for(int j=0;j<result[i].size();j++)
            cout<<result[i][j]<<" ";
        cout<<endl;
    }
	return 0;
}
