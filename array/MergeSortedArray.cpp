#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    // Time Complexity: O(n * mlog(m))
    // Space Complexity: O(1)
    // TLE
	void mergeApproachOne(int arr1[], int arr2[], int n, int m) {
	    int j = 0;
	    for(int i = 0; i < n; i++) {
	        if(arr1[i] > arr2[0]) {
	            swap(arr1[i], arr2[0]);
	            sort(arr2, arr2 + m);
	        }
	    }
	}

    // GAP Algorithm
    // Time Complexity: O(n+m * log2(n+m))
    // Space Complexity: O(1)
    // AC
    int nextGap(int gap) {
        if(gap <= 1)
            return 0;
        return (gap / 2) + (gap % 2);
    }
    void merge(int arr1[], int arr2[], int n, int m) {
        int i, j, gap = n + m;
        for (gap = nextGap(gap); gap > 0; gap = nextGap(gap)) {
            for (i = 0; i + gap < n; i++) {
                if (arr1[i] > arr1[i + gap]) {
                    swap(arr1[i], arr1[i + gap]);
                }
            }

            for (j = gap > n ? gap - n : 0; j < m && i < n; j++, i++) {
                if(arr1[i] > arr2[j]) {
                    swap(arr1[i], arr2[j]);
                }
            }

            if(j < m) {
                for (j = 0; j + gap < m; j++) {
                    if(arr2[j] > arr2[j + gap]) {
                        swap(arr2[j], arr2[j + gap]);
                    }
                }
            }
        }
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, i;
        cin >> n >> m;
        int arr1[n], arr2[m];
        for (i = 0; i < n; i++) {
            cin >> arr1[i];
        }
        for (i = 0; i < m; i++) {
            cin >> arr2[i];
        }
        Solution ob;
        ob.merge(arr1, arr2, n, m);
        for (i = 0; i < n; i++) {
            cout << arr1[i] << " ";
        }
        for (i = 0; i < m; i++) {
            cout << arr2[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}