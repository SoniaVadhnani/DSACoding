// LC-116 https://leetcode.com/problems/populating-next-right-pointers-in-each-node/
// Input: root = [1,2,3,4,5,6,7]
// Output: [1,#,2,3,#,4,5,6,7,#]

using namespace std;
#include <bits/stdc++.h>

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};


class Solution {
public:
    Node* connectIterative(Node* root) {
        Node* leftmost = root;
        
        while(leftmost)
        {
            Node* curr = leftmost;
            while(curr)
            {
                if(curr->left)
                {
                    curr->left->next=curr->right;
                    if(curr->next)
                    {
                        curr->right->next = curr->next->left;
                    }
                }
                curr = curr->next;
            }
            leftmost = leftmost->left;
        }
        return root;
    }

    Node* connectRecursive(Node* root) { 
       if(root == NULL) return NULL;
        if(root->left != NULL) root->left->next = root->right;
        if(root->right != NULL && root->next != NULL) root->right->next = root->next->left;
        connectRecursive(root->left);
        connectRecursive(root->right);
        return root;
    }
};
