using namespace std;
#include <bits/stdc++.h>

// LC- 199 https://leetcode.com/problems/binary-tree-right-side-view/submissions/1138277806/


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
        vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(root==NULL)
        return ans;
        queue<TreeNode*> q;
        q.push(root);
        ans.push_back(root->val);
        while(!q.empty())
        {
            int rightmost = -101;
            int qsize = q.size();
            for(int i=0;i<qsize;i++)
            {
                TreeNode* node = q.front();
                q.pop();
                if(node->left)
                {
                    q.push(node->left);
                    rightmost = node->left->val;
                }
                if(node->right)
                {
                    q.push(node->right);
                    rightmost = node->right->val;
                }
            }
            if(rightmost!=-101)
            ans.push_back(rightmost);
        }
        return ans;
    }
};


int main()
{
    TreeNode* r1r = new TreeNode(7);
    TreeNode* r1l = new TreeNode(15);
    TreeNode* r1 = new TreeNode(20,r1l,r1r);
    TreeNode* l1 = new TreeNode(9);
    TreeNode* root = new TreeNode(3,l1,r1);

    Solution s = Solution();
    vector<int> ans = s.rightSideView(root);
    for(auto l: ans)
    {
        cout<< l << " ";
    }
    return 0;

}