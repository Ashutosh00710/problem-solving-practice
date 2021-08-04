#include<bits/stdc++.h>

using namespace std;

class Solution{
    bool canMove(int newx, int newy, vector<vector<int>> &maze, vector<vector<bool>> &vis) {
        int n = maze.size();
        if (newx >= 0 && newy >= 0 && newx < n && newy < n && maze[newx][newy] == 1 && !vis[newx][newy]) {
            return true;
        }
        return false;
    }
    public:
    vector<string> findPath(vector<vector<int>> &maze, int n) {
        if(maze[0][0] == 0) return {};
        vector<string> ans;
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        string ds;
        function<void(int, int)> travelPossiblePaths;
        travelPossiblePaths = [&](int row, int col) mutable -> void {
            if(row == n - 1 && col == n - 1) {
                ans.push_back(ds);
                return;
            }
            //          D  L  R  U
            int dx[] = {1, 0, 0, -1};
            int dy[] = {0, -1, 1, 0};
            string str[] = {"D", "L", "R", "U"};
            for (int i = 0; i < 4; i++) {
                int newx = row + dx[i], newy = col + dy[i];
                if (canMove(newx, newy, maze, visited)) {
                  visited[row][col] = true;
                  ds.append(str[i]);
                  travelPossiblePaths(newx, newy);
                  ds.pop_back();
                  visited[row][col] = false;
                }
            }
        };
        travelPossiblePaths(0, 0);
        return ans;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
