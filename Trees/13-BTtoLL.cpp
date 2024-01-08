// LC - 114 https://leetcode.com/problems/flatten-binary-tree-to-linked-list/description/

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
    void flatten(TreeNode* root) {
        TreeNode* curr = root;
        while(curr)
        {
            if(curr->left)
            {
                TreeNode* temp = curr->right;
                curr->right = curr->left;
                curr->left = NULL;
                TreeNode* temp1 = curr;
                while(temp1->right)
                {
                    temp1 = temp1->right;
                }
                temp1->right = temp;
            }
            curr = curr->right;
        }
    }
};