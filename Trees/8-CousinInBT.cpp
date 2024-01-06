// LC 993 https://leetcode.com/problems/cousins-in-binary-tree/


using namespace std;
#include <bits/stdc++.h>

// * Definition for a binary tree node.
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
    bool isCousins(TreeNode* root, int x, int y) {
        TreeNode* xx = findNode(root, x);
        TreeNode* yy = findNode(root, y);

        return (level(root, xx, 0)==level(root,yy,0)) && !isSibling(root,xx,yy);
    }

    TreeNode*findNode(TreeNode* node, int x)
    {
        if(node==NULL) return node;
        if(node->val == x)
        return node;

        TreeNode* left = findNode(node->left,x);
        if(left!=NULL)
        return left;

        return findNode(node->right,x);
    }

    int level(TreeNode* node, TreeNode* x,int lev)
    {
        if(node==NULL)
        return 0;

        if(node==x)
        return lev;

        int l = level(node->left,x,lev+1);
        if(l!=0)
        return l;

        return level(node->right,x,lev+1);
    }

    bool isSibling(TreeNode* node, TreeNode* xx, TreeNode* yy)
    {
        if(node==NULL) return false;
        return (node->left == xx && node->right == yy) || (node->right == xx && node->left == yy) 
        || isSibling(node->left,xx,yy) || isSibling(node->right,xx,yy);
    }
};


int main()
{
    TreeNode* l1r = new TreeNode(2);
    TreeNode* r1r = new TreeNode(7);
    TreeNode* r1l = new TreeNode(15);
    TreeNode* r1 = new TreeNode(20,r1l,r1r);
    TreeNode* l1 = new TreeNode(9,NULL,l1r);
    TreeNode* root = new TreeNode(3,l1,r1);

    Solution s = Solution();
    cout<< s.isCousins(root,2,7);
    return 0;

}