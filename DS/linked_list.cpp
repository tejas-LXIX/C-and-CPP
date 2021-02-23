/*A linked list is represented by a pointer to the first node of the linked list. The first node is called the head.
//Basically,head is a pointer that points to the first node. If the linked list is empty, then the value of the head is NULL.
Each node in a list consists of at least two parts:
1) data
2) Pointer (Or Reference) to the next node
*/

//FOR TRAVERSAL,KEEP THE CHANGES LIMITED TO THE 2-D POINTER (POINTER TO POINTER) OF THE CURRENT.
//FOR MAKING CHANGES(DELETION,INSERTION etc.),MAKE CHANGES DIRECTLY TO THE POINTER POINTED TO BY CURRENT BY USING *CURRENT
#include<iostream>
using namespace std;

class Node
{
    public:
        int data; //data stored in each node.
        Node *next; //Node pointer that points to the next node.
};
void printLinkedList(Node *n)
{
    while(n) //exits when n becomes equal to NULL(the "next" of the last element.)
    {
        cout<<n->data<<endl;
        n=n->next;
    }
}
/*void pushatfront(Node *copiedhead,int newdata)
{
    Node *new_node=new Node();
    new_node->data=newdata;
    new_node->next=copiedhead;
    copiedhead=new_node;  //the copied head becomes equal to ptr. the actual head pointer therefore remains unchanged and isliye print nahi hota. so,we have to pass by reference.
    we pass the address of the actual head pointer to the function.
}*/

void pushatfront(Node **head_ref,int newvalue) //given a reference to head of a list,insert a new node at the front of the list.
{
    Node *new_node=new Node();
    new_node->data=newvalue;
    new_node->next=*head_ref; //now ptr->next points to the address of the initial head(initially first element)
    *head_ref=new_node; //value at address stored in head_ref i.e the value of pointer head now becomes equal to the new node.
}

void push_back(Node **head_ref,int newvalue) //given a reference to head of a list,append a new node at the end.
{
    Node* new_node=new Node();
    Node *last=*head_ref;  //becomes equal to head. points to the first element of the linked list.
    new_node->data=newvalue;
    new_node->next=NULL;
    if(*head_ref==NULL) //if the LL is empty
    {
        *head_ref=new_node;
        return;
    }//otherwise
    while(last->next!=NULL)
        last=last->next;
    last->next=new_node;
}
void insertintoLL(Node *prevnode,int newdata) //given a node prevnode,insert a new node after the given prevnode. agar yahan pe prevnode ke jagah sirf head node aur position di hoti,toh yahan bhi reference to head of a list dena padhta.
{ //this is O(1) insertion. deletion is also O(1) if the prevnode is given.
    if(prevnode==NULL)
        cout<<"The given previous node cannot be NULL";
    else
    {
        Node *new_node=new Node();
        new_node->data=newdata;
        new_node->next=prevnode->next;
        prevnode->next=new_node;  //prevnode ka "next" pointer is now equal to new_node which is the pointer to the new node that we are inserting.
        // therefore,next also now points to the new node which we inserted. 
    }
}
void deleteNode(Node **current,int value)  //given a reference(pointer to pointer) to the head of a list(stored in current here) and a value,delete the first occurrence of the value in the list.
{ //this is O(n) deletion because we iterate through each node in the linked list till we reach the required node. 
    if((*current)->data==value)  // if head node has the value which has to be deleted
    {
        Node *n=*current;  //now n and current point to the same Node pointer.
        *current=(*current)->next;
        delete n;  // delete releases the memory pointed to by n i.e it deletes the head node in this case.
        return;
    }
    while((*current)->next->data!=value)
    {
        current=&(*current)->next; //traversal
        if(*current==NULL)
        {
            cout<<"Element does not existin the  LL ";
            return;
        }
    }
    Node *n=(*current)->next;  //current is the node just before the node to be deleted. n  points to this node,for the purpose of being able to deallocate the memory.
    (*current)->next=(*current)->next->next;  //the pointer is changed directly,instead of its reference being changed.
    delete n;  // delete releases the memory pointed to by n i.e it deletes the node which has the required value in this case.
}
int size=0;
void insertintoanyposn(Node **current,int pos,int value)  //we pass the address of the head pointer to "current" here. but,we dont change the head in the function. it stays as it is.
//only the current changes.
// O(n) insertion
{ //can be used to insert element anywhere in the LL. start and end too.
    if(pos<1 || pos>size+1)
    {
        cout<<"Invalid position "<<endl;
        return;
    }
    while(pos--)
    {
        if(pos==0)
        {
            Node *new_node=new Node();
            new_node->data=value;
            new_node->next=*current;
            *current=new_node;
        }
        else
        {
            current=&(*current)->next; // we keep the changes to the 2d pointer "current" only. the head pointer isnt affected in any way.
        }
    }
    size++;
}
/* Function to delete the entire linked list */
void deleteList(Node** head_ref)  
{  
      
/* deref head_ref to get the real head */
Node* current = *head_ref;  
Node* next;  
  
while (current != NULL)  
{  
    next = current->next;  
    free(current);  
    current = next;  
}  
      
/* deref head_ref to affect the real head back
    in the caller. */
*head_ref = NULL;  
}  
int main()
{
    Node *head,*second,*third;
    head=new Node(); //head,second,third are pointers to Node objects.
    second=new Node();
    third=new Node();
    head->data=7;
    head->next=second;
    second->data=8;
    second->next=third;
    third->data=9;
    third->next=NULL; //to indicate that the linked list has terminated here.
    insertintoLL(second,76); //call by VALUE. second is passed to the function where second is copied to prevnode. basically prevnode becomes equal to second. they are two separate 
    //pointers but they point to the same Node object. isliye we are able to edit the values of new_node->data and new_node->next directly.
    //also this is why pushatfront does not work if you do same thing because its call by value and so copy of head
    //pushatfront(head,678); call by VALUE waala function which doesnt work as required.
    pushatfront(&head,678); //now this becomes a call by reference. since we are passing the address of head.
    push_back(&head,420); //this is also a call by reference.
    printLinkedList(head);
    size=6;
    insertintoanyposn(&head,5,7123);
    cout<<"NEW LL"<<endl;
    printLinkedList(head);
    cout<<"NEW LL"<<endl;
    deleteNode(&head,678);
    printLinkedList(head);
}