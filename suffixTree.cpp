#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

class SuffixTreeNode {
public:
    unordered_map<char, SuffixTreeNode*> children;
    bool isEndOfWord;

    SuffixTreeNode() : isEndOfWord(false) {}
};

class SuffixTree {
private:
    SuffixTreeNode* root;

public:
    SuffixTree() {
        root = new SuffixTreeNode();
    }

    // Insert all suffixes of the string into the tree
    void buildSuffixTree(const string& text) {
        for (int i = 0; i < text.size(); ++i) {
            insert(text.substr(i));
        }
    }

    // Insert a suffix into the tree
    void insert(const string& suffix) {
        SuffixTreeNode* current = root;
        for (char c : suffix) {
            if (current->children.find(c) == current->children.end()) {
                current->children[c] = new SuffixTreeNode();
            }
            current = current->children[c];
        }
        current->isEndOfWord = true;
    }

    // Search for a substring in the suffix tree
    bool search(const string& query) {
        SuffixTreeNode* current = root;
        for (char c : query) {
            if (current->children.find(c) == current->children.end()) {
                return false;
            }
            current = current->children[c];
        }
        return true;
    }
};

int main() {
    string text = "banana";
    SuffixTree suffixTree;

    // Build the suffix tree
    suffixTree.buildSuffixTree(text);

    // Search for substrings
    cout << "Substring 'ana' found: " << (suffixTree.search("ana") ? "Yes" : "No") << endl;
    cout << "Substring 'ban' found: " << (suffixTree.search("ban") ? "Yes" : "No") << endl;
    cout << "Substring 'xyz' found: " << (suffixTree.search("xyz") ? "Yes" : "No") << endl;

    return 0;
}