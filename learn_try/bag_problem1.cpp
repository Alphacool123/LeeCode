#include <iostream>
using namespace std;

int max_value(int *weight, int *value, int index, int rest, const int n)
{
    if (rest < 0)
        return -1;
    if (index == n)
        return 0;
    int p1 = max_value(weight, value, index + 1, rest, n);
    int p2 = max_value(weight, value, index + 1, rest - weight[index], n);
    if (p2 != -1)
        p2 = p2 + value[index];
    return max(p1, p2);
}

int main()
{
    int N;
    cin >> N;
    int bag;
    cin >> bag;
    int *weight = new int[N];
    int *value = new int[N];
    for (int i = 0; i < N; i++)
        cin >> weight[i];
    for (int i = 0; i < N; i++)
        cin >> value[i];
    cout << max_value(weight, value, 0, bag, N);
    return 0;
}