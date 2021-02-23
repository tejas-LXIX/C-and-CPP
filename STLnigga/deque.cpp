#include<iostream>
#include<vector>
#include<deque>
#include<algorithm>
using namespace std;

//very similar to vector. Difference is that vector can only grow at the end of the vector,whereas deque can grow at the end and at the beginning.
//also data in deque is not stored in contiguous memory locations. It still provides random access just like vector i.e deq[1]
int main()
{
    deque<int> deq={4,6,7};
    deq.push_front(2);
    deq.push_back(3);
    cout<<deq[2];
}