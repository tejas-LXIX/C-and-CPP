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
        void MinHeapify(int i)  //starts to heapify(RECONSTRUCT the heap) from the index i (element at index i and it's subtree). O(logn) since heapfiy is called again recursively for only one side of the subtree.
        //MinHeapify does NOT CREATE the heap,it just reconstructs it. Creating the heap toh insertion se hi hoti rehti hai.
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



        void getUnsortedArray()
        {
            for(int i=0;i<capacity;i++)
            {
                int value;
                cin>>value;
                insertKey(value);
                cout<<value<<" inserted"<<endl;
            }   //this CREATES the min heap of the input elements.
        }
        void heapSort()
        {
            for(int i=0;i<capacity;i++)     //not heap_size because heap_size keeps getting decremented whenever we call extractMin().
            {
                cout<<extractMin()<<" ";    //extracts the minvalue from the heap every time,and prints it. extractMin() automatically handles the MinHeapify process too.
            }
        }
};

int main()
{
    int size;
    cout<<"Enter the size of the array"<<endl;
    cin>>size;
    MinHeap obj(size);
    obj.getUnsortedArray();
    obj.heapSort();
}