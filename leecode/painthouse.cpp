#include <iostream>
#include <vector>
#include "string.h"
#include <limits>
using namespace std;

class Solution
{
public:
    /**
     * @param costs: n x k cost matrix
     * @return: an integer, the minimum cost to paint all houses
     */
    int minCostII(vector<vector<int>> &costs)
    {
        if (costs.size() == 0)
            return 0;
        // write your code here
        int N = costs.size();
        int K = costs[0].size();
        int **dp = new int *[N];
        for (int i = 0; i < N; i++)
            dp[i] = new int[K];
        for (int j = 0; j < K; j++)
            dp[0][j] = costs[0][j];

        int min1, min2;
        int j1, j2;

        for (int i = 1; i < N; i++)
        {
            min1 = numeric_limits<int>::max();
            min2 = numeric_limits<int>::max();
            for (int j = 0; j < K; j++)
            {
                if (dp[i - 1][j] < min1)
                {
                    min2 = min1;
                    j2 = j1;
                    min1 = dp[i - 1][j];
                    j1 = j;
                }
                else
                {
                    if (dp[i - 1][j] < min2)
                    {
                        min2 = dp[i - 1][j];
                        j2 = j;
                    }
                }
            }
            cout << min1 << endl;
            cout << min2 << endl;
            for (int j = 0; j < K; j++)
            {
                if (j == j1)
                    dp[i][j] = min2 + costs[i][j];
                else
                    dp[i][j] = min1 + costs[i][j];
                cout << dp[i][j] << " ";
            }
        }
        int res = dp[N - 1][0];
        for (int j = 0; j < K; j++)
        {
            res = min(res, dp[N - 1][j]);
        }
        return res;
    }
};

int main()
{
    Solution a;
    vector<vector<int>> v{{1, 2, 3}, {1, 4, 6}};
    cout << a.minCostII(v);

    return 0;
}