#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
 * @lc app=leetcode.cn id=136 lang=cpp
 *
 * [136] 只出现一次的数字
 */

// @lc code=start
class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int i = 0, j = 0;
        while (i <= j && i < nums.size() && j < nums.size())
        {
            if (nums[i] != nums[j] && (j - i) == 1)
                break;
            else if (nums[i] == nums[j])
                j++;
            else if (nums[i] != nums[j] && (j - i) > 1)
                i = j++;
        }
        return nums[i];
    }
};
// @lc code=end
