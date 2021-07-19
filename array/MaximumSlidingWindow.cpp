#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
      deque<int> dq; // or use a doubly link list
      vector<int> ans;
      int size = nums.size();
      // iterate through the array
      for (int i = 0; i < size; i++) {
        // remove out of bound
        if(!dq.empty() && dq.front() == i - k)
          dq.pop_front();

        // maintain decreasing order in deque
        while(!dq.empty() && nums[dq.back()] < nums[i])
          dq.pop_back();

        // push the index
        dq.push_back(i);

        // push the maximum which is at the front of the deque
        if(i >= k - 1)
          ans.push_back(nums[dq.front()]);
      }

      return ans;
    }

    void display(vector<int>& nums) {
      cout << "[";
      string str = "";
      for(auto i : nums) {
        cout <<str<< i;
        str = ", ";
      }
      cout << "]"<<endl;
    }
};

int main() {
  Solution s;
  vector<int> test1{1,3,-1,-3,5,3,6,7};
  vector<int> test2{1};
  vector<int> test3{1,-1};
  vector<int> test4{9,11};
  vector<int> test5{4,-2};
  vector<int> ans = s.maxSlidingWindow(test1, 3);
  s.display(ans);
  ans = s.maxSlidingWindow(test2, 1);
  s.display(ans);
  ans = s.maxSlidingWindow(test3, 1);
  s.display(ans);
  ans = s.maxSlidingWindow(test4, 2);
  s.display(ans);
  ans = s.maxSlidingWindow(test5, 2);
  s.display(ans);
}
