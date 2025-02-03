#include <iostream>
#include <vector>
using namespace std;

class FenwickTree {
private:
    vector<int> BIT; // Binary Indexed Tree
    int n;

public:
    FenwickTree(int size) : n(size), BIT(size + 1, 0) {}

    // Update the value at index `idx` by adding `delta`
    void update(int idx, int delta) {
        while (idx <= n) {
            BIT[idx] += delta;
            idx += idx & (-idx); // Move to the next node
        }
    }

    // Query the prefix sum up to index `idx`
    int query(int idx) const {
        int sum = 0;
        int i = idx;
        while (i > 0) {
            sum += BIT[i];
            i -= i & (-i); // Move to the parent node
        }
        return sum;
    }

    // Query the range sum from `l` to `r`
    int rangeQuery(int l, int r) const {
        return query(r) - query(l - 1);
    }
};

int main() {
    vector<int> arr = {1, 3, 5, 7, 9};
    int n = arr.size();

    FenwickTree ft(n);

    // Build the Fenwick Tree
    for (int i = 0; i < n; ++i) {
        ft.update(i + 1, arr[i]);
    }

    // Query prefix sums
    cout << "Prefix sum up to index 3: " << ft.query(3) << endl; // Output: 9
    cout << "Range sum from index 2 to 4: " << ft.rangeQuery(2, 4) << endl; // Output: 15

    // Update an element
    ft.update(3, 2); // Add 2 to the element at index 3
    cout << "Updated range sum from index 2 to 4: " << ft.rangeQuery(2, 4) << endl; // Output: 17

    return 0;
}