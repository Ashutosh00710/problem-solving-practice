#include<bits/stdc++.h>
#include<functional>

using namespace std;

class Solution {
public:
    // using while loop
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0;
        int high = n-1;
        while(low <= high){
            int mid = (low + high)/2;
            if(nums[mid] == target) return mid;
            if(nums[low] <= nums[mid]) {
                if(target < nums[mid] && target >= nums[low]) high = mid - 1;
                low = mid + 1;
            } else {
                if(target>nums[mid] && target<nums[low]) low = mid+1;
                high = mid-1;
            }
        }
        return -1;
    }
    // using recursion and lamda function
    int searchLamda(vector<int>& nums, int target) {
        int size = nums.size() - 1;
        function<int(int, int)> func;
        func = [&func, &nums, size, &target](int low, int high) mutable -> int {
            if (low > high)
              return -1;

            int mid = (low + high) / 2;
            if (nums[mid] == target)
            return mid;

            if (nums[low] <= nums[mid]) {
                if (target >= nums[low] && target <= nums[mid])
                    return func(low, mid - 1);

                return func(mid + 1, high);
            }

            if (target >= nums[mid] && target <= nums[high])
                return func(mid + 1, high);

            return func(low, mid - 1);
        };
        return func(0, nums.size() - 1);
    }
};

int main () {
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    int target = 0;
    Solution s;
    int ans = s.search(nums, target);
    cout << "ans = " << ans << endl;
    return 0;
}
