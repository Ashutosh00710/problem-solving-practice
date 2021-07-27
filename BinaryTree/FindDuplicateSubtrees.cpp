#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    // not an efficient solution because string concatenation will take O(n^2) time
    // O(n^2) for each concatenation + O(n) for traversal
    string postOrder(TreeNode* root, unordered_map<string, int>& um, vector<TreeNode *>& res) {
        if (root == nullptr) return "";
        string s = to_string(root->val) + "," + postOrder(root->left, um, res) + "," + postOrder(root->right, um, res);

        if(um[s]++ == 1) res.push_back(root);
        return s;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<TreeNode *> res;
        unordered_map<string, int> um;
        postOrder(root, um, res);
        return res;
    }
};