#include<iostream>
#include<unordered_map>    //change all the occurrences to map and you will see all the elements printed in sorted order(sorted in ascending order of keys). this is the difference between associative and unordered associative containers.
#include<map>
#include<algorithm>
using namespace std;

int main()
{
    unordered_map<char,int> s1;
    s1['c']=3;     //to add elements.
    s1['a']=1;
    s1['f']=6;
    s1['k']=11;
    s1.insert(pair<char,int>('z',26));      //also to add elements. this is the proper way. Use whatever you like though. The above one is simpler.
    s1['k']=69;         //you can change the value associated with a key. But you cannot change the key itself. you can only delete keys and then add new ones.
    unordered_map<char,int>::iterator itr;
    for(itr=s1.begin();itr!=s1.end();itr++)   //this is best way to print the elements
    {
        cout<<"KEY:\t"<<itr->first<<"\nValue:\t"<<itr->second<<endl;
    }
    cout<<"Alternate way of accessing value stored in a key\n";
    cout<<s1['k']<<endl;
    //better way is:
    itr=s1.find('k');
    if(itr!=s1.end())
    {
        cout<<itr->first<<" "<<itr->second<<endl;
    }
    s1.insert(pair<char,int>('z',234));      //fails because there already exists a key 'z' in the map. therefore this pair is not added.
    for(itr=s1.begin();itr!=s1.end();itr++)
    {
        cout<<"KEY:\t"<<itr->first<<"\nValue:\t"<<itr->second<<endl;
    }
    itr=s1.find('k');    //The find searches for the KEY. therefore, s1.find(11) will not work because 11 is a value,not a key.
    cout<<itr->first<<" "<<itr->second<<endl;



    map<int,int> gquiz2;      //Maps are associative containers that store elements in a mapped fashion. Each element has a key value and a mapped value. No two mapped values can have same key values.
    gquiz2.insert(pair<int,int>(1,40));
    gquiz2.insert(pair<int,int>(2,69));
    gquiz2.insert(pair<int,int>(1,51));
    map<int,int>::iterator itr1;
    cout<<"The map gquiz2 is: \n"<<"KEY\tELEMENT\n";
    for(itr1=gquiz2.begin();itr1!=gquiz2.end();itr1++)
    {
        cout<<itr1->first<<"\t"<<itr1->second<<endl;
    }

    multimap<int,int> gquiz1;  //Multimap is similar to map with an addition that multiple elements can have same keys. Also, it is NOT required that the key value and mapped value pair has to be unique in this case. One important thing to note about multimap is that multimap keeps all the keys in sorted order always.
    gquiz1.insert(pair<int,int>(1,40));
    gquiz1.insert(pair<int,int>(2,69));
    gquiz1.insert(pair<int,int>(1,51));
    multimap<int,int>::iterator itr2;
    cout<<"The map gquiz1 is: \n"<<"KEY\tELEMENT\n";
    for(itr2=gquiz1.begin();itr2!=gquiz1.end();itr2++)
    {
        cout<<itr2->first<<"\t"<<itr2->second<<endl;
    }
}