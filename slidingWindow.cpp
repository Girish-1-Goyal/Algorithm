#include <iostream>
#include <vector>
using namespace std;

// fixed size sliding window

int maxSumSubarrayOfSizeK(const vector<int>& arr, int k) {
    int n = arr.size();
    if (k > n) return -1; // Invalid input

    int windowSum = 0, maxSum = 0;
    for (int i = 0; i < k; ++i) windowSum += arr[i];

    maxSum = windowSum;

    for (int i = k; i < n; ++i) {
        windowSum += arr[i] - arr[i - k];
        maxSum = max(maxSum, windowSum);
    }

    return maxSum;
}

// variable sized sliding window approach

int longestSubstringWithoutRepeatingChars(const string& s) {
    unordered_map<char, int> charIndexMap;
    int maxLength = 0, left = 0;

    for (int right = 0; right < s.size(); ++right) {
        char currentChar = s[right];
        if (charIndexMap.find(currentChar) != charIndexMap.end()) {
            left = max(left, charIndexMap[currentChar] + 1);
        }
        charIndexMap[currentChar] = right;
        maxLength = max(maxLength, right - left + 1);
    }

    return maxLength;
}


int main() {
    vector<int> arr = {2, 1, 5, 1, 3, 2};
    int k = 3;
    cout << "Maximum sum of subarray of size " << k << ": " << maxSumSubarrayOfSizeK(arr, k) << endl;
    return 0;
}