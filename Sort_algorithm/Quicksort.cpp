#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>
using namespace std;

template <typename T>
void print(vector<T> &array)
{
    cout << "[";
    for (int i = 0; i < array.size(); i++)
        cout << " " << array[i];
    cout << " ]";
}

vector<int> rand_list(int n)
{
    srand((int)time(0));
    vector<int> res;
    for (int i = 0; i < n; i++)
    {
        int num = rand();
        res.push_back(num);
    }
    return res;
}

template <typename T>
int partition(vector<T> &Array, int left, int right)
{
    T pivot = Array[right];
    int leftidx = left, rightidx = right;
    while (leftidx < rightidx)
    {
        while (leftidx < rightidx && Array[leftidx] < pivot)
            leftidx++;
        while (leftidx < rightidx && Array[rightidx] >= pivot)
            rightidx--;
        swap(Array[leftidx], Array[rightidx]);
    }
    swap(Array[leftidx], Array[right]);
    return leftidx;
}

template <typename T>
void quick_sort(vector<T> &Array, int left, int right)
{
    if (left < right)
    {
        int mid_idx = partition(Array, left, right);
        quick_sort(Array, left, mid_idx - 1);
        quick_sort(Array, mid_idx + 1, right);
    }
}

int main()
{
    vector<int> v1 = rand_list(25);
    vector<int> v2(v1);

    cout << "排序前：";
    print(v1);
    cout << endl;
    cout << "排序后：";
    quick_sort(v1, 0, v1.size() - 1);
    print(v1);
    cout << endl;
    cout << "验  证：";
    sort(v2.begin(), v2.end());
    print(v2);
    cout << endl;
    if (v1.size() != v2.size())
        cout << "False" << endl;
    for (int i = 0; i < v1.size(); i++)
    {
        if (v1[i] != v2[i])
        {
            cout << "False" << endl;
        }
    }
    cout << "True" << endl;

    return 0;
}