#include "trie.h"

void insert(TrieNode *root, string key)
{
    TrieNode *temp = root;
    for (int i = 0; i < key.length(); i++)
    {
        int index = key[i] - 'a';
        if (temp->children[index] == NULL)
        {
            temp->children[index] = new TrieNode();
        }
        temp = temp->children[index];
    }
    temp->isEndOfWord = true;
}

bool search(TrieNode *root, string key)
{
    TrieNode *tmp = root;
    for (int i = 0; i < key.length(); i++)
    {
        int index = key[i] - 'a';
        if (tmp->children[index] == NULL)
            return false;
        tmp = tmp->children[index];
    }
    return tmp->isEndOfWord = true;
}

void createTrie(string fileName, TrieNode *root)
{
    ifstream input;
    input.open(fileName);
    if (!input.is_open())
    {
        cout << "File does not exist";
        return;
    }
    string s;
    while (getline(input, s))
    {
        insert(root, s);
    }
    input.close();
}

void displayHelper(TrieNode *cur, string s)
{
    if (cur->isEndOfWord)
        cout << s << endl;

    for (int i = 0; i < 26; i++)
    {
        if (cur->children[i])
            displayHelper(cur->children[i], s + char(i + 'a'));
    }
}

void dfs(TrieNode *root, string s, bool *used, string &tmp, vector<string> &ans)
{
    if (root->isEndOfWord)
    {
        if (tmp.length() >= 3)
            ans.push_back(tmp);
    }
    for (int i = 0; i < s.length(); i++)
    {
        if (!used[i] && root->children[s[i] - 'a'])
        {
            tmp.push_back(s[i]);
            used[i] = 1;
            dfs(root->children[s[i] - 'a'], s, used, tmp, ans);
            tmp.pop_back();
            used[i] = 0;
        }
    }
}