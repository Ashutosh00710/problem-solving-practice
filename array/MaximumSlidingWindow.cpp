#include<bits/stdc++.h>
#include "../utilities.h"
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

    // Using Heap
    // TLE (On GFG, LeetCode)
    // O(K*log(K)) -> empty minHeap
    // O(N*K) + O(K * log(K)) -> array traversal and pushing in heap
    // Total TC: O(K*log(K)) + O(N*K) + O(K * log(K))
    vector<int> maxSlidingWindow2(vector<int>& nums, int k) {
        vector<int> ans;
        size_t n = nums.size();
        if(n == 1) return {nums[0]};
        priority_queue<int> minHeap;
        // O(K*log(K))
        function<void()> emptyPq = [&]() -> void {
            while(!minHeap.empty()) {
                minHeap.pop();
            }
        };
        // O(N*K) + O(K * log(K))
        for (int i = 0; i <= n - k; i++) {
            for (int j = i; j < i + k; j++) {
                minHeap.push(nums[j]);
            }
            ans.push_back(minHeap.top());
            emptyPq();
        }
        return ans;
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
  displayVector(ans);
  ans = s.maxSlidingWindow(test2, 1);
  displayVector(ans);
  ans = s.maxSlidingWindow(test3, 1);
  displayVector(ans);
  ans = s.maxSlidingWindow(test4, 2);
  displayVector(ans);
  ans = s.maxSlidingWindow(test5, 2);
  displayVector(ans);
}
