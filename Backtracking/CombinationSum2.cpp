#include <bits/stdc++.h>
#include "../utilities.h"

using namespace std;

class Solution {
  public:
  vector<vector<int>> combinationSum2(vector<int>& arr, int target) {
      vector<vector<int>> ans;
      vector<int> ds;
      size_t s = arr.size();
      function<void(int, int)> findCombinations;
      findCombinations = [&findCombinations, &ds, &ans, &arr, s](int idx, int target) mutable -> void {
        if(target==0) {
            ans.push_back(ds);
            return;
        }

        for(int i = idx;i < s;i++) {
            if(i> idx && arr[i] == arr[i-1]) continue;
            if(arr[i] > target) break;
            ds.push_back(arr[i]);
            findCombinations(i + 1, target - arr[i]);
            ds.pop_back();
        }
      };
      findCombinations(0, target);
      return ans;
  }
};

int main() {
    vector<int> test1{10, 1, 2, 7, 6, 1, 5};
    Solution s;
    sort(test1.begin(), test1.end());
    vector<vector<int>> ans = s.combinationSum2(test1, 8);
    display2Dvector(ans);
    return 0;
}

