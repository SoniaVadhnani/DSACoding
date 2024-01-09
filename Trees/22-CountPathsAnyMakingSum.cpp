
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
 int countPath(TreeNode* root, int sum)
 {
    vector<int> path;
    return helper(root, sum, path);
 }

 int helper(TreeNode* node, int sum, vector<int> path)
 {
    if(node==NULL) return 0;
    path.push_back(node->val);
    int count = 0;
    int currsum = 0;

    // start from back and start adding
    for(int i=path.size()-1;i>=0;i--)
    {
        currsum += path[i];
        if(currsum == sum)
        count++;
        if(currsum>sum)
        break;
    }

    count += helper(node->left, sum, path) + helper(node->right, sum, path);

    //backtrack
    path.pop_back();

    return count;
 }

};

int main()
{
    TreeNode* r1r = new TreeNode(1);
    TreeNode* r1l = new TreeNode(14,r1r,nullptr);
    TreeNode* r1 = new TreeNode(15,r1l,nullptr);
    TreeNode* l1 = new TreeNode(6);
    TreeNode* root = new TreeNode(9,l1,r1);
    
    Solution s = Solution();
    cout<< s.countPath(root, 15);
    return 0;
}

