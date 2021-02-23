/*Associative containers are ALWAYS SORTED. Internally implemented with a BINARY TREE.
When an item is inserted,it will be inserted in the proper location. Default criteria is <
Also,when you remove an item from the tree,the tree is re-arranged automatically so that everything is still in order

Associative containers guarantee an O(logn) search,insertion and deletion. This is why they are faster than vectors for almost all operations,other than random access because vectors give O(1) random access,whereas associative containers dont have randomm access. Traversal is required to access any value.


Sets are a type of associative containers in which each element has to be unique, because the value of the element identifies it. The value of the element CANNOT be modified once it is added to the set, though it is possible to remove and add the modified value of that element. 

set<int,int> gquiz1;
 // insert elements in random order
    gquiz1.insert(40);
    gquiz1.insert(30);
    gquiz1.insert(60);
    gquiz1.insert(20);
    gquiz1.insert(50);     
    // only one 50 will be added to the set
    gquiz1.insert(50); wont be added to the set because 50 already exists in the set.
    gquiz1.insert(10);


INSERTION FUNCTION returns a pair<set<int>::iterator,bool>. The iterator points to the inserted value if the insertion is successful,otherwise it points to the duplicate item in the set. The bool tells you if the insertion was successful or not.
set<int>::iterator itr;
itr=gquiz1.find(50);        find returns an iterator the element if found,otherwise it returns gquiz1.end().
pair<set<int>::iterator,bool> ret;
ret=myset.insert(3);
if(ret.second==false)
{   itr=ret.first; }


Multisets are a type of associative containers similar to set, with an exception that multiple elements can have same values. In this sense,it is very similar to an array/vector because any number of non-unique values are also allowed.
They can be used in place of arrays only if you want fast O(logn) insertions,searches and deletions.


SEE map.cpp for usage.

Map and Multimap are very similar to Set and Multiset in their interface and behvaiour. only difference is sets mein sirf VALUE hota hai, whereas maps mein KEY:VALUE pair hota hai.
Maps are associative containers that store elements in a mapped fashion. Each element has a key value and a mapped value. No two mapped values can have same key values. Basically,map does not allow duplicate keys.
Format is KEY:VALUE.       A KEY CANNOT be modified once it is added to the set,though it is possible to remove that key and add a new key.
But the VALUE associated with a key can be modified anytime.

map<int, int> gquiz1; 
  
    // insert elements in random order 
    gquiz1.insert(pair<int, int>(1, 40)); 
    gquiz1.insert(pair<int, int>(2, 30)); 
    gquiz1.insert(pair<int, int>(5, 50)); 
    gquiz1.insert(pair<int, int>(6, 50));       //50 can be added to the map again under a different key, because values need not be unique.
    gquiz1.insert(pair<int, int>(5, 10)); //this will fail because KEY 5 already exists in the map. And keys must be unique. isliye insert hi nahi hoga.
    map<int,int>::iterator itr;
    itr=gquiz1.find(6);         // the find function will find an item in a map based on the KEY.


Multimap is similar to map with an addition that multiple elements can have same keys. Also, it is NOT required that the key value and mapped value pair has to be unique in this case. 
One important thing to note about multimap is that multimap keeps all the keys in sorted order always. These properties of multimap makes it very much useful in competitive programming.
Multimaps are just like maps, with the added feature that it allows duplicate keys.
multimap<int,int> gquiz2; 
    gquiz2.insert(pair<int, int>(5, 50)); 
    gquiz2.insert(pair<int, int>(6, 50));
    gquiz2.insert(pair<int, int>(5, 10)); //this will succeed because duplicate KEYS are allowed.

Multimap does not allow usage of [] operator for read/write. Map does.


Unordered_containers. unordered_map,unordered_multimap,unordered_set,unordered_multiset. Internally implemented with a HASH TABLE. The elements in unordered containers are NOT SORTED.
unordered containers provide FASTEST CONSTANT TIME O(1) searching. Theoretically,it can decay to O(n) if collisions occur due to improper hash function. But this usually never happens.
Associative Containers guarantee O(logn) search insertion and deletion everytime. Whereas unordered mein it might decay to O(n) theoretically, which usually never happens in real life.


SET ka primary usage is to store unique elements. Be it unique letters in a sentence, unique digits in a phone number etc. For example:they can be used to store all the DISTINCT words that appear in a string.
Whereas MAP can be used to store DISTINCT words as well as their FREQUENCIES in the given sentence.
*/
