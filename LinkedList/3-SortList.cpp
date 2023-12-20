using namespace std;
#include <bits/stdc++.h>

//https://leetcode.com/problems/sort-list/
 //Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

// merging 2 sorted lists
    ListNode* merge(ListNode* list1, ListNode* list2)
    {
        ListNode* list3 = new ListNode(0), *temp = list3;
        while(list1 && list2)
        {
            if(list1->val <= list2->val)
            {
                list3->next = list1;
                list1 = list1->next;
            }
            else
            {
                list3->next = list2;
                list2 = list2->next;
            }
            list3 = list3->next;
        }

        list3->next = list1 ? list1 : list2;
        return temp->next;
    }

    // find the mid node of linked list => slow and fast pointer
    ListNode* getMid(ListNode* head) {
        ListNode *f = head, *s = NULL;
        while(f && f->next)
        {
            s = s ? s->next : head;
            f = f->next->next;
        }
        ListNode *mid = s->next;
        s->next = NULL;
        return mid;
    }

    ListNode* sortlist(ListNode* head) {
        // using merge sort
        if(head == NULL || head->next == NULL)
        {
            return head;
        }

        ListNode *mid = getMid(head);
        ListNode *left = sortlist(head);
        ListNode *right = sortlist(mid);
        return merge(left,right);
    }

    int main()
    {
    ListNode *node4 = new ListNode(1);  // new here is imp when o/p pointer is needed.
    ListNode *node2 = new ListNode(8,node4);
    ListNode *node1 = new ListNode(3,node2);
    ListNode *head = new ListNode(0,node1);
    ListNode *p = sortlist(head);
    while(p!=NULL)
    {
        cout<< p->val << " --> ";
        p = p -> next;
    }
    cout<<  "END";
        return 0;
    }