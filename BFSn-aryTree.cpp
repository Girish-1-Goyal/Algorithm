#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct NTreeNode {
    int val;
    vector<NTreeNode*> children;
    NTreeNode(int x) : val(x) {}
};

void bfsNTree(NTreeNode* root) {
    if (!root) return;

    queue<NTreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        NTreeNode* current = q.front();
        q.pop();

        cout << current->val << " "; // Process the node

        for (NTreeNode* child : current->children) {
            q.push(child);
        }
    }
}

int main() {
    // Create an N-ary tree
    NTreeNode* root = new NTreeNode(1);
    root->children.push_back(new NTreeNode(2));
    root->children.push_back(new NTreeNode(3));
    root->children.push_back(new NTreeNode(4));
    root->children[0]->children.push_back(new NTreeNode(5));
    root->children[0]->children.push_back(new NTreeNode(6));

    cout << "BFS for N-Ary Tree: ";
    bfsNTree(root);
    cout << endl;

    return 0;
}