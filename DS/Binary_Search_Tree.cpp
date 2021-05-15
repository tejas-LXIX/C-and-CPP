/*A binary tree is just a tree where each node can have a MAXIMUM of two children. SEE DSA PHOTOS FOLDER. https://www.geeksforgeeks.org/binary-tree-set-3-types-of-binary-tree/
Max. number of nodes at level 'x'=2^x
Max, number of nodes in a binary tree of height 'h'=2^(h+1) -1
class Node
{
    Node *left,*right;          //for left child and right child respectively.
    int data;
};
*/

/*BINARY SEARCH TREE.
Binary Search Tree is a node-based binary tree data structure which has the following properties:

The left subtree of a node contains only nodes with keys lesser than the node’s key.
The right subtree of a node contains only nodes with keys greater than the node’s key.
The left and right subtree each must also be a binary search tree*/
#define SPACE 10
#include<iostream>
using namespace std;

class TreeNode
{
    public:
        int value;
        TreeNode *left,*right;
        TreeNode()
        {
            value=0;
            left=NULL;
            right=NULL;
        }
        TreeNode(int v)
        {
            value=v;
            left=NULL;
            right=NULL;
        }
};

class BST
{
    public:
        TreeNode* root;      //pointer to the root of the BST. baaki puri linking toh root ke aage se hojaayegi because of the left and right pointers of TreeNode class.
        BST()
        {
          root=NULL;
        }
        bool isTreeEmpty()
        {
            if(root==NULL)
              return true;
            return false;
        }
        void insertNode(TreeNode* new_node)
        {
            if(root==NULL)
            {
              root=new_node;
            }
            else
            {
                TreeNode* temp=root;
                while(temp!=NULL)
                {
                    if(new_node->value==temp->value)
                    {
                        cout<<"Duplicate values cannot be inserted\n";
                        return;
                    }
                    else if(new_node->value<temp->value && temp->left==NULL)
                    {
                        temp->left=new_node;
                        cout<<"Value inserted to the left\n";
                        return;
                    }
                    else if(new_node->value<temp->value)
                    {
                        temp=temp->left;
                    }
                    else if(new_node->value>temp->value && temp->right==NULL)
                    {
                        temp->right=new_node;
                        cout<<"Value inserted to the right\n";
                        return;
                    }
                    else
                    {
                        temp=temp->right;
                    }
                }
            }
        }

        //In all these recursive searches/prints, we have to pass a TreeNode* as an argument because we need it for the recursive calls(to traverse the left or the right of the tree as required,without any looping).
        //Jahan pe recursion nahi chahiye hota,udhar we can use the root of the object directly(since it is public) without needing it to be passed as a parameter,and then traverse using a loop.
        //THE THREE BELOW ARE ALL DFS
        void printPreorder(TreeNode *r)    //Preorder(NLR)(node-left-right). First time call karte toh root is passed as argument from main. uske baad it goes on its own.
        {
          if(r==NULL)
            return;
          cout<<r->value<<" ";       /* first print data of node */
          printPreorder(r->left);       /* then recur on left subtree */
          printPreorder(r->right);      /* then recur on right subtree */
        }

        void printInorder(TreeNode *r)    //Inorder(LNR)(left-node-right). First time call karte toh root is passed as argument from main. uske baad it goes on its own. PRINTS NODES IN ASCENDING ORDER FOR A BST.
        {
          if(r==NULL)
            return;
          printInorder(r->left);          /* first recur on left subtree */
          cout<<r->value<<" ";                 /* then print data of node */
          printInorder(r->right);         /* then recur on right subtree */
        }

        void printPostorder(TreeNode *r)    //Preorder(LRN)(left-right-node). First time call karte toh root is passed as argument from main. uske baad it goes on its own.
        {
          if(r==NULL)
            return;
          printPostorder(r->left);       /* first recur on left subtree */
          printPostorder(r->right);      /* then recur on right subtree */
          cout<<r->value<<" ";       /* then print data of node */
        }

        void print2D(TreeNode* r,int space)     //the tree is printed in a horizontal way
        {
          if(r==NULL)    //base case,to stop recursion at the leaf.
            return;
          space+=SPACE;   // Increase distance between levels   2
          print2D(r->right,space);      // Process right child first.
          cout<<endl;
          for(int i=SPACE;i<space;i++)
            cout<<" ";
          cout<<r->value<<endl;         //print the current node's value.
          print2D(r->left,space);       // Process left child 
        }

        TreeNode* iterativeSearch(int v)
        {
          if(root==NULL)
            return root;
          else
          {
            TreeNode* temp=root;
            while(temp!=NULL)
            {
              if(v==temp->value)
                return temp;
              else if(v<temp->value)     //if the value is lesser than the current node's value,then it has to be on the left side of the node. hence temp->left
                temp=temp->left;
              else
                temp=temp->right;        //if the value is greater than the current node's value,then it has to be on the right side of the node. hence temp->right
            }
            return NULL;
          }
        }

        TreeNode* recursiveSearch(TreeNode* r,int v)
        {
          if(r==NULL || r->value==v)     //to return if the value is found or we reach a leaf.
            return r;
          else if(v<r->value)
            recursiveSearch(r->left,v);
          else
            recursiveSearch(r->right,v);         
        }

