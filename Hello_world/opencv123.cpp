#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;
    vector<vector<int>> dp(N, vector<int>(M, -1));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
            cout << dp[i][j] << "\t";
        cout << endl;
    }

    return 0;
}