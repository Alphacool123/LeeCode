#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    ListNode *deleteNode(ListNode *head, int val)
    {
        if (head->val == val)
            return head->next;
        ListNode *prev = NULL;
        ListNode *cur = head;
        while (cur != NULL)
        {
            if (cur->val == val)
            {
                prev->next = cur->next;
                return head;
            }
            prev = cur;
            cur = cur->next;
        }
    }
};

class Solution
{
public:
    ListNode *deleteNode(ListNode *head, int val)
    {
        if (head->val == val)
            return head->next;
        ListNode *pre = head, *cur = head->next;
        while (cur != nullptr && cur->val != val)
        {
            pre = cur;
            cur = cur->next;
        }
        if (cur != nullptr)
            pre->next = cur->next;
        return head;
    }
};
