using namespace std;
#include <bits/stdc++.h>

//143- https://leetcode.com/problems/reorder-list/
 //Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
    ListNode* getMid(ListNode* head)
    {
    ListNode* s = head, *f = head;
    while(f && f->next)
    {
        s = s->next;
        f = f->next->next;
    }
    return s;
    }

ListNode* reverseLL(ListNode* head)
{
    if(head == NULL || head->next == NULL)
    return head;

    ListNode* p = NULL, *curr = head, *next = head->next;

    while(curr!=NULL)
    {
        curr->next = p;
        p = curr;
        curr = next;
        if(next!=NULL)
        next = next->next;
    }
    return p;
}


    //L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
    // questions are mostly based on fast n slow pointers & require reversing of LL
    void reorderList(ListNode* head) {
        // in case of 0-2 nodes
        if(head == NULL || head->next == NULL || head->next->next == NULL)
        return;

        ListNode* mid = getMid(head);
        ListNode* hs = reverseLL(mid);

        ListNode* hf = head;
        ListNode* temp;

        while(hf && hs)
        {
            temp = hf->next;
            hf->next = hs;
            hf = temp;

            temp = hs->next;
            hs->next = hf;
            hs = temp;
        }

        // set next of tail to null
        if(hf!=NULL)
        hf->next = NULL;

    }

  int main()
 {
    ListNode *node4 = new ListNode(4);
    ListNode *node2 = new ListNode(3,node4);
    ListNode *node1 = new ListNode(2,node2);
    ListNode *head = new ListNode(1,node1);
    ListNode *p = head;
    reorderList(head);
    while(p!=NULL)
    {
        cout<< p->val << " --> ";
        p = p -> next;
    }
    cout<<  "END";
    return 0;
 }