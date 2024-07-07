#include <iostream>
#include <cstring>
#include <string>
#include <fstream>

using namespace std;

struct Trie
{
    Trie *child[26];
    bool isEnd;
    Trie()
    {
        memset(child, 0, sizeof(child)); // set 26 child to NULL
        isEnd = false;
    }
};

Trie *root = new Trie();

void Add(string &s);

bool checkString(string &s);

void readFile(string filename);

void displayHelper(Trie *cur, string s);
void display();

int main()
{
    readFile("Dic.txt");
    display();

    delete root;
    return 0;
}

void Add(string &s)
{
    Trie *cur = root;
    for (int i = 0; i < s.length(); i++)
    {
        int k = s[i] - 'a';
        if (cur->child[k] == NULL)
        {
            cur->child[k] = new Trie();
        }
        cur = cur->child[k];
    }
    cur->isEnd = true;
}

bool checkString(string &s)
{
    Trie *cur = root;
    for (int i = 0; i < s.length(); ++i)
    {
        int k = s[i] - 'a';
        if (cur->child[k] == NULL)
        {
            return false;
        }
        cur = cur->child[k];
    }
    return cur->isEnd;
}

void readFile(string filename)
{
    ifstream fin;
    fin.open(filename);
    if (!fin.is_open())
    {
        cout << "Cannot open that file\n";
        return;
    }

    string line;
    while (getline(fin, line))
    {
        Add(line);
    }

    fin.close();
}

void displayHelper(Trie* cur, string s)
{
    if(cur->isEnd)
        cout << s << endl;

    for (int i = 0; i < 26; i++)
    {
        if(cur->child[i])
            displayHelper(cur->child[i], s + char(i + 'a'));
    }
}

void display()
{
    displayHelper(root, "");
}
