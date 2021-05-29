#include <iostream>
using namespace std;

struct Node
{
    int val;
    Node *next;
    Node(int x) : val(x), next(nullptr){};
};

Node *reverse(Node *head)
{
    Node *pred = nullptr;
    while (head != nullptr)
    {
        Node *temp = head->next;
        head->next = pred;
        pred = head;
        head = temp;
    }
    return pred;
}

void print(Node *head)
{
    while (head)
    {
        cout << head->val << " ";
        head = head->next;
    }
}

int main()
{
    Node *a1 = new Node(1);
    Node *a2 = new Node(2);
    Node *a4 = new Node(3);
    a1->next = a2;
    a2->next = a4;
    print(a1);
    cout << endl;

    print(reverse(a1));
}