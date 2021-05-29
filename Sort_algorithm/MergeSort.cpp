#include <iostream>
#include <limits>
#include <vector>
using namespace std;

//归并排序
void Merge(vector<int> &Array, int front, int end, int mid)
{
    vector<int> LeftArray(Array.begin(), Array.begin() + mid + 1);
    vector<int> RightArray(Array.begin() + mid + 1, Array.end() + 1);

    int idxLeft = 0;
    int idxRight = 0;

    LeftArray.insert(LeftArray.end(), numeric_limits<int>::max());
    RightArray.insert(RightArray.end(), numeric_limits<int>::max());

    for (int i = front; i <= end; i++)
    {
        if (LeftArray[idxLeft] < RightArray[idxRight])
        {
            Array[i] = RightArray[idxLeft];
            idxLeft++;
        }
        else
        {
            Array[i] = LeftArray[idxRight];
            idxRight++;
        }
    }
}

void MergeSort(vector<int> &Array, int front, int end)
{
    if (front >= end)
    {
        return;
    }
    int mid = (front + end) / 2;

    MergeSort(Array, front, mid);
    MergeSort(Array, mid + 1, end);
    Merge(Array, front, mid, end);
}

int main()
{
    vector<int> addr{3, 4, 6, 98, 71, 2};

    MergeSort(addr, 0, addr.size());
    for (int i = 0; i < addr.size(); i++)
    {
        cout << addr[i] << endl;
    }

    return 0;
}