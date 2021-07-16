#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // using hash table to store the number of times of each number
    // Time complexity: O(n)
    // Space complexity: O(n)
    int findDuplicateUsingSet(vector<int>& nums) {
      set<int> s;
      int res = 0;
      for (int i = 0; i < nums.size(); i++) {
        if (s.find(nums[i]) != s.end()) {
          res = nums[i];
          break;
        } else {
          s.insert(nums[i]);
        }
      }
      return res;
    }

    // Floyd's Algorithm
    // Time complexity: O(n)
    // Space complexity: O(1)
    int findDuplicate(vector<int>& nums) {
      int slow = nums[0], fast = nums[0];
      do {
        slow = nums[slow];
        fast = nums[nums[fast]];
      } while (slow != fast);
      fast = nums[0]; // reset the fast pointer to the beginning of the array
      while(slow != fast) {
        slow = nums[slow];
        fast = nums[fast];
      }
      return slow;
    }
};

int main() {
    Solution sol;
    vector<int> test1 = { 1,3,4,2,2 };
    vector<int> test2 = { 3,1,3,4,2 };
    vector<int> test3 = { 1,1 };
    vector<int> test4 = { 1,1,2 };
    cout<<sol.findDuplicate(test1)<<endl;
    cout<<sol.findDuplicate(test2)<<endl;
    cout<<sol.findDuplicate(test3)<<endl;
    cout<<sol.findDuplicate(test4)<<endl;
    return 0;
}
