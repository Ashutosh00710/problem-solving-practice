#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
  // first approach
	int firstApproach(vector<vector<int>> arr, int n, int m) {
	    int mxm = -1, row;
	    for(int i = 0; i < n; i++) {
	        int count = 0;
	        for(int j = 0; j < m; j++) {
	            if(arr[i][j] == 1) {
	                count++;
	            }
	        }
	        if(count != 0 && count > mxm) {
	            mxm = count;
	            row = i;
	        }
	    }
	    return mxm == -1 ? -1 : row;
	}

  // second approach
  int first(vector<int>& arr) {
      int low = 0, mid = 0, high = arr.size() - 1;
      while (low <= high) {
        mid = (low + high) / 2;
        if((mid == 0 || arr[mid - 1] == 0) && arr[mid] == 1) {
          return mid;
        } else if(arr[mid] == 0) {
          low = mid + 1;
        } else {
          high = mid - 1;
        }
      }
      return -1;
  }

  int rowWithMax1s(vector<vector<int>> arr, int n, int m) {
      const int row = arr.size(), col = arr[0].size();
      int max = -1, max_row = -1;
      for (int i = 0; i < row; i++) {
        int index = first(arr[i]);
        if(index != -1 && col - index > max) {
            max = col - index;
            max_row = i;
        }
      }
      return max_row;
  }

};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector< vector<int> > arr(n,vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin>>arr[i][j];
            }
        }
        Solution ob;
        auto ans = ob.rowWithMax1s(arr, n, m);
        cout << ans << "\n";
    }
    return 0;
}