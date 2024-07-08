#include "trie.h"

int main()
{
    TrieNode *root = new TrieNode();
    createTrie("Dic.txt", root);

    // Code
    char c;
    string s;
    while (cin >> c)
    {
        s.push_back(c);
    }

    bool *used = new bool[s.length()]{0};
    string tmp = "";
    vector<string> ans;
    dfs(root, s, used, tmp, ans);
    cout << ans.size() << endl;
    sort(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << endl;
    }
    return 0;
}