#include <iostream>
using namespace std;

const int MaxSize = 100;
template <class DataType>
class SeqList
{
public:
    SeqList() { length = 0; }     //构造函数
    SeqList(DataType a[], int n); //有参构造
    ~SeqList() {}                 //声明和定义

    int Length() { return length; } //线性表长度
    DataType Get(int i);            //按位查找
    int Locate(DataType x);         //按值查找
    void Insert(int i, DataType x);
    DataType Delete(int i);
    void PrintList();

private:
    DataType data[MaxSize];
    int length;
};

template <class DataType>
SeqList<DataType>::SeqList(DataType a[], int n)
{
    if (n > MaxSize)
        throw "wrong parameter";
    for (int i = 0; i < n; i++)
    {
        data[i] = a[i];
        length = n;
    }
}

template <class DataType>
DataType SeqList<DataType>::Get(int i)
{
    if (i < i && i > length)
        throw "wrong location";
    else
        return data[i - 1];
}

template <class DataType>
int SeqList<DataType>::Locate(DataType x)
{
    for (int i = 0; i < length; i++)
    {
        if (data[i] == x)
            return i + 1;
        else
            return 0;
    }
}

template <class DataType>
void SeqList<DataType>::Insert(int i, DataType x)
{
    if (length >= MaxSize)
        throw "overflow";
    if (i < 1 || i > length + 1)
        throw "location";
    for (int j = length; j >= i; j--)
    {
        data[j] = data[j - 1];
    }
    data[i - 1] = x;
    length++;
}

template <class DataType>
DataType SeqList<DataType>::Delete(int i)
{
    int x;
    if (length == 0)
        throw "underflow";
    if (i < 1 || i > length)
        throw "location";
    x = data[i];
    for (int j = i; j < length; j++)
    {
        data[j - 1] = data[j];
    }
    length--;
    return x;
}

template <class DataType>
void SeqList<DataType>::PrintList()
{
    for (int i = 0; i < length; i++)
    {
        cout << data[i] << endl;
    }
}

int main()
{
    SeqList<int> p;
    p.Insert(1, 9);
    p.Insert(2, 4);
    p.PrintList();
    p.Insert(2, 3);
    cout << p.Length() << endl;
    p.PrintList();
    p.Delete(2);
    p.PrintList();

    return 0;
}
