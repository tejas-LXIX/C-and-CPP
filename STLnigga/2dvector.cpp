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
    //basically, arr is a vector of vectors. Elements of arr are arranged in a row(just like any normal vector),WHERE EACH ELEMENT of arr is itself a vector of size 'n'. Each of these elements represent the columns of the vector arr.
    /*i.e   first,a vector of 1 2 3 4 5 is inserted into arr. then 6 7 8 9 10. Then 11 12 13 14 15. And below is how they are inserted into the vector.

           1 6 11       no. of rows,m=3; no. of columns,n=5;
           2 7 12
           3 8 13
           4 9 14
           5 10 15
    */
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

    
    cout<<endl<<arr[0].size(); //to get number of columns(no. of elements in the first vector)
    cout<<endl<<arr.size(); //to get number of rows(no. of vectors inside the big vector)
}