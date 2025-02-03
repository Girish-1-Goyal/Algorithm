/*
*
*    Author : Girish Kumar Goyal.
*
*/

#include <bits/stdc++.h>

using namespace std;

// prefix and suffix sum for trees 

class TreeNode{
    int val;
    vector<TreeNode*> children;
    TreeNode(int x) : val(x){}
};

void computePrefixSumTree(TreeNode* root, int parentSum, vector<int> &prefixSum){
    if(!root) return;
    prefixSum[root->val] = prefixSum + root->val;
    for(TreeNode* child : root->children){
        computePrefixSumTree(child, prefixSum[root->val], prefixSum);
    }
}

void computeSuffixSumTree(TreeNode* root, vector<int> &suffixSum){
    if(!root) return;
    int total = root->val;
    for(TreeNode* child : root->children){
        computeSuffixSumTree(child, suffixSum);
        total += suffixSum[child->val];
    }
    suffixSum[root->val] = total;
}

void solve(){
    //Code Here....
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
