#include<iostream>
#include<string>
//Elements are added and removed from the same side.
/*Stack will be like    4
                        3
                        2
                        1
                        0
                top->   -1  (initial)
Stack is LIFO (Last in First Out).                
*/

using namespace std;

class Stack
{
    private:
        int top,arr[5];  //top always points to the top of the stack even if values are pushed or popped.
        // top=-1 means the stack is empty.
    public:
        Stack()
        {
            top=-1;
            for(int i=0;i<5;i++)
            {
                arr[i]=0; //making default values zero initially.
            }
        }

        bool isEmpty()
        {
            if(top==-1)
                return true;
            else
                return false;
        }

        bool isFull()
        {
            if(top==4)
                return true;
            else
                return false;
        }

        void push(int val)
        {
            if(isFull())
                cout<<"Stack overflow"<<endl;  //if the stack is full, then we cant push any more values.
            else
            {
                top++;
                arr[top]=val;
            }
        }

        int pop()
        {
            if(isEmpty())
            {
                cout<<"Stack underflow";
                return 0;
            }
            else
            {
                int popValue=arr[top];
                arr[top]=0;
                top--;
                return popValue;
            }
        }

        int count()
        {
            return top+1; //since top is index of the element, therefore total number of elements is top+1
        }

        int peek(int pos)  //get the value stored in the stack at a particular position.
        {
            if(isEmpty())
            {
                cout<<"Stack underflow";
                return 0;
            }
            else
            {
                return arr[pos];
            }
        }

        void change(int pos,int val)
        {
            arr[pos]=val;
            cout<<"value changed at location"<<pos<<endl;
        }

        void display()
        {
            cout<<"All values in the stack are: "<<endl;
            for(int i=4;i>=0;i--)  //printing top to bottom.
            {
                cout<<arr[i]<<endl;
            }
        }        

};
int main()
{
    Stack s1;
    int option,position,value;

    do
    {
        cout << "What operation do you want to perform? Select Option number. Enter 0 to exit." << endl;
        cout << "1. Push()" << endl;
        cout << "2. Pop()" << endl;
        cout << "3. isEmpty()" << endl;
        cout << "4. isFull()" << endl;
        cout << "5. peek()" << endl;
        cout << "6. count()" << endl;
        cout << "7. change()" << endl;
        cout << "8. display()" << endl;
        cout << "9. Clear Screen" << endl << endl;
        
        cin>>option;
        
        switch(option)
        {
            case 0:
                break;
            case 1:
                cout<<"Enter an item to push in the stack"<<endl;
                cin>>value;
                s1.push(value);
                break;
            case 2:
                cout<<"Pop function called; Popped value: "<<s1.pop()<<endl;
                break;
            case 3:
                if (s1.isEmpty())
                    cout << "Stack is Empty" << endl;
                else
                    cout << "Stack is not Empty" << endl;
                break;
            case 4:
                if (s1.isFull())
                    cout << "Stack is Full" << endl;
                else
                    cout << "Stack is not Full" << endl;
                break;
            case 5:
                cout<<"Enter position of item you want to peek: "<<endl;
                cin>>position;
                cout << "Peek Function Called - Value at position " << position << " is "<<s1.peek(position)<<endl;
                break;
            case 6:
                cout << "Count Function Called - Number of Items in the Stack are: " << s1.count() << endl;
                break;
            case 7:
                cout << "Change Function Called - " << endl;
                cout << "Enter position of item you want to change : ";
                cin >> position;
                cout << endl;
                cout << "Enter value of item you want to change : ";
                cin >> value;
                s1.change(position, value);
                break;
            case 8:
                cout << "Display Function Called - " << endl;
                s1.display();
                break;
            case 9:
                system("cls");  //cleaar screen
                break;
            default:
                cout << "Enter Proper Option number " << endl;
    }
    }while(option!=0);
}