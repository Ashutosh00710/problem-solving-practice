#include<bits/stdc++.h>

using namespace std;

using chrono::high_resolution_clock;
using chrono::duration_cast;
using chrono::milliseconds;

int getTime() {
    auto t = high_resolution_clock::now();
    return duration_cast<milliseconds>(t.time_since_epoch()).count();
}

int sort2DvectorColumnWise(vector<vector<int>>& v, int col) {
    sort(v.begin(), v.end(), [&col](const vector<int> &a, const vector<int> &b) { return a[col] < b[col]; });
}

int lowerBound(vector<int>& v, int key) {
    int low = 0, high = v.size() - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (v[mid] < key) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return low;
}

int lowerBound(int arr[], int n, int key) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] < key) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return low;
}


int binarySearch(vector<int>& v, int key) {
    int low = 0, high = v.size() - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (v[mid] == key) {
            return mid;
        } else if (v[mid] < key) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}

int binarySearch(int v[], int n, int key) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (v[mid] == key) {
            return mid;
        } else if (v[mid] < key) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}

int upperBound(vector<int>& v, int key) {
    int low = 0, high = v.size() - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (v[mid] <= key) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return low;
}

int upperBound(int v[], int n, int key) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (v[mid] <= key) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return low;
}
