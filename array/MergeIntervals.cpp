#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        const int row = intervals.size();
        if (row == 0) return intervals;
        vector<vector<int>> result;
        sort(intervals.begin(), intervals.end(), [](const vector<int> &a, const vector<int> &b)
             { return a[0] < b[0]; });
        result.push_back(intervals[0]);
        for (int i = 0; i < row; i++) {
          if (result.back()[1] < intervals[i][0]) result.push_back(intervals[i]);
          else result.back()[1] = max(result.back()[1], intervals[i][1]);
        }
        return result;
    }

    void display(vector<vector<int>>& intervals) {
      cout << "[";
      string str = "";
      for (auto interval : intervals) {
        cout <<str<< "[" << interval[0] << "," << interval[1] << "]";
        str = ", ";
      }
      cout << "]"<<endl;
    }
};

int main() {
  vector<vector<int>> intervals1{{1,3},{2,6},{8,10},{15,18}};
  vector<vector<int>> intervals2{{1,4},{2,3}};
  Solution s;
  vector<vector<int>> ans = s.merge(intervals1);
  s.display(ans);
  ans = s.merge(intervals2);
  s.display(ans);
  return 0;
}

