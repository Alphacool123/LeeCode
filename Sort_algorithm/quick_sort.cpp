#include <iostream>
#include <vector>
using namespace std;

template <typename T>
int partition(vector<T> &Array, int left, int right)
{
    T pivot = Array[right];
    // idxright不取值right-1的原因是，防止极端情况出现
    int idxleft = left, idxright = right;
    while (idxleft < idxright)
    {
        while (idxleft < idxright && Array[idxleft] < pivot)
        {
            idxleft++;
        }

        while (idxleft < idxright && Array[idxright] >= pivot)
        {
            idxright--;
        }
        swap(Array[idxleft], Array[idxright]);
    }
    swap(Array[idxright], Array[right]);
    return idxleft;
}

template <typename T>
void quick_sort(vector<T> &Array, int left, int right)
{
    if (left < right)
    {
        int partition_index = partition(Array, left, right);
        quick_sort(Array, left, partition_index - 1);
        quick_sort(Array, partition_index + 1, right);
    }
}

// 区数组左边第一个元素作为pivot
template <typename T>
int partition1(vector<T> &Array, int left, int right)
{
    T pivot = Array[left];
    int idx_left = left, idx_right = right;
    while (idx_left < idx_right)
    {
        while (idx_left < idx_right && Array[right] >= pivot)
            idx_left--;
        while (idx_left < idx_right && Array[left] < pivot)
            idx_right++;
        swap(Array[idx_right], Array[idx_left]);
    }
    swap(Array[left], Array[idx_left]);

    return idx_right;
}

template <typename T>
void quick_sort1(vector<T> &Array, int left, int right)
{
    if (left <= right)
    {
        int partition_index = partition1(Array, left, right);
        quick_sort1(Array, left, partition_index - 1);
        quick_sort1(Array, partition_index + 1, right);
    }
}

// 第三遍quick_sort
template <typename T>
int partition2(vector<T> &Array, int left, int right)
{
    T pivot = Array[right];
    int left_idx = left, right_idx = right;
    while (left_idx < right_idx)
    {
        while (left_idx < right_idx && Array[left_idx] <= pivot)
            left_idx++;
        while (left_idx < right_idx && Array[right_idx] > pivot)
            right_idx--;
        swap(Array[left_idx], Array[right_idx]);
    }
    swap(Array[right], Array[left_idx]);
    return right_idx;
}

template <typename T>
void quick_sort2(vector<T> &Array, int left, int right)
{
    if (left < right)
    {
        int mid_idx = partition2(Array, left, right);
        quick_sort2(Array, left, mid_idx - 1);
        quick_sort2(Array, mid_idx + 1, right);
    }
}

// 第四次quick_sort
int Paritition3(int A[], int low, int high)
{
    int pivot = A[low];
    while (low < high)
    {
        while (low < high && A[high] >= pivot)
        {
            --high;
        }
        A[low] = A[high];
        while (low < high && A[low] <= pivot)
        {
            ++low;
        }
        A[high] = A[low];
    }
    A[low] = pivot;
    return low;
}

void QuickSort(int A[], int low, int high) //快排母函数
{
    if (low < high)
    {
        int pivot = Paritition3(A, low, high);
        QuickSort(A, low, pivot - 1);
        QuickSort(A, pivot + 1, high);
    }
}

int main()
{
    vector<int> v1{10, 3, 2, 0, 6, 5, 4, 8, 9, 7};
    int array[10] = {1, 3, 2, 0, 6, 5, 4, 8, 9, 7};
    quick_sort1(v1, 0, v1.size() - 1);
    for (int i = 0; i < 10; i++)
    {
        cout << v1[i] << endl;
    }
    return 0;
}