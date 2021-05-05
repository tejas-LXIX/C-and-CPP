/* STL has algorithms and containers. Containers contain data. Algorithms operate on the data stored in Containers.
In OOPS,algos and data are combined into a class,and accessed using objects. STL goes opposite from OOPS. It separates algorithms from the data structures.
This helps in code re-use. One Container can use all algorithms, and all algorithms can work on any Container.
For this relationship to work, "ITERATORS" are used as a middle ground for "Algorithms" to access data from the "Containers". Iterators act as the common middle ground.
Each container provides a common interface defined by Iterators. Iterators can "iterate" each item inside the Container.
Algorithms therefore,work only on the iterators. They dont need to know anything about the containers.
Also Easily extendable. Defining new containers that provide iterator interface means that all existing algos can work on the new container. Vice-versa too. */

#include <iostream>
#include<vector>
#include<algorithm>
using namespace std; //everything inside stl is defined inside the namespace std.

/*
A vector is functionally same as an array. But, to the language vector is a type, and int is also a type. To a function argument, an array of any type (including vector[]) is treated as pointer. 
A vector<int> is not same as int[] (to the compiler). vector<int> is non-array, non-reference, and non-pointer - it is being passed by value, and hence it will call copy-constructor.
So, you must use vector<int>& (preferably with const, if function isn't modifying it) to pass it as a reference.
*/

int main()
{
    vector<int> test(1934,69);          //initialise the vector test with 1934 elements,each element having the value 69
    vector<int> vec;
    vec={1,2};
    vec.push_back(4); //appends element to the end of the array.
    vec.push_back(1);
    vec.push_back(17);
    vec.push_back(69);
    vec.push_back(1273);
    vector<int>::iterator itr1=vec.begin();//member function of vector that points to first element of vector
    vector<int>::iterator itr2=vec.end();//member function of vector that points to memory location just after the last element of the vector.
    // Therefore, it doesn't actually point to any data stored in the vector.
    cout<<vec.capacity()<<endl; //output is 8
    for(vector<int>::iterator itr=itr1;itr!=itr2;itr++)
    {
        cout<<*itr<<" "; //even though iterator is a class,it behaves like a regular pointer
    }
    cout<<endl;
    sort(itr1,itr2); //algos work on iterators,not on containers directly.
    for(vector<int>::iterator itr=itr1;itr!=itr2;itr++)
    {
        cout<<*itr<<" "; //even though iterator is a class,it behaves like a regular pointer
    }
    cout<<endl;
    vector<int> vec2(vec); //copy constructor. vec values are copied into vec2
    vec.clear(); //vec becomes empty
    vec2.swap(vec); //values are swapped. therefore,now vec2 becomes empty.
    cout<<vec.capacity()<<endl; //doesn't show 8 because ye khudko fit karliya when you swapped
    vec.insert(vec.begin()+3,91); //91 is inserted at index 3 of vec. vec.begin() is index 0. vec.begin()+7 is not allowed because vec.capacity() is only 5 here.
    //FUCK THIS
    itr1=vec.begin();
    itr2=vec.end(); //have to do this again nahi toh the memory at which itr1 points doesnt change,it remains as it was initially and therefore doesnt point to the new
    //memory location where vec.begin() actually is
    for(vector<int>::iterator itr=itr1;itr!=itr2;itr++)
    {
        cout<<*itr<<" "; //even though iterator is a class,it behaves like a regular pointer
    }
    vec={1,2,3,4,5};
    vector<int>::iterator itr;
    for(itr=vec.begin();itr!=vec.end();itr++)
    {
        if(itr==vec.begin()+1) //if itr points to value stored in index 1 of vec,then don't print.
        {}
        else
            cout<<*itr<<endl;
    }
    vector<int> vec3(vec.begin(),vec.begin()+3); //this copies values of vec into vec3 as [vec.begin(),vec.end())
    //see birthday_chocolate.cpp in ProblemSolving
    for(itr=vec3.begin();itr!=vec3.end();itr++)
    {
        if(itr==vec3.begin()+1) //if itr points to value stored in index 1 of vec,then don't print.
        {}
        else
            cout<<*itr<<endl;
    }

   vector<int> arr123;
   for(int i=0;i<11;i++)
   {
       arr123.push_back(i);
   }
   vector<int>::iterator itrboi;
   for(itrboi=arr123.begin();itrboi!=arr123.end();itrboi++)
   {
       if(itrboi+2<arr123.end())
       {
           cout<<*(itrboi+2)<<" ";
       }
   }
}