#include <iostream>
#include <vector>
/*
 * @lc app=leetcode.cn id=704 lang=cpp
 *
 * [704] 二分查找
 */

// @lc code=start
class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        if (nums[0] > target || nums[nums.size() - 1] < target)
            return -1;
        int left = 0;
        int right = nums.size() - 1;
        while (right - left > 1)
        {
            int mid = (left + right) / 2;
            if (nums[mid] == target)
                return mid;
            if (nums[mid] > target)
                right = mid;
            if (nums[mid] < target)
                left = mid;
        }
        if (nums[left] == target)
            return left;
        if (nums[right] == target)
            return right;
        return -1;
    }
};
// @lc code=end
