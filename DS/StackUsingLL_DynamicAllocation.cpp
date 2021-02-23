// C++ program for linked list implementation of stack 
#include <bits/stdc++.h> 
using namespace std; 

// A structure to represent a stack 
class StackNode { 
public: 
	int data; 
	StackNode* prev;   //prev points to the node prior to itself,useful for popping.
}; 

StackNode* newNode(int data) 
{ 
	StackNode* stackNode = new StackNode(); 
	stackNode->data = data; 
	stackNode->prev = NULL; 
	return stackNode; 
} 

int isEmpty(StackNode* top) 
{ 
	return !top; //if stack is empty,then top=NULL,i.e top is false. so !top becomes true. therefore,isEmpty() returns true.
} 

void push(StackNode** top, int data) 
{ 
	StackNode* stackNode = newNode(data); 
	stackNode->prev = *top; 
	*top = stackNode; 
	cout << data << " pushed to stack\n"; 
} 

int pop(StackNode** top) 
{ 
	if (isEmpty(*top)) 
		return INT_MIN; 
	StackNode* temp = *top; 
	*top = (*top)->prev; 
	int popped = temp->data; 
	delete temp; 

	return popped; 
} 

int peek(StackNode* top) 
{ 
	if (isEmpty(top)) 
		return INT_MIN; 
	return top->data; 
} 

int main() 
{ 
	StackNode* top = NULL; 

	push(&top, 10); 
	push(&top, 20); 
	push(&top, 30); 

	cout << pop(&top) << " popped from stack\n"; 

	cout << "Top element is " << peek(top) << endl; 

	return 0; 
}
