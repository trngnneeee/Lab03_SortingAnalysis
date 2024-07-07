#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct TrieNode
{
    TrieNode *children[26];
    bool isEndOfWord;
    TrieNode()
    {
        isEndOfWord = false;
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
    }
};

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

bool search(TrieNode* root, string key){
    TrieNode* tmp = root;
    for (int i = 0; i < key.length(); i++)
    {
        int index = key[i] - 'a';
        if (tmp -> children[index] == NULL) return false;
        tmp = tmp -> children[index];
    }
    return tmp -> isEndOfWord = true;
}

void createTrie(string fileName, TrieNode* root){
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

void displayHelper(TrieNode* cur, string s)
{
    if(cur->isEndOfWord)
        cout << s << endl;

    for (int i = 0; i < 26; i++)
    {
        if(cur->children[i])
            displayHelper(cur->children[i], s + char(i + 'a'));
    }
}

vector<string> ans;

void dfs(TrieNode* root, string s, bool* used, string &tmp) {
    if (root -> isEndOfWord)
    {
        if (tmp.length() >= 3) ans.push_back(tmp);
    }
    for (int i = 0; i < s.length(); i++)
    {
        if (!used[i] && root -> children[s[i] - 'a'])
        {
            tmp.push_back(s[i]);
            used[i] = 1;
            dfs(root -> children[s[i] - 'a'], s, used, tmp);
            tmp.pop_back();
            used[i] = 0;
        }
    }
}

int main(){
    TrieNode* root = new TrieNode();
    createTrie("Dic.txt", root);

    // Code
    char c;
    string s;
    while (cin >> c)
    {
        s.push_back(c);
    }

    bool* used = new bool[s.length()]{0};
    string tmp = "";

    dfs(root, s, used, tmp); 
    cout << ans.size() << endl;
    sort(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << endl;
    } 
    return 0;
}