#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void moveNegative(vector<int>& prices) {
      int j = 0;
      for (int i = 0; i < prices.size(); i++) {
        if (prices[i] < 0) {
          if(i != j) swap(prices[i], prices[j]);
          j++;
        }
      }
    }

    void printArray(vector<int>& prices) {
      for(auto it: prices) {
        cout << it << ", ";
      }
      cout << endl;
    }
};

int main() {
    Solution sol;
    vector<int> test = { -1, 2, -3, 4, 5, 6, -7, 8, 9 };
    sol.moveNegative(test);
    sol.printArray(test);
    return 0;
}
