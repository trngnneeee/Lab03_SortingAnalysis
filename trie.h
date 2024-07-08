#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct TrieNode
{
    bool isEndOfWord;
    TrieNode *children[26];
    TrieNode()
    {
        isEndOfWord = false;
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
    }
};

void insert(TrieNode *root, string key);
bool search(TrieNode *root, string key);
void createTrie(string fileName, TrieNode *root);
void displayHelper(TrieNode *cur, string s);
void dfs(TrieNode *root, string s, bool *used, string &tmp, vector<string> &ans);

