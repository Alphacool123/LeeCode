#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int inf = 1e9;
        int minprice = inf, maxprofit = 0;
        for (int i = 0; i < prices.size(); i++)
        {
            maxprofit = max(maxprofit, prices[i] - minprice);
            minprice = min(minprice, prices[i]);
        }

        return maxprofit;
    }

    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        vector<int> num;
        int p = 0, p1 = 0, p2 = 0;
        int length = nums1.size() + nums2.size();
        int half = length / 2 + 1;
        while (p1 < nums1.size() && p2 < nums2.size() && p <= half)
        {
            if (nums1[p1] < nums2[p2])
            {
                num.push_back(nums1[p1++]);
                p++;
            }
            else
            {
                num.push_back(nums2[p2++]);
                p++;
            }
        }
        while (p1 < nums1.size() && p <= half)
        {
            num.push_back(nums1[p1++]);
        }
        while (p2 < nums2.size() && p <= half)
        {
            num.push_back(nums2[p2++]);
        }
        if (length % 2 == 1)
        {
            return (double)num[length / 2];
        }
        else
        {
            return ((double)num[length / 2] + (double)num[length / 2 - 1]) / 2;
        }
    }

    vector<int> nextPermutation(vector<int> &nums)
    {
        int i = nums.size() - 1;
        if (i = 0)
            return nums;
        while (--i >= 0)
        {
            if (nums[i] > nums[i + 1])
                continue;
            else
            {
                int p = 0;
                for (int j = i + 1; j < nums.size(); j++)
                {
                    if (nums[j] > nums[i])
                        p = j;
                    else
                        break;
                }
                break;
            }
        }

        return nums;
    }

    // 最大子序和
    int maxSubArray(vector<int> &nums)
    {
        int max_sub = numeric_limits<int>::min();
        for (int i = 0; i < nums.size() - 1; i++)
        {
            for (int j = i + 1; j < nums.size(); j++)
            {
                int p = i;
                int count = 0;
                while (p < j)
                {
                    count += nums[p];
                    max_sub = max(max_sub, count);
                    p++;
                }
            }
        }
        return max_sub;
    }
};

int main()
{
    vector<int> v1{1, 2, 3};
    vector<int> v2{2, 2, 4, 4};
    Solution a;
    int b = a.maxSubArray(v1);
    cout << b;
    return 0;
}