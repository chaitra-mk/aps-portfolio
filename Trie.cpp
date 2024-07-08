#include <bits/stdc++.h>
using namespace std;

struct TrieNode {
    TrieNode* childNode[26];
    bool wordEnd;

    TrieNode() {
        wordEnd = false;
        for (int i = 0; i < 26; i++) {
            childNode[i] = NULL;
        }
    }
};

void to_lowercase(string &key) {
    for (char &c : key) {
        c = tolower(c);
    }
}

void insert_key(TrieNode* root, string& key) {
    to_lowercase(key);
    TrieNode* currentNode = root;
    for (auto c : key) {
        if (currentNode->childNode[c - 'a'] == NULL) {
            TrieNode* newNode = new TrieNode();
            currentNode->childNode[c - 'a'] = newNode;
        }
        currentNode = currentNode->childNode[c - 'a'];
    }
    currentNode->wordEnd = true;
}

bool search_key(TrieNode* root, string& key) {
    to_lowercase(key);
    TrieNode* currentNode = root;
    for (auto c : key) {
        if (currentNode->childNode[c - 'a'] == NULL) {
            return false;
        }
        currentNode = currentNode->childNode[c - 'a'];
    }
    return currentNode->wordEnd == true;
}

bool delete_key(TrieNode* root, string& key, int depth = 0) {
    if (!root) return false;

    if (depth == key.size()) {
        if (root->wordEnd) {
            root->wordEnd = false;
            for (int i = 0; i < 26; i++) {
                if (root->childNode[i]) return false;
            }
            return true;
        }
    } else {
        int index = tolower(key[depth]) - 'a';
        if (delete_key(root->childNode[index], key, depth + 1)) {
            delete root->childNode[index];
            root->childNode[index] = NULL;
            return !root->wordEnd && std::all_of(begin(root->childNode), end(root->childNode), [](TrieNode* child) { return !child; });
        }
    }
    return false;
}

void print_trie(TrieNode* root, string prefix = "") {
    if (root->wordEnd) {
        cout << prefix << endl;
    }
    for (int i = 0; i < 26; i++) {
        if (root->childNode[i]) {
            print_trie(root->childNode[i], prefix + char('a' + i));
        }
    }
}


int main() {
    TrieNode* root = new TrieNode();

    vector<string> inputStrings = { "badami", "bagalkot", "panji", "patna", "panipat" };
    int n = inputStrings.size();
    for (int i = 0; i < n; i++) {
        insert_key(root, inputStrings[i]);
    }

    cout << "Trie contents after insertion:" << endl;
    print_trie(root);

    vector<string> searchQueryStrings = { "badami", "panipat" };
    int searchQueries = searchQueryStrings.size();
    for (int i = 0; i < searchQueries; i++) {
        cout << "Query String: " << searchQueryStrings[i] << "\n";
        if (search_key(root, searchQueryStrings[i])) {
            cout << "The query string is present in the Trie\n";
        } else {
            cout << "The query string is not present in the Trie\n";
        }
    }

    vector<string> deleteStrings = {"bagalkot", "panji" };
    for (string &key : deleteStrings) {
        if (!delete_key(root, key)) {
            cout << "Deleted " << key << " from Trie\n";
        } else {
            cout << "Failed to delete " << key << " from Trie\n";
        }
    }

    cout << "Trie contents after deletion:" << endl;
    print_trie(root);

    return 0;
}
