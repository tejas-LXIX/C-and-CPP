#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n=21,u,c;
    while(n>=1)
    {
        cout<<"No of matchsticks are : "<<n<<endl;
        cout<<"Your turn....."<<endl;
        cout<<"Enter 1,2,3,4 as ur choice...."<<endl;
        cin>>u;
        if(u>4)
        {
            cout<<"Invalid....."<<endl;
            break;
        }
        c=5-u;
        cout<<"Computer chooses : "<<c<<endl;
        n=n-u-c;
        continue;
        if(n==1)
        break;
        n--;
        cout<<"Computer Wins....";
    }
	return 0;
}
