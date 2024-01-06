using namespace std;
#include <bits/stdc++.h>

// LC- 637 https://leetcode.com/problems/average-of-levels-in-binary-tree/


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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ans;
        if(root == NULL)
        return  ans;

        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty())
        {
            double sum = 0;
            int qsize = q.size();
            for(int i = 0; i < qsize; i++)
            {
                TreeNode* item = q.front();
                q.pop();
                sum += item->val;
                if(item->left)
                {
                    q.push(item->left);
                }
                if(item->right)
                {
                    q.push(item->right);
                }
            }
            ans.push_back(sum/qsize);
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
    vector<double> ans = s.averageOfLevels(root);
    for(auto l: ans)
    {
        cout<< l << " ";
    }
    return 0;
}
