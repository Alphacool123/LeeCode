#include <iostream>
#include <vector>
using namespace std;

/*
 * @lc app=leetcode.cn id=300 lang=cpp
 *
 * [300] 最长递增子序列
 */

// @lc code=start
class Solution
{
public:
    // int max_num(int *nums, int n)
    // {
    //     int max_number = nums[0];
    //     for (int i = 0; i < n; i++)
    //     {
    //         max_number = max_number >= nums[i] ? max_number : nums[i];
    //     }
    //     return max_number;
    // }

    int lengthOfLIS(vector<int> &nums)
    {
        vector<int> dp(nums.size(), 0);
        dp[0] = 1;
        for (int i = 1; i < nums.size(); i++)
        {
            int j = i - 1;
            while (j >= 0)
            {
                if (nums[i] > nums[j])
                    dp[i] = max(dp[i], dp[j] + 1);
                j--;
            }
            if (dp[i] == 0)
                dp[i] = 1;
        }
        return *max_element(dp.begin(), dp.end());
    }
};
// @lc code=end
