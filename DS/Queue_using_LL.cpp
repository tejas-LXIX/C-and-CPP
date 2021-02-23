#include<iostream>

using namespace std;

class Qnode
{
    int data;
    Qnode* next;
    public:
        Qnode(int d)
        {
            data=d;
            next=NULL;
        }
    friend class Queue;     //so that the Qnode pointers front and rear of the class Queue,can access the data members "data" and "next" of the class Qnode.
};

class Queue
{
    Qnode* front,*rear;
    public:
        Queue()
        {
            front=NULL;
            rear=NULL;
        }
        bool isEmpty()
        {
            if(front==NULL && rear==NULL)
                return true;
            return false;
        }
        void enQueue(int data)
        {
            Qnode* new_node=new Qnode(data);        //isFull() does not exist because any number of nodes can be added to this queue,since we are using linked lsit.
            if(isEmpty())
            {
                front=new_node;
                rear=new_node;
            }
            else
            {
                rear->next=new_node;      //for linking the nodes of the linked list.
                rear=new_node;
            }
        }
        void deQueue()
        {
            if(isEmpty())
            {
                cout<<"Queue is empty\n";
            }
            else if(front==rear)    //if we are deleting the last element of the queue,then we have to make front and rear NULL again.
            {
                delete front;
                front=NULL;
                rear=NULL;
            }
            else
            {
                Qnode* temp=front;
                front=front->next;
                delete temp;
            }
        }
        void printQueue()
        {
            Qnode* itr=front;
            if(isEmpty())
                cout<<"Queue is empty\n";
            while(itr!=NULL)
            {
                cout<<itr->data<<endl;
                itr=itr->next;
            }
        }

        void checkIfValueExist(int d)
        {
            Qnode* itr=front;
            while(itr!=NULL)
            {
                if(itr->data==d)
                {
                    cout<<d<<" exists in the queue\n";
                    return;
                }
                itr=itr->next;
            }
            cout<<d<<" does not exist in the queue\n";
        }
        int giveCount()
        {
            int count=0;
            Qnode* itr=front;
            while(itr!=NULL)
            {
                count++;
                itr=itr->next;
            }
            return count;
        }
};


int main()
{
    Queue q;
    q.enQueue(75);
    q.enQueue(69);
    q.enQueue(420);
    q.deQueue();
    q.checkIfValueExist(69);
    q.deQueue();
    cout<<"The number of elements in the queue are: "<<q.giveCount()<<endl;
    q.deQueue();
    q.printQueue();
}