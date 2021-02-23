#include<iostream>

using namespace std;

//last is an external pointer that points to the last node of the list. If we have a pointer last pointing to the last node, then last -> next will point to the first node. 
class Node
{
    public:
        int data;
        Node* next;
};

// Insertion in an empty List. Initially, when the list is empty, last pointer will be NULL. 
Node* addtoEmpty(Node* last,int data)  //only for adding first element to empty list.
{
    if(last!=NULL)  
        return last;
    Node* new_node=new Node;
    new_node->data=data;
    last=new_node;
    last->next=last;  //points to itself. Note : list was empty. We link single node to itself.
    return last;
}

Node* addBegin(Node* last,int data)  //Function to insert node in the beginning of the List.
{
    if(last==NULL)
        return addtoEmpty(last,data);
    Node* new_node=new Node;
    new_node->data=data;
    new_node->next=last->next;
    last->next=new_node;
    return last;
}

Node* addEnd(Node* last,int data)
{
    if(last==NULL)
        return addtoEmpty(last,data);
    Node* new_node=new Node;
    new_node->data=data;
    new_node->next=last->next;
    last->next=new_node;
    last=new_node;
    return last;
}

Node* addAfter(Node* last,int data,int item)    //the new node is added after the existing node whose data==item. so basically we search for the node which holds item,and then we insert the new node after it.
{
    if(last==NULL)
        return NULL;
    Node* new_node=new Node;    //new_node is an object of Node class. has its own next pointer and int data.
    Node* p;        //p is only a pointer to a Node object. p->next here means that the "next" pointer of the Node object pointed to by the pointer "p".
    p=last->next;   //head of the list
    do
    {
        if(p->data==item)
        {
            new_node->data=data;
            new_node->next=p->next;
            p->next=new_node;
            if(p==last)
                last=new_node;
            return last;
        }
        p=p->next;
    } while (p!=last->next);
    cout<<item<<" not present in the list\n";
    return last;
}

void printList(Node* last)
{
    Node* p;
    if(last==NULL)
    {
        cout<<"List is empty\n";
        return;
    }
    p=last->next;
    do
    {
        cout<<p->data<<" ";
        p=p->next;
    } while (p!=last->next);
    
}
int main()
{
    Node* last=NULL;
    last=addtoEmpty(last,69);
    last=addtoEmpty(last,420);    //will fail

    last=addBegin(last,420);
    last=addBegin(last,2);
    last=addEnd(last,666);
    last=addEnd(last,2507);
    last=addAfter(last,99,101);       //will fail because no node with data equal to 101 exists.
    last=addAfter(last,747,69);
    printList(last);
}