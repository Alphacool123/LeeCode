#include <iostream>
using namespace std;

int walk(const int N, int cur, int rest, const int P)
{
    if (rest == 0)
        return cur == P ? 1 : 0;
    else if (cur == 1)
        return walk(N, 2, rest - 1, P);
    else if (cur == N)
        return walk(N, N - 1, rest - 1, P);
    else
        return walk(N, cur - 1, rest - 1, P) + walk(N, cur + 1, rest - 1, P);
}

int dp_walk(const int N, const int M, const int K, const int P)
{
    int **dp = new int *[K + 1];
    for (int i = 0; i <= K; i++)
    {
        dp[i] = new int[N + 1];
    }
    for (int i = 1; i <= N; i++)
    {
        if (i == P)
            dp[0][i] = 1;
        else
            dp[0][i] = 0;

        cout << dp[0][i] << " ";
    }
    cout << endl;
    for (int i = 1; i <= K; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            if (j == 1)
                dp[i][j] = dp[i - 1][2];
            else if (j == N)
                dp[i][j] = dp[i - 1][N - 1];
            else
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j + 1];
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    return dp[K][M];
}

int main()
{
    cout << walk(7, 3, 5, 2) << endl;
    cout << dp_walk(7, 3, 5, 2) << endl;
    return 0;
}