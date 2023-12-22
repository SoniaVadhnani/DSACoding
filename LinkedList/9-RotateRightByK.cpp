using namespace std;
#include <bits/stdc++.h>

//16 - https://leetcode.com/problems/rotate-list/
 //Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || head->next==NULL || k<1)
        return head;

        ListNode* tail = head;
        int size = 1;
        while(tail->next)
        {
            tail = tail->next;
            size++;
        }

        // find the new tail
        ListNode* newTail = head;
        int skip = size - (k % size);
        for(int i = 0 ; i<skip-1; i++)
        {
            newTail  = newTail->next;
        }

        tail -> next = head;
        head = newTail->next;
        newTail->next = NULL;

        return head;
    }

int main()
 {
    ListNode *node4 = new ListNode(4 , new ListNode(5, new ListNode(6)));
    ListNode *node2 = new ListNode(3,node4);
    ListNode *node1 = new ListNode(2,node2);
    ListNode *head = new ListNode(1,node1);
    ListNode *p = rotateRight(head, 2);
    
    while(p!=NULL)
    {
        cout<< p->val << " --> ";
        p = p -> next;
    }
    cout<<  "END";
    return 0;
} 