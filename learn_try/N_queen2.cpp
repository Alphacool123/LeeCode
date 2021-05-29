#include <iostream>
#include <iterator>
using namespace std;

// 判断i行，j列放置皇后，是否会和前面放置的皇后有冲突
bool is_valid(int arr[], int i, int j)
{
    for (int k = 0; k < i; k++)
    {
        if (arr[k] == j || abs(i - k) == abs(arr[k] - j))
            return false;
    }
    return true;
}

// 使用回说算法
// 限制条件index == n
// 利用数组的元素覆盖，不回朔
int N_queens(int index, int record[], int n)
{
    if (index == n)
        return 1;
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        if (is_valid(record, index, i))
        {
            record[index] = i;
            res += N_queens(index + 1, record, n);
        }
    }
    return res;
}

int main()
{
    int N;
    cin >> N;
    int *arr = new int[N];
    for (int i = 0; i < N; i++)
        arr[i] = -1;
    cout << N_queens(0, arr, N);

    return 0;
}