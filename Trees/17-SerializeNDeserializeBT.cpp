// lc 297 (hard) https://leetcode.com/problems/serialize-and-deserialize-binary-tree/

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

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        TreeNode* curr = root;
        queue<TreeNode*> q;
        q.push(root);
        string ans = "";
        while(!q.empty())
        {
            TreeNode* node = q.front();
            q.pop();
            if(node==NULL)
            {
                ans += 'n';
                continue;
            }
            ans += to_string(node->val);
            cout<<ans<<endl;
            q.push(node->left);
            q.push(node->right);
        }
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        return helper(data, 0);
    }

    TreeNode* helper(string data, int curr)
    {
        if(curr >= data.length() || data[curr]=='n')
        return NULL;

        int d = int(data[curr])-48;
        cout<<d;
        TreeNode* node = new TreeNode(d);
        node->left = helper(data, 2*curr+1);
        node->right = helper(data, 2*curr+2);
        return node;
    }
};

int main()
{
    TreeNode* a = new TreeNode(6);
    TreeNode* b = new TreeNode(7);
    TreeNode* r1r = new TreeNode(5);
    TreeNode* r1l = new TreeNode(4,a,b);
    TreeNode* r1 = new TreeNode(3,r1l,r1r);
    TreeNode* l1 = new TreeNode(2);
    TreeNode* root = new TreeNode(1,l1,r1);
    Codec ser, deser;
    TreeNode* ans = deser.deserialize(ser.serialize(root));
    //cout<< ser.serialize(root);
    return 0;

    // todo: need to come back again
}
