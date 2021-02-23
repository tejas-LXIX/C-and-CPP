#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//DIFFERENCE BETWEEN PRE AND POST INCREMENT.
//In the Pre-Increment, value is first incremented and then used inside the expression.
//In the Post-Increment, value is first used in a expression and then incremented.

int main()
{
    for(int i=0;i<5;i++)  //is the same as ++i because incrementation/decrementation is always done after we go through the loop
        cout<<i<<" ";
    //control flow is. 1. initialisation happens first and only once. 2. condition in the for loop is evaluated on each loop iteration. if true,then the statements inside the loop body are executed.
    //3. after statement execution,the incrementation/decrementation part is executes which updates the loop counter. since this is done at the last of each loop iteration,
    //so  i++   is the same as   ++i
    //DIFFERENCE COMES HERE
    cout<<endl;
    int i=5;
    while(--i) //here,first i is decremented by 1,and then the expression is evaluated. this is why 0 is not printed in this loop.
        cout<<i<<endl;
    cout<<"finisihed"<<endl;
    i=5;
    while(i--)  //first expression is evaluated,then i is decremented by 1. this is why 0 is printed in this loop. this happens because when i is equal to 1,it enters the loop again
        cout<<i<<endl;
    // and is first checked to be true or false,and then it is decremented. since 1 is true,so the expression evaluates to true. after checking,i is decremented(so it becomes equal to 0)
    //So we enter the loop body with value of i as 0. this is why 0 is printed by this loop.
    cout<<"finished"<<endl;
    i=1;
    do
    {
        cout<<i<<endl;
    }while(i--);  // 1 and 0 both are printed. because i=1 goes inside the test expression. now i is used in the expression first and then decremented.
    //so i=1 is checked,which is true. after checking it is decremented. so we again enter the loop with the now value of i=0(due to decrement)

    cout<<"finisihed"<<endl;
    i=1;
    do
    {
        cout<<i<<endl;
    } while (--i); //only 1 is printed. because i=1 goes inside the test expression. now i is first decremented and then it is used in the expression.
    //so i=0 is checked,which is false. so we dont enter the loop again.
    
}