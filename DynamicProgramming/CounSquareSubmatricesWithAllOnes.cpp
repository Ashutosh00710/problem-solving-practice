#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int col = matrix[0].size(), row = matrix.size();
        int result = 0;
        for(int i = 0; i < row; i++) {
            for(int j = 0; j < col; j++) {
                if(matrix[i][j] == 1) {
                    if(i == 0 || j == 0) {
                        result += 1;
                    }
                    else {
                       int res = min(
                           { matrix[i - 1][j - 1], matrix[i][j - 1], matrix[i - 1][j] }
                       ) + matrix[i][j];
                       result += res;
                       matrix[i][j] = res;
                    }
                }
            }
        }
        return result;
    }
};

int main () {
    Solution s;
    vector<vector<int>> matrix = {{1,0,1,0,0},
                                  {1,0,1,1,1},
                                  {1,1,1,1,1},
                                  {1,0,0,1,0}};
    cout << s.countSquares(matrix) << endl;
    return 0;
}
