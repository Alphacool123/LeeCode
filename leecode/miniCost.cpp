#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    /**
     * @param costs: n x 3 cost matrix
     * @return: An integer, the minimum cost to paint all houses
     */
    int minCost(vector<vector<int>> &costs)
    {
        int N = costs.size();
        if (N <= 0)
            return 0;
        int **dp = new int *[N];
        for (int i = 0; i < N; i++)
            dp[i] = new int[3];
        dp[0][0] = costs[0][0];
        dp[0][1] = costs[0][1];
        dp[0][2] = costs[0][2];
        for (int i = 1; i < costs.size(); i++)
        {
            dp[i][0] = min(costs[i][0] + dp[i - 1][1], costs[i][0] + dp[i - 1][2]);
            dp[i][1] = min(costs[i][1] + dp[i - 1][0], costs[i][1] + dp[i - 1][2]);
            dp[i][2] = min(costs[i][2] + dp[i - 1][0], costs[i][2] + dp[i - 1][1]);
        }
        return min(dp[N - 1][0], min(dp[N - 1][1], dp[N - 1][2]));
    }
};

int main()
{
    Solution a;
    vector<vector<int>> v{{}};
    cout << a.minCost(v);
    return 0;
}