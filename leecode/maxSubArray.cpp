#include <iostream>
#include <vector>
#include <limits>
using namespace std;

class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        if (nums.size() == 1)
            return nums[0];
        int max_sum = numeric_limits<int>::min();
        for (int i = 0; i < nums.size(); i++)
        {
            int p = i;
            int count = 0;
            for (int j = i; j < nums.size(); j++)
            {
                while (p < j + 1)
                {
                    count += nums[p++];
                    max_sum = max(max_sum, count);
                }
            }
        }
        return max_sum;
    }
};

int main()
{

    vector<int> v{-2, 1, -3, 4, -1, 2, 1, -5, 4};
    Solution a;
    int b = a.maxSubArray(v);
    cout << b << endl;

    return 0;
}