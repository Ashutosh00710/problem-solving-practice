#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int current = 0;
        int maxSoFar = 0;

        for(int i = 1;  i < prices.size(); i++) {
            current = max(0, current += prices[i] - prices[i - 1]);
            maxSoFar = max(current, maxSoFar);
        }
        return maxSoFar;
    }
};

int main() {
    Solution sol;
    vector<int> test1 = {7,1,5,3,6,4};
    vector<int> test2 = {7,6,4,3,1};
    cout << sol.maxProfit(test1) << endl;
    cout << sol.maxProfit(test2) << endl;
    return 0;
}
