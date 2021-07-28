#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
      // declare a queue for traversal
      queue<pair<int /*row*/, int /*column*/>> q;
      int rows = grid.size(), columns = grid[0].size(), countTotalOranges = 0, countRottenOranges = 0, days = 0;

      for (int i = 0; i < rows; i++) {
          for (int j = 0; j < columns; j++) {
              if (grid[i][j] != 0) countTotalOranges++;
              if (grid[i][j] == 2) q.push({i, j});
          }
      }
      //           L  T  R  D
      int dx[] = {-1, 0, 1, 0};
      int dy[] = {0, -1, 0, 1};

      while(!q.empty()) {
          int size = q.size();
          countRottenOranges += size;
          while(size--) {
              int x = q.front().first, y = q.front().second;
              q.pop();
              for (int i = 0; i < 4; i++) {
                  int newx = x + dx[i], newy = y + dy[i];
                  // if true, do not move further in loop, just "continue" with the next iteration
                  if (newx < 0 || newy < 0 || newx >= rows || newy >= columns || grid[newx][newy] != 1) continue;
                  grid[newx][newy] = 2;
                  q.push({newx, newy});
              }
          }
          if (!q.empty()) days++;
      }

      return countTotalOranges == countRottenOranges ? days : -1;
    }
};

int main() {
  Solution sol;
  vector<vector<int>> matrix{{2, 1, 1}, {1, 1, 0}, {0, 1, 1}};
  cout<<sol.orangesRotting(matrix)<<endl;
}
