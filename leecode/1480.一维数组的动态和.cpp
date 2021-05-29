#include <iostream>
#include <vector>
using namespace std;

/*
 * @lc app=leetcode.cn id=1480 lang=cpp
 *
 * [1480] 一维数组的动态和
 */

// @lc code=start
class Solution
{
public:
    vector<int> runningSum(vector<int> &nums)
    {
        int count = 0;
        vector<int> result;

        for (int i = 0; i < nums.size(); i++)
        {
            count += nums[i];
            result.push_back(count);
        }
        return result;
    }
};
// @lc code=end
