#include <iostream>
using namespace std;

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
    int **dp = new int *[N + 1];
    for (int i = 0; i <= N; i++)
        dp[i] = new int[bag + 1];

    // 初始化
    for (int i = 0; i <= bag; i++)
        dp[N][i] = 0;

    for (int i = N - 1; i >= 0; i--)
    {
        for (int j = 0; j <= bag; j++)
        {
            dp[i][j] = max(dp[i + 1][j], (j - weight[i] >= 0 ? dp[i + 1][j - weight[i]] + value[i] : -1));
        }
    }
    cout << dp[0][bag];

    return 0;
}