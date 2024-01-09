// LC 112 https://leetcode.com/problems/path-sum/
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
    bool hasPathSum(TreeNode* root, int targetSum) {
        return helper(root, targetSum, 0);
    }
    bool helper(TreeNode* root, int targetSum, int curr)
    {
        if(root==NULL)
        return false;

        curr += root->val;

        if(curr==targetSum && root->left==NULL && root->right==NULL)
        return true;

        return helper(root->left, targetSum, curr) || helper(root->right, targetSum, curr);
    }
};