// lc hard 124 https://leetcode.com/problems/binary-tree-maximum-path-sum/description/

using namespace std;
#include <bits/stdc++.h>
//Definition for a binary tree node.
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
int currmax = INT_MIN;
int maxPathSum(TreeNode* root) {
        maxPathSum1(root);
        return currmax;
    }
    int maxPathSum1(TreeNode* root) {
        if(root==NULL)
        return 0;

        int left = max(0,maxPathSum1(root->left));
        int right = max(0,maxPathSum1(root->right));
        int total = left + right + root->val;
        currmax = max(currmax, total);
        return max(left,right) + root->val;
    }
};