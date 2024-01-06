using namespace std;
#include <bits/stdc++.h>


struct TreeNode {
      int val;
      int startInterval;
      int endInterval;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
      TreeNode(int v, int s, int e) : val(v), startInterval(s), endInterval(e) {}
   };

class SegmentTree {
public:
    TreeNode* root;
    SegmentTree(int arr[])
    {
        int size = sizeof(arr)/sizeof(arr[0]);
        this->root = constructST(arr, 0, size-1);
    }

    TreeNode* constructST(int arr[], int start, int end)
    {
        if(start==end)
        {
            return new TreeNode(arr[start], start, end);
        }

        TreeNode* curr = new TreeNode();
        int mid = (start + end)/2;
        curr -> left = constructST(arr, start, mid);
        curr -> right = constructST(arr, mid+1, end);
        curr->val = curr->left->val + curr->right->val;

        return curr;
    }
};

int main()
{
    int arr[] = {3,8,6,7,-2,-8,4,9};

    return 0;
}