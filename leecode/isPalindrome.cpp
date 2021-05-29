#include <iostream>
#include <vector>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    bool isPalindrome(ListNode *head)
    {
        while (head == nullptr || head->next == nullptr)
            return true;
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast->next != NULL && fast->next->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode *pre = NULL;
        ListNode *temp;
        while (slow != NULL)
        {
            temp = slow->next;
            slow->next = pre;
            pre = slow;
            slow = temp;
        }

        fast = head;
        slow = pre;
        while (fast != NULL && slow != NULL)
        {
            if (fast->val != slow->val)
                return false;
            fast = fast->next;
            slow = slow->next;
        }
        return true;
    }
};

int main()
{

    return 0;
}
