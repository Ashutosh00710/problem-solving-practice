#include<bits/stdc++.h>

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
  void display(vector<vector<int>> arr) {
      int m = arr.size();
      string str = "";
      cout << "[";
      for (int i = 0; i < m; i++) {
          cout << str << "[";
          string s = "";
          for (auto it : arr[i]) {
              cout << s << it;
              s = ", ";
          }
          cout << "]";
          str = ", ";
      }
      cout << "]";
  }
};

int main() {
    vector<int> nums{1, 1, 2};
    Solution s;
    vector<vector<int>> ans = s.subsets2(nums);
    s.display(ans);
    return 0;
}
