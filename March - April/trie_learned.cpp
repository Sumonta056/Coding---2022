// C++ implementation of search and insert
// operations on Trie
#include <bits/stdc++.h>
using namespace std;
//
#define ll long long
#define ull unsigned long long
#define mx 100010
#define mod 1000000007
#define endl '\n'
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0)

const int SIZE = 26;

struct TrieNode
{
    int count;
    int endHere;

    bool isEndOfWord;
    struct TrieNode *children[SIZE];

    TrieNode()
    {
        isEndOfWord = false;
        endHere = 0 ;
        for (int i = 0; i < SIZE; i++)
            children[i] = NULL;
    }
};

TrieNode *root;

void insert(string key)
{
    struct TrieNode *curr = root;
    int index;

    for (int i = 0; i < key.length(); i++)
    {
        index = key[i] - 'a';
        if (!curr->children[index])
            curr->children[index] = new TrieNode();

        curr = curr->children[index];
    }

    // mark last node as leaf
    curr->isEndOfWord = true;
    curr->endHere += 1;
}

// Returns true if key presents in trie, else
// false
bool search(string key)
{
    struct TrieNode *curr = root;

    for (int i = 0; i < key.length(); i++)
    {
        int index = key[i] - 'a';
        if (!curr->children[index])
            return false;

        curr = curr->children[index];
    }

    return (curr != NULL && curr->isEndOfWord);
}

void print(struct TrieNode *temp, string str)
{
    if (temp->isEndOfWord == true)
        cout << str << " " << temp->endHere << endl;
    for (int i = 0; i < 26; i++)
    {
        if (temp->children[i] != NULL)
            print(temp->children[i], str + (char)(i + 97));
    }
}

// Driver
int main()
{
    // Input keys (use only 'a' through 'z' and lower case)
    string keys[] = {"the", "a", "there", "answer", "any", "by", "bye", "their","a"};
    int n = sizeof(keys) / sizeof(keys[0]);

    root = new TrieNode();

    // Construct trie
    for (int i = 0; i < n; i++)
        insert(keys[i]);
    // Search for different keys
    search("the") ? cout << "Yes\n" : cout << "No\n";
    search("these") ? cout << "Yes\n" : cout << "No\n";

    print(root, "");

    return 0;
}
