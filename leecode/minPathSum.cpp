#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    /**
     * @param grid: a list of lists of integers
     * @return: An integer, minimizes the sum of all numbers along its path
     */
    int minPathSum(vector<vector<int>> &grid)
    {
        // write your code here
        int m = grid.size();
        int n = grid[0].size();
        int **dp = new int *[m];
        for (int i = 0; i < m; i++)
            dp[i] = new int[n];

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == 0 && j == 0)
                    dp[i][j] = grid[i][j];
                else if (i == 0)
                    dp[i][j] = grid[i][j] + dp[i][j - 1];
                else if (j == 0)
                    dp[i][j] = grid[i][j] + dp[i - 1][j];
                else
                    dp[i][j] = min(grid[i][j] + dp[i][j - 1], grid[i][j] + dp[i - 1][j]);
            }
        }
        return dp[m - 1][n - 1];
    }
};

int main()
{
    Solution a;
    vector<vector<int>> v{{1, 3, 2}};
    cout << a.minPathSum(v);

    return 0;
}