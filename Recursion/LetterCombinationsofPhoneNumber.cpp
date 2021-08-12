#include<bits/stdc++.h>
#include "../utilities.h"
using namespace std;

class Solution {
    vector<string> keys{"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    void findCombinations(string digits, int currentLength, vector<string>&ans, string& ds) {
        if(currentLength == digits.length()) {
            ans.push_back(ds);
            return;
        }

        for(auto &c: keys[digits[currentLength] - '2']) {
            ds.push_back(c);
            findCombinations(digits, currentLength + 1, ans, ds);
            ds.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        if(digits == "") return {};
        vector<string> ans;
        string ds;
        findCombinations(digits, 0, ans, ds);
        return ans;
    }
};

int main() {
    Solution s;
    string digits{"23"};
    vector<string> ans = s.letterCombinations(digits);
    cout << ans;
    return 0;
}
