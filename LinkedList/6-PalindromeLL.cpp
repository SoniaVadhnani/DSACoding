using namespace std;
#include <bits/stdc++.h>

//234- https://leetcode.com/problems/palindrome-linked-list/description/
 //Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

// Reverse 2nd half of LL
// compare 1st and 2nd half
// Re-Reverse the 2nd half

ListNode* getMid(ListNode* head)
{
    ListNode* s = NULL, *f = head;
    while(f && f->next)
    {
        s = s ? s->next : head;
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

bool isPalindrome(ListNode* head) {
    if(head == NULL || head->next == NULL)
    {
        return head;
    }

    ListNode* last = getMid(head);
    ListNode* newMid = reverseLL(last->next);
    ListNode* head2 = newMid;
    //last->next = newMid;

    // compare the halves
    ListNode* start = head;
    while(start && head2)
    {
        if(start->val != head2->val)
        break;

        start = start->next;
        head2 = head2->next;
    }

    reverseLL(newMid);

    return head == NULL|| head2 == NULL;

}

 int main()
 {
    ListNode *node4 = new ListNode(3);
    ListNode *node2 = new ListNode(2,node4);
    ListNode *node1 = new ListNode(2,node2);
    ListNode *head = new ListNode(1,node2);
    cout<<  isPalindrome(head);
    return 0;
 }