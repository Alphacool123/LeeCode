#include <iostream>
#include <map>
using namespace std;

// Definition for a Node.
class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        if (head == NULL)
            return head;
        Node *temp;
        Node *itr = head;
        while (itr != NULL)
        {
            Node *copy = new Node(itr->val);
            temp = itr->next;
            itr->next = copy;
            copy->next = temp;
            itr = temp;
        }
        itr = head;
        while (itr != NULL)
        {
            temp = itr->next->next;
            itr->next->random = itr->random != NULL ? itr->random->next : NULL;
            itr = temp;
        }
        itr = head;
        Node *res = head->next;
        while (itr != NULL)
        {
            temp = itr->next->next;
            itr->next->next = temp != NULL ? temp->next : NULL;
            itr->next = temp;
            itr = temp;
        }
        return res;
    }
};