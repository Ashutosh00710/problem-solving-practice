#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void rotateByOne(vector<int>& array) {
      int size = array.size() - 1;
      int current = array[size];
      int temp;
      for(int i = 0; i <= size; i++) {
        temp = array[i];
        array[i] = current;
        current = temp;
      }
    }

    void printArray(vector<int>& array) {
      for(auto it: array) {
        cout << it << ", ";
      }
      cout << endl;
    }
};

int main() {
    Solution sol;
    vector<int> test = { 1, 2, 3, 4, 5 };
    sol.rotateByOne(test);
    sol.printArray(test);
    return 0;
}
