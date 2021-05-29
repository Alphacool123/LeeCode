#include <iostream>
using namespace std;

template <class DataType>
struct Node
{
    DataType data;        //存储当前节点数据
    Node<DataType> *next; //存储下一个节点地址
};

template <class DataType>
class LinkList
{
public:
    LinkList();
    LinkList(DataType a[], int n);
    LinkList(const LinkList<DataType> &p);
    ~LinkList();
    int Length();
    DataType Get(int i);
    int Locate(DataType x);
    void Insert(int i, DataType x);
    DataType Delete(int i);
    void PrintList();

private:
    Node<DataType> *first;
};

template <class DataType>
LinkList<DataType>::LinkList()
{
    first = new Node<DataType>;
    first->next = NULL;
}

//头插法
// template<class DataType>
// LinkList<DataType>::LinkList(DataType a[], int n)
// {
//     first = new Node<DataType>;
//     first->next =NULL;
//     for (int i =0;i<n;i++)
//     {
//         Node<DataType> *s = new Node<DataType>;
//         s->data=a[i];
//         s->next= first->next;
//         first->next =s;

//     }
// }

//尾插法
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
int LinkList<DataType>::Length()
{
    Node<DataType> *p = first->next;
    int count = 0;
    while (p != NULL)
    {
        p = p->next;
        count++;
    }
    return count;
}

template <class DataType>
DataType LinkList<DataType>::Get(int i)
{
    Node<DataType> *p = first->next;
    int count = 1;
    while (p != NULL && count < i)
    {
        p = p->next;
        count++;
    }
    if (p == NULL)
        throw "location";
    else
        return p->data;
}

template <class DataType>
int LinkList<DataType>::Locate(DataType x)
{
    Node<DataType> *p = first->next;
    int count = 1;
    while (p != NULL)
    {
        if (p->data == x)
            return count;
        p = p->next;
        count++;
    }
    return 0;
}

template <class DataType>
void LinkList<DataType>::Insert(int i, DataType x)
{
    Node<DataType> *p = first;
    int count = 0;
    while (p != NULL && count < i - 1)
    {
        p = p->next;
        count++;
    }
    if (p == NULL)
        throw "location";
    else
    {
        Node<DataType> *s = new Node<DataType>;
        s->data = x;
        s->next = p->next;
        p->next = s;
    }
}

template <class DataType>
DataType LinkList<DataType>::Delete(int i)
{
    Node<DataType> *p = first;
    int count = 0;
    while (p != NULL && count < i - 1)
    {
        p = p->next;
        count++;
    }
    if (p == NULL || p->next == NULL)
        throw "locaation";
    else
    {
        Node<DataType> *q = p->next;
        DataType x = q->data;
        p->next = q->next;
        return x;
    }
}

template <class DataType>
void LinkList<DataType>::PrintList()
{
    Node<DataType> *p = first->next;
    while (p != NULL)
    {
        cout << p->data << endl;
        p = p->next;
    }
}

int main()
{
    LinkList<int> p;
    p.Insert(1, 5);
    p.Insert(2, 9);
    p.Insert(3, 6);
    p.Insert(4, 0);
    p.PrintList();
    // cout << p.Length() << endl;
    // cout << p.Get(2) << endl;
    cout << p.Locate(9) << endl;
    p.Delete(1);
    cout << p.Get(1) << endl;
    p.PrintList();
    return 0;
}
