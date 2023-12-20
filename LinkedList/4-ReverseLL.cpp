using namespace std;
#include <bits/stdc++.h>

//https://leetcode.com/problems/reverse-linked-list/description/
 //Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

// Recursive
ListNode* reverseLL(ListNode* curr)
{
    // base condition
    if(curr == NULL || curr->next == NULL)
    return curr;

    ListNode* rest = reverseLL(curr->next); // do nothing with this
    
    curr->next->next = curr;
    curr->next  =NULL;

    // returning the end node
    return rest;
}

//Iterative or INPLACE ************** VVVImp
ListNode* inplace(ListNode* head)
{
    // only one element
    if(head == NULL || head->next == NULL)
    return head;

    ListNode* prev = NULL, *curr = head, *next = head->next;
    while(curr)
    {
        curr->next = prev;
        prev = curr;
        curr = next;
        if(next != NULL)
        next = next->next;
    }
    return prev;
}


 int main()
 {
    ListNode *node4 = new ListNode(4);  // new here is imp when o/p pointer is needed.
    ListNode *node2 = new ListNode(3,node4);
    ListNode *node1 = new ListNode(2,node2);
    ListNode *head = new ListNode(1,node1);
    ListNode *p = inplace(head);
    while(p!=NULL)
    {
        cout<< p->val << " --> ";
        p = p -> next;
    }
    cout<<  "END";
    return 0;
 }