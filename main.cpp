#include "trie.h"

int main()
{
    //Create a new TrieNode as the root of the Trie
    TrieNode *root = new TrieNode();
    //Input filename 
    string filename;
    cout << "Enter filename: ";
    getline(cin, filename); // E.g "Dic.txt"

    //Create the Trie from filename
    createTrie(filename, root);

    // Input letter 
    string s;
    cout << "Enter letters: ";
    getline(cin, s);

    //Create a boolean array to keep track of the letters that have been used    
    bool *used = new bool[s.length()]{0};

    //Create a string to store the current word and a vector to store the answer
    string tmp = "";

    //Vector to store the answer
    vector<string> ans;

    //DFS to find all the words that can be formed from the given letters
    dfs(root, s, used, tmp, ans);

    //Output the answer
    cout << ans.size() << endl;
    sort(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << endl;
    }

    //Deallocation
    delete root;
    delete[] used;

    return 0;
}