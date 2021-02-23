#include<iostream>
//Queue is just like a normal queue. LILO (Last in Last Out) structure. SEE Simple Snippets video to understand.
//Peeche se add hote rehte hai,aur front se nikalte rehte hai. just like a normal queue.
//Elements are added at one side(enqueued), and removed from the other side(dequeued)


//We need circular queue because normal queue is very inefficient with memory,because ek baar dequeue kardiya toh you cant use that some position again,leading to memory wastage.
//Circular queue mein rear is linked back to the first,making a circle.

//THIS CODE IS FOR CIRCULAR QUEUE. IMPLEMENTED SO AS TO HAVE DYNAMIC SIZE ALLOCATION WHICH CAN BE DECIDED AT RUNTIME BY THE USER.
using namespace std;

class Queue
{
    public:
      int front,rear,size;
      unsigned capacity;
      int *array;  //Used for the actual queue. Pointer to an integer.
        
      Queue(unsigned capacity)
      {
        this->capacity=capacity;
        this->front=0;
        this->size=0;
        this->rear=capacity-1;
        this->array=new int[capacity*sizeof(int)];
      }
};

bool isFull(Queue* queue)
{
    return (queue->size==queue->capacity);
}

bool isEmpty(Queue* queue)
{
    return (queue->size==0);
}

// Function to add an item to the queue. 
// It changes rear and size 
void enqueue(Queue* queue,int value)
{
    if(isFull(queue))
    {
        cout<<"FAILED\n";
        return;
    }
    queue->rear=(queue->rear+1)%queue->capacity;  //this is so that after the first enqueue,the value of rear becomes zero which is equal to fron,indicating that there is only one element in the queue. And rear ka max value will remain one less than capacity always. Also,it wont go back to zero and repeat the whole thing again because the above if condition is there to check when the queue is full and exit from the function. 
    queue->array[queue->rear]=value;  //the array at the index rear, will store the input value.
    queue->size++;
    cout<<value<<" has been enqueued\n";
}

// Function to remove an item from queue. 
// It changes front and size 
int dequeue(Queue* queue)
{
    if(isEmpty(queue))
    {
        cout<<"FAILED";
        return 0;
    }
    int value=queue->array[queue->front];
    //delete queue->array[queue->front];   doesn't work.
    queue->array[queue->front]=INT_MIN;  //THE ELEMENTS AREN'T ACTUALLY DELETED,THEY ARE JUST MADE EQUAL TO INT_MIN HERE TO SHOW THAT THOSE SPACES ARE BASICALLY EMPTY.
    queue->front=(queue->front+1)%queue->capacity;
    queue->size--;
    return value;
}

int front(Queue* queue) //to return front of queue
{
    if(isEmpty(queue))
    {
        cout<<"FAILED";
        return INT_MIN;
    }
    return queue->array[queue->front];
}

int rear(Queue* queue)  //to return rear of queue
{
    if(isEmpty(queue))
    {
        cout<<"FAILED";
        return 0;
    }
    return queue->array[queue->rear];
}

void printQueue(Queue* queue)  //the elements aren't actually deleted from the queue,they stay there only and are replaced by INT_MIN to show that those spaces are basically empty. isliye jab print karo toh pura queue print hota hai,even the INT_MIN values. But practical purposes ke liye jaise bhi queue use hota,queue se requried correct values hi use hoti hai because of the front,rear and size variables. so no issue.
{
    if(isEmpty(queue))
    {
        cout<<"FAILED,queue is empty\n";
        return;
    }
    int i=0;
    cout<<"THE QUEUE ELEMENTS ARE:\n";
    while(queue->array[i]!=NULL)
    {
        cout<<queue->array[i]<<endl;
        i++;
    }
}

int main()
{
    Queue* queue=new Queue(3); //change the size,you will see that INT_MIN starts coming before 73 in the queue when you printQueue(). this is because we have a circular queue here. so, after a lot of dequeues,the values before 71 become INT_MIN too.
    enqueue(queue,69);
    enqueue(queue,420);
    enqueue(queue,71);
    cout<<dequeue(queue)<<" has been dequeued from the queue\n";
    cout<<dequeue(queue)<<" has been dequeued from the queue\n";
    cout<<dequeue(queue)<<" has been dequeued from the queue\n";
    cout<<dequeue(queue)<<" has been dequeued from the queue\n";
    enqueue(queue,73);
    cout<<front(queue)<<" is the front of the queue\n";  //but the front and rear of the queue show correct values because we are changing the pointers properly to point to the usable values only.
    cout<<rear(queue)<<" is the rear of the queue\n";
    printQueue(queue);
}




