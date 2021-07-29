#include<bits/stdc++.h>

using namespace std;

class Solution {
  public:
  // dynamic programming

  // recursive approach starts
  bool isPalindrome(string str) {
      int low = 0, high = str.length() - 1;
      while (low <= high) {
          if (str[low++] != str[high--]) return false;
      }
      return true;
  }

  void partition(int idx, string& s, vector<vector<string>>& ans, vector<string>& ds) {
    if(idx == s.size()) {
        ans.push_back(ds);
        return;
    }

    for (int i = idx; i < s.size(); i++) {
        string str = s.substr(idx, i - idx + 1);
        if (isPalindrome(str)) {
            ds.push_back(str);
            partition(i + 1, s, ans, ds);
            ds.pop_back();
        }
    }
  }

  vector<vector<string>> partition(string s) {
      vector<vector<string>> ans;
      vector<string> ds;
      partition(0, s, ans, ds);
      return ans;
  }
  // recursive approach end

  void display(vector<vector<string>> arr) {
      int m = arr.size();
      string str = "";
      cout << "[";
      for (int i = 0; i < m; i++) {
          cout << str << "[";
          string s = "";
          for (auto it : arr[i]) {
              cout << s<<" \"" << it << "\" ";
              s = ", ";
          }
          cout << "]";
          str = ", ";
      }
      cout << "]";
  }
};

int main() {
    string str = "aab";
    Solution s;
    vector<vector<string>> ans = s.partition(str);
    s.display(ans);
    return 0;
}

