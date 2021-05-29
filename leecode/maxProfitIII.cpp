#include <iostream>
#include <vector>
#include <limits>
using namespace std;

class Solution
{
public:
    /**
     * @param prices: Given an integer array
     * @return: Maximum profit
     */
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        if (n == 0)
            return 0;

        vector<vector<int>> dp(n + 1, vector<int>(5 + 1, 0));
        dp[0][1] = 0;
        dp[0][2] = dp[0][3] = dp[0][4] = dp[0][5] = numeric_limits<int>::min();
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j <= 5; j++)
            {
                if (i % 2 != 0)
                {
                    dp[i][j] = dp[i - 1][j];
                    if (j > 1 && i > 1 && dp[i - 1][j - 1] != numeric_limits<int>::min())
                        dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + prices[i - 1] - prices[i - 2]);
                }
                else
                {
                    dp[i][j] = dp[i - 1][j - 1];
                    if (i > 1 && dp[i - 1][j] != numeric_limits<int>::max())
                        dp[i][j] = max(dp[i][j], dp[i - 1][j] + prices[i - 1] - prices[i - 2]);
                    if (j > 2 && i > 1 && dp[i - 1][i - 2] != numeric_limits<int>::min())
                        dp[i][j] = max(dp[i][j], dp[i - 1][j - 2] + prices[i - 1] - prices[i - 2]);
                }
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }
        return max(max(dp[n][1], dp[n][3]), dp[n][5]);
    }
};

int main()
{
    vector<int> v{4, 4, 6, 1, 1, 4, 2, 5};
    Solution a;
    cout << a.maxProfit(v);
    return 0;
}