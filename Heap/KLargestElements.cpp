#include <bits/stdc++.h>

using namespace std;

class Solution{
public:
	vector<int> kLargest(int arr[], int n, int k) {
        vector<int> ans;
        priority_queue<int, vector<int>, greater<int>> minHeap;
        for (int i = 0; i < n; i++) {
            if (minHeap.size() > k) {
            minHeap.pop();
            }
        }
        while (minHeap.empty() == false) {
            ans.push_back(minHeap.top());
            minHeap.pop();
        }
        return ans;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.kLargest(arr, n, k);
        for (auto x : ans) {
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}