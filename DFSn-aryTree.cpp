#include <iostream>
#include <vector>
using namespace std;

struct NTreeNode {
    int val;
    vector<NTreeNode*> children;
    NTreeNode(int x) : val(x) {}
};

// Preorder Traversal for N-Ary Tree
void preorderNTree(NTreeNode* root) {
    if (!root) return;
    cout << root->val << " "; // Process the node
    for (NTreeNode* child : root->children) {
        preorderNTree(child);
    }
}

// Postorder Traversal for N-Ary Tree
void postorderNTree(NTreeNode* root) {
    if (!root) return;
    for (NTreeNode* child : root->children) {
        postorderNTree(child);
    }
    cout << root->val << " "; // Process the node
}

int main() {
    // Create an N-ary tree
    NTreeNode* root = new NTreeNode(1);
    root->children.push_back(new NTreeNode(2));
    root->children.push_back(new NTreeNode(3));
    root->children.push_back(new NTreeNode(4));
    root->children[0]->children.push_back(new NTreeNode(5));
    root->children[0]->children.push_back(new NTreeNode(6));

    cout << "Preorder Traversal for N-Ary Tree: ";
    preorderNTree(root);
    cout << endl;

    cout << "Postorder Traversal for N-Ary Tree: ";
    postorderNTree(root);
    cout << endl;

    return 0;
}