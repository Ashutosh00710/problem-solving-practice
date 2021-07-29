#include<bits/stdc++.h>

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
    vector<int> test1{2, 3, 6, 7};
    Solution s;
    vector<vector<int>> ans = s.combinationSum(test1, 7);
    s.display(ans);
    return 0;
}

