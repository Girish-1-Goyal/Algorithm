/*
*
*    Author : Girish Kumar Goyal.
*
*/

#include <bits/stdc++.h>

using namespace std;

bool isSafe(int row, int col, const vector<int> &queens){
    for(int prevRow = 0; prevRow < row; ++prevRow){
        int prevCol = queens[prevRow];
        if(prevCol == col || abs(prevRow - row) == abs(prevCol - col)){
            return false;
        }
    }
    return true;
}

void SolveNQueensUtil(int row, int N, vector<int> &queens, vector<vector<string>> &solutions){
    if(row == N){
        vector<string> board(N, string(N, '.'));
        for(int i = 0; i < N; ++i){
            board[i][queens[i]] = 'Q';
        }
        solutions.push_back(board);
        return;
    }
    for(int col = 0; col < N; ++col){
        if(isSafe(row, col, queens)){
            queens[row] = col;
            SolveNQueensUtil(row + 1, N, queens, solutions);
            queens[row] = -1;
        }
    }
}

vector<vector<string>> solveNQueens(int N){
    vector<vector<string>> solutions;
    vector<int> queens(N, -1);
    SolveNQueensUtil(0, N, queens, solutions);
    return solutions;
}

void solve(){
    int N = 8;
    vector<vector<string>> solutions = solveNQueens(N);
    cout << "No of solutions: " << solutions.size() << "\n";
    for(const auto &board : solutions){
        for(const string &row : board){
            cout << row << "\n";
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
