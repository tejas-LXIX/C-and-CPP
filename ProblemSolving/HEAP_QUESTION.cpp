// https://leetcode.com/problems/find-k-pairs-with-smallest-sums/
class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        // THERE IS A FORMULA TO SOLVE ALL HEAPS QUESTION,IF THE QUES ASKED TO FIND SMALLEST, USE MAX HEAP OR IF ASKED LARGEST/BIGGEST, USE MIN HEAP AND THAT'S IT

        // make heap of pairs, push values, pop it when size > k
        // in the end, pop all values and psh it in a vector
        
        // notice the pair carefully, it's a pair within a pair, it's like pair<totalSum,<nums1,num2>>
        priority_queue<pair<int,pair<int,int>>> maxHeap; 
        // run double for loop to create all pairs,and push values based on the sum values
        for(int i=0;i<nums1.size();i++) {
            for(int j=0;j<nums2.size();j++) {
                int sum=nums1[i]+nums2[j]; // find totalsum
                maxHeap.push({sum,{nums1[i],nums2[j]}}); // ALWAYS PUSH BEFORE POPPING
                if(maxHeap.size()>k) { // once the size > k, since it's a maxheap, the biggest sum pair will be popped of, since we are popping the top value, THE MAXHEAP ALWAYS ACTS ON THE FIRST DATA STRUCTURE BY DEFAULT, our first value in the heap was an int, which was the sum of nums1 and nums2, so if a sum is high, it will come on top of heap and will get popped
                    maxHeap.pop();
                }
            }
        }
        
        // once we are out of this loop, we are only left with k elements,which will all be the minimum sum elements since all the higher ones have been popped off. You can simply push them in the vector.
        vector<vector<int>> res;
        while(!maxHeap.empty()) {
            res.push_back({maxHeap.top().second.first,maxHeap.top().second.second}); // this is the way to push pairs into a vector, notice the {}, vectors are pushed in that way, just enclose nuumbers in {} in the push_back function
            // maxHeap.top().second.first means, pair's top's value's second's part's first value
            // pair<totalSum,<nums1,num2>> got the idea?.
            maxHeap.pop();
        }
        return res;
    }
};