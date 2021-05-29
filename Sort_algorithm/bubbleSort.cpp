#include <iostream>
#include <limits>
#include <vector>
using namespace std;

// 代码分功能写
// 冒泡排序
// 时间复杂度O(n2)
// 空间复杂度O(1)
// 最好时间复杂度O(n)
template <typename T>
void bubbleSort(T *addr, int length)
{
    for (int i = 1; i < length; i++)
    {
        for (int j = 0; j < length - i; j++)
        {
            if (addr[j] > addr[j + 1])
            {
                swap(addr[j], addr[j + 1]);
            }
        }
    }
}

//冒泡排序2
template <typename T>
void bubbleSort2(T *addr, int length)
{
    for (int i = 1; i < length; i++)
    {
        for (int j = 0; j < length - i; j++)
        {
            if (addr[j] > addr[j + 1])
            {
                swap(addr[j], addr[j + 1]);
            }
        }
    }
}

// 选择排序
// 时间复杂度O(n2)
// 空间复杂度O(1)
// 最好情况O(n2)
// 不稳定，两个相等的数
template <typename T>
void selectionSort(T *addr, int length)
{
    for (int i = 0; i < length - 1; i++)
    {
        int minIdex = i;
        for (int j = i + 1; j < length; j++)
        {
            if (addr[j] < addr[minIdex])
            {
                minIdex = j;
            }
        }
        swap(addr[minIdex], addr[i]);
    }
}

//选择排序2
template <typename T>
void selectionSort2(T *addr, int length)
{
    for (int i = 0; i < length - 1; i++)
    {
        for (int j = i + 1; j < length; j++)
        {
            if (addr[i] > addr[j])
            {
                swap(addr[i], addr[j]);
            }
        }
    }
}

// 选择排序3
template <typename T>
void selectionSort3(T *addr, int length)
{
    int p;
    for (int i = 0; i < length - 1; i++)
    {
        p = i;
        for (int j = i + 1; j < length; j++)
        {
            p = addr[p] > addr[j] ? j : p;
        }
        swap(addr[p], addr[i]);
    }
}

// 插入排序
// 稳定排序
// 时间复杂度O(n2)
// 空间复杂度O(1)
// 最快时间O(n)
template <typename T>
void insertSort3(T *addr, int length)
{
    for (int i = 1; i < length; i++)
    {
        for (int j = i; j > 0; j--)
        {
            if (addr[j] < addr[j - 1])
                swap(addr[j], addr[j - 1]);
        }
    }
}

template <typename T>
void insertSort2(T *addr, int length)
{
    for (int i = 1; i < length; i++)
    {
        T maxIndex = i;
        while (maxIndex >= 1)
        {
            if (addr[maxIndex] < addr[maxIndex - 1])
            {
                swap(addr[maxIndex], addr[maxIndex - 1]);
            }
            maxIndex--;
        }
    }
}

//插入排序
template <typename T>
void insertSort(T *addr, int length)
{
    for (int i = 0; i < length; i++)
    {
        int preIndex = i - 1;
        T current = addr[i];
        while (preIndex >= 0 && addr[preIndex] > current)
        {
            addr[preIndex + 1] = addr[preIndex];
            preIndex -= 1;
        }

        addr[preIndex + 1] = current;
    }
}

//归并排序；迭代版
template <typename T>
void merge_sort(T arr[], int len)
{
    T *a = arr;
    // 在堆区开辟了T型的数组，数组长度为len
    T *b = new T[len];

    // 从数组每个元素开始，×2，×4......
    for (int seg = 1; seg < len; seg += seg)
    {
        for (int start = 0; start < len; start += seg + seg)
        {
            // 熟练使用max,min等方法
            int low = start, mid = min(start + seg, len), high = min(start + seg + seg, len);
            int k = low;
            int start1 = low, end1 = mid;
            int start2 = mid, end2 = high;

            // 当两个数组长度不一样时的分开讨论
            while (start1 < end1 && start2 < end2)
                b[k++] = a[start1] < a[start2] ? a[start1++] : a[start2++];
            while (start1 < end1)
                b[k++] = a[start1++];
            while (start2 < end2)
                b[k++] = a[start2++];
        }
        T *temp = a;
        a = b;
        b = temp;
    }
    if (a != arr)
    {
        for (int i = 0; i < len; i++)
            b[i] = a[i];
        b = a;
    }
    delete[] b;
}

//归并排序
void Merge(vector<int> &Array, int front, int mid, int end)
{
    vector<int> LeftSubArray(Array.begin() + front, Array.begin() + mid + 1);
    vector<int> RightSubArray(Array.begin() + mid + 1, Array.begin() + end + 1);
    int idxLeft = 0;
    int idxRight = 0;

    //在数组后面插入int类型的最大数字
    LeftSubArray.insert(LeftSubArray.end(), numeric_limits<int>::max());
    RightSubArray.insert(RightSubArray.end(), numeric_limits<int>::max());

    for (int i = front; i <= end; i++)
    {
        if (LeftSubArray[idxLeft] < RightSubArray[idxRight])
        {
            Array[i] = LeftSubArray[idxLeft++];
        }
        else
        {
            Array[i] = RightSubArray[idxRight]++;
        }
    }
}

void MergeSort(vector<int> &Array, int front, int end)
{
    if (front >= end)
        return;
    int mid = (front + end) / 2;
    MergeSort(Array, front, mid);
    MergeSort(Array, mid + 1, end);
    Merge(Array, front, mid, end);
}

//归并排序
void MergeSort1(vector<int> &Array, int front, int mid, int end)
{
    vector<int> LeftSubArray(Array.begin() + front, Array.begin() + mid + 1);
    vector<int> RightSubArray(Array.begin() + mid + 1, Array.begin() + end + 1);
    int idxLeft = 0;
    int idxRight = 0;
    LeftSubArray.insert(LeftSubArray.end(), numeric_limits<int>::max());
    RightSubArray.insert(RightSubArray.end(), numeric_limits<int>::max());
    for (int i = front; i <= end; i++)
    {
        if (LeftSubArray[idxLeft] < RightSubArray[idxRight])
        {
            Array[i] = LeftSubArray[idxLeft];
            idxLeft++;
        }
        else
        {
            Array[i] = RightSubArray[idxRight];
            idxRight++;
        }
    }
}

void Merge1(vector<int> &Array, int front, int end)
{
    if (front >= end)
        return;
    int mid = (front + end) / 2;
    Merge1(Array, front, mid);
    Merge1(Array, mid + 1, end);
    MergeSort1(Array, front, mid, end);
}

// 快速排序
// 单轴快排和双轴快排....

int main()
{
    int addr[] = {0, 2, 3, 1, 6, 5, 4, 9, 8, 7};
    vector<int> v = {0, 2, 3, 1, 6, 5, 4, 9, 8, 7};

    MergeSort(v, 0, 9);
    for (int i = 0; i < 10; i++)
    {
        cout << v[i] << endl;
    }

    return 0;
}