// LC - 103 https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/description/
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

// almost copy of bfs
class Solution {
public:
    
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == NULL)
        return ans;

        deque <TreeNode*> dq;
        dq.push_front(root);
        bool normal = true;
        while(!dq.empty())
        {
            vector<int> level;
            int dqsize = dq.size();
            if(normal)
            {
                for(int i = 0; i<dqsize;i++)
                {
                    TreeNode* node = dq.front();
                    level.push_back(node->val);
                    dq.pop_front();
                    if(node->left)
                    {
                        dq.push_back(node->left);
                        
                    }
                    if(node->right)
                    {
                        dq.push_back(node->right);
                        
                    }
                }
            }
            else
            {
                for(int i = 0; i<dqsize;i++)
                {
                    TreeNode* node = dq.back();
                    level.push_back(node->val);
                    dq.pop_back();
                    if(node->right)
                    {
                        dq.push_front(node->right);
                        
                    }
                    if(node->left)
                    {
                        dq.push_front(node->left);
                        
                    }
                    
                }
            }
            ans.push_back(level);
            normal = !normal;
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
     vector<vector<int>> ans = s.zigzagLevelOrder(root);
    for(auto l: ans)
    {
        for(auto i:l)
        cout<< i << " ";
        cout << endl;
    }
    return 0;
}
