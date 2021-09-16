/* 9 0 2 1 3 4 7 8 6
    target sum=9
*/
// 0 1 2 3 4 6 7 8 9
#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> ans;

void findNumber(vector<int> &vec,int target,int n)
{
    unordered_set<int> st;
    for(int i=0;i<n;i++)
    {
        st.insert(vec[i]);
    }
    sort(vec.begin(),vec.end());
    int start=0,end=n-1;

    while(start<end)
    {
        int sum=vec[start]+vec[end];
        if(st.find(target-sum)!=st.end())
        {
            auto itr=st.find(target-sum);
            if(vec[start]!=*itr && vec[end]!=*itr)
            {
                ans.push_back({vec[start],vec[end],*itr});
                start++,end--;
            }
            else if(sum<target)
                start++;
            else
                end--;
        }
        else if(sum<target)
            start++;
        else
            end--;
    }
}

int main()
{
    vector<int> vec={9,0,2,1,3,4,7,8,6};
    int target=9;
    findNumber(vec,target,9);
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i][0]<<" "<<ans[i][1]<<" "<<ans[i][2];
        cout<<endl;
    }
}