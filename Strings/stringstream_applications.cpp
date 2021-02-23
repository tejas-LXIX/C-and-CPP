#include <iostream>
#include<sstream>
#include<map>
#include<algorithm>
using namespace std;

string removespaces(string str)
{
    stringstream ss;
    string temp;
    ss<<str;
    str="";
    //One by one tokens are extracted from the stringstream ss,stored in string temp,and then added to the string str.
    while(ss>>temp)     //each token from ss is passed into temp. Temp is first cleared and then the next token from ss is passed into the string temp.
    {
        str+=temp;      //The token stored in temp is added to the string str.
    }
    return str;
}

int countwords(string str)
{
    stringstream ss(str);
    string word;
    int count=0;
    while(ss>>word)      //each token from ss is passed into word, one by one. ">>" CLEARS the string word,and then passes a token from ss to word. Tokens are separated by SPACES,NEWLINES,TABS. See stringstream.cpp
        count++;
    return count;
}

void printFrequency(string str)
{
    map<string,int> frequency_of_word;
    stringstream ss(str);
    string word;
    while(ss>>word)
    {
        frequency_of_word[word]++;     //If the key "word" exists in the map,then its integer value is incremented by 1. Else,this key is created and its integer value is set to 1.
    }
    map<string,int>::iterator itr;
    for(itr=frequency_of_word.begin();itr!=frequency_of_word.end();itr++)
    {
        cout<<itr->first<<" "<<itr->second<<endl;
    }
}

int main()
{
    string str="My life is a mess";
    cout<<removespaces(str)<<endl;
    str="I don't have the guts to talk to anyone properly";
    cout<<removespaces(str)<<endl;
    str="I dont feel like interacting with anyone. I feel down everyday";
    cout<<removespaces(str)<<endl;
    cout<<"The number of words in str are: "<<countwords(str)<<endl;
    printFrequency(str);
    str="I just want COVID to end";
    cout<<removespaces(str)<<endl;
}