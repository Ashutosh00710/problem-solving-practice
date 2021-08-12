#include<bits/stdc++.h>
#include "../utilities.h"

using namespace std;

class Solution {
    // Approach 2 (with less space)
    void findPermutation(int idx, vector<int>& nums, vector<vector<int>>& ans) {
        if(idx == nums.size()) {
            ans.push_back(nums);
            return;
        }

        for(int i = idx; i < nums.size(); i++) {
            swap(nums[idx], nums[i]);
            findPermutation(idx + 1, nums, ans);
            swap(nums[idx], nums[i]);
        }
    }

    // Approach 1 TC: O(n! * n)
    void findPermutations(vector<int>& freq, vector<int>& nums, vector<vector<int>>& ans, vector<int>& ds) {
      if(ds.size() == nums.size()) {
          ans.push_back(ds);
          return;
      }

      for (int i = 0; i < nums.size(); i++) {
        if(!freq[i]) {
            ds.push_back(nums[i]);
            freq[i] = 1;
            findPermutations(freq, nums, ans, ds);
            freq[i] = 0;
            ds.pop_back();
        }
      }
    }
  public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        vector<int> freq(nums.size(), 0);
        findPermutations(freq, nums, ans, ds);
        return ans;
    }

    vector<vector<int>> permute2(vector<int>& nums) {
        vector<vector<int>> ans;
        findPermutation(0, nums, ans);
        return ans;
    }
};

int main() {
    Solution s;
    vector<int> nums{1, 2, 3};
    vector<vector<int>> ans = s.permute(nums);
    cout << ans;
    ans = s.permute2(nums);
    cout << ans;
    return 0;
}
