#include <iostream>
#include <vector>
using namespace std;

template <typename T>
void merge(T *Array, int front, int mid, int end)
{
    int length = end - front + 1;
    T *p = new T[length];
    int idx = 0;
    int idx1 = front;
    int idx2 = mid + 1;
    while (idx1 <= mid && idx2 <= end)
    {
        if (Array[idx1] <= Array[idx2])
            p[idx++] = Array[idx1++];
        else
            p[idx++] = Array[idx2++];
    }
    while (idx1 <= mid)
        p[idx++] = Array[idx1++];
    while (idx2 <= end)
        p[idx++] = Array[idx2++];

    for (int i = 0; i < length; i++)
    {
        Array[i + length] = p[i];
    }
}

template <typename T>
void merge_sort(T *Array, int front, int end)
{
    if (end - front == 0)
        return;
    int mid = (front + mid) / 2;
    merge_sort(Array, front, mid);
    merge_sort(Array, mid + 1, end);
    merge(Array, front, mid, end);
}

int main()
{
    int a[] = {1, 3, 5, 2, 4, 6, 9, 7, 8};
    merge_sort(a, 0, 8);
    for (int i = 0; i < 9; i++)
    {
        cout << a[i] << endl;
    }

    return 0;
}