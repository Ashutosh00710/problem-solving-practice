#include <bits/stdc++.h>
#include "../utilities.h"

using namespace std;

class Solution {
  void findSubsets(int index, vector<int>& nums, vector<vector<int>>& ans, vector<int>& ds) {
      ans.push_back(ds);
      for (int i = index; i < nums.size(); i++) {
          if (i > index && nums[i] == nums[i - 1]) continue;
          ds.push_back(nums[i]);
          findSubsets(i + 1, nums, ans, ds);
          ds.pop_back();
      }
  }

public:
  vector<vector<int>> subsets2(vector<int>& nums) {
      sort(nums.begin(), nums.end());
      vector<vector<int>> ans;
      vector<int> ds;
      findSubsets(0, nums, ans, ds);
      return ans;
  }
};

int main() {
    vector<int> nums{1, 1, 2};
    Solution s;
    vector<vector<int>> ans = s.subsets2(nums);
    display2Dvector(ans);
    return 0;
}
