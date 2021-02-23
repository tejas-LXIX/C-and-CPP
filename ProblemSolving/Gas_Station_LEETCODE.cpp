//slow solution. Runtime is 268 ms.


#include<bits/stdc++.h>
using namespace std;
int pathTester(vector<int>& gas, vector<int>& cost,int index)
    {
        int i=index,remgas=0;
        while(true)
        {
            if(remgas+gas[i]>=cost[i])
            {
                remgas+=gas[i]-cost[i];
                i++;
                if(i==gas.size())
                    i=0;
            }
            else
                return -1;
            if(i==index)
                return index;
        }
    }


int canCompleteCircuit(vector<int>& gas, vector<int>& cost)
    {
        int i=0,index;
        while(i<gas.size())
        {
            if(gas[i]-cost[i]>=0)
            {
                index=pathTester(gas,cost,i);           //tests for each individual path. If satisfies,then index is returned. else, we increment i and test for the next value.
                if(index==i)
                    return index;
                else 
                    i++;
            }
            else
                i++;
        }
        return -1;
    }

int main()
{
    vector<int> gas={2},cost={2};
    cout<<canCompleteCircuit(gas,cost);
}

/*MUCH BETTER SOLUTION

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        
        // There is no possible starting point if sum of difference berween gas and cost is negative
        int totalDiff = 0;
        vector<int> diff;
        int temp;
        
        for(int i = 0; i < gas.size(); i++) {
            temp = gas[i] - cost[i];
            totalDiff += temp;
            diff.push_back(temp);
        }
        
        if(totalDiff < 0) return -1;
        
        
        // Find the maximum sub array and it's starting index
        int currSub = 0, idx = 0;
        
        for(int i = 0; i < diff.size(); i++) {
            if(currSub < 0) {       //agar currsub<0 matlab that index cannot be the starting position,so idx=i ban jaata hai. ab agar iske baad currsub becomes +ve,this means idx has to be the starting position of the gas station. Because, idx se start karoge toh wapas pahunch paaoge.
                currSub = 0;
                idx = i;
            }
            currSub += diff[i];
            
        }
        
        return idx;
        
    }
}; */