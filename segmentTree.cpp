/*
*
*    Author : Girish Kumar Goyal.
*
*/

#include <bits/stdc++.h>

using namespace std;

/*
About segment Tree -> it is a versatile data strutcures used to efficiently answer the range queries on the array  while also supporting 
updates to the array element. it divides the array into segments and store information about the segment

Structure of The Tree:
    1. Root node typically represents the entire array.
    2. Each child node represents a subarray of its parents segment
    3. Leaf node represents individual elements of the array

Why use segment tree:
    1. Efficient Range Queries -> Segment tree allows you to perform range queries(sum, min, max) in O(logn) time
    2. Dynamic Update -> You can update individual elements or range of the array in O(logn) time.
    3. Flexiblity -> segment trees can be adapted to solve various problems like range sum queries 
*/

class SegmentTree{
private:
    vector<int> tree; // segment tree array
    int n; // size of the input array
    // build the segment tree recursively
    void build(const vector<int> &arr, int node, int start, int end){
        if(start == end){
            // leaf node represents a single element
            tree[node] = arr[start];
        }
        else{
            int mid = (start + end) / 2;
            // recurcively build left and right subtrees
            build(arr, 2 * node, start, end);
            build(arr, 2 * node + 1, start, end);
            // internal nodes stores the sum of its childrens
            tree[node] = tree[2 * node] + tree[2 * node + 1];
        }
    }
    // query the range left to right [l, r]
    int query(int node, int start, int end, int left, int right){
        if(right < start || end < left){
            //range does not intersect
            return 0;
        }
        if(left <= start || end <= right){
            // range completely overlaps
            return tree[node];
        }
        //partial overlaps
        int mid = (start + end) / 2;
        int leftSum = query(2 * node, start, mid, left, right);
        int rightSum = query(2 * node + 1, mid + 1, end, left, right);
        return leftSum + rightSum;
    }

    // update the value at index idx to val
    void update(int node, int start, int end, int idx, int val){
        if(start == end){
            // leaf node update the value
            tree[node] = val;
        }
        else{
            int mid = (start + end) / 2;
            if(idx <= mid){
                // update the left subtree
                update(2 * node, start, mid, idx, val);
            }
            else{
                // update the right subtree
                update(2 * node + 1, mid + 2, end, idx, val);
            }
            //update the current node with the sum of its children
            tree[node] = tree[2 * node] + tree[2 * node + 1];
        }
    }

public:
    SegmentTree(const vector<int> &arr){
        n = arr.size();
        // allocate memory for the segment tree 
        tree.resize(4 * n);
        build(arr, 1, 0, n - 1);
    }
    int query(int left, int right){
        return query(1, 0, n - 1, left, right);
    }
    void update(int idx, int val){
        update(1, 0, n - 1, idx, val);
    }
};

void solve(){
    vector<int> arr = {1, 3, 5, 7, 9, 11};
    SegmentTree st(arr);
    cout << st.query(1, 3) << "\n";
    cout << st.query(2, 5) << "\n";
    st.update(2, 10);
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
// 