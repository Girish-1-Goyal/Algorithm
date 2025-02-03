/*
*
*    Author : Girish Kumar Goyal.
*
*/

#include <bits/stdc++.h>

using namespace std;

bool isValid(int row, int col, char num, const vector<vector<char>> &board){
    for(int i = 0; i < 9; ++i){
        if(board[row][i] == num || board[i][col] == num){
            return false;
        }
    }
    int startRow = 3 * (row / 3);
    int startCol = 3 * (col / 3);
    for(int i = 0; i < 3; ++i){
        for(int j = 0; j < 3; ++j){
            if(board[startRow + i][startCol + j] == num){
                return false;
            }
        }
    }
    return true;
}

bool sudokuSolverUtil(vector<vector<char>> &board){
    for(int row = 0; row < 9; ++row){
        for(int col = 0; col < 9; ++col){
            if(board[row][col] == '.'){
                for(char num = '1'; num <= '9'; ++num){
                    if(isValid(row, col, num, board)){
                        board[row][col] = num;
                        if(sudokuSolverUtil(board)) return true;
                        board[row][col] = '.';
                    }
                }
                return false;
            }
        }
    }
    return true;
}

void solveSudoku(vector<vector<char>> &board){
    sudokuSolverUtil(board);
}

void solve(){
    vector<vector<char>> board = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
    };

    solveSudoku(board);
    cout << "Solved Sudoku:\n";
    for(const auto &row : board){
        for(char c : row){
            cout << c << " ";
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
