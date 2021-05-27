#include<bits/stdc++.h>
using namespace std;
//https://www.youtube.com/watch?v=TKvbwPIOGCM
//https://www.geeksforgeeks.org/a-program-to-check-if-a-binary-tree-is-bst-or-not/
class Node
{
    public:
        int data;
        Node* left=NULL;
        Node* right=NULL;
        Node(int data)
        {
            this->data=data;
        }
};

bool isBSTUtil(Node* node,int min,int max)  //min and max represent the range of valid values of a particular node. If the node value does not fall b/w min and max, then we return false.
{
    if(node==NULL)
        return true;
    if(node->data<min || node->data>max)
        return false;
    else
    {
        return isBSTUtil(node->left,min,node->data-1) && isBSTUtil(node->right,node->data+1,max);
        
        //since in the LEFT subtree, the MIN value stays as it is, but the MAX value becomes equal to the value of the current node-1 i.e (node->data-1). Not node->data, since by definition itself, bst's have distinct keys.
        //This is because ALL nodes in the LEFT subtree must have a value SMALLER than the value of the current node.

        //since in the RIGHT subtree, the MAX value stays as it is, but the MIN value becomes equal to the value of the current node+1 i.e (node->data+1). Not node->data, since by definition itself, bst's have distinct keys.
        //This is because ALL nodes in THE RIGHT subtree must have a value LARGER than the value of the current node.
    }
}

bool isBST(Node* root)
{
    return isBSTUtil(root,INT_MIN,INT_MAX);
}
int main()
{
    Node *root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(5);
    root->left->left = new Node(1);     //make this 1 to get Is BST
    root->left->right = new Node(3);
     
    if(isBST(root))
        cout<<"Is BST";
    else
        cout<<"Not a BST";
         
    return 0;
}