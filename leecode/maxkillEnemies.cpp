#include <iostream>
#include <vector>
#include "string.h"
using namespace std;

class Solution
{
public:
    /**
     * @param grid: Given a 2D grid, each cell is either 'W', 'E' or '0'
     * @return: an integer, the maximum enemies you can kill using one bomb
     */
    int maxKilledEnemies(vector<vector<char>> &grid)
    {
        // write your code here
        if (grid.size() == 0)
            return 0;

        int m = grid.size();
        int n = grid[0].size();

        int left[m][n], right[m][n], up[m][n], down[m][n];
        memset(left, 0, sizeof(left));
        memset(right, 0, sizeof(right));
        memset(up, 0, sizeof(up));
        memset(down, 0, sizeof(down));

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == 0)
                {
                    if (grid[i][j] == '0')
                        up[i][j] = 0;
                    if (grid[i][j] == 'E')
                        up[i][j] = 1;
                    if (grid[i][j] == 'W')
                        up[i][j] = 0;
                }
                else
                {
                    if (grid[i][j] == '0')
                        up[i][j] = up[i - 1][j];
                    if (grid[i][j] == 'E')
                        up[i][j] = up[i - 1][j] + 1;
                    if (grid[i][j] == 'W')
                        up[i][j] = 0;
                }
            }
        }

        for (int i = m - 1; i >= 0; i--)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == m - 1)
                {
                    if (grid[i][j] == '0')
                        down[i][j] = 0;
                    if (grid[i][j] == 'E')
                        down[i][j] = 1;
                    if (grid[i][j] == 'W')
                        down[i][j] = 0;
                }
                else
                {
                    if (grid[i][j] == '0')
                        down[i][j] = down[i + 1][j];
                    if (grid[i][j] == 'E')
                        down[i][j] = down[i + 1][j] + 1;
                    if (grid[i][j] == 'W')
                        down[i][j] = 0;
                }
            }
        }

        for (int j = 0; j < n; j++)
        {
            for (int i = 0; i < m; i++)
            {
                if (j == 0)
                {
                    if (grid[i][j] == '0')
                        left[i][j] = 0;
                    if (grid[i][j] == 'E')
                        left[i][j] = 1;
                    if (grid[i][j] == 'W')
                        left[i][j] = 0;
                }
                else
                {
                    if (grid[i][j] == '0')
                        left[i][j] = left[i][j - 1];
                    if (grid[i][j] == 'E')
                        left[i][j] = left[i][j - 1] + 1;
                    if (grid[i][j] == 'W')
                        left[i][j] = 0;
                }
            }
        }

        for (int j = n - 1; j >= 0; j--)
        {
            for (int i = 0; i < m; i++)
            {
                if (j == 0)
                {
                    if (grid[i][j] == '0')
                        right[i][j] = 0;
                    if (grid[i][j] == 'E')
                        right[i][j] = 1;
                    if (grid[i][j] == 'W')
                        right[i][j] = 0;
                }
                else
                {
                    if (grid[i][j] == '0')
                        right[i][j] = right[i][j + 1];
                    if (grid[i][j] == 'E')
                        right[i][j] = right[i][j + 1] + 1;
                    if (grid[i][j] == 'W')
                        right[i][j] = 0;
                }
            }
        }

        int result = 0;
        int temp;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 'E')
                    temp = 1;
                if (grid[i][j] == '0' || grid[i][j] == 'W')
                    temp = up[i][j] + down[i][j] + left[i][j] + right[i][j];
                result = max(result, temp);
            }
        }
        return result;
    }
};

int main()
{
    Solution a;
    vector<vector<char>> v = {{'0', 'E', '0', '0'}, {'E', '0', 'W', 'E'}, {'0', 'E', '0', '0'}};
    cout << a.maxKilledEnemies(v);
    return 0;
}