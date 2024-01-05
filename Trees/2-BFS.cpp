using namespace std;
#include <bits/stdc++.h>

// LC- 102 https://leetcode.com/problems/binary-tree-level-order-traversal/


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
    vector<vector<int>> levelOrder(TreeNode* root) {

        vector<vector<int>> ans;
        if(root == NULL)
        return  ans;

        queue<TreeNode*> q;
        q.push(root);
        ans.push_back({root->val});
        
        while(!q.empty())
        {
            TreeNode* item = q.front();
            q.pop();
            vector<int> level;
            if(item->left)
            {
                q.push(item->left);
                level.push_back(item->left->val);
            }
            if(item->right)
            {
                q.push(item->right);
                level.push_back(item->right->val);
            }

            if(level.size())
            ans.push_back(level);
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
    vector<vector<int>> ans = s.levelOrder(root);
    for(auto l: ans)
    {
        for(auto i:l)
        cout<< i << " ";
        cout << endl;
    }
    return 0;
}