/*
*
*    Author : Girish Kumar Goyal.
*
*/

#include <bits/stdc++.h>
#include "debug_utils.h"

using namespace std;

//write a program to put all the zeros to the end of the array and construct an algorithm

vector<int> put_to_end(vector<int> &arr, int n){
    vector<int> temp(n);
    int cnt = 0;
    for(int i = 0; i < n; ++i){
        if(arr[i] != 0){
            temp[cnt++] = arr[i];
        }
    }
    while(cnt < n){
        temp[cnt++] = 0;
    }
    for(int i = 0; i < n; ++i){
        arr[i] = temp[i];
    }
    return arr;
}

void solve(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> arr(n);
        for(int i = 0; i < n; ++i){
            cin >> arr[i];
        }
        vector<int> res = put_to_end(arr, n);
        for(int i = 0; i < res.size(); ++i){
            cout << res[i] << " ";
        }
        cout << "\n";
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
