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
    ListNode *detectCycle(ListNode *head)
    {
        if (head == NULL || head->next == NULL || head->next->next == NULL)
            return NULL;
        ListNode *slow = head->next;
        ListNode *fast = head->next->next;
        while (fast->next != NULL && fast->next->next != NULL)
        {
            if (slow == fast)
            {
                fast = head;
                while (fast != NULL)
                {
                    if (fast == slow)
                        return slow;
                    fast = fast->next;
                    slow = slow->next;
                }
            }
            slow = slow->next;
            fast = fast->next->next;
        }
        return NULL;
    }
};
