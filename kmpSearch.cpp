/*
*
*    Author : Girish Kumar Goyal.
*
*/

#include <bits/stdc++.h>

using namespace std;

/*
Implement Knuth morris algorithm(KMP algorithm)

It is a string algorithm which is used to find the patterns in the string at given indexes

Ex->
    txt = "aabaacaadaabaaba", pat = "aaba"
    output = [0, 9, 12]

Dry Run->
                                                              _   _   _   _  
                        _  _  _  _                 _  _   _   _
            String ->   a  a  b  a  a  c  a  a  d  a  a   b   a   a   b   a
            Indexes ->  0  1  2  3  4  5  6  7  8  9  10  11  12  13  14  15
            
            first pattern ->  0 - 3
            second pattern -> 9 - 12
            third pattern ->  12 - 15




*/

vector<int> computeLSP(const string &pattern){
    int n = pattern.size();
    vector<int> lsp(n, 0);
    int len = 0, i = 1;
    while(i < n){
        if(pattern[i] == pattern[len]){
            lsp[i++] = ++len;
        }
        else{
            if(len != 0){
                len = lsp[len - 1];
            }
            else{
                lsp[i++] = 0;
            }
        }
    }
    return lsp;
}

void kmpSearch(const string &text, const string &pattern){
    vector<int> lsp = computeLSP(pattern);
    int i = 0, j = 0;
    while(i < text.size()){
        if(text[i] == pattern[j]){
            i++;
            j++;
        }
        if(j == pattern.size()){
            cout << "Pattern found at index " << i - j << "\n";
            j = lsp[j - 1];
        }
        else if(i < text.size() && text[i] != pattern[j]){
            if(j != 0){
                j = lsp[j - 1];
            }
            else{
                i++;
            }
        }
    }
}

void solve(){
    string str  = "aabaacaadaabaaba";
    string pattern = "aaba";
    kmpSearch(str, pattern);
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
