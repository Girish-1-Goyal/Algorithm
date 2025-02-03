/*
*
*    Author : Girish Kumar Goyal.
*
*/

#include <bits/stdc++.h>

using namespace std;

void preprocessBadCharacter(const string &pattern, vector<int> &badCharTable){
    int m = pattern.size();
    for(int i = 0; i < 256; ++i){
        badCharTable[i] = -1; // initialise all character to -1
    }
    for(int i = 0; i < m; ++i){
        badCharTable[(int)pattern[i]] = i; // store the last occurance of each character
    }
}


// preprocess the good suffix table
void preprocessGoodSuffix(const string &pattern, vector<int> &goodSuffixTable){
    int m = pattern.size();
    vector<int> boardPos(m + 1, 0); // border position
    vector<int> shift(m + 1, 0);  // shift values


    // compute border for the pattern
    int i = m;
    int j = m + 1;
    boardPos[i] = j;
    while(i > 0){
        while(j <= m && pattern[i - 1] != pattern[j - 1]){
            if(shift[j] == 0) shift[j] = j - i;
            j = boardPos[j];
        }
        --i;
        --j;
        boardPos[i] = j;
    }

    // adjust shift for prefixes
    j = boardPos[0];
    for(int i = 0; i <= m; ++i){
        if(shift[i] == 0) shift[i] = j;
        if(i == j) j = boardPos[j];
    }
    for(int k = 0; k <= m; ++k){
        goodSuffixTable[k] = shift[k];
    }
}

vector<int> boyerMooreSearch(const string &text, const string &pattern){
    int n = text.size();
    int m = pattern.size();
    vector<int> badCharTable(256, -1);
    vector<int> goodSuffixTable(m + 1, 0);

    // preprocess the table
    preprocessBadCharacter(pattern, badCharTable);
    preprocessGoodSuffix(pattern, goodSuffixTable);

    vector<int> matches;
    int s = 0;
    while(s <= n - m){
        int j = m - 1;

        // compare the pattern from right to left
        while(j >= 0 && pattern[j] == text[s + j]){
            --j;
        }
        if(j < 0){
            matches.push_back(s);

            // shift using the good suffix rule
            s += goodSuffixTable[0];
        }
        else{
            int badCharShift = j - badCharTable[(int)text[s + j]]; // bad character rule
            int goodSuffixShift = goodSuffixTable[j + 1];          // good suffix rule  
            s += max(badCharShift, goodSuffixShift);               // take the maximum shift

        }
    }
    return matches;
}

void solve(){
    string text = "ABAAABCDABAAABCDBA";
    string pattern = "ABA";

    vector<int> matches = boyerMooreSearch(text, pattern);

    cout << "Pattern found at index: ";
    for(int idx : matches){
        cout << idx << " ";
    }
    cout << "\n";
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
