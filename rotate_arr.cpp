/*
*
*    Author : Girish Kumar Goyal.
*
*/

#include <bits/stdc++.h>
#include "debug_utils.h"

using namespace std;

vector<int> rotate_m1(vector<int> &arr, int &k){
    int n = arr.size();

    //handle when k > n
    k %= n;

    //array to store rotated version of an array
    vector<int> temp(n);

    //copy last k elements to the front  of temp
    for(int i = 0; i < k; ++i){
        temp[i] = arr[n - k - i];
    }
    //copy the first n - k element to the back of the temp
    for(int i = 0; i < n - k; ++i){
        temp[i + k] = arr[i];
    }

    //copy all the elements of the temp array into the origional array
    for(int i = 0; i < n; ++i){
        arr[i] = temp[i];
    }
    return arr;
}

void rotate_m2(vector<int> &arr, int &k){
    int n = arr.size();

    //handle when the k > n
    k %= n;

    //reverse the entire array
    reverse(arr.begin(), arr.end());

    //reverse the first k elements
    reverse(arr.begin(), arr.end() + k);

    //reverse the remaining n - k elements
    reverse(arr.begin() + k, arr.end());
}

void solve(){
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        vector<int> arr(n);
        for(int i = 0; i < n; ++i){
            cin >> arr[i];
        }
        vector<int> res = rotate_m1(arr, k);
        for(int i = 0; i < n; ++i){
            cout << res[i] << " ";
        }
        cout << "\n";
        rotate_m2(arr, k);
        for(int i = 0; i < n; ++i){
            cout << arr[i] << " ";
        }
        cout << '\n';
    }
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
