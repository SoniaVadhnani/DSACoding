
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

bool findPath(TreeNode* root, vector<int> arr)
{
 return helper(root, arr, 0);
}

bool helper(TreeNode* root, vector<int>& arr, int index)
{
    if(root==NULL || arr[index] != root->val)
    {
        return false;
    }

    if(index == arr.size()-1 && arr[index] == root->val)
    return true;

    return helper(root->left, arr, index+1) || helper(root->right, arr, index+1);

}
};

int main()
{
    TreeNode* r1r = new TreeNode(16);
    TreeNode* r1l = new TreeNode(14);
    TreeNode* r1 = new TreeNode(15,r1l,r1r);
    TreeNode* l1 = new TreeNode(3);
    TreeNode* root = new TreeNode(9,l1,r1);
    vector<int> arr = {9,15,14};
    Solution s = Solution();
    cout<< s.findPath(root, arr);
    return 0;
}

