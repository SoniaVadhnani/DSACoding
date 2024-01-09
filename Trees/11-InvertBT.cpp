// lc -226 https://leetcode.com/problems/invert-binary-tree/description/

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
    TreeNode* invertTree(TreeNode* root) {
        if(root==NULL || (root->left==NULL && root->right==NULL))
        return root;

        // left side swapping
        root->left = invertTree(root->left);
        //right side swapping
        root->right = invertTree(root->right);

        // curr node swapping in last
        TreeNode* temp = root->left;
        root->left = root->right;
        root->right = temp;

        return root;
    }
};