        int height(TreeNode *r)
        {
          if(r==NULL)
            return -1;
          else
          {
            int lheight=height(r->left);
            int rheight=height(r->right);
            if(lheight>rheight)
              return lheight+1;
            return rheight+1;
          }
        }

              /* Print nodes at a given level */
        void printGivenLevel(TreeNode * r, int level)
        {
          if (r == NULL)
            return;
          else if (level == 0)
            cout << r -> value << " ";
          else // level > 0  
          {
            printGivenLevel(r -> left, level - 1);    //because of level-1,this parameter becomes zero at the required level. Then in the next recursive call due to the above else if,value print hojaati hai. See SimpleSnippets video on YT to understand.
            printGivenLevel(r -> right, level - 1);
          }
        }
        void printLevelOrderBFS(TreeNode * r) //BFS hai ye
        {
          int h = height(r);
          for (int i = 0; i <= h; i++)    //each iteration starts from the root node,and due to the value of i we go to the desired level.
            printGivenLevel(r, i);
        }
 
        TreeNode * minValueNode(TreeNode * node)
        {
          TreeNode * current = node;
          /* loop down to find the leftmost leaf */
          while (current -> left != NULL) {
            current = current -> left;
          }
          return current;
        }

        TreeNode* deleteNode(TreeNode* r,int v)      //Takes the root of the tree and the value to be deleted as parameters. See CodeSnippets video on YT if you want to understand.
        {
          if(r==NULL)         //base condition in recursion(for an exit condition).
            return r;
          else if(v<r->value)     //If value smaller,then go to left subtree.
            r->left=deleteNode(r->left,v);
          else if(v>r->value)
            r->right=deleteNode(r->right,v);    //If value larger,then go to right subtree.
          else        //if v is found
          {
            TreeNode* temp;
            if(r->left==NULL)           //Node with only right child or no child.
            {
              temp=r->right;
              delete r;
              return temp;
            }
            else if(r->right==NULL)     //Node with only left child.
            {
              temp=r->left;
              delete r;
              return temp;
            }
            else      //Node with two children.
            {
              temp=minValueNode(r->right);      //find minimum value in the RIGHT subtree.
              r->value=temp->value;             //copy the minimum value in RIGHT subtree into the node to be deleted. By doing this,we dont need to actually delete the node with two children. we just copy min value, and then delete the minvalue node. 
              r->right=deleteNode(r->right,temp->value);    //we need to delete the minvaluenode from the RIGHT subtree of the node which was supposed to be deleted initially. so,we pass the root of the right subtree as parameter,and minvalue as temp->value.
              //this recursion is a bit complicated when it comes to returning values,so see the photo in DSA folder and dry run this algorithm yourself.
            }            
          }
          return r;
        }
 
};        



int main()
{
  BST obj;
  int option, val;

  do {
    cout << "What operation do you want to perform? " <<
      " Select Option number. Enter 0 to exit." << endl;
    cout << "1. Insert Node" << endl;
    cout << "2. Search Node" << endl;
    cout << "3. Delete Node" << endl;
    cout << "4. Print/Traversal BST values" << endl;
    cout << "5. Height of Tree" << endl;
    cout << "6. Clear Screen" << endl;
    cout << "0. Exit Program" << endl;

    cin >> option;
    //Node n1;
    TreeNode * new_node = new TreeNode();

    switch (option) {
    case 0:
      break;
    case 1:
      cout << "INSERT" << endl;
      cout << "Enter VALUE of TREE NODE to INSERT in BST: ";
      cin >> val;
      new_node -> value = val;
      obj.insertNode(new_node);
      cout << endl;
      break;
    case 2:
      cout << "SEARCH" << endl;
      cout << "Enter VALUE of TREE NODE to SEARCH in BST: ";
      cin >> val;
      //new_node = obj.iterativeSearch(val);
      new_node = obj.recursiveSearch(obj.root, val);
      if (new_node != NULL) {
        cout << "Value found" << endl;
      } else {
        cout << "Value NOT found" << endl;
      }
      break;
    case 3:
      cout << "DELETE" << endl;
      cout << "Enter VALUE of TREE NODE to DELETE in BST: ";
      cin >> val;
      new_node = obj.iterativeSearch(val);
      if (new_node != NULL) {
        obj.deleteNode(obj.root, val);
        cout << "Value Deleted" << endl;
      } else {
        cout << "Value NOT found" << endl;
      }
      break;
    case 4:
      cout << "PRINT 2D: " << endl;
      obj.print2D(obj.root, 5);
      cout << endl;
      cout << "Print Level Order BFS: \n";
      obj.printLevelOrderBFS(obj.root);
      cout << endl;
      cout <<"PRE-ORDER: ";
      obj.printPreorder(obj.root);
      cout<<endl;
      cout <<"IN-ORDER: ";
      obj.printInorder(obj.root);
      cout<<endl;
      cout <<"POST-ORDER: ";
      obj.printPostorder(obj.root);
      break;
    case 5:
      cout << "TREE HEIGHT" << endl;
      cout << "Height : " << obj.height(obj.root) << endl;
      break;
    case 6:
      system("cls");
      break;
    default:
      cout << "Enter Proper Option number " << endl;
    }

  } while (option != 0);
}