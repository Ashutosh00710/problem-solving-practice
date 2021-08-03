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

template<typename T>
int merge(T arr, int low, int mid, int high) {
    int *temp = new int[high - low + 1];
    int i = low, j = mid + 1, k = 0;
    while(i <= mid && j <= high)
    {
        if(arr[i] <= arr[j])
        {
            temp[k] = arr[i];
            i++;
        }
        else
        {
            temp[k] = arr[j];
            j++;
        }
        k++;
    }
    while(i <= mid)
    {
        temp[k] = arr[i];
        k++;
        i++;
    }
    while(j <= high)
    {
        temp[k] = arr[j];
        k++;
        j++;
    }
    for(int i = low; i <= high; i++)
        arr[i] = temp[i - low];
    delete[] temp;
    return 0;
}

template<typename T>
int mergesort(T arr, int low, int high) {
    if(low < high)
    {
        int mid = (low + high) / 2;
        mergesort(arr, low, mid);
        mergesort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
    return 0;
}

template<typename T>
void display2Dvector(vector<vector<T>>& v, bool isString = false) {
    int m = v.size();
      string str = "";
      cout << "[";
      for (int i = 0; i < m; i++) {
          cout << str << "[";
          string s = "";
          for (auto it : v[i]) {
              if(isString) cout << s<<"\"" << it << "\"";
              else cout << s << it;
              s = ", ";
          }
          cout << "]";
          str = ", ";
      }
      cout << "]"<<"\n";
}

template<typename T>
void displayVector(vector<T>& v, bool isString = false) {
    string s = "";
    cout << "[";
    for (auto it : v) {
        if(isString) cout << s<<"\"" << it << "\"";
        else cout << s << it;
        s = ", ";
    }
    cout << "]"<<"\n";
}
