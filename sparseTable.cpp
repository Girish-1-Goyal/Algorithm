#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class SparseTable {
private:
    vector<vector<int>> table; // Sparse table
    int n;

public:
    SparseTable(const vector<int>& arr) {
        n = arr.size();
        int logN = log2(n) + 1;
        table.assign(n, vector<int>(logN, 0));

        // Initialize the first column with the array values
        for (int i = 0; i < n; ++i) {
            table[i][0] = arr[i];
        }

        // Fill the rest of the table
        for (int j = 1; (1 << j) <= n; ++j) {
            for (int i = 0; i + (1 << j) <= n; ++i) {
                table[i][j] = min(table[i][j - 1], table[i + (1 << (j - 1))][j - 1]);
            }
        }
    }

    // Query the minimum in range [l, r]
    int query(int l, int r) const {
        int len = r - l + 1;
        int k = log2(len);
        return min(table[l][k], table[r - (1 << k) + 1][k]);
    }
};

int main() {
    vector<int> arr = {1, 3, 4, 8, 6, 1, 4, 2};
    SparseTable st(arr);

    // Query range minimum
    cout << "Minimum in range [1, 4]: " << st.query(1, 4) << endl; // Output: 1
    cout << "Minimum in range [3, 7]: " << st.query(3, 7) << endl; // Output: 1

    return 0;
}