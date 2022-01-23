#include<iostream>
using namespace std;

class TrieNode{
    public:
        TrieNode* children[26];
        bool isEndOfWord=false;
};

class Trie{
    private:
        TrieNode* root; //root of Trie. All words start from this node.

    public:
        Trie(){
            root=getNewNode();
        }
        // Returns new trie node (initialized to NULLs)
        TrieNode* getNewNode(){
            TrieNode* new_node=new TrieNode();
            for(int i=0;i<26;i++){
                new_node->children[i]=NULL;
            }
            return new_node;
        }

        // If not present, inserts word into Trie. If the word has been inserted successfully OR If the word is a prefix of a word that already exists in the Trie, then just mark it as leaf node (sets the isEndOfWord flag to true).
        //O(n) where n is the length of the word to be inserted.
        void insert(string word){
            TrieNode* crawler=root;    //while inserting, we always start with the root.
            for(int i=0;i<word.length();i++){
                int index=word[i]-'a';  //to get the index where we have to check the TrieNode's children array.
                if(!crawler->children[index])   //if the reference for the letter does not exist in this TrieNode(if the reference is NULL), then we create a reference for it. Basically, we create a new TrieNode and store it's reference in the appropriate index (for "a" the index will be 0, for "z" the index will be 25).
                    crawler->children[index]=getNewNode();
                crawler=crawler->children[index];   //traverse to the next TrieNode. Doesn't matter if it's been newly created or if it already existed.
            }
            crawler->isEndOfWord=true;  //if the word has been successfully inserted or the word is a prefix of an already existing word, whatever the case we have to mark the last node as a leaf node (denoting that such a word exists).
        }

        //O(n) where n is the length of the word to be searched.
        bool search(string word){
            TrieNode* crawler=root;
            for(int i=0;i<word.length();i++){
                int index=word[i]-'a';
                if(!crawler->children[index])   //basically, if we reach a letter that does not exist in the current TrieNode's children array, then we return false. Because this means that no such word exists in the Trie. EG: "aple" search kar rhe ho, and you reach "apl" but in the "l" TrieNode you don't have a reference for "e". This implies that the word "aple" does not exist in the Trie. 
                    return false;
                crawler=crawler->children[index];
            }
            return (crawler->isEndOfWord);  //if we have traversed all the letters of the word, then we check if the isEndOfWord is marked "true" or not. This is because the word could also be a prefix of an existing word in the Trie, but not be inserted itself to return true.
            //EG: If we have inserted the word "apple" in the Trie but haven't inserted the word "appl" in the Trie. Then, if we search for "appl", we will be able to crawl through the entire word because it is a prefix of "apple" and "apple" exists in the Trie already. But returning "true" would be wrong because "apple" exists in the Trie as a word, but "appl" does not exist as a separate word in the Trie. It only exists as a prefix of "apple".
        }

        //O(n) where n is the length of the prefix to be searched.
        bool startsWith(string prefix){
            TrieNode* crawler=root;
            for(int i=0;i<prefix.length();i++){
                int index=prefix[i]-'a';
                if(!crawler->children[index])   //if we reach a letter that does not exist in the current TrieNode's children array, then we return false. Because this means that no such word exists in the Trie with the required prefix.
                    return false;
                crawler=crawler->children[index];
            }
            return true;    //since you have traversed the whole prefix and were always able to find a reference in the TrieNodes for each of the letter, implies that there does exist atleast one word with the required prefix. So, we return true;
        }

        //The idea to do this is to start traversing from the root node of trie, whenever we find a NON-NULL child node, we add parent key of child node in the “string str” and then recursively call the same process for the child node and same goes on till we find the node which is a leafnode (where isEndOfWord is marked "true"), which actually marks the end of the string. 
        void displayUtil(TrieNode* root,string str){
            if(root->isEndOfWord){  //because isEndOfWord does not necessarily mean that there are no other words extending from the TrieNode. EG: "apple" will have the node after "e" marked as endOfWord. Now, if we insert "apples", then the node after "e" will also have a child for "s", which points to another TrieNode. Therefore, we can't stop the function execution here by "returning". We carry on till THE NODE WHICH HAS NO CHILDREN.
                cout<<str<<endl;
            }
            for(int i=0;i<26;i++){
                if(root->children[i]){
                    str+=(i+'a');   //add the child letter.
                    displayUtil(root->children[i],str); //then call the displayUtil function for the child node (the node which is pointed to by children[i])
                    str.pop_back(); //remove the current child letter, and go to the next iteration to add the new child letter if it exists.
                }
            }
        }
        void display(){
            displayUtil(root,"");
        }
};

int main(){
    string words[]={"a","there","answer","any","by","apple","bye","their","apples"};
    int n=sizeof(words)/sizeof(words[0]);
    Trie myTrie;
    for(int i=0;i<n;i++){
        myTrie.insert(words[i]);
    }
    myTrie.search("there")?cout<<"Yes\n":cout<<"No\n";
    myTrie.search("theree")?cout<<"Yes\n":cout<<"No\n";
    myTrie.search("answe")?cout<<"Yes\n":cout<<"No\n";  //"answe" does not exist. "answer" exists. So, returns "false". agar myTrie.prefix("answe") karte toh "true" return hota.
    myTrie.search("any")?cout<<"Yes\n":cout<<"No\n";

    myTrie.startsWith("the")?cout<<"Yes\n":cout<<"No\n";
    myTrie.startsWith("pre")?cout<<"Yes\n":cout<<"No\n";
    myTrie.startsWith("answer")?cout<<"Yes\n":cout<<"No\n"; //"answer" exists as a prefix of the word "answer". So, returns true.
    cout<<"The contents of the Trie are\n";
    myTrie.display();
}