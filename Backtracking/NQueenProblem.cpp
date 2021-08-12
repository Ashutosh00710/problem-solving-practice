#include <bits/stdc++.h>
#include "../utilities.h"

using namespace std;

class Solution {
    // slow function to check validation of Queen
    bool isSafe(int row, int col, vector<string> board, int n) {
        int duprow = row;
        int dupcol = col;

        while(row >= 0 && col >= 0) {
            if(board[row][col] == 'Q') return false;
            row--;
            col--;
        }


        col = dupcol;
        row = duprow;
        while(col>=0) {
            if(board[row][col] == 'Q') return false;
            col--;
        }

        row = duprow;
        col = dupcol;
        while(row<n && col>=0) {
            if(board[row][col] == 'Q') return false;
            row++;
            col--;
        }

        return true;
    }

    void findPlacement(int col, int n, vector<string>& ds, vector<vector<string>>& ans) {
        if(col == n) {
            ans.push_back(ds);
            return;
        }

        for(int row = 0; row < n; row++) {
            if(isSafe(row, col, ds, n)) {
                ds[row][col] = 'Q';
                findPlacement(col + 1, n, ds, ans);
                ds[row][col] = '.';
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n);
        string s(n, '.');
        for(int i = 0; i < n; i++) board[i] = s;
        findPlacement(0, n, board, ans);
        return ans;
    }
};

int main() {
    Solution s;
    vector<vector<string>> ans = s.solveNQueens(4);
    cout<< ans;
    return 0;
}
