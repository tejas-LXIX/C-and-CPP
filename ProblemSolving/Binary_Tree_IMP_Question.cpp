/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
//https://leetcode.com/problems/pseudo-palindromic-paths-in-a-binary-tree/          WORKS FOR 53/56 testcases. Baaki pe timeout.
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> vec;    //vector of all paths.
    bool isLeaf(TreeNode* node)
    {
        return (node->left == nullptr && node->right == nullptr);
    }
 
    // Recursive function to find paths from the root node to every leaf node
    void getRootToleafPaths(TreeNode* node, vector<int> &path)
    {
        // base case
        if (node == nullptr) {
            return;
        }

        // include the current node to the path
        path.push_back(node->val);

        // if a leaf node is found, push the path
        if (isLeaf(node))
        {
            vec.push_back(path);
        }

        // recur for the left and right subtree
        getRootToleafPaths(node->left, path);
        getRootToleafPaths(node->right, path);

        // backtrack: remove the current node after the left, and right subtree are done.
        path.pop_back();
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        vector<int> path;
        getRootToleafPaths(root,path);
        int ans=0;
        /*for(auto a:vec)
        {
            for(auto b:a)
                cout<<b<<" ";
            cout<<endl;
        }           for printing each path,to verify the correctness.*/
        for(auto a:vec)
        {
            bool palindrome=true;
            int count[10]={0};    //count of each digit from 0-9. We don't need the count of 0 though.
            for(auto b:a)
            {
                count[b]++;
            }
            int odd = 0;
            for (int i=1;i<10;i++)
            {
                if (count[i] & 1)
                    odd++;
                if (odd > 1)
                    palindrome=false;
            }
            if(palindrome)
                ans++;
        }
        return ans;
    }
};