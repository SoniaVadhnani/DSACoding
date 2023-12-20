using namespace std;
#include <bits/stdc++.h>

 struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution {
public:
    

    void insertUsingRecursion(ListNode* head, int val, int index) {
        head = insertRec(3,3,head);
    }
private:
    ListNode* insertRec(int val, int indexDistance, ListNode* currNode)
    {
        // base condition if indexDistance = 0, meaning here we have to insert the node
        if(indexDistance == 0)
        {
            ListNode* a = new ListNode(val, currNode);
            return a;
        }

        currNode->next = insertRec(val, indexDistance - 1, currNode->next);
        return currNode;
    }
};


int main()
{
    ListNode *node4 = new ListNode(4);  // new here is imp when o/p pointer is needed.
    ListNode *node2 = new ListNode(2,node4);
    ListNode *node1 = new ListNode(1,node2);
    ListNode *head = new ListNode(0,node1);


    Solution sol = Solution();
    sol.insertUsingRecursion(head, 3, 3); 
    
    // display
    ListNode* p = head;
    while(p!=nullptr)
    {
        cout<< p->val << " --> ";
        p = p -> next;
    }
    cout<<  "END";

    return 0;
}