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
      TreeNode(int s, int e) : startInterval(s), endInterval(e) {}
   };

class Solution {
public:

    vector<int> inorderTraversal(TreeNode* root) {
        
    }
};

int main()
{
    int arr[] = {3,8,6,7,-2,-8,4,9};

    TreeNode* node = new TreeNode(0,7);
    return 0;
}