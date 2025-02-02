/*
*
*    Author : Girish Kumar Goyal.
*
*/

#include <bits/stdc++.h>

using namespace std;

/*
TrieNode class ->
    a boolean mark the end of the word
    a vector of pointers to represents child nodes for each possible character


Trie class ->
    insert.
        traverse the trie character by character
        create new nodes as needed
        mark the last node as the end of the word
    
    search.
        traverse the trie character by character
        return false if any character is missing
        ensure that the final node is marked as the end of the word

    startsWith.
        similar to search, but does not require the final node to be marked as the end of the word

    memory management.
        the destructor ensures all dynamically allocated nodes are properly deleted to prevent memory leaks

Time complexity ->
    Insert -> O(L) -> L is the length of the word
    search -> O(L)
    startWith -> O(L)
    delete -> O(L)

*/

class TrieNode{
public:
    bool isEndOfWord; // mark the end of a word
    vector<TrieNode*> children; // pointer to the child nodes

    TrieNode() : isEndOfWord(false), children(26, nullptr) {}   // 26 for lower english letters       
};

class Trie{
private:
    TrieNode* root;

    // helper function to delete a node recursively
    void deleteNode(TrieNode* node){
        if(!node) return;
        for(auto child : node->children){
            deleteNode(child);
        }
        delete node;
    }  
public:
    Trie(){
        root = new TrieNode(); // initialise a root node
    }

    ~Trie(){
        deleteNode(root); // clean up memory
    }

    void insert(const string &word){
        TrieNode* current = root;
        for(char c : word){
            int index = c - 'a'; // assuming lower english letters
            if(!current->children[index]){
                current->children[index] = new TrieNode();
            }
            current = current->children[index];
        }
        current->isEndOfWord = true; // mark the end of the word
    }

    // search for a word in the trie
    bool search(const string &word){
        TrieNode* current = root;
        for(char c : word){
            int index = c - 'a';
            if(!current->children[index]){
                return false;
            }
            current = current->children[index];
        }
        return current->isEndOfWord; // ensure it's the end of the word
    }

    // check if any word starts with the given prefix
    bool startWith(const string &prefix){
        TrieNode* current = root;
        for(char c : prefix){
            int index = c - 'a';
            if(!current->children[index]){
                return false; // prefix not found
            }
            current = current->children[index];
        }
        return true; // prefix exists
     }

     // delete a word from the trie
     bool deleteWord(TrieNode* current, const string &word, int depth = 0){
         if(!current){
             return false;
         }
         if(depth == word.size()){
             if(!current->isEndOfWord){
                 return false; // word doesnt exists
             }
             current->isEndOfWord = false; // unmark the end of the word

             // check if the node has no children
             for(int i = 0; i < 26; ++i){
                 if(current->children[i]){
                     return false; // node has children
                 }    
             }
             return true; // node can be deleted
         }
         int index = word[depth] - 'a';
         if(deleteWord(current->children[index], word, depth + 1)){
             delete current->children[index];  // delete child node
             current->children[index] = nullptr;

             // check if the current node can be deleted
             return !current->isEndOfWord && all_of(current->children.begin(), current->children.end(), [](TrieNode* child){return child == nullptr;});
         }
         return false;
     }

     // public interface to deleting a word
     void deleteWord(const string &word){
         deleteWord(root, word);
     }
};

void solve(){
    Trie trie;

    // insert word into a trie
    trie.insert("apple");
    trie.insert("app");
    trie.insert("banana");

    // search for words
    cout << "search 'apple': " << (trie.search("apple") ? "Found" : "Not Found") << "\n";
    cout << "search 'app': " << (trie.search("app") ? "Found" : "Not Found") << "\n";
    cout << "search 'appl': " << (trie.search("appl") ? "Found" : "Not Found") << "\n";

    // check prefix
    cout << "Starts with 'app': " << (trie.startWith("app") ? "yes" : "No") << "\n";
    cout << "starts with 'ban': " << (trie.startWith("ban") ? "Yes" : "No") << "\n";

    // delete a word
    trie.deleteWord("app");
    cout << "After deleting word 'app', search 'app': " << (trie.search("app") ? "Found" : "Not Found") << "\n";
}

void init_code(){
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int main(){
    init_code();
    solve();
    return 0;
}
