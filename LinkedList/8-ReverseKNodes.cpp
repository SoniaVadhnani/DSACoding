using namespace std;
#include <bits/stdc++.h>

//25 - https://leetcode.com/problems/reverse-nodes-in-k-group/description/
 //Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

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

ListNode* reverseKGroup(ListNode* head, int k) {
    if(head == NULL || k<=1)
    return head;

    int size = 0;
    ListNode* a = head;
    while(a!=NULL)
    {
        size++;
        a=a->next;
    }
    int r = size/k;
   
    ListNode* p = NULL, *curr = head;
    while(r)
    {
        ListNode* last = p;
        ListNode* newEnd = curr;
        ListNode* next = curr->next;
        
        for(int i = 0; i < k && curr!=NULL ; i++)
        {
            curr->next = p;
            p = curr;
            curr = next;
            if(next!=NULL)
            next = next->next;
        }
        
        if(last != NULL)
        last->next = p;
        else
        head = p;

        newEnd->next = curr;
        p = newEnd;

        if(curr == NULL)
        break;

        r--;

    }
    return head;
}

int main()
 {
    ListNode *node4 = new ListNode(4);
    ListNode *node2 = new ListNode(3,node4);
    ListNode *node1 = new ListNode(2,node2);
    ListNode *head = new ListNode(1,node1);
    ListNode *p = reverseKGroup(head, 3);
    
    while(p!=NULL)
    {
        cout<< p->val << " --> ";
        p = p -> next;
    }
    cout<<  "END";
    return 0;
}