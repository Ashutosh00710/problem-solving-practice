#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
      size_t n1 = nums1.size(), n2 = nums2.size();
      if (n1 > n2) return findMedianSortedArrays(nums2, nums1);
      int low = 0, high = n1;
      while(low <= high) {
        int cut1 = (low + high) >> 1;
        int cut2 = (n1 + n2 + 1) / 2 - cut1;

        int left1 = cut1 == 0 ? INT_MIN : nums1[cut1 - 1];
        int left2 = cut2 == 0 ? INT_MIN : nums2[cut2 - 1];

        int right1 = cut1 == n1 ? INT_MAX : nums1[cut1];
        int right2 = cut2 == n2 ? INT_MAX : nums2[cut2];

        if(left1 <= right2 && left2 <= right1) {
          if((n1 + n2) % 2 == 0) {
              return (max(left1, left2) + min(right1, right2)) / 2.0;
          } else {
              return max(left1, left2);
          }
        } else if(left1 > right2) {
          high = cut1 - 1;
        } else {
            low = cut1 + 1;
        }
      }
    }
};

int main() {
  Solution s;
  vector<int> testNums1{7, 12, 14, 15};
  vector<int> testNums2{1, 2, 3, 4, 9, 11};
  cout << s.findMedianSortedArrays(testNums1, testNums2);
  return 0;
}
