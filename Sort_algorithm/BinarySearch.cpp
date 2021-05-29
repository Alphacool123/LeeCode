#include <iostream>
#include <vector>
using namespace std;

template <class T>
int BinarySearch(T &arr, int value)
{
    auto low = 0;
    auto high = sizeof(arr) / sizeof(arr[0]) - 1;

    while (low < high)
    {
        auto mid = (low + high) / 2;
        if (arr[mid] == value)
        {
            return mid;
        }
        if (arr[mid] < value)
            low = mid + 1;
        else
            high = mid - 1;
    }
}

int main()
{
    int addr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27};

    cout << BinarySearch(addr, 15);

    return 0;
}
#include <iostream>
#include <vector>
using namespace std;

int BinarySearch(int *arr, int value)
{
    int low = 0;
    int high = sizeof(arr) / sizeof(arr[0]) - 1;

    while (low < high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] == value)
        {
            return mid;
        }
        if (arr[mid] < value)
            low = mid + 1;
        else
            high = mid - 1;
    }
}

int main()
{
    int addr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27};

    cout << BinarySearch(addr, 15);

    return 0;
}
