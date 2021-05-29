#include <iostream>
using namespace std;

template <class DataType>
struct Node
{
    DataType data;
    Node<DataType> *next;
};

template <class DataType>
class LinkList
{
public:
    LinkList();
    LinkList(DataType a[], int n);
    ~LinkList();
    Node<DataType> *first;
};

template <class DataType>
LinkList<DataType>::LinkList()
{
    first = new Node<DataType>;
    first->next = NULL;
}

template <class DataType>
LinkList<DataType>::LinkList(DataType a[], int n)
{
    first = new Node<DataType>;
    Node<DataType> *r = first;
    for (int i = 0; i < n; i++)
    {
        Node<DataType> *s = new Node<DataType>;
        s->data = a[i];
        r->next = s;
        r = s;
    }
    r->next = NULL;
}

template <class DataType>
LinkList<DataType>::~LinkList()
{
    while (first != NULL)
    {
        Node<DataType> *p = first;
        first = first->next;
        delete p;
    }
}

template <class DataType>
Node<DataType> *mid_upnode(Node<DataType> *head)
{
    if (head == NULL || head->next == NULL || head->next->next == NULL)
        return head;
    Node<DataType> *slow = head;
    Node<DataType> *fast = head;
    while (fast->next != NULL && fast->next->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

template <class DataType>
Node<DataType> *mid_downode(Node<DataType> *head)
{
    if (head == NULL)
        return NULL;
    if (head->next == NULL)
        return head;
    Node<DataType> *slow = head->next;
    Node<DataType> *fast = head->next;
    while (fast->next != NULL && fast->next->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

template <class DataType>
Node<DataType> *sort_node(Node<DataType> *head, int pivot)
{
    Node<DataType> *less_front = NULL; //小于的头节点
    Node<DataType> *less_back = NULL;  //小于的尾节点
    Node<DataType> *same_front = NULL;
    Node<DataType> *same_back = NULL;
    Node<DataType> *more_front = NULL;
    Node<DataType> *more_back = NULL;
    Node<DataType> *temp = NULL;

    while (head != NULL)
    {
        temp = head->next;
        head->next = NULL;
        if (head->data < pivot)
        {
            if (less_front == NULL)
            {
                less_front = head;
                less_back = head;
            }
            else
            {
                less_back->next = head;
                less_back = head;
            }
        }
        if (head->data == pivot)
        {
            if (same_front == NULL)
            {
                same_front = head;
                same_back = head;
            }
            else
            {
                same_back->next = head;
                same_back = head;
            }
        }
        if (head->data > pivot)
        {
            if (more_front == NULL)
            {
                more_front = head;
                more_back = head;
            }
            else
            {
                more_back->next = head;
                more_back = head;
            }
        }
        head = temp;
    }
    if (less_back != NULL)
    {
        less_back->next = same_front;
        same_back = same_back == NULL ? less_back : same_back;
    }
    if (same_back != NULL)
    {
        same_back->next = more_front;
    }

    // less_back->next = same_front;
    // same_back->next = more_front;

    return less_front != NULL ? less_front : (same_front != NULL ? same_front : more_front);
    // return less_front;
}

int main()
{
    int a[5] = {0, 4, 3, 3, 2};
    LinkList<int> b(a, 5);
    Node<int> *p = b.first->next;
    cout << "分割前：";
    while (p != NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
    p = b.first->next;
    Node<int> *res = sort_node(p, 4);
    cout << "分割后：";
    while (res != NULL)
    {
        cout << res->data << " ";
        res = res->next;
    }
    // Node<int> *p = mid_downode(b.first->next);

    return 0;
}