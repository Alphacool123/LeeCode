#include <iostream>
#include <vector>
using namespace std;

/*
 * @lc app=leetcode.cn id=312 lang=cpp
 *
 * [312] 戳气球
 */

// @lc code=start
class Solution
{
public:
    int maxCoins(vector<int> &nums)
    {

        if (nums.size() == 1)
            return nums[0];
        int max_coins = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            vector<int> temp = nums;
            nums.erase(nums.begin() + i);
            if (i == 0)
                max_coins = max(max_coins, (temp[i] * temp[i + 1] + maxCoins(nums)));
            else if (i == nums.size() - 1)
                max_coins = max(max_coins, (temp[i] * temp[i - 1] + maxCoins(nums)));
            else
                max_coins = max(max_coins, (temp[i - 1] * temp[i] * temp[i + 1] + maxCoins(nums)));

            nums = temp;
        }
        return max_coins;
    }
};
