//Priority queues are a type of container adapters, specifically designed such that the first element of the queue is the greatest of all elements in the queue and elements are in non increasing order.
//hence we can see that each element of the queue has a priority {fixed order}.
//Priority queue is implemented using heap in STL.
#include<iostream>
#include<queue>     //to include queue and priority queue.
using namespace std;

/*
How to implement Min Heap? 
priority_queue supports a constructor that requires two extra arguments to make it min-heap. 

priority_queue <Type, vector<Type>, ComparisonType > min_heap;      EG: priority_queue<int,vector<int>,greater<int>> pq;
The third parameter, ‘Comparison Type’ can either be a function or factor (aka function object) that must have bool as return-type and must have 2 arguments.*/

/*
priority_queue::empty() in C++ STL– empty() function returns whether the queue is empty.
priority_queue::size() in C++ STL– size() function returns the size of the queue.
priority_queue::top() in C++ STL– Returns a reference to the top most element of the queue
priority_queue::push() in C++ STL– push(g) function adds the element ‘g’ at the end of the queue.
priority_queue::pop() in C++ STL– pop() function deletes the first element of the queue.
*/


void printpq(priority_queue<int> gq)
{
    while(!gq.empty())
    {
        cout<<gq.top()<<" ";
        gq.pop();
    }
    cout<<endl;
}
void printminpq(priority_queue<int,vector<int>,greater<int>> gq)
{
    while(!gq.empty())
    {
        cout<<gq.top()<<" ";
        gq.pop();
    }
    cout<<endl;
}

//USER DEFINED CLASS FOR PRIORITY_QUEUE
class Point
{
   int x;
   int y;
public:
   Point(int _x, int _y)
   {
      x = _x;
      y = _y;
   }
   int getX() const { return x; }
   int getY() const { return y; }
};
 
// To compare two points
class myComparator
{
public:
    int operator() (const Point& p1, const Point& p2)
    {
        return p1.getX() > p2.getX();   //so that the larger element is placed later in the queue. this makes the pq a min heap.
    }
};

int main()
{
    priority_queue<int> gquiz;  //By default C++ creates a max-heap for priority queue
    gquiz.push(10);
    gquiz.push(30);
    gquiz.push(20);
    gquiz.push(5);
    gquiz.push(1);
    printpq(gquiz);
    gquiz.pop();
    printpq(gquiz);
    priority_queue<int,vector<int>,greater<int>> pq;
    pq.push(10);
    pq.push(30);
    pq.push(20);
    pq.push(5);
    pq.push(1);
    printminpq(pq);
    pq.pop();
    printminpq(pq);

    // for user defined class.
    priority_queue <Point, vector<Point>, myComparator > userpq;
 
    // Insert points into the min heap
    userpq.push(Point(10, 2));
    userpq.push(Point(2, 1));
    userpq.push(Point(1, 5));
 
    // One by one extract items from min heap
    while (userpq.empty() == false)
    {
        Point p = userpq.top();
        cout << "(" << p.getX() << ", " << p.getY() << ")";
        cout << endl;
        userpq.pop();
    }
}
//the maxheap always acts on the first data structure by default. SEE HEAP_QUESTION.cpp in ProblemSolving folder.