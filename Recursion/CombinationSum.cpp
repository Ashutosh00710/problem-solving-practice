#include<bits/stdc++.h>
#include "../utilities.h"

using namespace std;

class Solution {
  public:
  vector<vector<int>> combinationSum(vector<int>& arr, int target) {
      vector<vector<int>> ans;
      vector<int> ds;
      size_t s = arr.size();
      function<void(int, int)> findCombinations;
      findCombinations = [&findCombinations, &ds, &ans, &arr, s](int idx, int target) mutable -> void {
        if (idx == s) return;
        if (target == 0) {
            ans.push_back(ds);
            return;
        }

        if(arr[idx] <= target) {
            ds.push_back(arr[idx]);
            findCombinations(idx, target - arr[idx]);
            ds.pop_back();
        }

        findCombinations(idx + 1, target);
      };
      findCombinations(0, target);
      return ans;
  }
};

int main() {
    vector<int> test1{2, 3, 6, 7};
    Solution s;
    vector<vector<int>> ans = s.combinationSum(test1, 7);
    display2Dvector(ans);
    return 0;
}