//THE CODE FOR NORMAL QUEUE IMPLEMENTED USING ARRAYS WITH FIXED SIZE. THE VALUES ARE NOT DELETED. THEY ARE JUST MADE EQUAL TO ZERO OR GARBAGE VALUE. ALSO,IF YOU DO LOTS OF ENQUEUE AND DEQUEUE,AT ONE POINT YOU CANNOT ADD MORE ELEMENTS TO THE QUEUE
//BECAUSE THE SIZE OF THE QUEUE IS FIXED AT 5, AND BY INCREMENTING FRONT AND REAR FOR EVERY DEQUEUE AND ENQUEUE RESPECTIVELY,THE INITIAL POSITIONS OF THE QUEUE CANNOT BE USED AGAIN,
//UNLESS YOU KEEP DOING DEQUEUE SO THAT AT THE LAST ELEMENT, THE FRONT AND REAR BECOME EQUAL TO -1 AGAIN.-1 HOJAAYEGA JAB,TAB YOU CAN USE THE WHOLE QUEUE AGAIN. SEE DEQUEUE FUNCTION.
//BUT AGAR EK VALUE RAKHNI HAI AND WANT TO REUSE THE QUEUE WITH DEQUEUEING ALL THE VALUES,THEN THAT IS NOT POSSIBLE BECAUSE REAR WILL BE EQUAL TO 4 TILL THE TIME YOU DONT DEQUEUE ALL THE ELEMENTS.
//HERE IS WHERE CIRCULAR QUEUE COMES IN.
/*#include<iostream>

using namespace std;

class Queue {
  private:
    int front;
  int rear;
  int arr[5];

  public:
    Queue() {
      front = -1;
      rear = -1;
      for (int i = 0; i < 5; i++) {
        arr[i] = 0;
      }
    }
  bool isEmpty() {
    if (front == -1 && rear == -1)
      return true;
    else
      return false;
  }
  bool isFull() {
    if (rear == 4)
      return true;
    else
      return false;
  }
  void enqueue(int val) {
    if (isFull()) {
      cout << "Queue full" << endl;
      return;
    } else if (isEmpty()) {
      rear = 0;
      front = 0;
      arr[rear] = val;
    } else {
      rear++;
      arr[rear] = val;
    }

  }

  int dequeue() {
    int x = 0;
    if (isEmpty()) {
      cout << "Queue is Empty" << endl;
      return x;
    } else if (rear == front) {   //this means theres only one element in the queue. so,the front and rear are made equal to -1 so that the queue can be used again.
      x = arr[rear];
      rear = -1;
      front = -1;
      return x;
    } else {
      cout << "front value: " << front << endl;
      x = arr[front];
      arr[front] = 0;
      front++;
      return x;
    }
  }

  int count() {
    return (rear - front + 1);
  }

  void display() {
    cout << "All values in the Queue are - " << endl;
    for (int i = 0; i < 5; i++) {
      cout << arr[i] << "  ";
    }
  }

};

int main() {
  Queue q1;
  int value, option;

  do {
    cout << "\n\nWhat operation do you want to perform? Select Option number. Enter 0 to exit." << endl;
    cout << "1. Enqueue()" << endl;
    cout << "2. Dequeue()" << endl;
    cout << "3. isEmpty()" << endl;
    cout << "4. isFull()" << endl;
    cout << "5. count()" << endl;
    cout << "6. display()" << endl;
    cout << "7. Clear Screen" << endl << endl;

    cin >> option;

    switch (option) {
    case 0:
      break;
    case 1:
      cout << "Enqueue Operation \nEnter an item to Enqueue in the Queue" << endl;
      cin >> value;
      q1.enqueue(value);
      break;
    case 2:
      cout << "Dequeue Operation \nDequeued Value : " << q1.dequeue() << endl;
      break;
    case 3:
      if (q1.isEmpty())
        cout << "Queue is Empty" << endl;
      else
        cout << "Queue is not Empty" << endl;
      break;
    case 4:
      if (q1.isFull())
        cout << "Queue is Full" << endl;
      else
        cout << "Queue is not Full" << endl;
      break;
    case 5:
      cout << "Count Operation \nCount of items in Queue : " << q1.count() << endl;
      break;
    case 6:
      cout << "Display Function Called - " << endl;
      q1.display();
      break;
    case 7:
      system("cls");
      break;
    default:
      cout << "Enter Proper Option number " << endl;
    }

  } while (option != 0);

  return 0;
}*/