/*Here, we need to implement the functionality of countWordsEqualTo(), countWordsStartingWith() AND erase(). For the first two, we will have to change the Trie structure a little.
endsWith represents the number of words that end with the given sequence of characters. countPrefix represents the number of words that have the given sequence of characters as a prefix.
countPrefix increases whenever you touch a TrieNode. endsWith increases whenever a word ends with that sequence of characters.
EW and CP now help us implement the countWordsEqualTo() and countWordsStartingWith() methods easily. All we have to do is to traverse the Trie, and when we reach the Leaf node, just return the value of the required count. AND If you dont encounter a TrieNode with the required character, then just return 0.

ERASE: For erase function, just traverse the Trie according to the word to be deleted, and decrement the CP by 1 at each TrieNode. In the end, decrement the EW by 1. Erase done.
We are not deleting the node, we are just reducing the count here.

SEE DSA PHOTOS.*/

#include<iostream>
using namespace std;

class TrieNode{
    public:
        TrieNode* children[26];
        int endsWith=0,countPrefix=0;
};

class Trie{
    private:
        TrieNode* root;
    public:
        Trie(){
            root=getNewNode();
        }
        TrieNode* getNewNode(){
            TrieNode* new_node=new TrieNode();
            for(int i=0;i<26;i++){
                new_node->children[i]=NULL;
            }
            return new_node;
        }
        void insert(string word){
            TrieNode* crawler=root;
            for(int i=0;i<word.length();i++){
                int index=word[i]-'a';
                if(!crawler->children[index])
                    crawler->children[index]=getNewNode();
                crawler=crawler->children[index];
                crawler->countPrefix++;     //increase the CP of the next node. EG: if we have "apps", we also increase the countPrefix of the Trie that comes just after "p" i.e (Trie3 in the photos. countPrefix of Trie3 is also incremented). Once we reach Trie3, we create a new Trie for "s" as it does not exist already, and then set it's EW to 1 and CP to 1.
            }
            crawler->endsWith++;    //since we have reached the end of the word, so EW is incremented.
        }
        int countWordsEqualTo(string word){
            TrieNode* crawler=root;
            for(int i=0;i<word.length();i++){
                int index=word[i]-'a';
                if(!crawler->children[index])   //If no such word exists, then return 0.
                    return 0;
                crawler=crawler->children[index];
            }
            return crawler->endsWith;   //reached the end of the word, so just return the value of EW.
        }
        int countWordsStartingWith(string word){
            TrieNode* crawler=root;
            for(int i=0;i<word.length();i++){
                int index=word[i]-'a';
                if(!crawler->children[index])
                    return 0;
                crawler=crawler->children[index];
            }
            return crawler->countPrefix;    //reached the end of the word, so just return the value of CP.
        }
        bool search(string word){
            TrieNode* crawler=root;
            for(int i=0;i<word.length();i++){
                int index=word[i]-'a';
                if(!crawler->children[index])   //basically, if we reach a letter that does not exist in the current TrieNode's children array, then we return false. Because this means that no such word exists in the Trie. EG: "aple" search kar rhe ho, and you reach "apl" but in the "l" TrieNode you don't have a reference for "e". This implies that the word "aple" does not exist in the Trie. 
                    return false;
                crawler=crawler->children[index];
            }
            return (crawler->endsWith);  //if we have traversed all the letters of the word, then we check if endsWith has a value or not. This is because the word could also be a prefix of an existing word in the Trie, but not be inserted itself to return a value.
            //EG: If we have inserted the word "apple" in the Trie but haven't inserted the word "appl" in the Trie. Then, if we search for "appl", we will be able to crawl through the entire word because it is a prefix of "apple" and "apple" exists in the Trie already. But returning "true" would be wrong because "apple" exists in the Trie as a word, but "appl" does not exist as a separate word in the Trie. It only exists as a prefix of "apple".
        }

        void erase(string word){
            TrieNode* crawler=root;
            if(!search(word)) //if the word does not exist, then we don't do anything.
                return;
            for(int i=0;i<word.length();i++){
                int index=word[i]-'a';
                crawler=crawler->children[index];
                crawler->countPrefix--;     //decrease the CP of the next node. EG: if we have "apps", we also decrease the countPrefix of the Trie that comes just after "p" i.e (Trie3 in the photos. countPrefix of Trie3 is also incremented). This is because the sequence "app" is not represented by Trie2, it's represented by Trie2.
            }
            crawler->endsWith--;
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
    myTrie.erase("there");
    myTrie.search("there")?cout<<"Yes\n":cout<<"No\n";
}