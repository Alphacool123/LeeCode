#include <iostream>
using namespace std;

int second(int *arr, int left, int right);
int first(int *arr, int left, int right)
{
    if (left == right)
        return arr[left];
    return max(arr[left] + second(arr, left + 1, right), arr[right] + second(arr, left, right - 1));
}

int second(int *arr, int left, int right)
{
    if (left == right)
        return 0;
    return min(first(arr, left + 1, right), first(arr, left, right - 1));
}

int main()
{
    int N;
    cin >> N;
    int *arr = new int[N];
    for (int i = 0; i < N; i++)
        cin >> arr[i];
    int f = first(arr, 0, N - 1);
    int s = second(arr, 0, N - 1);
    if (f > s)
        cout << "先手赢" << endl;
    else if (f < s)
        cout << "后手赢" << endl;
    else
        cout << "平局" << endl;

    return 0;
}