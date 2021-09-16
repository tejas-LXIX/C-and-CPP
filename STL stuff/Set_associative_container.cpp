/* Associative containers are always sorted. Typically implemented with binary tree.
When an item is inserted,it will be inserted in the proper location. Default criteria is <
Also,when you remove an item from the tree,the tree is re-arranged automatically so that everything is still in order
Set has no duplicate items.
1. Fast Search
2. Traversing is slow (compared to vector and deque)
3. No random access [] operator. */
#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;

int main()
{
    set<int> myset;
    myset.insert(3);
    myset.insert(1);
    myset.insert(7); //insertion takes O(log(n)) time.
    set<int>::iterator it;
    it=myset.find(7);//Gives the iterator to the element 7 if it is found otherwise returns s.end()
     //takes O(log(n)) time. very fast. sequence containers dont even have find function because it takes too much time.
    
    //implementation of insert function of a set in the <set> header file
    pair<set<int>::iterator,bool> ret;
    ret=myset.insert(3); //insert function returns a pair of values. the second value is a boolean which indicates if insertion is successful or not.
    //since 3 is already present in the set,so the insertion fails.
    if(ret.second==false)
        it=ret.first;//the iterator returned by the insert function points to the element being inserted if the insertion is successful,or it points to the duplicate item
        //in the set if the insertion is unsuccessful.
    myset.erase(7);
    //set and multiset are read only    
    // *it=10;  not possible. this is because if you modify an element,the data structure will get corrupted because the elements may not be sorted anymore. 


    multiset<int> myset1; //multiset is a set that allows duplicated items
}