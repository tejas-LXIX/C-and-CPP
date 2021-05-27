/* See https://www.geeksforgeeks.org/heap-using-stl-c/ for maxheap STL.
/*
A Heap is a special Tree-based data structure in which the tree is a COMPLETE BINARY tree.
A full binary tree (sometimes proper binary tree or 2-tree) is a tree in which every node other than the leaves has two children. 
A complete binary tree is a binary tree in which every level, except possibly the last, is completely filled, and all nodes are as far left as possible. 
Generally, Heaps can be of two types:

Max-Heap: In a Max-Heap the key present at the root node must be greatest among the keys present at all of it’s children. The same property must be recursively true for all sub-trees in that Binary Tree.
NOTHING OF THE SORT LIKE LEFT SIDE ELEMENT SHOULD BE SMALLER OR WHATEVER. NO! BST NAHI HAI YE. Simple si baat, the parent node of the tree and all subtrees must be greater than the rest of the elements in the subtree
Min-Heap: In a Min-Heap the key present at the root node must be minimum among the keys present at all of it’s children. The same property must be recursively true for all sub-trees in that Binary Tree.
*/
//implemented as an array
//if you want to use it in problem solving,USE PRIORITY QUEUE TO IMPLEMENT MAX_HEAP. SEE STLnigga FOLDER.
#include<iostream>
#include<math.h> //important to get the height of the heap.
using namespace std;


class MinHeap
{
    public:
        int *harr;  //pointer to heap array
        int capacity;   //capacity of heap,given by user at runtime
        int heap_size;  //current size of the heap(number of elements in the heap currently)
        MinHeap(int cap)
        {
            capacity=cap;
            heap_size=0;
            harr=new int[cap];
        }
        int parent(int i) { return (i-1)/2; }
  
        // to get index of left child of node at index i
        int left(int i) { return (2*i + 1); }
    
        // to get index of right child of node at index i
        int right(int i) { return (2*i + 2); }

        int getMin(){return harr[0];}

        void linearSearch(int val)
        {
            for(int i=0;i<heap_size;i++)
            {
                if(harr[i]==val)
                {
                    cout<<"Value found at index "<<i<<endl;
                    return;
                }
            }
            cout<<"Value not found ";
        }
        void printHeap()
        {
          for(int i=0;i<heap_size;i++)
            cout<<harr[i]<<" "; 
          cout<<endl;
        }
        int height()
        {
          return ceil(log2(heap_size+1))-1;   //we need math.h for this function. ceil returns the smallest integer greater than or equal to the passed parameter.
        }
        void insertKey(int val)
        {
          if(heap_size==capacity)
          {
            cout<<"Not enough space\n";
            return;
          }
          heap_size++;
          int i=heap_size-1;
          harr[i]=val;
          while(i && harr[parent(i)]>harr[i]) //keep swapping the entered element with its parent till the parent doesn't become smaller than the value
          {
            swap(harr[i],harr[parent(i)]);
            i=parent(i);
          }
        }
        void MinHeapify(int i)  //starts to heapify(reconstruct the heap) from the index i. O(logn) since heapfiy is called again recursively for only one side of the subtree.
        {
          int l=left(i);
          int r=right(i);
          int smallest=i;     //index of the smallest element among the root of the subtree starting at index 'i' and it's children.
          if(l<heap_size && harr[l]<harr[smallest])
            smallest=l;
          if(r<heap_size && harr[r]<harr[smallest])
            smallest=r;
          if(smallest!=i)
          {
            swap(harr[i],harr[smallest]);
            MinHeapify(smallest);   //to call the MinHeapify function for the subtree jahan pe swapping hui hai,this is because we don't know if the new root of the subtree is the smallest within that subtree or not.
          }
        }
        int extractMin()    //returns the min value of the heap i.e the root, and also deletes it from the heap. Since we remove the root,the heap structure is broken. so,we call MinHeapify(0) to recreate the heap from the broken structure.
        {
          if(heap_size<=0)    //when no elements present in the heap,return INT_MAX
            return INT_MAX;
          if(heap_size==1)    //one element present in heap,then return harr[0]
          {
            heap_size--;
            return harr[0];
          }
          int min_value=harr[0];
          harr[0]=harr[heap_size-1];  //change the value of root of the heap to the last element of the heap. So,we dont actually remove the root,we just change its value. And then since our heap_size has decreased,the last value of the heap which was copied into the root(duplicate of the value of root) is not considered. 
          heap_size--;    //reduce the size of the heap by 1.
          MinHeapify(0);  //recreate the heap from the broken structure. 0 is passed since we extracted the very first element in the heap array. so,we have to heapify from the root node itself.
          return min_value;
        }
        void decreaseKey(int i,int new_val) //DECREASES the value at index i of the heap,to new_val. It is assumed that new_val is smaller than harr[i].
//Usually used for deletion operation where INT_MIN is passed into new_val,so that the value to be deleted becomes INT_MIN, and then it goes up and becomes the root of the heap. Then,we call extractMin() to remove the root. HENCE DELETION IS DONE.
        {
          harr[i]=new_val;
          while(i && harr[i]<harr[parent(i)])   //this is a logn loop, just like a regular tree.
          {
            swap(harr[i],harr[parent(i)]);
            i=parent(i);
          }
        }
        void deleteKey(int i) //delete value at index i of the heap. O(logn),since ek decreaseKey ka while loop is O(logn),and then extractMin calls Heapify() which is also O(logn) recursion
        {
          decreaseKey(i,INT_MIN); //the value at index i of the heap becomes INT_MIN,so that it eventually reaches the root of the heap, wherein we call extractMin() to remove the root. Therefore deletion is done.
          extractMin();
        }
};

