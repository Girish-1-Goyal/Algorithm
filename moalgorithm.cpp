#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

struct Query {
    int l, r, idx;
};

// Comparator for sorting queries
bool compareQueries(const Query& a, const Query& b, int blockSize) {
    if (a.l / blockSize != b.l / blockSize) {
        return a.l / blockSize < b.l / blockSize;
    }
    return a.r < b.r;
}

vector<int> mosAlgorithm(const vector<int>& arr, const vector<Query>& queries) {
    int n = arr.size();
    int q = queries.size();
    int blockSize = sqrt(n);

    // Sort queries using Mo's ordering
    vector<Query> sortedQueries = queries;
    sort(sortedQueries.begin(), sortedQueries.end(), [blockSize](const Query& a, const Query& b) {
        return compareQueries(a, b, blockSize);
    });

    vector<int> result(q);
    vector<int> freq(1e6 + 1, 0); // Frequency array
    int currentDistinct = 0;

    auto add = [&](int x) {
        if (freq[x] == 0) currentDistinct++;
        freq[x]++;
    };

    auto remove = [&](int x) {
        freq[x]--;
        if (freq[x] == 0) currentDistinct--;
    };

    int currL = 0, currR = -1;
    for (const auto& query : sortedQueries) {
        int l = query.l, r = query.r, idx = query.idx;

        // Expand or shrink the window
        while (currL > l) add(arr[--currL]);
        while (currR < r) add(arr[++currR]);
        while (currL < l) remove(arr[currL++]);
        while (currR > r) remove(arr[currR--]);

        result[idx] = currentDistinct;
    }

    return result;
}

int main() {
    vector<int> arr = {1, 2, 1, 3, 4, 1, 2, 5};
    vector<Query> queries = {{0, 3, 0}, {1, 6, 1}, {2, 7, 2}};

    vector<int> result = mosAlgorithm(arr, queries);

    for (int res : result) {
        cout << "Distinct elements in query: " << res << endl;
    }

    return 0;
}