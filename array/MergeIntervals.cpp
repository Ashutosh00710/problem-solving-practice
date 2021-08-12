#include <bits/stdc++.h>
#include "../utilities.h"
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        const int row = intervals.size();
        if (row == 0) return intervals;
        vector<vector<int>> result;
        sort2DvectorColumnWise(intervals, 0);
        result.push_back(intervals[0]);
        for (int i = 0; i < row; i++) {
          if (result.back()[1] < intervals[i][0]) result.push_back(intervals[i]);
          else result.back()[1] = max(result.back()[1], intervals[i][1]);
        }
        return result;
    }
};

int main() {
  vector<vector<int>> intervals1{{1,3},{2,6},{8,10},{15,18}};
  vector<vector<int>> intervals2{{1,4},{2,3}};
  Solution s;
  vector<vector<int>> ans = s.merge(intervals1);
  cout << ans;
  ans = s.merge(intervals2);
  cout << ans;
  return 0;
}