int main() {
  int size;
  cout << "Enter Size of Min Heap" << endl;
  cin >> size;
  MinHeap obj(size);
  cout << "Min Heap Created" << endl;

  int option, val;

  do {
    cout << "What operation do you want to perform? " <<
      " Select Option number. Enter 0 to exit." << endl;
    cout << "1. Insert Key/Node" << endl;
    cout << "2. Search Key/Node" << endl;
    cout << "3. Delete Key/Node" << endl;
    cout << "4. Get Min" << endl;
    cout << "5. Extract Min" << endl;
    cout << "6. Height of Heap" << endl;
    cout << "7. Print/Traversal Heap values" << endl;
    cout << "8. Clear Screen" << endl;
    cout << "0. Exit Program" << endl;

    cin >> option;

    switch (option) {
    case 0:
      break;
    case 1:
      cout << "INSERT Operation -" << endl;
      cout << "Enter VALUE to INSERT in HEAP: ";
      cin >> val;
      obj.insertKey(val);
      cout <<"Value inserted "<<endl;
      break;
    case 2:
      cout << "SEARCH Operation -" << endl;
      cout << "Enter VALUE to SEARCH in HEAP: ";
      cin >> val;
      obj.linearSearch(val);
      break;
    case 3:
      cout << "DELETE Operation -" << endl;
      cout << "Enter INDEX of Heap Array to DELETE: ";
      cin >> val;
      obj.deleteKey(val);
      break;
    case 4:
      cout << "GET Min value : " << obj.getMin();
      cout << endl;
      break;
    case 5:
      cout << "EXTRACT Min value : " << obj.extractMin();
      cout << endl;
      break;
    case 6:
      cout << "HEAP TREE HEIGHT : " << obj.height() << endl;
      break;

    case 7:
      cout << "PRINT Heap Array : " << endl;
      obj.printHeap();

      cout << endl;
      break;

    case 8:
      system("cls");
      break;

    default:
      cout << "Enter Proper Option number " << endl;
    }

  } while (option != 0);

  return 0;
}