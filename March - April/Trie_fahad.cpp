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
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
//
const int ALPHABET_SIZE = 26;

// trie node
struct TrieNode {
    struct TrieNode *children[ALPHABET_SIZE];

    // isEndOfWord is true if the node represents
    // end of a word
    bool isEndOfWord;

    // constructor to initialize
    TrieNode() {
        isEndOfWord = false;
        for (int i = 0; i < ALPHABET_SIZE; i++) children[i] = NULL;
    }
} *root;

// If not present, inserts key into trie
// If the key is prefix of trie node, just
// marks leaf node
void insert(string key) {
    struct TrieNode *cur = root;

    for (int i = 0; i < key.length(); i++) {
        int idx = key[i] - 'a';
        if (!cur->children[idx]) cur->children[idx] = new TrieNode();

        cur = cur->children[idx];
    }

    // mark last node as leaf
    cur->isEndOfWord = true;
}

// Returns true if key presents in trie, else
// false
bool search(string key) {
    struct TrieNode *cur = root;

    for (int i = 0; i < key.length(); i++) {
        int idx = key[i] - 'a';
        if (!cur->children[idx]) return false;

        cur = cur->children[idx];
    }

    return (cur != NULL && cur->isEndOfWord);
}

// Driver
int main() {
    // Input keys (use only 'a' through 'z' and lower case)
    string keys[] = {"the", "a", "there", "answer", "any", "by", "bye", "their"};
    int n = sizeof(keys)/sizeof(keys[0]);

    root = new TrieNode();

    // Construct trie
    for (int i = 0; i < n; i++) insert(keys[i]);
    // Search for different keys
    search("the") ? cout << "Yes\n" : cout << "No\n";
    search("these") ? cout << "Yes\n" : cout << "No\n";

    return 0;
}
