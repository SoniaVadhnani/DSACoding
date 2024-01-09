// lc 543 https://leetcode.com/problems/diameter-of-binary-tree/


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
int diameter=0;
    int diameterOfBinaryTree(TreeNode* root) {
        int h = height(root);
        return diameter-1;
    }

    int height(TreeNode* node)
    {
        // leaf node
        if(node==NULL)
        return 0;

        //caller
        int left = height(node->left);
        int right = height(node->right);
        //diameter update
        diameter = max(diameter, left+right+1);
        return max(left,right)+1;
    }
};

int main()
{
    TreeNode* r1r = new TreeNode(7);
    TreeNode* r1l = new TreeNode(15);
    TreeNode* r1 = new TreeNode(9,r1l,r1r);
    TreeNode* l1 = new TreeNode(9,r1r,NULL);
    TreeNode* root = new TreeNode(3,l1,r1);

    Solution s = Solution();
    cout<< s.diameterOfBinaryTree(root);
    return 0;
}