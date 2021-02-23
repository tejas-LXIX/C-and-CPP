#include<iostream>
using namespace std;

class Node
{
    public:
        int data;
        Node* next;
        Node* prev;
};

void push(Node** head_ref,int new_data)     //adding a node at the front.
{
    /* 1. allocate node */
    Node* new_node=new Node;
    /* 2. put in the data  */
    new_node->data=new_data;
    /* 3. Make next of new node as head and previous as NULL */
    new_node->next=*head_ref;
    new_node->prev=NULL;
    /* 4. change prev of head node to new node */
    if(*head_ref!=NULL)     //for initial condition when the ll is empty.
        (*head_ref)->prev=new_node;  
    /* 5. move the head to point to the new node */
    *head_ref=new_node;
}

void append(Node** head_ref,int new_data)  /* Given a reference (pointer to pointer) to the head of a DLL and an int, appends a new node at the end  */
{
    Node* last=*head_ref;
    Node* new_node=new Node;    //create a new node
    new_node->data=new_data;    //assign data to this new node.
    new_node->next=NULL;    //since it will be last node.
    if(*head_ref==NULL)         // If the Linked List is empty, then make the new node as head.
    {
        new_node->prev=NULL;
        *head_ref=new_node;
        return;
    }
    
    while(last->next!=NULL)    /* 5. Else traverse till the last node */
        last=last->next;
    last->next=new_node;  /* 6. Change the next of last node */
    new_node->prev=last;    /* 7. Make last node as previous of new node */
    return;
}

/* Given a node as next_node, insert a new node before the given node */
void insertBefore(Node** head_ref,Node* next_node,int new_data)   //next_node is the pointer to the given node, before which the new node has to be added.
{
    if(next_node==NULL)  //Check if the next_node is NULL or not. If it’s NULL, return from the function because any new node can not be added before a NULL
        return;
    Node* new_node=new Node;   //Allocate memory for the new node, let it be called new_node. 
    new_node->data=new_data;   //Set new_node->data = new_data
    new_node->prev=next_node->prev;  //Set the previous pointer of this new_node as the previous node of the next_node, new_node->prev = next_node->prev
    next_node->prev=new_node;        //Set the previous pointer of the next_node as the new_node, next_node->prev = new_node
    new_node->next=next_node;        //Set the next pointer of this new_node as the next_node, new_node->next = next_node;
    if(new_node->prev!=NULL)    //If the previous node of the new_node is not NULL, then set the next pointer of this previous node as new_node, new_node->prev->next = new_node
        new_node->prev->next=new_node;
    else    //Else, if the prev of new_node is NULL, it will be the new head node. So, make (*head_ref) = new_node.
    {
        *head_ref=new_node;
    }
}

void insertAfter(Node* prev_node,int new_data) /* Given a node as prev_node, insert a new node after the given node */
{
/*1. check if the given prev_node is NULL */
    if (prev_node == NULL)
    { 
        cout<<"the given previous node cannot be NULL"; 
        return;
    }
    Node* new_node=new Node;
    new_node->data=new_data;
    new_node->next=prev_node->next;     /*Make next of new node as next of prev_node */
    new_node->prev=prev_node;       /*Make prev_node as previous of new_node */
    prev_node->next=new_node;       /*Make the next of prev_node as new_node */
    if(new_node->next!=NULL)        /*Change previous of new_node's next node */
        new_node->next->prev=new_node;
}
void printLL(Node* node)  
{  
    Node* last;  
    cout<<"\nTraversal in forward direction\n";
    while(node!=NULL)
    {  
        cout<<node->data<<endl;
        last=node;  
        node=node->next;  
    }  
  
    cout<<"Traversal in reverse direction\n";  
    while(last!=NULL)
    {
        cout<<last->data<<endl;  
        last=last->prev;  
    }  
}

void deleteNode(Node** head_ref,Node* del) /* Function to delete a node in a Doubly Linked List. head_ref --> pointer to head node pointer. del --> pointer to node to be deleted. */
{
    if(*head_ref==NULL || del==NULL)
        return;
    if(*head_ref==del)
        *head_ref=(*head_ref)->next;  //If node to be deleted is head node, then change the head pointer to next current head. 
    if(del->next!=NULL)      /* Change next only if node to be deleted is NOT the last node */
        del->next->prev=del->prev;
    if(del->prev!=NULL)      /* Change prev only if node to be deleted is NOT the first node */
        del->prev->next=del->next;   
        //If the node to be deleted is the last node,then the third IF statement won't be executed. And in the above if statement,the node previous to the last node will have it's next 
        //pointer pointing to the next of del,which will be NULL in this case (since del is equal to the last node,)
    delete del;
}

void deleteNodeAtGivenPos(Node** head_ref, int n)
{
    /* if list in NULL or invalid position is given */
    if (*head_ref == NULL || n <= 0)
        return;
    Node* current = *head_ref;
    int i;
    /* traverse up to the node at position 'n' from
       the beginning */
    for (int i = 1; current != NULL && i < n; i++)
        current = current->next;
    /* if 'n' is greater than the number of nodes
       in the doubly linked list */
    if (current == NULL)
        return;
 
    /* delete the node pointed to by 'current' */
    deleteNode(head_ref, current);
}

int main()
{
    Node* head_ref=NULL;    //start with empty linked list
    push(&head_ref,69);
    push(&head_ref,420);
    push(&head_ref,666);
    insertBefore(&head_ref,head_ref->next->next,2507);
    insertAfter(head_ref,2001);
    printLL(head_ref);
    cout<<"Done\n";
    deleteNode(&head_ref,head_ref->next->next->next->next);  //delete the last node(since we have only 5 elements in the LL). deletes 69.
    deleteNodeAtGivenPos(&head_ref,2);  //delete node at second position.
    printLL(head_ref);
    cout<<"\nTOO EZ";
}