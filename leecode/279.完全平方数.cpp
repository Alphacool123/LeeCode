#include <iostream>
using namespace std;

/*
 * @lc app=leetcode.cn id=279 lang=cpp
 *
 * [279] 完全平方数
 */

// @lc code=start
class Solution
{
public:
    int numSquares(int n)
    {
        int *dp = new int[n + 1];
        dp[0] = 0;
        dp[1] = 1;
        for (int i = 2; i <= n; i++)
        {
            int j = 1;
            dp[i] = i;
            while (j * j <= i)
            {
                dp[i] = min(dp[i], dp[i - j * j] + 1);
                j++;
            }
        }
        return dp[n];
    }
};
// @lc code=end
