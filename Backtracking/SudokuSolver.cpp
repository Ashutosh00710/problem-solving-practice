#include<bits/stdc++.h>
#include "../utilities.h"

using namespace std;

class Solution {
    bool isValid(int row, int col, char c, vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            if (board[row][i] == c) return false;

            if (board[i][col] == c) return false;

            if (board[3 * (row/3) + i / 3][3 * (col/3) + i % 3] == c) return false;
        }
        return true;
    }
    bool findPossibleBoard(vector<vector<char>>& board) {
        for (int i = 0; i < board.size(); i++) {
          for (int j = 0; j < board[0].size(); j++) {
            if(board[i][j] == '.') {
                for (char c = '1'; c <= '9'; c++) {
                    if (isValid(i, j, c, board)) {
                        board[i][j] = c;
                        if (findPossibleBoard(board) == true) return true;
                        else board[i][j] = '.';
                    }

                }
                return false;
            }
          }
        }
        return true;
    }
public:
    void solveSudoku(vector<vector<char>>& board) {
        findPossibleBoard(board);
    }
};

int main() {
    Solution s;
    vector<vector<char>> board{{'5','3','.','.','7','.','.','.','.'},
                               {'6','.','.','1','9','5','.','.','.'},
                               {'.','9','8','.','.','.','.','6','.'},
                               {'8','.','.','.','6','.','.','.','3'},
                               {'4','.','.','8','.','3','.','.','1'},
                               {'7','.','.','.','2','.','.','.','6'},
                               {'.','6','.','.','.','.','2','8','.'},
                               {'.','.','.','4','1','9','.','.','5'},
                               {'.','.','.','.','8','.','.','7','9'}};
    s.solveSudoku(board);
    cout<< board;
}
