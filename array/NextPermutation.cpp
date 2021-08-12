#include <bits/stdc++.h>
#include "../utilities.h"

using namespace std;

class Solution {
public:
    void reverse(vector<int>& arr, int start, int end) {
        while (start < end) swap(arr[start++], arr[end--]);
    }
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return;
        int i = n - 2, j = n - 1;
        while (i >= 0 && nums[i] >= nums[i + 1]) --i;
        if (i >= 0) {
            j = n - 1;
            while (j >= 0 && nums[i] >= nums[j]) --j;
            swap(nums[i], nums[j]);
        }
        reverse(nums, i + 1, n - 1);
    }
};

int main() {
  vector<int> nums1{1, 2, 3};
  vector<int> nums2{3, 2, 1};
  vector<int> nums3{1, 1, 5};
  vector<int> nums4{1};
  Solution s;
  s.nextPermutation(nums1);
  cout << nums1;
  s.nextPermutation(nums2);
  cout << nums2;
  s.nextPermutation(nums3);
  cout << nums3;
  s.nextPermutation(nums4);
  cout << nums4;
  return 0;
}