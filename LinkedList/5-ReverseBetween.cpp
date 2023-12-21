using namespace std;
#include <bits/stdc++.h>

//https://leetcode.com/problems/reverse-linked-list-ii/
 //Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };


ListNode* reverseBetween(ListNode* head, int left, int right) {
        // traverse till left - 1 to place prev there - this is skipping till left - 1 nodes
        ListNode* curr = head, *prev = NULL;
        for(int i = 1; i<left; i++) // make i = 0 in case counting from 0
        {
            prev = curr;
            curr = curr->next;
        }

        ListNode* last = prev;
        ListNode* newEnd = curr;
        
        ListNode* next = curr->next;
        // reverse from left to right as seperate LL
        // size of between list time
        for(int i = 0; curr!=NULL && i< right-left+1 ; i++)
        {
            curr->next = prev;
            prev  = curr;
            curr = next;
            if(next !=NULL)
            next = next->next;
        }

        // join the missing links
        if(last!=NULL)
        {
            last->next = prev;
        }
        else
        {
            head = prev;
        }

        newEnd->next = curr;
        return head;
    }

 int main()
 {
    ListNode *node4 = new ListNode(2);
    ListNode *node2 = new ListNode(3,node4);
    ListNode *node1 = new ListNode(4,node2);
    ListNode *head = new ListNode(1,node1);
    ListNode *p = reverseBetween(head, 2, 4);
    while(p!=NULL)
    {
        cout<< p->val << " --> ";
        p = p -> next;
    }
    cout<<  "END";
    return 0;
 }