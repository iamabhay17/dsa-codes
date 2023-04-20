#include <bits/stdc++.h>
using namespace std;

class TrieNode
{
public:
    char data;
    TrieNode *children[26];
    bool isTerminal;

    TrieNode(char d)
    {
        this->data = d;
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

class Trie
{
public:
    TrieNode *root;
     
    //  insertion 
    void insertUtil(TrieNode *root, string word)
    {
        if(word.length()==0)
        {
            root->isTerminal=true;
        }
    }

    void insertWord(string word)
    {
        insertUtil(root, word);
    }
};