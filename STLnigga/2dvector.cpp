#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int print(vector<vector<int>> &arr)
{
    cout<<arr[53][61]<<endl;
    return 0;
}
int main()
{
    int m=71,n=65;
    vector<vector<int>> arr(m,vector<int>(n,17));   //initialising a 2d vector.
    //passing this vector to a function.
    cout<<print(arr);
    vector<vector<int>> vec; //vector is a dynamically allocated CONTIGUOUS array in memory. other containers aren't.
    for(int i=0;i<3;i++)
    {
        vector<int> b;
        for(int j=0;j<2;j++)
        {
            b.push_back(j+i);
        }
        vec.push_back(b);
    }
    cout<<vec[2][1]<<endl;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<2;j++)
        {
            cout<<vec[i][j]<<" "; //no range check
            cout<<vec.at(i).at(j); //throw range_error exception of out of range
            cout<<endl; 
        }
    }
    cout<<endl<<endl;
    
    vector<vector<int>>::iterator row;
    vector<int>::iterator col;
    for(row=vec.begin();row!=vec.end();row++) //this is a better way as it is faster than random access(vec[i][j]).
    //also because it is a universal way of traversing a container i.e it works for ALL containers.
    {
        for(col=row->begin();col!=row->end();col++) //row is an iterator,it behaves exactly as a pointer. 
        {
            cout<<*col<<" ";
        }
    }
    cout<<endl<<vec[0].size(); //to get number of columns(no. of elements in the first vector)
    cout<<endl<<vec.size(); //to get number of rows(no. of vectors inside the big vector)
}