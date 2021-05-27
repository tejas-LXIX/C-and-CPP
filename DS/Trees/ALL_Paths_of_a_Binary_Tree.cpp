#include <iostream>
#include <vector>
using namespace std;
 
vector<vector<int>> vec;    //to store the final result. Has all the paths.
// Data structure to store a binary tree node
struct TreeNode
{
    int val;
    TreeNode *left, *right;
 
    TreeNode(int val)
    {
        this->val=val;
        this->left = this->right = nullptr;
    }
};

bool isLeaf(TreeNode* node)
    {
        return (node->left == nullptr && node->right == nullptr);
    }
 
    // Recursive function to find paths from the root node to every leaf node
    void getRootToleafPaths(TreeNode* node, vector<int> &path)
    {
        //base case
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
 
// The main function to print paths from the root node to every leaf node
void allPaths(TreeNode* node)
{
    // vector to store root-to-leaf path
    vector<int> path;
    getRootToleafPaths(node, path);
}
 
int main()
{
    /* Construct the following tree
              1
            /   \
           /     \
          2       3
         / \     / \
        4   5   6   7
               /     \
              8       9
    */
 
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    root->right->left->left = new TreeNode(8);
    root->right->right->right = new TreeNode(9);
 
    // print all root-to-leaf paths
    allPaths(root);
    for(auto a:vec)
    {
        for(auto b:a)
            cout<<b<<" ";
        cout<<endl;
    }
 
    return 0;
}