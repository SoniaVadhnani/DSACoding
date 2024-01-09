// lc 105 https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/

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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // if the vector is empty, meaning no node
        if(preorder.size()==0)
        return NULL;

        // now the first element of preorder will be the root
        // find where the first element exists in inorder traversal

        int r = preorder[0];
        int index = 0;

        for(int i=0; i<inorder.size();i++)
        {
            if(inorder[i]==r)
            {
                index = i;
                break;
            }
        }

        TreeNode* root = new TreeNode(r);

        vector<int> lPre(preorder.begin()+1,preorder.begin()+index+1);
        vector<int> rPre(preorder.begin()+index+1,preorder.end());
        vector<int> lIn(inorder.begin(),inorder.begin()+index);
        vector<int> rIn(inorder.begin()+index+1,inorder.end());
        // instead of it, also 4 more parameters could be passed in the helper method are sstrat and end index of both the vectors
        // and hashmaps as well
        root->left = buildTree(lPre,lIn);
        root->right = buildTree(rPre,rIn);
        return root;
    }
};

int main()
{
    vector<int> pre = {3,8,9,20,15,7};
    vector<int> in = {8,9,3,15,20,7};

    Solution s = Solution();
    TreeNode* ans = s.buildTree(pre, in);
}