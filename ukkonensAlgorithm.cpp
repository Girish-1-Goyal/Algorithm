#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

struct SuffixTreeNode {
    unordered_map<char, SuffixTreeNode*> children;
    SuffixTreeNode* suffixLink; // Suffix link for fast traversal
    int start, *end;            // Edge label range [start, end)
    int suffixIndex;            // For leaf nodes, stores the suffix index

    SuffixTreeNode(int start, int* end) : start(start), end(end), suffixLink(nullptr), suffixIndex(-1) {}

    // Get the length of the edge label
    int edgeLength() const {
        return (*end) - start + 1;
    }
};

class SuffixTree {
private:
    string text;               // Input string
    SuffixTreeNode* root;      // Root of the suffix tree
    SuffixTreeNode* activeNode; // Current active node
    int activeEdge;            // Current active edge (index in text)
    int activeLength;          // Length of the active point
    int remainingSuffixCount;  // Number of suffixes yet to be added
    int* leafEnd;              // Pointer to the global end variable
    int size;                  // Size of the input string

    // Create a new internal node
    SuffixTreeNode* createNode(int start, int* end) {
        return new SuffixTreeNode(start, end);
    }

    // Extend the suffix tree with the next character
    void extendSuffixTree(int pos) {
        leafEnd = &pos; // Update global end variable
        remainingSuffixCount++;
        SuffixTreeNode* lastNewNode = nullptr;

        while (remainingSuffixCount > 0) {
            if (activeLength == 0) activeEdge = pos;

            // Check if there is an outgoing edge starting with text[activeEdge]
            if (activeNode->children.find(text[activeEdge]) == activeNode->children.end()) {
                // Rule 1: Add a new leaf node
                activeNode->children[text[activeEdge]] = createNode(pos, leafEnd);

                // Link the previously created internal node to the current node via suffix link
                if (lastNewNode != nullptr) {
                    lastNewNode->suffixLink = activeNode;
                    lastNewNode = nullptr;
                }
            } else {
                // Rule 2: Follow the existing edge
                SuffixTreeNode* next = activeNode->children[text[activeEdge]];
                if (activeLength >= next->edgeLength()) {
                    activeEdge += next->edgeLength();
                    activeLength -= next->edgeLength();
                    activeNode = next;
                    continue;
                }

                // Rule 3: Split the edge if necessary
                if (text[next->start + activeLength] == text[pos]) {
                    if (lastNewNode != nullptr && activeNode != root) {
                        lastNewNode->suffixLink = activeNode;
                        lastNewNode = nullptr;
                    }
                    activeLength++;
                    break;
                }

                // Split the edge
                int splitEnd = next->start + activeLength - 1;
                SuffixTreeNode* split = createNode(next->start, new int(splitEnd));
                activeNode->children[text[activeEdge]] = split;
                split->children[text[pos]] = createNode(pos, leafEnd);
                next->start += activeLength;
                split->children[text[next->start]] = next;

                // Link the previously created internal node to the split node
                if (lastNewNode != nullptr) {
                    lastNewNode->suffixLink = split;
                }
                lastNewNode = split;
            }

            remainingSuffixCount--;
            if (activeNode == root && activeLength > 0) {
                activeLength--;
                activeEdge = pos - remainingSuffixCount + 1;
            } else if (activeNode != root) {
                activeNode = activeNode->suffixLink;
            }
        }
    }

    // Traverse the tree and print edges
    void traverse(SuffixTreeNode* node, const string& text) {
        if (!node) return;
        for (const auto& [c, child] : node->children) {
            cout << "Edge: " << text.substr(child->start, child->edgeLength()) << endl;
            traverse(child, text);
        }
    }

public:
    SuffixTree(const string& input) : text(input + "$"), size(input.size()), activeNode(nullptr), activeEdge(0),
                                      activeLength(0), remainingSuffixCount(0), leafEnd(nullptr) {
        root = createNode(-1, new int(-1)); // Initialize root
        activeNode = root;

        // Build the suffix tree incrementally
        for (int i = 0; i <= size; ++i) {
            extendSuffixTree(i);
        }
    }

    // Print the suffix tree edges
    void printTree() {
        cout << "Suffix Tree Edges:\n";
        traverse(root, text);
    }
};

int main() {
    string text = "banana";
    SuffixTree suffixTree(text);

    // Print the suffix tree edges
    suffixTree.printTree();

    return 0;
}