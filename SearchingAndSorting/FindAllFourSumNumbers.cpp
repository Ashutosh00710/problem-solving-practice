#include <bits/stdc++.h>
using namespace std;

class Solution{
  public:
    vector<vector<int>> fourSum(vector<int> &arr, int k) {
        int n = arr.size();
        set<vector<int>> uniqueResult;
        vector<vector<int>> result;
        sort(arr.begin(), arr.end());
        for (int i = 0; i < n - 3; i++) {
            for (int j = i + 1; j < n - 2; j++) {
                int l = j + 1, r = n - 1;
                while(l < r) {
                    if(arr[i] + arr[j] + arr[l] + arr[r] == k) {
                        uniqueResult.insert({arr[i], arr[j], arr[l], arr[r]});
                        l++;
                        r--;
                    } else if(arr[i] + arr[j] + arr[l] + arr[r] < k)
                        l++;
                    else
                        r--;
                }
            }
        }
        for(auto it: uniqueResult) {
            result.push_back(it);
        }
        return result;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, i;
        cin >> n >> k;
        vector<int> a(n);
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        vector<vector<int>> ans = ob.fourSum(a, k);
        for (auto &v : ans) {
            for (int &u : v) {
                cout << u << " ";
            }
            cout << "$";
        }
        if (ans.empty()) {
            cout << -1;
        }
        cout << "\n";
    }
    return 0;
}