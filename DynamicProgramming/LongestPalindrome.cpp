#include<bits/stdc++.h>
#include "../utilities.h"

using namespace std;

int LPS(string s, int left, int right, vector<vector<int>>& dp) {
  if(left == right)
    return 1;
  if(left > right) return 0;
  if(dp[left][right]) return dp[left][right];
  return dp[left][right] = s[left] == s[right] ? LPS(s, left + 1, right - 1, dp) + 2 :
    max(LPS(s, left + 1, right, dp), LPS(s, left, right - 1, dp));
}

int LPS(string s) {
  int n = s.size();
  vector<vector<int>> dp(n, vector<int>(n, 0));
  return LPS(s, 0, n - 1, dp);
}

int main() {
  string s1{"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggg"};
  string s2{"cbbd"};
  int t1 = getTime();
  cout<<LPS(s1)<<endl;
  int t2 = getTime();
  cout<<"Execution Time: "<<t2 - t1<<" ms"<<endl;
  cout<<LPS(s2)<<endl;
  return 0;
}