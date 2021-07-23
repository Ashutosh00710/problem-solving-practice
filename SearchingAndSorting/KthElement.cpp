#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int kthElement(int nums1[], int nums2[], int n, int m, int k) {
      if (n > m) return kthElement(nums2, nums1, m, n, k);
      int low = max(0, k - m), high = min(k, n);
      while(low <= high) {
        int cut1 = (low + high) >> 1;
        int cut2 = k - cut1;

        int left1 = cut1 == 0 ? INT_MIN : nums1[cut1 - 1];
        int left2 = cut2 == 0 ? INT_MIN : nums2[cut2 - 1];

        int right1 = cut1 == n ? INT_MAX : nums1[cut1];
        int right2 = cut2 == m ? INT_MAX : nums2[cut2];

        if(left1 <= right2 && left2 <= right1) {
          return max(left1, left2);
        } else if(left1 > right2) {
          high = cut1 - 1;
        } else {
            low = cut1 + 1;
        }
      }
      return 1;
    }
};

int main() {
  Solution s;
  int testNums1[] = {100, 112, 256, 349, 770};
  int testNums2[] = {72, 86, 113, 119, 265, 445, 892};
  cout << s.kthElement(testNums1, testNums2, 5, 7, 7);
  return 0;
}
