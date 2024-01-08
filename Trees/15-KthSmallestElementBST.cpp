// lc - 230 https://leetcode.com/problems/kth-smallest-element-in-a-bst/description/

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

// solution 1 - in order traversal and return kth val
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        vector<int> ans = inOt(root);
        return ans[k-1];
    }

    vector<int> inOt(TreeNode* root)
    {
        if(root == NULL)
        return {};

        vector<int> l = inOt(root->left);
        l.push_back(root->val);
        vector<int> r = inOt(root->right);
        if(r.size())
        l.insert(l.end(), r.begin(), r.end());
        return l;
    }
};

// solution 2 - while in order trvaersal, maintain the count and check with k, when match return it
class Solution2 {
public:
    int kthSmallest(TreeNode* root, int k) {
        TreeNode* ans = inOt(root,k);
        return ans->val;
    }
int count = 0;
    TreeNode* inOt(TreeNode* root, int k)
    {
        if(root == NULL)
        return root;

        TreeNode* l = inOt(root->left, k);
        if(l)
        return l;

        count++;
        
        if(count==k)
        return root;

        return inOt(root->right, k);
        
    }
};

int main()
{
    TreeNode* r1r = new TreeNode(16);
    TreeNode* r1l = new TreeNode(14);
    TreeNode* r1 = new TreeNode(15,r1l,r1r);
    TreeNode* l1 = new TreeNode(3);
    TreeNode* root = new TreeNode(9,l1,r1);

    Solution s = Solution();
    for(auto i: s.inOt(root))
    cout<< i << " ";
    return 0;
}
