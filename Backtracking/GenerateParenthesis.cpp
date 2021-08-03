#include <bits/stdc++.h>

#include "./utilities.h"
using namespace std;
vector<string> AllParenthesis(int n) ;

// N is the number of pairs of parentheses
// Return list of all combinations of balanced parantheses
class Solution
{
    public:
    // AC: GFG | AC: LeetCode (Better than 100%)
    void findPermutation2(string& str, vector<string>& ans, int n, int open = 0, int close = 0)
    {
        if(str.length() == 2 * n) {
            ans.push_back(str);
            return;
        }

        if(open < n) {
            findPermutation2(str.append("("), ans, n, open + 1, close);
            str.pop_back();
        }
        if(close < open) {
            findPermutation2(str.append(")"), ans, n, open, close + 1);
            str.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string str = "";
        findPermutation2(str, ans, n);
        return ans;
    }

    // TLE: GFG | AC: LeetCode (Better than 5.5%)
    // TC: O(2^2n * n)
    bool isValid(string str) {
        int bal = 0;
        for(auto it: str) {
            if (it == '(')
                bal += 1;
            else
                bal -= 1;
            if (bal < 0) return false;
        }
        return bal == 0;
    }
    void findPermutation(string& str, vector<string>& ans, int n) {
        if(str.length() == 2 * n) {
            if(isValid(str)) ans.push_back(str);
            return;
        }

        findPermutation(str.append("("), ans, n);
        str.pop_back();
        findPermutation(str.append(")"), ans, n);
        str.pop_back();
    }
    vector<string> AllParenthesis(int n) {
        vector<string> ans;
        string str = "";
        findPermutation(str, ans, n);
        return ans;
    }
};

// { Driver Code Starts.


int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		Solution ob;
		vector<string> result = ob.AllParenthesis(n);
        sort(result.begin(),result.end());
		for (int i = 0; i < result.size(); ++i)
			cout<<result[i]<<"\n";
	}
	return 0;
}
  // } Driver Code Ends