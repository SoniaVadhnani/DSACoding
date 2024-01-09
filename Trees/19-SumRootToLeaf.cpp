// lc 129 https://leetcode.com/problems/sum-root-to-leaf-numbers/description/

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
    int sumNumbers(TreeNode* root) {
        return summ(root,0);
    }

    int summ(TreeNode* root, int sum)
    {
        if(root==NULL)
        return 0;

        if(root->left==NULL && root->right==NULL)
        {
            return sum+root->val;        }
        

        sum = (sum+root->val)*10;
       

        return summ(root->left, sum) + summ(root->right, sum);
    }
};